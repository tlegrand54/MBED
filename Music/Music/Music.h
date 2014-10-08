/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This is a simple music library for the mbed.      *
 *                                                   *
 * Created by: Michael Dushkoff (mad1841@rit.edu)    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MBED_MUSIC_H
#define MBED_MUSIC_H
 
#include "mbed.h"
#include "Notes.h"

/* Define the music_note structure */
typedef struct {
    double freq;  //The frequency of the note
    int duration; //The duration is given by a number [1 - 64]
} music_note;

/* Define an m_song structure */
typedef struct {
    music_note* note; //The notes of the song
    int len;           //The length of the song
} m_song;

class music {
public:

    music(PinName M0); //basic music constructor
    music(PinName M0, double freq); //music constructor
    void freq(double freq);  //Frequency setter
    void play(char* song, double tempo, int num);
    
private:

    /* Private functions */
    void flip();  //Flips the output of a pin at a fixed frequency
    m_song parse(char* song, int num_notes);  //Parses a character array into notes
    void init_song(m_song *m, int num);  //Initialize an m_song
    void dal_song(m_song *m);  //Deallocate an m_song
    
    /* Private variables */
    Ticker _flipper;
    DigitalOut _M0;
    double _freq;
    
};

#endif