#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
 
int main(void)
{
  DDRB |= (1<<PB0);        //B0 is an output
  PORTB |= (1<<PB0);       //B0 is set (Active PullUp)

  if(PORTB == 1)
  {
    DDRB = 0x03;          //B1 is an output
    PORTB = 0x03;         //B1 is set (Active PullUp)
  }
  else
  {
  return 0;
  }

  DDRC |= (1<<PC0);        //C0 is an output
  
  while(1)
  {
  if(PORTB == 0x03)        //Both B0 and B1 is ON  
  {
  PORTC |= (1<<PC0);       //C0 gives out DC output for the oscillator if B0 and B1 is ON
  _delay_ms(50000);        //Turn on C0 for 50s
  PORTC = 0x00;            //Reset C0
  }
  
  else
  {
    PORTC = 0x00;
  }
  }
  
}
