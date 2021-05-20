#include<avr/io.h>
#define F_CPU 12000000
#include<util/delay.h>
void main()
{
  DDRC=0xc0;//input for sensors make sure that all sensors are active high
                                        //( high    for wight)
  PORTC=0xff;//internal pull up
  DDRD=0xff;//motor control pins
  PORTD=0x00;//motor halt
  unsigned char sensor;
 while(1)
 {
     sensor=PINC & 0x03;//masking for lower 2 bits
       if(sensor==0x03)// both are on white
   PORTD=0xaa;//forward
  else if(sensor==0x01)//left sensor on black line
   PORTD=0x66;//left turn
  else if(sensor==0x02)//right sensor on black line
   PORTD=0x99;//right turn
  else 
   PORTD=0x00;//robot stop
   
 }
}
