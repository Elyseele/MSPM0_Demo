#include "delay.h"
#include "ti/driverlib/m0p/dl_core.h"

#define DELAY_MS (CPUCLK_FREQ / 1000)
#define DELAY_US (CPUCLK_FREQ / 1000000)
#define DELAY_NS (CPUCLK_FREQ / 10000000000)

void delay_ms(uint16_t ms) {
  while (ms--) {
    delay_cycles(DELAY_MS);
  }
}

void delay_us(uint16_t us) {
  while (us--) {
    delay_cycles(DELAY_US);
  }
}

void delay_ns(uint16_t ns) {
  while (ns--) {
    delay_cycles(DELAY_NS);
  }
}