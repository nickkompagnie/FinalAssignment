//==============================================================
// Filename : CollectibleDots.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Collectible dots give the player points when colected
//==============================================================

#ifndef BONUS_ITEM
#define BONUS_ITEM

#include "PointsCollectible.h"



class CollectibleDots : public PointsCollectible
{
    //Taking in an x, y, sprite and direction because it is a GameObjectStruct class
private:
    int num_points;

public:
    void Appear()
    {

    }

};

#endif