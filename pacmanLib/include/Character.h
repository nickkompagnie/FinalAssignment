//==============================================================
// Filename : Character.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Base class for all character
//==============================================================

#ifndef CHARACTER
#define CHARACTER

#include "GameObjectStruct.h"
#include "ObjectPositionStruct.h"


/// Base class of player and ghosts
class Character : public GameObjectStruct
{

public:


    void Move() {

    }

    void Die() {


    }

    ObjectPositionStruct GetPosInFront()
    {
    // Calculate the position in front of the character based on their direction
    ObjectPositionStruct posInFront;

    if (dir == LEFT)
    {
        posInFront.x = x - 1;
        posInFront.y = y;
    }
    else if (dir == RIGHT)
    {
        posInFront.x = x + 1;
        posInFront.y = y;
    }
    else if (dir == UP)
    {
        posInFront.x = x;
        posInFront.y = y - 1;
    }
    else if (dir == DOWN)
    {
        posInFront.x = x;
        posInFront.y = y + 1;
    }
    return posInFront;
    }


};

#endif