#include "mbed.h"

DigitalOut myled( LED1 );
DigitalOut myled2( LED2 );
DigitalOut myled3( LED3 );
DigitalOut myled4( LED4 );
DigitalOut red( p23 );
DigitalOut green( p24 );
DigitalOut blue( p25 );

AnalogIn Pot1( p19 );
AnalogIn Pot2( p20 );

void chenillard( void );

int main(){
    while( 1 ){
      if( Pot1 > 0.5 ){
        chenillard();
        red = 1;
        wait(1);
        red = 0;
      }

      if( Pot2 > 0.7 ){
        chenillard ();

        green = 1;
        wait(1);
        green = 0;
      }

      printf("\r\nValeur de Pot1 : %f",Pot1.read() );

      printf("\r\nValeur de Pot2 : %f",Pot2.read() );

      blue = 1;
      wait( 0.2 );
      blue = 0;

      wait( 1 );
    }

    return 0;
}

void chenillard( void ){
  myled = 1;
  wait(0.2);
  myled = 0;
  myled2 = 1;
  wait(0.2);
  myled2 = 0;
  myled3 = 1;
  wait(0.2);
  myled3 = 0;
  myled4 = 1;
  wait(0.2);
  myled4 = 0;
  wait(0.2);
}
