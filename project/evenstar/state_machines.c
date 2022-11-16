#include "state_machines.h"
#include "led.h"

// State0 (button pushed) calls custom function
// will count to 100 then call the function
void fast_counter(void)
{
  static int count = 0;
  static int blink_count = 0;


  count++;
  // every 2/5ths of a second
  if (count >= 100)
    {
    // call custom function (C or Assembly)
    blink_pattern(blink_count);
    // increment blink counter
    blink_count++;
    // tell led.c the led changed
    led_changed = 1;
    led_update();
    // reset counter to 0
    count = 0;
    }
  
  // reset blinkCount to 0 if it reaches 25 (end of pattern)
  if (blink_count > 25)
    {
    blink_count = 0;
    }
}

// State1 (button not pushed) executes code once per second
// The light will turn on/off every second
void second_counter(void)
{
  // number of ticks per second
  const  int second_limit = 250;
  static int second_count = 0;


  // measure a second
  second_count ++;
  // once each second
  if (second_count >= second_limit)
    {
      // flip the green light
      green_on = 1 - green_on;
      // update lights after signaling change
      led_changed = 1;
      led_update();
      // reset it for the next one
      second_count = 0;
    }
}
