#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char red_val[] = {0, LED_RED}, green_val[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS; // anything on LEDS goes to output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed)
    {
      char led_flags = red_val[red_on] | green_val[green_on];

      P1OUT &= (0xff^LEDS) | led_flags; // clear bit
      P1OUT |= led_flags; // set bit
      led_changed = 0;
    }
}
