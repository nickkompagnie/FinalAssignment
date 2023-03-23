//==============================================================
// Filename : Collectible.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Collectible is the base class for powerups, bonuses and collectible dots
//==============================================================

#ifndef COLLECTIBLE
#define COLLECTIBLE

#include "GameObjectStruct.h"


/// Base class of collectibles
///
class Collectible : public GameObjectStruct
{
    //Taking in anx, y, sprite and direction because it is a GameObjectStruct class


public:
    void DisappearOnCollision()
    {

    }

};

#endif