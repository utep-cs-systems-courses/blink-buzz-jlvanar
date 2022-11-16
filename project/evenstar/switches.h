#ifndef switches_included
#define switches_included


#define SW1 BIT3      //switch 1 is p1.3
#define SWITCHES SW1  //only 1 switch I care about

void switch_init();
void check_switches();

extern char switch_state_down, switch_state_changed;

#endif
