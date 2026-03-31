#include "SI5351.h"
#include "delay.h"

/**
 * @brief I2C 软件延时函数
 */
static void I2C_Delay() {
    delay_us(5);
}

void I2C_Start(void) {
    SDA_H; SCL_H; I2C_Delay();
    SDA_L; I2C_Delay();
    SCL_L; I2C_Delay();
}

void I2C_Stop(void) {
    SDA_L; SCL_L; I2C_Delay();
    SCL_H; I2C_Delay();
    SDA_H; I2C_Delay();
}

void I2C_SendByte(uint8_t dat) {
    for (uint8_t i = 0; i < 8; i++) {
        if (dat & 0x80) {
            SDA_H; 
        } else {
            SDA_L;
        }
        I2C_Delay();
        SCL_H; I2C_Delay();
        SCL_L; I2C_Delay();
        dat <<= 1;
    }
    // 释放SDA等待ACK (开漏模式下写高电平即释放总线)
    SDA_H; I2C_Delay();
}

uint8_t I2C_WaitAck(void) {
    uint16_t timer = 0;
    SCL_H; I2C_Delay();
    while (SDA_read) { 
        if (++timer > 2000) break; 
    }
    SCL_L; I2C_Delay();
    return (timer < 2000);
}

static void SI5351_WriteBulk(uint8_t reg, uint8_t *data, uint8_t len) {
    I2C_Start();
    I2C_SendByte(SI_I2C_ADDR); I2C_WaitAck();
    I2C_SendByte(reg);         I2C_WaitAck();
    for (uint8_t i = 0; i < len; i++) {
        I2C_SendByte(data[i]); I2C_WaitAck();
    }
    I2C_Stop();
}

void SI5351_WriteReg(uint8_t reg, uint8_t data) {
    SI5351_WriteBulk(reg, &data, 1);
}

// ================== 第二部分：Si5351A 参数逻辑 ==================

/**
 * @brief Si5351 通用 8 字节 P-参数打包
 */
static void _SI5351_Pack8(uint8_t *buf, uint32_t ratio_int, uint32_t num, uint32_t den, uint8_t r_div) {
    uint32_t P1 = 128 * ratio_int + (128 * num / den) - 512;
    uint32_t P2 = 128 * num - den * (128 * num / den);

    buf[0] = (uint8_t)(den >> 8);
    buf[1] = (uint8_t)den;
    buf[2] = (uint8_t)((P1 >> 16) & 0x03) | r_div;
    buf[3] = (uint8_t)(P1 >> 8);
    buf[4] = (uint8_t)P1;
    buf[5] = (uint8_t)(((den >> 12) & 0xF0) | ((P2 >> 16) & 0x0F));
    buf[6] = (uint8_t)(P2 >> 8);
    buf[7] = (uint8_t)P2;
}

void SI5351_Init(void) {
    SI5351_WriteReg(SI_REG_XTAL_LOAD, 0xD2); // 10pF 负载电容
    SI5351_WriteReg(SI_REG_OUTPUT_EN, 0xFF); // 初始全关
}

/**
 * @brief 合并高低频、支持手动选择 PLL
 */
void SI5351_SetFrequency(si_clk_t clk, uint32_t freq_hz, si_pll_t pll) {
    if (clk > SI_CLK2) return;

    uint8_t  params[8];
    uint32_t ms_div, vco_freq;
    uint8_t  r_div_bits = 0;
    uint32_t target = freq_hz;

    // 1. 动态计算 R 分频位 (bits 6:4)
    // 只要频率低于 500kHz，就尝试增大 R 分频以保证 VCO 频率足够高
    while (target < 500000 && r_div_bits < 0x70) {
        target <<= 1;
        r_div_bits += 0x10;
    }

    // 2. 计算 Multisynth 分频比 (Integer 模式)
    // 目标让 VCO 在 600-900MHz 之间 (取 800M 附近)
    ms_div = 800000000 / target;
    if (ms_div % 2) ms_div--; // 保证偶数
    if (ms_div < 6) ms_div = 6;

    vco_freq = ms_div * target;

    // 3. 配置 PLL (Fractional 模式)
    uint32_t mult = vco_freq / SI_XTAL_FREQ;
    uint32_t num  = (uint32_t)(((uint64_t)(vco_freq % SI_XTAL_FREQ) * 1048575) / SI_XTAL_FREQ);
    _SI5351_Pack8(params, mult, num, 1048575, 0);
    SI5351_WriteBulk((pll == SI_PLLA) ? 26 : 34, params, 8);

    // 4. 配置 Multisynth (强制整数模式)
    _SI5351_Pack8(params, ms_div, 0, 1, r_div_bits);
    SI5351_WriteBulk(42 + (clk * 8), params, 8);

    // 5. 应用生效
    SI5351_WriteReg(177, (pll == SI_PLLA) ? 0x20 : 0x80); // 重置选中的PLL

    // 0x4F | (pll << 5): 8mA, 整数模式, PLLA/B 选择
    uint8_t ctrl = 0x4F | (pll << 5);
    if (freq_hz > 112500000) ctrl |= 0x40;
    SI5351_WriteReg(16 + clk, ctrl);

    // Reg 3 操作由用户手动管理或在初始化后统一置 0
    SI5351_WriteReg(3, 0x00);
}

void SI5351_DisableOutput(si_clk_t clk) {
    SI5351_WriteReg(SI_REG_CLK0_CTRL + clk, 0x80);
}