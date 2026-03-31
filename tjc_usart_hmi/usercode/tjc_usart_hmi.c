#include "tjc_usart_hmi.h"
#include <stdio.h>
#include <stdarg.h>

__attribute__((aligned(4))) HMI_Buffer_t tjc_rb;
UART_Regs *tjc_huart = UART_0_INST;
static uint8_t tjc_tx_buf[TX_TEMP_LEN];

void HMI_Init(void) {
    tjc_rb.head = 0;
    DL_DMA_setSrcAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t)(&tjc_huart->RXDATA));
    DL_DMA_setDestAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t)tjc_rb.data);
    DL_DMA_setTransferSize(DMA, DMA_CH0_CHAN_ID, RINGBUFF_LEN);
    DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);
    DL_UART_Main_enableDMAReceiveEvent(tjc_huart, DL_UART_MAIN_DMA_INTERRUPT_RX);
}

uint16_t HMI_Get_Count(HMI_Buffer_t *rb, UART_Regs *uart) {
    uint16_t remaining = DL_DMA_getTransferSize(DMA, DMA_CH0_CHAN_ID);
    uint16_t tail = RINGBUFF_LEN - remaining;
    return (tail - rb->head + RINGBUFF_LEN) % RINGBUFF_LEN;
}

void HMI_Delete(HMI_Buffer_t *rb, uint16_t size) {
    rb->head = (rb->head + size) % RINGBUFF_LEN;
}

uint8_t HMI_Peek(HMI_Buffer_t *rb, uint16_t index) {
    return rb->data[(rb->head + index) % RINGBUFF_LEN];
}

void HMI_Printf(UART_Regs *uart, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf((char *)tjc_tx_buf, TX_TEMP_LEN - 3, fmt, args);
    va_end(args);
    if (len <= 0) return;
    tjc_tx_buf[len++] = 0xFF;
    tjc_tx_buf[len++] = 0xFF;
    tjc_tx_buf[len++] = 0xFF;
    for (int i = 0; i < len; i++) {
        DL_UART_Main_transmitDataBlocking(uart, tjc_tx_buf[i]);
    }
}

