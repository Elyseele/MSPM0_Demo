#include "ti/driverlib/dl_adc12.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti/driverlib/dl_timera.h"
#include "ti/driverlib/m0p/dl_core.h"
#include "ti_msp_dl_config.h"
#include <float.h>
#include "adc.h"


uint16_t ADC_Sample_size = ADC_SIZE;
uint16_t gADCSamples[ADC_SIZE];
uint32_t Sample_Rate=10000;

volatile uint8_t check_music_adc=0;
volatile uint8_t check_wave_adc=0;

// void ADC_Init() {
//   DL_DMA_setSrcAddr(
//       DMA, Wave_DMA_CHAN_ID,
//       (uint32_t)DL_ADC12_getMemResultAddress(Wave_ADC_INST, DL_ADC12_MEM_IDX_0));
//   DL_DMA_setDestAddr(DMA, Wave_DMA_CHAN_ID, (uint32_t)&gADCSamples[0]);
//   DL_DMA_setTransferSize(DMA, Wave_DMA_CHAN_ID, ADC_Sample_size);
//   DL_DMA_enableChannel(DMA, Wave_DMA_CHAN_ID);

//   DL_DMA_setSrcAddr(
//       DMA, Music_DMA_CHAN_ID,
//       (uint32_t)DL_ADC12_getMemResultAddress(Music_ADC_INST, DL_ADC12_MEM_IDX_0));
//   DL_DMA_setDestAddr(DMA, Music_DMA_CHAN_ID, (uint32_t)&gADCSamples[0]);
//   DL_DMA_setTransferSize(DMA, Music_DMA_CHAN_ID, ADC_Sample_size);
//   DL_DMA_enableChannel(DMA, Music_DMA_CHAN_ID);

//     NVIC_EnableIRQ(Wave_ADC_INST_INT_IRQN);
//     NVIC_EnableIRQ(Music_ADC_INST_INT_IRQN);
// }

void ADC_Init() {
    DL_DMA_setSrcAddr(DMA, Wave_DMA_CHAN_ID,(uint32_t)DL_ADC12_getMemResultAddress(Wave_ADC_INST, DL_ADC12_MEM_IDX_0));
    DL_DMA_setDestAddr(DMA, Wave_DMA_CHAN_ID, (uint32_t)&gADCSamples[0]);
    DL_DMA_setTransferSize(DMA, Wave_DMA_CHAN_ID, ADC_Sample_size);
    DL_DMA_enableChannel(DMA, Wave_DMA_CHAN_ID);

    DL_DMA_setSrcAddr(DMA, Music_DMA_CHAN_ID,(uint32_t)DL_ADC12_getFIFOAddress(Music_ADC_INST));
    DL_DMA_setDestAddr(DMA, Music_DMA_CHAN_ID, (uint32_t)&gADCSamples[0]);
    DL_DMA_setTransferSize(DMA, Music_DMA_CHAN_ID, ADC_FIFO_SIZE);
    DL_DMA_enableChannel(DMA, Music_DMA_CHAN_ID);

    NVIC_EnableIRQ(Wave_ADC_INST_INT_IRQN);
    NVIC_EnableIRQ(Music_ADC_INST_INT_IRQN);
}

void TIM_Set_Fre(GPTIMER_Regs *TIMER,uint32_t Fre){
    uint32_t LoadValue = (uint32_t)(TIM_CLK/Fre);
    DL_TimerG_stopCounter(TIMER);
    DL_TimerG_setTimerCount(TIMER,0);
    DL_TimerG_setLoadValue(TIMER,LoadValue);
}

void Start_Music_ADC(uint32_t Sample_Rate){
    TIM_Set_Fre(Music_TIM_INST,Sample_Rate);
    DL_TimerG_startCounter(Music_TIM_INST);
}

void Start_Wave_ADC(uint32_t Sample_Rate){
    TIM_Set_Fre(Wave_TIM_INST,Sample_Rate);
    DL_TimerG_startCounter(Wave_TIM_INST);
}

//中断回调函数
void Wave_ADC_INST_IRQHandler(void) {
    switch (DL_ADC12_getPendingInterrupt(Wave_ADC_INST)) {
        case DL_ADC12_IIDX_DMA_DONE:
            DL_TimerG_stopCounter(Wave_TIM_INST); 
            check_wave_adc = 1;
            break;
        default:
            break;
  }
}

void Music_ADC_INST_IRQHandler(void) {
    switch (DL_ADC12_getPendingInterrupt(Music_ADC_INST)) {
        case DL_ADC12_IIDX_DMA_DONE:
            DL_TimerG_stopCounter(Music_TIM_INST);
            check_music_adc = 1;
            break;
        default:
            break;
  }
}
