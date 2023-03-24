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

    void respawn() {
    }


};

#endif