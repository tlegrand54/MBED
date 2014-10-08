/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This is a definitions class for music notes and   *
 * their frequencies.                                *
 *                                                   *
 * Created by: Michael Dushkoff (mad1841@rit.edu)    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "mbed.h"
#include "Notes.h"

// Initialize local note arrays for indexing
double _A[]  = {NOTE_A0, NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4,
                NOTE_A5, NOTE_A6, NOTE_A7};
double _AS[] = {NOTE_AS0, NOTE_AS1, NOTE_AS2, NOTE_AS3, NOTE_AS4,
                NOTE_AS5, NOTE_AS6, NOTE_AS7};
double _B[]  = {NOTE_B0, NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4,
                NOTE_B5, NOTE_B6, NOTE_B7};
double _BS[] = {NOTE_C0, NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4,
                NOTE_C5, NOTE_C6, NOTE_C7, NOTE_C8};
double _C[]  = {NOTE_C0, NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4,
                NOTE_C5, NOTE_C6, NOTE_C7, NOTE_C8};
double _CS[] = {NOTE_CS0, NOTE_CS1, NOTE_CS2, NOTE_CS3, NOTE_CS4,
                NOTE_CS5, NOTE_CS6, NOTE_CS7, NOTE_CS8};
double _D[]  = {NOTE_D0, NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4,
                NOTE_D5, NOTE_D6, NOTE_D7, NOTE_D8};
double _DS[] = {NOTE_DS0, NOTE_DS1, NOTE_DS2, NOTE_DS3, NOTE_DS4,
                NOTE_DS5, NOTE_DS6, NOTE_DS7, NOTE_DS8};
double _E[]  = {NOTE_E0, NOTE_E1, NOTE_E2, NOTE_E3, NOTE_E4,
                NOTE_E5, NOTE_E6, NOTE_E7};
double _ES[] = {NOTE_F0, NOTE_F1, NOTE_F2, NOTE_F3, NOTE_F4,
                NOTE_F5, NOTE_F6, NOTE_F7};
double _F[]  = {NOTE_F0, NOTE_F1, NOTE_F2, NOTE_F3, NOTE_F4,
                NOTE_F5, NOTE_F6, NOTE_F7};
double _FS[] = {NOTE_FS0, NOTE_FS1, NOTE_FS2, NOTE_FS3, NOTE_FS4,
                NOTE_FS5, NOTE_FS6, NOTE_FS7};
double _G[]  = {NOTE_G0, NOTE_G1, NOTE_G2, NOTE_G3, NOTE_G4,
                NOTE_G5, NOTE_G6, NOTE_G7};
double _GS[] = {NOTE_GS0, NOTE_GS1, NOTE_GS2, NOTE_GS3, NOTE_GS4,
                NOTE_GS5, NOTE_GS6, NOTE_GS7};

/*
 * This is a lookup function to provide the correct
 * frequency given a note and an octave
 *
 * note - The given note character [A - G]
 * sharp - Whether the note is sharp (1) or not (0)
 * octave - The given octave [0 - 8]
 */
double notes::get_freq(char note, int sharp, int octave) {
    switch(note){
        case 'A':
            //A Note
            if (octave>=0 && octave <=7){
                if (sharp == 0){
                    return _A[octave];
                }
                else{
                    return _AS[octave];
                }
            }
        break;
        case 'B':
            //B Note
            if (octave>=0 && octave <=7){
                if (sharp == 0){
                    return _B[octave];
                }
                else{
                    return _BS[octave];
                }
            }
        break;
        case 'C':
            //C Note
            if (octave>=0 && octave <=8){
                if (sharp == 0){
                    return _C[octave];
                }
                else{
                    return _CS[octave];
                }
            }
        break;
        case 'D':
            //D Note
            if (octave>=0 && octave <=8){
                if (sharp == 0){
                    return _D[octave];
                }
                else{
                    return _DS[octave];
                }
            }
        break;
        case 'E':
            //E Note
            if (octave>=0 && octave <=7){
                if (sharp == 0){
                    return _E[octave];
                }
                else{
                    return _ES[octave];
                }
            }
        break;
        case 'F':
            //F Note
            if (octave>=0 && octave <=7){
                if (sharp == 0){
                    return _F[octave];
                }
                else{
                    return _FS[octave];
                }
            }
        break;
        case 'G':
            //G Note
            if (octave>=0 && octave <=7){
                if (sharp == 0){
                    return _G[octave];
                }
                else{
                    return _GS[octave];
                }
            }
        break;
    }
    return 0;
}