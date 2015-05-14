#include "VNH5019.h"

VNH5019::VNH5019(PinName INA_, PinName INB_, PinName PWM_)
 : INA(INA_),
   INB(INB_),
   PWM(PWM_)
{
    this->init();
}

void VNH5019::init()
{
   PWM.period(0.00025);   // 4 kHz (valid 0 - 20 kHz)
   PWM.write(0);
   INA = 0;
   INB = 0;
}

 
void VNH5019::speed(float Speed)
{
   bool Reverse = 0;
  
   if (Speed < 0)
   {
     Speed = -Speed;  // Make speed a positive quantity
     Reverse = 1;  // Preserve the direction
   }
  
   // clamp the speed at maximum
   if (Speed > 1.0)
      Speed = 1.0;
    
   if (Speed == 0.0)
   {
       INA = 0;
       INB = 0;
       PWM = 0;
    }
    else
    {
      INA = !Reverse;
      INB = Reverse;
      PWM = Speed;
    }
}

void VNH5019::stop()
{
    INA = 0;
    INB = 0;
    PWM = 0.0;
}

void VNH5019::brake(float Brake)
{
   // normalize Brake to 0..1
   if (Brake < 0)
      Brake = -Brake;
   if (Brake > 1.0)
      Brake = 1.0;

   INA = 0;
   INB = 0;
   PWM = Brake;
}