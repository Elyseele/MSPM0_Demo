#ifndef TJC_USART_HMI_H
#define TJC_USART_HMI_H

#include "ti_msp_dl_config.h"

#define RINGBUFF_LEN 64
#define TX_TEMP_LEN  64

typedef struct {
    volatile uint16_t head;
    uint8_t data[RINGBUFF_LEN];
} HMI_Buffer_t;

extern HMI_Buffer_t tjc_rb;
extern UART_Regs *tjc_huart;

// 函数声明
void HMI_Init(void);

uint16_t HMI_Get_Count(HMI_Buffer_t *rb, UART_Regs *uart);

void HMI_Delete(HMI_Buffer_t *rb, uint16_t size);

uint8_t HMI_Peek(HMI_Buffer_t *rb, uint16_t index);

void HMI_Printf(UART_Regs *uart, const char *fmt, ...);

#endif