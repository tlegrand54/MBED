#include "Minitel.h"
#include "PololuQik2/PololuQik2.h"

Minitel::Minitel(PinName TxPin, PinName RxPin, PinName ResetPin, PinName ErrorPin) : qik(TxPin, RxPin, ResetPin, ErrorPin, NULL, true)
{
    /*
     * Initialisation de la qik
     */
    do
    {
        qik.begin();
    } while(qik.hasFrameError() || qik.hasDataOverrunError() || qik.hasTimeoutError());
}

void Minitel::trackLine(double rate,int sensorRight,int sensorLeft)
{
    printf("\r%f : Avance\n", timeEnd.read());

    go(rate);

    if(!sensorRight && !sensorLeft)
    {
        qik.setMotor0Speed((int)RMOTEURD*rate);
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Tourne à gauche
     */
    if(!sensorRight)
    {
        printf("\r%f : Gauche !\n", timeEnd.read());
        if(angleGo) {
            cptPosition ++;
            seuilStack(1);
        }
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Troune à droite
     */
    if(!sensorLeft)
    {
        printf("\r%f : Droite !\n", timeEnd.read());
        if(angleGo) {
            cptPosition --;
            seuilStack(0);
        }
        qik.setMotor0Speed((int)RMOTEURD*rate);
    }    
}

void Minitel::goBackward(double rate,int sensorRight,int sensorLeft)
{
    printf("\r%f : Reculer\n", timeEnd.read());

    qik.setMotor0Speed((int)RMOTEURD*rate);
    qik.setMotor1Speed((int)RMOTEURG*rate);

    if(!sensorRight && !sensorLeft)
    {
        qik.setMotor0Speed((int)RMOTEURD*rate);
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Tourne à gauche
     */
    if(!sensorRight)
    {
        printf("\r%f : Gauche !\n", timeEnd.read());
        if(angleGo) {
            cptPosition ++;
            seuilStack(1);
        }
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Troune à droite
     */
    if(!sensorLeft)
    {
        printf("\r%f : Droite !\n", timeEnd.read());
        if(angleGo) {
            cptPosition --;
            seuilStack(0);
        }
        qik.setMotor0Speed((int)RMOTEURD*rate);
    }
}

void Minitel::go(int rate)
{
    rightMotor(rate);
    leftMotor(rate);
}

void Minitel::rightMotor(int rate)
{
    qik.setMotor0Speed((int)AMOTEURD*rate);
}

void Minitel::leftMotor(int rate)
{
    qik.setMotor1Speed((int)AMOTEURG*rate);
}

void Minitel::stopLeftMotor()
{
    leftMotor(0);
}

void Minitel::stopRightMotor()
{
    rightMotor(0);
}

void Minitel::stopMotors()
{
    qik.stopBothMotors();
}

void Minitel::seuilStack(int isLeft)
{
    if(cptStack >= 0 && isLeft)
    {
        ++cptStack;
    }
    else if(cptStack <= 0 && isLeft)
    {
        cptStack = 1;
    }
    else if(cptStack >= 0 && !isLeft)
    {
        cptStack = -1;
    }
    else if(cptStack <=0 && !isLeft)
    {
        --cptStack;
    }
}

void Minitel::endMatch()
{
    timeEnd.start();
}

int Minitel::readCurrentTime()
{
    return timeEnd.read();
}
