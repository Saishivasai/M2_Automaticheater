#include"heater.h"

int main(void)
{DDRD|=(1<<PD0);//sets direction of pin0 as output
PORTD&=~(1<<PD0);//clears bit PD0
tim();
return 0;}