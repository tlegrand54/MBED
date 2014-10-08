/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This is a simple music library for the mbed.      *
 *                                                   *
 * Created by: Michael Dushkoff (mad1841@rit.edu)    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "mbed.h"
#include "Music.h"
#include "Notes.h"

/*
 * This is the minimal constructor that creates a music object
 * with 0 initial output frequency on a specified pin
 *
 * M0 - The pin to output on
 */
music::music(PinName M0) : _M0(M0){
    _flipper.attach(this,&music::flip,0);
}

/*
 * This constructs a music object which has an initial frequency
 * equal to a given one
 *
 * M0 - The pin to output on
 * freq - The initial frequency
 */
music::music(PinName M0, double freq) : _M0(M0), _freq(freq) {
    _flipper.attach(this,&music::flip,1/(2*_freq));
}

/*
 * This changes the current output frequency to a given one
 *
 * freq - The given frequency
 */
void music::freq(double freq){
    _freq=freq;
    _flipper.detach();
    _flipper.attach(this,&music::flip,1/(2*_freq));
}

/*
 * This is an internal flipper that allows for a fixed
 * frequency oscillation.
 */
void music::flip(){
    _M0 = !_M0;
}

/*
 * This initializes a given m_song to a given size
 *
 * *m - The given m_song
 * num - The given size
 */
void music::init_song(m_song *m, int num){
    m->len = 0;
    m->note = new music_note[((int)(num/5))];
}

/*
 * This deallocates an m_song by deallocating the notes
 * that it contains and setting the length to 0
 *
 * *m - The given m_song
 */
void music::dal_song(m_song *m){
    m->len = 0;
    delete [] m->note;
//    free(m->note);
}

/*
 * This parses a given character array into an m_song
 *  Format:
 *    <note_letter><[sharp]><octave>:<length>; . . .;
 *  Example (Super Mario Bros.):
 *    E3:8; E3:8; R:8; E3:8; R:8; C3:8; E3:4; G3:4; R:4; G2:4; R:4;
 *
 *  Sharp notes are represented with the # symbol as shown below:
 *    C#:4;
 *
 * song - The song character array
 * num - The number of characters in the array 
 */
m_song music::parse(char* song, int num){
    //Create a new song and initialize it
    m_song out;
    init_song(&out,num);
    
    char curnote = ' ';   // Note
    int octave = 0;       // Octave
    int dur[] = {0,0};     // Duration
    int flag = 0;         // Complete flag
    int sharp = 0;        // Sharp flag
    int inl = 1;          // Index of dur[]
    
    for (int i=0; i<num; i++){
        switch(song[i]){
            case 'A':
                //A Note
                curnote = 'A';
            break;
            case 'B':
                //B Note
                curnote = 'B';
            break;
            case 'C':
                //C Note
                curnote = 'C';
            break;
            case 'D':
                //D Note
                curnote = 'D';
            break;
            case 'E':
                //E Note
                curnote = 'E';
            break;
            case 'F':
                //F Note
                curnote = 'F';
            break;
            case 'G':
                //G Note
                curnote = 'G';
            break;
            case 'R':
                //Rest
                curnote = 'R';
            break;
            case '#':
                //Sharp set
                sharp = 1;
            break;
            case '0':
                if (flag == 0){
                    //Octave set
                    octave = 0;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 0;
                    }
                    else{
                        //Set
                        dur[1] = 0;
                        inl=0;
                    }
                }
            break;
            case '1':
                if (flag == 0){
                    //Octave set
                    octave = 1;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 1;
                    }
                    else{
                        //Set
                        dur[1] = 1;
                        inl=0;
                    }
                }
            break;
            case '2':
                if (flag == 0){
                    //Octave set
                    octave = 2;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 2;
                    }
                    else{
                        //Set
                        dur[1] = 2;
                        inl=0;
                    }
                }
            break;
            case '3':
                if (flag == 0){
                    //Octave set
                    octave = 3;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 3;
                    }
                    else{
                        //Set
                        dur[1] = 3;
                        inl=0;
                    }
                }
            break;
            case '4':
                if (flag == 0){
                    //Octave set
                    octave = 4;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 4;
                    }
                    else{
                        //Set
                        dur[1] = 4;
                        inl=0;
                    }
                }
            break;
            case '5':
                if (flag == 0){
                    //Octave set
                    octave = 5;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 5;
                    }
                    else{
                        //Set
                        dur[1] = 5;
                        inl=0;
                    }
                }
            break;
            case '6':
                if (flag == 0){
                    //Octave set
                    octave = 6;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 6;
                    }
                    else{
                        //Set
                        dur[1] = 6;
                        inl=0;
                    }
                }
            break;
            case '7':
                if (flag == 0){
                    //Octave set
                    octave = 7;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 7;
                    }
                    else{
                        //Set
                        dur[1] = 7;
                        inl=0;
                    }
                }
            break;
            case '8':
                if (flag == 0){
                    //Octave set
                    octave = 8;
                }
                else {
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 8;
                    }
                    else{
                        //Set
                        dur[1] = 8;
                        inl=0;
                    }
                }
            break;
            case '9':
                if (flag == 1){
                    //Duration set
                    if (inl == 0){
                        //Shift
                        dur[0] = dur[1];
                        
                        //Set
                        dur[1] = 9;
                    }
                    else{
                        //Set
                        dur[1] = 9;
                        inl=0;
                    }
                }
            break;
            case ':':
                flag = 1;
            break;
            case ';':
                if (flag == 1){
                    //Calculate duration
                    int t1 = (dur[0])*10;
                    int t2 = dur[1];
                    int tst = t1+t2;
                    
                    if (tst>0 && tst<=64 && curnote != ' '){
                        notes n;
                        
                        //DEAD CODE: Will work when realloc is fixed
                        //Create a temporary checker
                        //music_note* tmpn; //= new music_note[out.len+1];
                        
                        //Reallocate space for note
                        //tmpn = (music_note*) realloc(out.note, (out.len+1)*sizeof(music_note));
//                        if (tmpn == NULL){
//                            //Failed to allocate
//                            free(out.note);
//                            exit(1);
//                        }
//                        out.note = tmpn;
                        
                        //Set frequency using lookup function
                        out.note[out.len].freq = n.get_freq(curnote, sharp, octave);
                        
                        //Set duration
                        out.note[out.len].duration = tst;
                        
                        //Increment current song size
                        out.len=out.len+1;
                    }
                    
                    //Reset values
                    flag = 0;
                    sharp = 0;
                    dur[0] = 0;
                    dur[1] = 0;
                    curnote = ' ';
                    octave = 0;
                    inl = 1;
                }
                else{
                    //Default to quarter note:
                }
            break;
        }
    }
    return out;
}

/*
 * This plays a given song string at a given tempo
 *
 * song - The song character array
 * tempo - The specified beats per minute
 * num - The number of characters in the array
 */
void music::play(char* song, double tempo, int num){
    double dl;
    m_song msng = parse(song, num);
    
    /* Play m_song */
    for (int i=0; i<msng.len; i++){
        // Output the frequency:
        freq(msng.note[i].freq);
        
        // Calculate delay:
        dl = (60*4)/(tempo*(msng.note[i].duration));
        
        // Wait for the note to be complete
        wait(dl);
    }
    
    //Stop playing
    freq(0);
    
    //Deallocate song:
    dal_song(&msng);
}