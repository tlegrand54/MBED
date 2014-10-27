#include "mbed.h"

DigitalOut afficheur(p23);
DigitalOut afficheur2(p21);
DigitalOut segment2(p27);
DigitalOut segment(p30);

int main()
{
    afficheur = 1;
    afficheur2 = 1;
    segment = 1;
    segment2 = 0;

    exit(0);
}
