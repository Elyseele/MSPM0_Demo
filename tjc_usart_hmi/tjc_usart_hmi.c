/*

 */
//#include "dl_uart_main.h" 
#include <ti/driverlib/dl_uart_main.h>
#include "ti_msp_dl_config.h"
#include "tjc_usart_hmi.h" 
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>

#define STR_LENGTH 100

// Ring buffer structure definition
typedef struct
{
	uint16_t Head;
	uint16_t Tail;
	uint16_t Lenght;
	uint8_t  Ring_data[RINGBUFF_LEN];
}RingBuff_t;

RingBuff_t ringBuff;



//------------------------------------------------------------------
// Function: uart0_send_char
// Purpose:  Send a single character via UART0 (blocking)
// Args:     ch - Character to send
//------------------------------------------------------------------
void uart0_send_char(char ch)
{
    while( DL_UART_isBusy(UART_0_INST) == true );
    DL_UART_Main_transmitData(UART_0_INST, ch);
}

//------------------------------------------------------------------
// Function: uart0_send_string
// Purpose:  Send a null-terminated string via UART0
// Args:     str - Pointer to the string
//------------------------------------------------------------------
void uart0_send_string(char* str)
{
    while(*str!=0&&str!=0)
    {
        uart0_send_char(*str++);
    }
}


//------------------------------------------------------------------
// Function: tjc_send_string
// Purpose:  Send a string to the TJC HMI, appending 0xFF x3 as protocol terminator
// Args:     str - Pointer to the string
//------------------------------------------------------------------
void tjc_send_string(char* str)
{
    while(*str!=0&&str!=0)
    {
        uart0_send_char(*str++);
    }
    // Append protocol terminator (0xFF x3)
	uart0_send_char(0xff);
	uart0_send_char(0xff);
	uart0_send_char(0xff);
}



//------------------------------------------------------------------
// Function: TJC_SendData
// Purpose:  Send raw data bytes to the TJC HMI
// Args:     data - Pointer to data array
//           len  - Number of bytes to send
//------------------------------------------------------------------
void TJC_SendData(uint8_t *data, uint16_t len)
{
	while(len--)
	{
		uart0_send_char(*data++);
		
	}

}


//------------------------------------------------------------------
// Function: TJCPrintf
// Purpose:  Formatted print function for TJC HMI (supports variable arguments)
// Example:  TJCPrintf("n0.val=%d", 123) sends "n0.val=123\xFF\xFF\xFF"
// Args:     str - Format string followed by optional arguments
//------------------------------------------------------------------
void TJCPrintf(const char *str, ...)
{


	uint8_t end = 0xff;
	char buffer[STR_LENGTH+1];  // ???????
	va_list arg_ptr;
	va_start(arg_ptr, str);
	int len = vsnprintf(buffer, STR_LENGTH+1, str, arg_ptr);
	va_end(arg_ptr);
	for(int i = 0; i < len; i++)
	{
		uart0_send_char(buffer[i]);
		
	}

	uart0_send_char(end);
	uart0_send_char(end);
	uart0_send_char(end);
}


//------------------------------------------------------------------
// Function: initRingBuff
// Purpose:  Initialize the ring buffer (reset pointers and length)
//------------------------------------------------------------------
void initRingBuff(void)
{
  ringBuff.Head = 0;
  ringBuff.Tail = 0;
  ringBuff.Lenght = 0;
}




//------------------------------------------------------------------
// Function: writeRingBuff
// Purpose:  Write a byte to the ring buffer (discard if buffer is full)
// Args:     data - Byte to write
//------------------------------------------------------------------
void writeRingBuff(uint8_t data)
{
  if(ringBuff.Lenght >= RINGBUFF_LEN) // Buffer full, discard data
  {
    return ;
  }
  ringBuff.Ring_data[ringBuff.Tail]=data;
  ringBuff.Tail = (ringBuff.Tail+1)%RINGBUFF_LEN;// Circular increment
  ringBuff.Lenght++;

}



//------------------------------------------------------------------
// Function: deleteRingBuff
// Purpose:  Delete a specified number of bytes from the buffer.
//           If size exceeds current length, reset the buffer.
// Args:     size - Number of bytes to delete
//------------------------------------------------------------------
void deleteRingBuff(uint16_t size)
{
	if(size >= ringBuff.Lenght)
	{
	    initRingBuff();
	    return;
	}
	for(int i = 0; i < size; i++)
	{

		if(ringBuff.Lenght == 0)// Safety check for empty buffer
		{
		initRingBuff();
		return;
		}
		ringBuff.Head = (ringBuff.Head+1)%RINGBUFF_LEN;// Circular increment
		ringBuff.Lenght--;

	}

}



//------------------------------------------------------------------
// Function: read1BFromRingBuff
// Purpose:  Read 1 byte from the ring buffer at a logical offset
// Args:     position - Offset from the Head pointer
// Returns:  Byte value at the specified position
//------------------------------------------------------------------
uint8_t read1BFromRingBuff(uint16_t position)
{
	uint16_t realPosition = (ringBuff.Head + position) % RINGBUFF_LEN;

	return ringBuff.Ring_data[realPosition];
}




//------------------------------------------------------------------
// Function: getRingBuffLenght
// Purpose:  Get current data length in the ring buffer
// Note:     Typo in "Lenght" (should be "Length")
// Returns:  Current buffer length
//------------------------------------------------------------------
uint16_t getRingBuffLenght()
{
	return ringBuff.Lenght;
}


//------------------------------------------------------------------
// Function: isRingBuffOverflow
// Purpose:  Check if the ring buffer is full
// Returns:  1 if full, 0 otherwise
//------------------------------------------------------------------
uint8_t isRingBuffOverflow()
{
	return ringBuff.Lenght == RINGBUFF_LEN;
}







