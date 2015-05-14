#ifndef VNH5019MotorShield_h
#define VNH5019MotorShield_h

#include <mbed.h>

class VNH5019
{
    public:
        VNH5019(PinName INA_, PinName INB_, PinName PWM_);
        
        // set motor speed from -1.0 to +1.0
        void speed(float Speed);

        // stop (no current to the motors)
        void stop();        
    
        // Brake, with strength 0..1
        void brake(float Brake);

    private:
        void init();

        DigitalOut   INA;
        DigitalOut   INB;
        PwmOut       PWM;
};

#endif
