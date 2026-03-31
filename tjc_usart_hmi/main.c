#include "ti_msp_dl_config.h"
#include "tjc_usart_hmi.h"
#include "delay.h"

#include <string.h>
#include <stdlib.h>

// 参数
float fre = 1000.0f;
float vol = 1000.0f;
uint8_t current_page = 1;

int main(void) {
    SYSCFG_DL_init();

    HMI_Init();

    while (1) {

    }
}

void TJC_Page1_Handler(uint8_t cmd, char *str) {
    if (cmd == 0x01) { // 频率+100
        fre += 100.0f;
        HMI_Printf(tjc_huart, "t0.txt=\"%.2f\"", fre);
    } 
    else if (cmd == 0x02) { // 频率-100
        if (fre > 100) fre -= 100.0f;
        HMI_Printf(tjc_huart, "t0.txt=\"%.2f\"", fre);
    } 
    else if (cmd == 0x03) { // 电压+100
        vol += 100.0f;
        HMI_Printf(tjc_huart, "t1.txt=\"%.2f\"", vol);
    } 
    else if (cmd == 0x04) { // 电压-100
        if (vol > 100) vol -= 100.0f;
        HMI_Printf(tjc_huart, "t1.txt=\"%.2f\"", vol);
    } 
    else if (cmd == 0x11) { // 设置频率
        fre = atof(str);
        HMI_Printf(tjc_huart, "t0.txt=\"%.2f\"", fre);
    } 
    else if (cmd == 0x12) { // 设置电压
        vol = atof(str);
        HMI_Printf(tjc_huart, "t1.txt=\"%.2f\"", vol);
    } 
    else if (cmd == 0x21) { // 设置频率+电压 (逗号分隔解析)
        char *p = str;
        fre = atof(p);
        p = strchr(p, ',');
        if (p) {
            vol = atof(++p);
        }
        HMI_Printf(tjc_huart, "t0.txt=\"%.2f\"", fre);
        HMI_Printf(tjc_huart, "t1.txt=\"%.2f\"", vol);
    }
}

void TJC_Page2_Handler(uint8_t cmd, char *str) { /* 第2页处理 */ }
void TJC_Page3_Handler(uint8_t cmd, char *str) { /* 第3页处理 */ }

/**
 * @brief 核心接收逻辑：帧头校验、寻找 3*0xFF 帧尾、页面分发
 */
void TJC_Receive_Process(void) {
    while (HMI_Get_Count(&tjc_rb, tjc_huart) >= 5) {
        // 检查帧头 0x55
        if (HMI_Peek(&tjc_rb, 0) != 0x55) {
            HMI_Delete(&tjc_rb, 1);
            continue;
        }

        // 找帧尾 0xFF 0xFF 0xFF
        uint8_t len = 0;
        uint8_t cnt = HMI_Get_Count(&tjc_rb, tjc_huart);

        for (uint8_t i = 1; i <= cnt - 3; i++) {
            if (HMI_Peek(&tjc_rb, i) == 0xFF &&
                HMI_Peek(&tjc_rb, i + 1) == 0xFF &&
                HMI_Peek(&tjc_rb, i + 2) == 0xFF) {
                len = i + 3;
                break;
            }
        }

        if (!len) break; // 未找到完整帧尾，退出循环等下一次轮询

        // 提取页码和命令码
        uint8_t page = HMI_Peek(&tjc_rb, 1);
        uint8_t cmd  = HMI_Peek(&tjc_rb, 2);

        // 提取文本数据区 (从索引3开始)
        // 长度计算：总长 - 1(头) - 1(页) - 1(命) - 3(尾) = len - 6
        int text_len = len - 6; 
        char str[32];
        if (text_len < 0) text_len = 0;
        if (text_len > 31) text_len = 31;

        for (uint8_t i = 0; i < text_len; i++) {
            str[i] = HMI_Peek(&tjc_rb, 3 + i);
        }
        str[text_len] = '\0';

        // 根据页码分发
        switch (page) {
            case 0x01:
                TJC_Page1_Handler(cmd, str);
                current_page = 1;
                break;
            case 0x02:
                TJC_Page2_Handler(cmd, str);
                current_page = 2;
                break;
            case 0x03:
                TJC_Page3_Handler(cmd, str);
                current_page = 3;
                break;
            default:
                break;
        }

        // 处理完毕，删除整帧
        HMI_Delete(&tjc_rb, len);
    }
}

void SysTick_Handler(void)
{
    TJC_Receive_Process();
}


