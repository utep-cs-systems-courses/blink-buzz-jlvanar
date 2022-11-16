#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"


int main(void)
{
  /* 
   * initialization block
   * leds and switches
   */
  led_init();
  switch_init();

  /* 
   * master oscillator, CPU, peripheral clocks
   * also enable interrupts
   */
  configureClocks();
  enableWDTInterrupts();

  /* turn off CPU, turn on Interrupt Enable */
  or_sr(0x18);
}
