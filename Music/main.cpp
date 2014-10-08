#include <mbed.h>
#include "Music/Music.h"


int main(){
  printf("Debut du code");
  
  char s1[] = "E4:8; E4:8; R:8; E4:8; R:8; C4:8; E4:4; G4:4; R:4; G3:4; R:4;";
  int len = 61;
   
  /* Set up music pin on pin 21 */
  music m1(p21);
  double tempo = 180;
   
  m1.play(s1,tempo,len);

  
  printf("Fin du code");
}
