//==============================================================
// Filename : PointsCollectible.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : PointsCollectible is the base class for bonuses and collectible dots
//==============================================================

#ifndef POINTS_COLLECTIBLE
#define POINTS_COLLECTIBLE

#include "Collectible.h"



class PointsCollectible : public Collectible
{
    //Taking in an x, y, sprite and direction because it is a GameObjectStruct class


public:
    void IncreaseScore()
    {
        
    }

};

#endif