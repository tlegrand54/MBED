/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	configuration.h (Fichier d'en-tête)			*
 *															*
 * 	Objectif:	Fichier contenant toute la configuration	*
 *				du robot (numéro de pin, bibliothèque)		*
 * 															*	
 ************************************************************/
#include "mbed.h"
#include "AX12Mbed.h"
#include "VNH5019.h"
#include "SRF08.h"
#include "Timer.h"
#include "utils.h"
 
#define SDA p9
#define SCL p10

#define PIN_TX p13
#define PIN_RX p14

#define PIN_TIRETTE_IN p26
#define PIN_TIRETTE_OUT p25

#define PIN_COULEUR_IN p28
#define PIN_COULEUR_OUT p27

#define PIN_INA p24
#define PIN_INB p22
#define PIN_ENDIAG p30
#define PIN_CS p29
#define PIN_PWM p23

#define ID 2
#define BAUD 115200
#define TAILLE_MAX 5
#define DISTANCE 40