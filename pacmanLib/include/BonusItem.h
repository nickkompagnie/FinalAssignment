//==============================================================
// Filename : BonusItem.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : BonusItems give the player bonus points when colected
//==============================================================

#ifndef BONUS_ITEM
#define BONUS_ITEM

#include "PointsCollectible.h"



class BonusItem : public PointsCollectible
{
    //Taking in an x, y, sprite and direction because it is a GameObjectStruct class
private:
    const int points = 3;

public:
    void Appear() override
    {

    };


};

#endif