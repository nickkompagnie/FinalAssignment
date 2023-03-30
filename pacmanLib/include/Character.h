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
#include <vector>

std::vector<std::vector<int>> map = {{
 #include "board.def"
}};


/// Base class of player and ghosts
class Character : public GameObjectStruct
{

private:
    ObjectPositionStruct startPos;

public:


    void Move() {

    



    }

    void Die() {


    }

    void SetStartPos() {
        startPos.x = x;
        startPos.y = y;
    }

    void ResetPos() {
        x = startPos.x;
        y = startPos.y;
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

    ObjectPositionStruct GetPosRight()
    {
    // Calculate the position right of the character based on their direction
    ObjectPositionStruct posRight;

    if (dir == LEFT)
    {
        posRight.x = x;
        posRight.y = y - 1;
    }
    else if (dir == RIGHT)
    {
        posRight.x = x;
        posRight.y = y + 1;
    }
    else if (dir == UP)
    {
        posRight.x = x + 1;
        posRight.y = y;
    }
    else if (dir == DOWN)
    {
        posRight.x = x - 1;
        posRight.y = y;
    }
    return posRight;
    }

    Direction turnLeft(Direction _direction, int amount)
    {
        Direction direction = _direction;
        for (int i = 0; i < amount; i++)
        {
            if (direction == LEFT)
                direction = DOWN;
            if (direction == UP)
                direction = LEFT;
            if (direction == RIGHT)
                direction = UP;
            if( direction == DOWN)
                direction = RIGHT;        
        }        
        return direction;
    }
};

#endif