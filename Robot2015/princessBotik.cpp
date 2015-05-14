/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	princessBotik.cpp (Fichier source)			*
 *															*
 * 	Objectif:	Code principal du robot princess'botik		*
 * 															*	
 ************************************************************/
#include "configuration.h"

SRF08 ultraArr(SDA, SCL, 0xE2); 			// SRF08 ranging module 1 capteur arrière
SRF08 ultraG(SDA, SCL, 0xE4); 				// SRF08 ranging module 2 capteur gauche
SRF08 ultraD(SDA, SCL, 0xE6); 				// SRF08 ranging module 3 capteur droit

AX12 ax(PIN_TX,PIN_RX,ID,BAUD);				// Permet de contrôler l'AX12 pour faire la direction du robot

Timer timeEndMatch; 						// Permet de connaître le temps du match

//VNH5019 motor(PIN_INA,PIN_INB,PIN_ENDIAG,PIN_CS,PIN_PWM); // Permet de contrôler le moteur

DigitalOut tiretteOut(PIN_TIRETTE_OUT); 	
DigitalOut buttonOut(PIN_COULEUR_OUT);		

DigitalOut ina(PIN_INA);
DigitalOut inb(PIN_INB);
PwmOut pwm(PIN_PWM);

DigitalIn tiretteIn(PIN_TIRETTE_IN);		// Permet de connaître si le match est lancé si on a 0 le match n'est pas lancé sinon il l'est
DigitalIn buttonIn(PIN_COULEUR_IN);			// Permet de connaître sa couleur si on a 0 on est jaune sinon on est vert

int main(void){
    int distanceGauche[TAILLE_MAX] = {0};			// Tableau permettant de connaître la distance avec l'obstacle
    int distanceDroit[TAILLE_MAX] = {0};
    int distanceArr[TAILLE_MAX] = {0};

    printf("\rMise à 0 de la position");

    ax.setGoalPosition(0);

    tiretteOut = 1; // On envoie 1 pour savoir si on a la tirette ou non
    buttonOut = 1;	// On envoie pour savoir dans quelle couleur on est

    wait(5);

    ina = 1;

    inb = 0;

    pwm = 0.1;

    /*while(tiretteIn){
        ; // On attend que la tirette soit enlevé
    }*/

    //timeEndMatch.start();

   /* while(timeEndMatch.read() < 89){


    }
    */

    wait(5);

    ax.setGoalPosition(300);
    printf("mise en route des moteurs\n");
      
    wait(5);

    printf("stop les moteurs\n");

    pwm = 0;
    // timeEndMatch.stop(); // On stop le chronomètre

    exit(0);
}
