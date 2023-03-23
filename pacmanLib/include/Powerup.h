//==============================================================
// Filename : Powerup.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : A powerup gives the player power to eat ghosts and slows the ghosts down
//==============================================================

#ifndef POWERUP
#define POWERUP

#include "Collectible.h"


class Powerup : public Collectible
{
    //Taking in an x, y, sprite and direction because it is a GameObjectStruct class


public:
    void Appear() override
    {

    };
    
    void ActivatePowermode()
    {

    }

};

#endif