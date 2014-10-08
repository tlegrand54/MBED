#include <mbed.h>
#include "MaxbotixDriver/sonar.h"

#define pinPW p7

int main()
{   
    Timer t; /**< timer pour mesurer les pulsations*/
    Sonar sonar(pinPW, t);

    printf("\r\n");
    printf("Début de la fonction main\n");
    while(1){

        printf("Mesure : %d cm \n", int(sonar)); /**< on utilise l'opérateur int redéfini dans la classe Sonar*/

        printf("\r\n");
        wait_ms(1000);
    }
}


