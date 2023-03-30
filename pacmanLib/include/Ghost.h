//Ghost.h

//==============================================================
// Filename : PacmanChar.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Ghost class, moves around randomly
//==============================================================

#ifndef GHOST
#define GHOST

#include <iostream>
#include <array>
#include "Character.h"

std::array<Direction,4> directionlist = {RIGHT,LEFT,UP,DOWN};



/// Class of ghost character
class Ghost : public Character
{
private:
    
public:
    int slowness = 10; //Opposite of speed (it does the same, but higher is slower)
    int moveCounter = 0;
    int direction = 0;

    void Move() 

    {
        if(moveCounter < slowness) {
            moveCounter++;
            return;
        }

        ObjectPositionStruct inFrontOfCharacter = GetPosInFront();
        ObjectPositionStruct leftOfCharacter= GetPosLeft();
        ObjectPositionStruct rightOfCharacter = GetPosRight();

        if(map[inFrontOfCharacter.y][inFrontOfCharacter.x] != 1) { //If no wall in front

            if(map[leftOfCharacter.y][leftOfCharacter.x] != 1) { //If no wall to the left
                int randomvalue = rand()%3;
                if(randomvalue == 0) { //33% chance to turn left
                    dir = turnLeft(dir, 1);
                }
            }

            if(map[rightOfCharacter.y][rightOfCharacter.x] != 1) { //If no wall to the right
                int randomvalue = rand()%3;
                if(randomvalue == 0) { //33% chance to turn right
                    dir = turnLeft(dir, 3);
                }
            }


            if(dir == RIGHT) {
                if(x <= 26) {
                    x++;
                    moveCounter = 0;
                }
                else { //Possible teleport to other side
                    x = 0;
                    moveCounter = 0;
                }
            }

            else if(dir == LEFT){
                if(x >= 1) {
                    x--;
                    moveCounter = 0;
                }
                else { //Possible teleport to other side
                    x = 27;
                    moveCounter = 0;
                }
            }
            else if(dir == DOWN){
                if(y <= 26) {
                    y++;
                    moveCounter = 0;
                }
            }
            else if(dir == UP){
                if(y >= 0) {
                    y--;
                    moveCounter = 0;
                }
            }
        }
        
        //If a wall in front, change direction to random direction
        else {
            int randomvalue = rand()%4;
            dir = directionlist[randomvalue];
        }
    }

};

#endif