//==============================================================
// Filename : CollectibleDot.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Collectible dots give the player points when colected
//==============================================================

#ifndef COLLECTIBLE_DOT
#define COLLECTBLE_DOT

#include "PointsCollectible.h"



class CollectibleDot : public PointsCollectible
{
    //Taking in an x, y, sprite and direction because it is a GameObjectStruct class
private:
    const int points = 1;

public:
    void Appear() override
    {

    };


};

#endif