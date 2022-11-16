#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "state_machines.h"

char switch_state_down, switch_state_changed;

void switch_init()
{
  P1REN |= SWITCHES;
  P1IE  |= SWITCHES;
  P1OUT |= SWITCHES;
  P1DIR &= ~SWITCHES;
}

void check_switches()
{
  char p1val = P1IN;
  // reverse the variable for intuitiveness
  switch_state_down = (p1val & SW1) ? 0:1;
  if (switch_state_down)
    {
      // if button, call state0
      fast_counter();
    } else
    {
      second_counter();
    }
  led_changed = 1;
  led_update();
}
