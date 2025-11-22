#ifndef ADC_H_
#define ADC_H_

#include <ti/driverlib/dl_adc12.h>

#define ADC_SIZE         (1200)     
#define TIM_CLK          (40000000)
#define ADC_FIFO_SIZE (ADC_SIZE >> 1)   //这里注意必须是DMA Samples Count的整数倍

// 全局缓冲区声明
extern uint16_t gADCSamples[ADC_SIZE];
extern uint32_t Sample_Rate;
extern uint16_t ADC_Sample_size;

// 状态标志（volatile跨文件访问）
extern volatile uint8_t check_wave_adc;
extern volatile uint8_t check_music_adc;

// ADC初始化函数
void ADC_Init(void);

// 定时器频率配置
void TIM_Set_Fre(GPTIMER_Regs *TIMER, uint32_t Fre);

// ADC采样控制
void Start_Music_ADC(uint32_t Sample_Rate);
void Start_Wave_ADC(uint32_t Sample_Rate);

// 中断处理函数声明（需在.c文件中关联）
void Wave_ADC_INST_IRQHandler(void);
void Music_ADC_INST_IRQHandler(void);

#endif /* ADC_H_ */