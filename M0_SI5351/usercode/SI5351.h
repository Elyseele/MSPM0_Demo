/*
 * SI5351A 软件IIC驱动，输出频率8k-160M (MSPM0 版本)
 */
#ifndef SI5351_h
#define SI5351_h

#include "ti_msp_dl_config.h"
#include <stdint.h>

/* =========================================================================
 * 【引脚配置说明】
 * 请在 SysConfig 中添加一个 GPIO 分组 (GPIO_SI5351)，包含两个引脚：
 * 1. SCL 引脚: 命名为 SCL
 * 2. SDA 引脚: 命名为 SDA
 * IO 模式配置为 Standard 并开启内部上拉 Pull-Up Resistor
 * ========================================================================= */

#define SCL_H DL_GPIO_setPins(GPIO_SI5351_SCL_PORT, GPIO_SI5351_SCL_PIN)
#define SCL_L DL_GPIO_clearPins(GPIO_SI5351_SCL_PORT, GPIO_SI5351_SCL_PIN)

#define SDA_H DL_GPIO_setPins(GPIO_SI5351_SDA_PORT, GPIO_SI5351_SDA_PIN)
#define SDA_L DL_GPIO_clearPins(GPIO_SI5351_SDA_PORT, GPIO_SI5351_SDA_PIN)

#define SDA_read (DL_GPIO_readPins(GPIO_SI5351_SDA_PORT, GPIO_SI5351_SDA_PIN) ? 1 : 0)

// Si5351A 寄存器
#define SI_I2C_ADDR             0xC0
#define SI_XTAL_FREQ            (25000000 + 2490)

#define SI_REG_OUTPUT_EN        3     // 输出使能控制
#define SI_REG_CLK0_CTRL        16    // CLK0 控制
#define SI_REG_CLK1_CTRL        17    // CLK1 控制
#define SI_REG_CLK2_CTRL        18    // CLK2 控制
#define SI_REG_PLL_A            26    // PLLA 参数起始
#define SI_REG_PLL_B            34    // PLLB 参数起始
#define SI_REG_MS0              42    // MS0 参数起始
#define SI_REG_MS1              50    // MS1 参数起始
#define SI_REG_MS2              58    // MS2 参数起始
#define SI_REG_PLL_RESET        177   // PLL 复位
#define SI_REG_XTAL_LOAD        183   // 负载电容设置

// 参数枚举
typedef enum { SI_PLLA = 0, SI_PLLB = 1 } si_pll_t;
typedef enum { SI_CLK0 = 0, SI_CLK1 = 1, SI_CLK2 = 2 } si_clk_t;

// 函数接口
void SI5351_Init(void);
void SI5351_SetFrequency(si_clk_t clk, uint32_t freq_hz, si_pll_t pll);
void SI5351_DisableOutput(si_clk_t clk);

#endif