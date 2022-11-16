#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "state_machines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const int second_limit = 250;
  static int variable_limit = 0;
  static int blink_count = 0;
  static int second_count = 0;

  blink_count++;
  if (blink_count >= variable_limit)
    {
      blink_count = 0;
      red_on = 1 - red_on;
      led_changed = 1;
      led_update();
    }

  second_count++;
  if (second_count >= 250)
    {
      led_changed = 1;
      led_update();
      second_count = 0;
      if (variable_limit >=4)
	{
	  variable_limit = 0;
	}
      else
	{
	  variable_limit = 4;
	}
    }

  check_switches();
}
