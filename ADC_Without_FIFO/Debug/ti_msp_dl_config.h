/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define GPIO_HFXT_PORT                                                     GPIOA
#define GPIO_HFXIN_PIN                                             DL_GPIO_PIN_5
#define GPIO_HFXIN_IOMUX                                         (IOMUX_PINCM10)
#define GPIO_HFXOUT_PIN                                            DL_GPIO_PIN_6
#define GPIO_HFXOUT_IOMUX                                        (IOMUX_PINCM11)
#define CPUCLK_FREQ                                                     40000000



/* Defines for Music_TIM */
#define Music_TIM_INST                                                   (TIMG0)
#define Music_TIM_INST_IRQHandler                               TIMG0_IRQHandler
#define Music_TIM_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define Music_TIM_INST_LOAD_VALUE                                       (39999U)
#define Music_TIM_INST_PUB_0_CH                                              (1)
/* Defines for Wave_TIM */
#define Wave_TIM_INST                                                    (TIMG6)
#define Wave_TIM_INST_IRQHandler                                TIMG6_IRQHandler
#define Wave_TIM_INST_INT_IRQN                                  (TIMG6_INT_IRQn)
#define Wave_TIM_INST_LOAD_VALUE                                            (0U)
#define Wave_TIM_INST_PUB_0_CH                                               (2)




/* Defines for Music_ADC */
#define Music_ADC_INST                                                      ADC1
#define Music_ADC_INST_IRQHandler                                ADC1_IRQHandler
#define Music_ADC_INST_INT_IRQN                                  (ADC1_INT_IRQn)
#define Music_ADC_ADCMEM_0                                    DL_ADC12_MEM_IDX_0
#define Music_ADC_ADCMEM_0_REF                   DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define Music_ADC_ADCMEM_0_REF_VOLTAGE_V                                     3.3
#define Music_ADC_INST_SUB_CH                                                (1)
#define GPIO_Music_ADC_C0_PORT                                             GPIOA
#define GPIO_Music_ADC_C0_PIN                                     DL_GPIO_PIN_15

/* Defines for Wave_ADC */
#define Wave_ADC_INST                                                       ADC0
#define Wave_ADC_INST_IRQHandler                                 ADC0_IRQHandler
#define Wave_ADC_INST_INT_IRQN                                   (ADC0_INT_IRQn)
#define Wave_ADC_ADCMEM_0                                     DL_ADC12_MEM_IDX_0
#define Wave_ADC_ADCMEM_0_REF                    DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define Wave_ADC_ADCMEM_0_REF_VOLTAGE_V                                      3.3
#define Wave_ADC_INST_SUB_CH                                                 (2)
#define GPIO_Wave_ADC_C0_PORT                                              GPIOA
#define GPIO_Wave_ADC_C0_PIN                                      DL_GPIO_PIN_27



/* Defines for Music_DMA */
#define Music_DMA_CHAN_ID                                                    (1)
#define Music_ADC_INST_DMA_TRIGGER                    (DMA_ADC1_EVT_GEN_BD_TRIG)

/* Defines for Wave_DMA */
#define Wave_DMA_CHAN_ID                                                     (0)
#define Wave_ADC_INST_DMA_TRIGGER                     (DMA_ADC0_EVT_GEN_BD_TRIG)


/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_Music_TIM_init(void);
void SYSCFG_DL_Wave_TIM_init(void);
void SYSCFG_DL_Music_ADC_init(void);
void SYSCFG_DL_Wave_ADC_init(void);
void SYSCFG_DL_DMA_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
