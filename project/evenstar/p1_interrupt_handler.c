#include <msp430.h>
#include "switches.h"

void
__interrupt_vec(PORT1_VECTOR) Port_1()
{
  /* 
   * if a switch caused the interrupt:
   * clear pending switch interrupts
   * call the handler and let it know what's up
   */
  if (P1IFG & SWITCHES)
    {
      P1IFG &= ~SWITCHES;
      check_switches();
    }
}
