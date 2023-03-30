//==============================================================
// Filename : PacmanChar.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Class for player controller pacman character
//==============================================================

#ifndef PACMAN_CHAR
#define PACMAN_CHAR

#include "Character.h"


/// Class of pacman player character
class PacmanChar : public Character
{
    
public:
    int slowness = 5; //Opposite of speed (it does the same, but higher is slower)
    int moveCounter = 0;

    void Move() 
    {
        //Only progress through here once every "slowness" game updates
        if(moveCounter < slowness) {
            moveCounter++;
            return;
        }

        //Movement
        if(dir == RIGHT) {
            if(x <= 26) {
                x++;
                moveCounter = 0;
            }
            else { //Possible teleport to other side
                    x = 0;
                    moveCounter = 0;
            }
        }
        else if(dir == LEFT){
            if(x >= 1) {
                x--;
                moveCounter = 0;
            }
            else { //Possible teleport to other side
                    x = 27;
                    moveCounter = 0;
            }
        }
        else if(dir == DOWN){
            if(y <= 26) {
                y++;
                moveCounter = 0;
            }
        }
        else if(dir == UP){
            if(y >= 0) {
                y--;
                moveCounter = 0;
            }
        }
    }

};

#endif