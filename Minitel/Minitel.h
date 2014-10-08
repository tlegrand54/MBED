#ifndef MINITEL_H_
#define MINITEL_H_

#include "PololuQik2/PololuQik2.h"
#include "mbed.h"

#define AMOTEURD 27
#define AMOTEURG 32
#define RMOTEURD -27
#define RMOTEURG -27

/**
 * \class Minitel
 *
 * \brief Permet de faire rouler le minitel à l'aide d'une qik
 *
 */

class Minitel
{
    private:
        PololuQik2 qik;
        int cptStack=0; /**< */
        int cptPosition=0; /**< Permet de calculer la position */
        int angleGo=0; /**< Permet de savoir si on est dans l'angle de la ligne*/

        Timer timeEnd;


        void seuilStack(int isLeft);

    public:
        /**
         * \brief Constructor 
         *
         * \param txPin Number of pin TX 
         * \param rxPin Number of pin RX
         * \param resetPin Number of pin use for reset the Qik
         * \param errorPin Number of pin use for know if Qik is default
         */
        Minitel(PinName txPin, PinName rxPin, PinName resetPin, PinName errorPin);

        /**
         * \brief go and track the line
         *                    
         * \param rate
         * \param sensorRight status of the right sensor
         * \param sensorLeft status of the left sensor
         */
        void trackLine(double rate,int rightSensor,int leftSensor);

        /**
         * \brief go without track the line
         *
         * \param rate
         */
        void go(int rate);

        /**
         * \brief Fait reculer le minitel en suivant la ligne
         *
         * \param rate
         * \param sensorRight status of the right sensor
         * \param sensorLeft status of the left sensor
         */
        void goBackward(double rate,int rightSensor,int leftSensor);

        /**
         * \brief Stop the left motor
         */
        void stopLeftMotor();

        /**
         * \brief Stop the right motor
         */
        void stopRightMotor();

        /**
         * \brief Stop the both motors
         */
        void stopMotors();

        /**
         * \brief Active the right motor
         *
         * \param rate
         */
        void rightMotor(int rate);

        /**
         * \brief Active the left motor
         *
         * \param rate
         */
        void leftMotor(int rate);

        /**
         * \brief Active the timer for the match's end
         */
        void endMatch();

        /**
         * \brief read the current time
         * \return return the current time
         */
        int readCurrentTime();
};
#endif
