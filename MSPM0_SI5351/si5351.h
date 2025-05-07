#ifndef __SI53531_H__
#define __SI53531_H__
#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"
#include "stdint.h"
     
//#include "system.h"
//Si5351寄存器声明
#define SI_CLK0_CONTROL	16			// Register definitions
#define SI_CLK1_CONTROL	17
#define SI_CLK2_CONTROL	18
#define SI_SYNTH_PLL_A	26
#define SI_SYNTH_PLL_B	34
#define SI_SYNTH_MS_0		42
#define SI_SYNTH_MS_1		50
#define SI_SYNTH_MS_2		58
#define SI_PLL_RESET		177

#define SI_R_DIV_1		0x00			// R-division ratio definitions
#define SI_R_DIV_2		16				//0b00010000
#define SI_R_DIV_4		32				//0b00100000
#define SI_R_DIV_8		48				//0b00110000
#define SI_R_DIV_16		64				//0b01000000
#define SI_R_DIV_32		80				//0b01010000
#define SI_R_DIV_64		96				//0b01100000
#define SI_R_DIV_128		112			//0b01110000

#define SI_CLK_SRC_PLL_A	0x00
#define SI_CLK_SRC_PLL_B	0b00100000
#define XTAL_FREQ	25000000			// Crystal frequency
//IIC总线引脚配置

#define SDA(n) {n?DL_GPIO_setPins(si5351_SDA_PORT, si5351_SDA_PIN):DL_GPIO_clearPins(si5351_SDA_PORT, si5351_SDA_PIN);}
#define CLK(n) {n?DL_GPIO_setPins(si5351_CLK_PORT, si5351_CLK_PIN):DL_GPIO_clearPins(si5351_CLK_PORT, si5351_CLK_PIN);}
//相关函数声明
void SetPLLClk(uint8_t pll, uint8_t mult, uint32_t num, uint32_t denom);//设置PPL时钟
void SetFrequency(uint32_t frequency,uint8_t div);//时钟Si5351时钟频率
void SetMultisynth(uint8_t synth,uint32_t divider,uint8_t rDiv);//设置多synth
#endif

