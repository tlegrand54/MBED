#include "main.h"

/* ################# Informations générales sur le robot ############ */
/* 
 * 		qikP.setMotor1Speed qui contrôle le moteur de la porte
 * 		Pour actionner le moteur il faut mettre une valeur positive pour 
 * le monter et une valeur négative pour le descendre mais attention
 * si on a fait descendre entièrement le clavier il se peut 
 * que ce soit inversé
 * 		
 * 		le moteur de la porte est sur le canal 1 de la QIK
 */
/* ################################################################## */

/* ##################   DECLARATION DES INPUTS ###################### */
DigitalIn Tirette(TIRETTE_PIN);
DigitalIn Couleur(COULEUR_PIN);

/*
 * Si détection : 1
 * sinon : 0
 */
DigitalIn capteurDroit(CAPTEUR_DROIT);
DigitalIn capteurGauche(CAPTEUR_GAUCHE);

/* ################################################################## */

/* ###################  DECLARATION DES OUTPUTS ##################### */
DigitalOut ledGauche(LED_GAUCHE);
DigitalOut ledDroite(LED_DROITE);

DigitalOut reset_qik(RESET_QIK);
DigitalOut error_qik(ERROR_QIK);

/* ##############  DECLARATION objets capteurs ###################### */
SRF08 ultraArr(SDA, SCL, 0xE2); //SRF08 ranging module 1 capteur arrière
SRF08 ultraG(SDA, SCL, 0xE4); //SRF08 ranging module 2 capteur gauche
SRF08 ultraD(SDA, SCL, 0xE6); //SRF08 ranging module 3 capteur droit
SRF08 ultraM(SDA, SCL, 0xE0); //SRF08 ranging module 4 capteur milieu petit

/* ################################################################## */

/* ################  DECLARATION de l'objet princess ###################### */
Minitel princess(TX_QIK,RX_QIK,RESET_QIK,ERROR_QIK);
/* ################################################################## */

/* ##########  DECLARATION du timer pour la fin de jeu ############## */
Timer timeEnd;
Timer timeOut;
Timer timeAngle;
/* ################################################################## */

/* #############  DECLARATION des variables globales ################ */
int distanceGauche[TAILLE_MAX];
int distanceDroit[TAILLE_MAX];
int distanceMilieu[TAILLE_MAX];
int distanceArr[TAILLE_MAX];
/* ################################################################## */

int main()
{   
    int cpt = 0;

    printf("\r\n");
    printf("\r\n");
    printf("\r\n");
    printf("\rDebut de la fonction main\n");

    // Instanciation de l'objet princess
    for(cpt=0;cpt<TAILLE_MAX;cpt++)
    {
        distanceGauche[cpt] = 0;
        distanceDroit[cpt] = 0;
        distanceMilieu[cpt] = 0;
        distanceArr[cpt] = 0;
    }


    /* 
     * On rempli une première fois les tableaux de distance
     * avec des valeurs non fictives
     for(cpt=0;cpt<TAILLE_MAX;cpt++)
     {
     ultraG.startRanging();
     while (!ultraG.rangingFinished()) wait(0.01);
     distanceGauche[cpt] = ultraG.getRange();

     ultraD.startRanging();
     while (!ultraD.rangingFinished()) wait(0.01);
     distanceDroit[cpt] = ultraD.getRange();

     ultraM.startRanging();
     while (!ultraM.rangingFinished()) wait(0.01);
     distanceMilieu[cpt] = ultraM.getRange();

     ultraArr.startRanging();
     while (!ultraArr.rangingFinished()) wait(0.01);
     distanceArr[cpt] = ultraArr.getRange();
     }
     * */

    printf("\rAttente de tirette\n");
    while(Tirette){}
    timeEnd.start();

    /*
     * On part du coin et on avance tant que le robot ne trouvre pas
     * de ligne noir et on éteint les moteurs après.
     */

    princess.go(1);

    printf("\rAttente de %f secondes pour rejoindre la ligne\n", HAND_TROLL_TIMEOUT);
    wait(HAND_TROLL_TIMEOUT);

    princess.stopMotors();

    match();


    printf("\rFin du match et du code\n");
    return EXIT_SUCCESS;
}

/**
 * \brief Permet de gérer les actions pour le match
 */
void match()
{
    int hasTurned = 0;
    printf("\r%f : Début de match !\n", timeEnd.read());

    // Lancement timer avant mesure de l'angle
    timeAngle.start();

    // Boucle de temps du match
    while(timeEnd.read() < 90.0)
    {	

        /*
         * On affiche sur les leds l'état des capteurs
         * 	=> allumés : pas de détection
         *  => éteint  : détection
         */
        ledGauche = !capteurGauche;
    }

    princess.stopMotors(); 
}


/*
 * \brief  abs calcul la valeur absolue d'une valeur
 *
 * \param valeur dont on souhaite la valeur absolue
 * \return retourne la valeur absolue de l'entier en paramètre
 */
int abs(int n)
{
    return n < 0 ? -n : n;
}

/**
 * \brief Calcul la moyenne d'un tableau
 *
 * \param Tableau dont on souhaite connaitre la moyenne
 * \return retourne la moyenne du tableau
 */
int moyenne(int tab[])
{
    int calcule = 0, i = 0;
    int taille = 0;
    for(i=0;i<TAILLE_MAX;i++)
    {
        if(tab[i] != 0) {
            calcule += tab[i];
            ++taille;		
        }
    }

    return (calcule/taille);
}

/** 
 * \brief  remplirTab permet d'ajouter un nouvel élément à la dernière position d'un tableau
 *
 * \param tab est le tableau dans lequel on souhaite mettre une nouvelle valeur
 * \param nvlElt est le nouvel élement qu'on veut mettre en début de tableau
 */
void remplirTab(int tab[], int nvlElt)
{
    int i = 0;

    for(i=0;i<(TAILLE_MAX-1);i++)
    {
        tab[i+1] = tab[i];
    }

    tab[0] = nvlElt;
}
