#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6|BIT7); //ensure zeros on P2SEL2.6 and ".7
  P2SEL &= ~BIT7; //P2SEL.7 must also be zero
  P2SEL |= BIT6; //P2SEL.6 should be 1, and output
  P2DIR = BIT6;
}

void buzzer_set_period
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
