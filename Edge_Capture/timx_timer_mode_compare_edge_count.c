/*
边沿捕获Demo
上限5.6Mhz
 */

#include "ti/driverlib/dl_gpio.h"
// #include "ti/driverlib/dl_timer.h"
#include "ti/driverlib/dl_timerg.h"
#include "ti_msp_dl_config.h"

const uint32_t TIM_32BIT_MAX_VALUE = 0xFFFFFFFFU; //0-4294967296

volatile uint8_t check_capture=0;
uint32_t edge_num=0,load_value=0;
int main(void)
{
    SYSCFG_DL_init();

    DL_TimerG_setLoadValue(COMPARE_1_INST,TIM_32BIT_MAX_VALUE);
    //DL_TimerA_setCoreHaltBehavior(COMPARE_0_INST, DL_TIMER_CORE_HALT_IMMEDIATE);
    //DL_TimerG_setCoreHaltBehavior(COMPARE_1_INST, DL_TIMER_CORE_HALT_IMMEDIATE);
    //DL_TimerG_setCoreHaltBehavior(PWM_0_INST, DL_TIMER_CORE_HALT_IMMEDIATE);
    DL_TimerG_setCoreHaltBehavior(TIMER_0_INST, DL_TIMER_CORE_HALT_IMMEDIATE);
    //DL_TimerG_setCoreHaltBehavior(TIMER_1_INST, DL_TIMER_CORE_HALT_IMMEDIATE);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);

    while(1){
        if(check_capture){
            check_capture=0;
            edge_num=DL_TimerG_getTimerCount(COMPARE_1_INST);
            load_value=DL_TimerG_getLoadValue(COMPARE_1_INST);
            DL_GPIO_togglePins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);
            __BKPT(0);
            DL_TimerG_setTimerCount(COMPARE_1_INST,0);
            DL_TimerA_startCounter(COMPARE_0_INST);
        }
    }
}
void TIMER_0_INST_IRQHandler(void){
        switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMERG_IIDX_ZERO:
            DL_TimerA_stopCounter(COMPARE_0_INST);
            check_capture=1;
            break;
        default:
            break;
    }
}

// void COMPARE_0_INST_IRQHandler(void)
// {
//     switch (DL_TimerG_getPendingInterrupt(COMPARE_0_INST)) {
//         case DL_TIMERG_IIDX_LOAD:
//             DL_GPIO_togglePins(GPIO_LEDS_PORT,
//                 (GPIO_LEDS_USER_LED_1_PIN | GPIO_LEDS_USER_TEST_PIN));
//             break;
//         default:
//             break;
//     }
// }
