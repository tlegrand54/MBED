#ifndef MAIN_H
#define MAIN_H

#include "mbed.h"

#include "PololuQik2.h"
#include "SRF08.h"
#include "Minitel.h"

/* #####################  AUTRES DEFINE  ############################ */
#define HAND_TROLL_TIMEOUT 3.5
#define TAILLE_MAX 5
#define DISTANCE_CAPTEUR 40
#define DISTANCE_FRESQUE 8
#define SEUIL 4
#define SEUIL_STACK 6
#define ANGLE_MAX_TIMER 5

// Dance !
#define DANCE_ROTATION_TIME 5
#define DANCE_OPENING_TIME 3
#define DANCE_CLOSING_TIME 3
#define DANCE_MOVING_TIME 5

// POM POM !
#define POM_POM_ROTATION_TIME 5
#define POM_POM_OPENING_TIME 2
#define POM_POM_CLOSING_TIME 2
#define POM_POM_MOVING_TIME 3

/* ################################################################## */

/* ##################  ENTREES SUR L'MBED  ########################## */
#define SDA p9
#define SCL p10

/* ======== define pour la qik de contrôle des moteurs  ============= */
#define TX_QIK p13
#define RX_QIK p14
#define RESET_QIK p15
#define ERROR_QIK p16

/* ======= define pour la qik de contrôle du moteur clavier  ======== */
#define TX_QIK_P p28
#define RX_QIK_P p27
#define RESET_QIK_P p25
#define ERROR_QIK_P p26

/* ======= define des autres entrées sur la Mbed  =================== */
#define COULEUR_PIN p7
#define TIRETTE_PIN p18
#define CAPTEUR_DROIT p22
#define CAPTEUR_GAUCHE p21

/* ################################################################## */

/* ###################  SORTIES SUR L'MBED  ######################### */
#define LED_DROITE p19
#define LED_GAUCHE p20

/* ################################################################## */

/* ###################  DECLARATION DES FONCTIONS ################### */

/**
 * Fonction qui gére le match
 */
void match();

/**
 * \brief Calcule et renvoie la moyenne d'un tableau
 *   
 * \param tableau dont on souhaite la moyenne
 * \return renvoie la moyenne du tableau en paramètre
 */
 int moyenne(int tab[]);
 
 /**
  * \brief Rempli un tableau en décalant et supprimant le premier élément
  *
  * \param tableeau dans lequel on souhaite rajouter un élément à la dernière position
  * \param élément que l'on souhaite rajouter
  */
 /// tab est le tableau dans lequel il faut mettre le nouvelle elet
 /// nvlElt le nouvelle elet à mettre dans le tableau
 void remplirTab(int tab[], int nvlElt);
/* ################################################################## */
#endif
