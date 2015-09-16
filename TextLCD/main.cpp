#include "mbed.h"
#include "TextLCD.h"
 
TextLCD lcd(p15, p14, p13, p18, p19, p20, TextLCD::LCD20x4); // rs, e, d4-d7
 
int main() {
    int nValue = 0;

    while(1){
        lcd.cls();
        lcd.printf("Bienvenue a Nancyborg! %d", nValue);
        wait(1);

        lcd.cls();
        lcd.printf("Welcome to Nancyborg! %d", nValue);
        //   lcd.cls();

        wait(1);

        ++nValue;

        if(nValue == 10){
            nValue = 0;
        }
    }
}
