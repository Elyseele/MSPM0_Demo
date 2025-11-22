#include "delay.h"
#define MS_DELAY (CPUCLK_FREQ / 1000)
#define US_DELAY (CPUCLK_FREQ / 1000000)
void delay_ms(uint16_t ms) {
  while (ms--) {
    delay_cycles(MS_DELAY);
  }
}
void delay_us(uint16_t us) {
  while (us--) {
    delay_cycles(US_DELAY);
  }
}
