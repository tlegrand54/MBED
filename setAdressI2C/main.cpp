#include "mbed.h"
#include "SRF08/SRF08.h"

SRF08 rangeMod1(p9, p10, 0xE0); //SRF08 ranging module 1
Serial PC(USBTX, USBRX);        //Debug port to PC

int main()
{
  PC.printf("\rStart ranging test\r\n");
  //rangeMod1.setAddress(0xE6); //Factory default is 0xE0
  while(1) {
    rangeMod1.startRanging();
    while (!rangeMod1.rangingFinished() ) wait(0.01);
    int range1 = rangeMod1.getRange();
    int light1 = rangeMod1.getLightIntensity();
    PC.printf(" \n");
    PC.printf(" Range_1: %i", range1);
    PC.printf(" Light_1: %i", light1);
    PC.printf("\r\n");
    wait(1);
  }
}
