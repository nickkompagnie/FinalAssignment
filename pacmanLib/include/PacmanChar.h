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
    int slowness = 10; //Opposite of speed (it does the same, but higher is slower)
    int moveCounter = 0;

    void Respawn() {
    }

    void Move() 
    {
        if(dir == RIGHT) {
            if(x <= 25) {
                moveCounter++;
                if(moveCounter > slowness) {
                    x++;
                    moveCounter = 0;
                }
            }
        }
        else if(dir == LEFT){
            if(x >= 2) {
                moveCounter++;
                if(moveCounter > slowness) {
                    x--;
                    moveCounter = 0;
                }
            }
        }
        else if(dir == DOWN){
            if(y <= 24) {
                moveCounter++;
                if(moveCounter > slowness) {
                    y++;
                    moveCounter = 0;
                }
            }
        }
        else if(dir == UP){
            if(y >= 2) {
                moveCounter++;
                if(moveCounter > slowness) {
                    y--;
                    moveCounter = 0;
                }
            }
        }
    }

};

#endif