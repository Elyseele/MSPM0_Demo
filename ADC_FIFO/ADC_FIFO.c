/*
 * 2 channels ADC + TIM + DMA in repeat mode 
 * 采集的
 */

#include "ti_msp_dl_config.h"
#include "adc.h"

int main(void)
{
    SYSCFG_DL_init();
    ADC_Init();

    //Start_Wave_ADC(10000);
    Start_Music_ADC(10000);

    while (1) {
        if(check_wave_adc==1){
            check_wave_adc=0;
            __BKPT(0);
            Start_Wave_ADC(10000);
        }
        if(check_music_adc==1){
            check_music_adc=0;
            __BKPT(0);
            Start_Music_ADC(10000);
        }

    }
}