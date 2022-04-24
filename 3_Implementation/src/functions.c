#include"heater.h"

//Function to initiate ADC with required registers
void InitADC()
{ADMUX=(1<<REFS0);
ADCSRA=((1<<ADEN)|(7<<ADPS0));}

//Funtion for ADC
uint16_t ReadADC(uint8_t ch)
{ADMUX&=0xf8;
ch=ch&0b00000111;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);
while(!(ADCSRA&(1<<ADIF)))
ADCSRA|=(1<<ADIF);
return(ADC);}

//Function for Interrupt overflow
ISR(TIMER0_OVF_vect)
{o_flow++;}

void tim()
{
    PORTD&=~(1<<PD0);//this opens relay by giving 0v to PD0 pin0 every time tim() is called so heater is OFF
    TCCR0B|=(1<<CS02);
    TIMSK0|=(1<<TOIE0);
    TCNT0=0;
    sei();
    o_flow=0;
    while(1)
    {
        if(o_flow>=14648)
        {
            if(TCNT0>=111)
            {temp();}
        }
    }
}

void temp()
{
    InitADC();
    uint16_t temp;
    temp=ReadADC(0);
    if(temp>357)
    {
        PORTD|=(1<<PD0);//this closes relay by giving 5v to PD0 pin0 so heater is ON
        led1(7324,55);
    }
    else
    {
        PORTD|=(1<<PD0);//this closes relay by giving 5v to PD0 pin0 so heater is ON
        led1(0,0);
    }
}

void led1(unsigned volatile a1,unsigned volatile b1)
{
    TCCR0B|=(1<<CS02);
    TIMSK0|=(1<<TOIE0);
    TCNT0=0;
    sei();
    o_flow=0;
    while(1)
        {
            if(o_flow>=a1)
            {
                if(TCNT0>=b1)
                {
                    TCNT0=0;
                    o_flow=0;
                    tim(14648,111);
                }
            }
        }
}