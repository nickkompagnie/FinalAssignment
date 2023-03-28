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

std::vector<std::vector<int>> map = {{
 #include "board.def"
}};


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

    ObjectPositionStruct GetPosLeft()
    {
    // Calculate the position left of the character based on their direction
    ObjectPositionStruct posLeft;

    if (dir == LEFT)
    {
        posLeft.x = x;
        posLeft.y = y + 1;
    }
    else if (dir == RIGHT)
    {
        posLeft.x = x;
        posLeft.y = y - 1;
    }
    else if (dir == UP)
    {
        posLeft.x = x - 1;
        posLeft.y = y;
    }
    else if (dir == DOWN)
    {
        posLeft.x = x + 1;
        posLeft.y = y;
    }
    return posLeft;
    }

    Direction turnLeft(Direction direction)
    {
        Direction newDir;

        if (direction == LEFT)
            newDir = DOWN;
        if (direction == UP)
            newDir = LEFT;
        if (direction = RIGHT)
            newDir = UP;
        if( direction = DOWN)
            newDir = RIGHT;
        return newDir;
    }

};

#endif