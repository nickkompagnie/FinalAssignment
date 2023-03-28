//Ghost.h

//==============================================================
// Filename : PacmanChar.h
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : Ghost class
//==============================================================

#ifndef GHOST
#define GHOST

#include "Character.h"




/// Class of pacman player character
class Ghost : public Character
{
    
public:
    int slowness = 10; //Opposite of speed (it does the same, but higher is slower)
    int moveCounter = 0;
    int direction = 0;




    void Respawn() {


    }

    void Move() 

    {

        ObjectPositionStruct inFrontOfCharacter = GetPosInFront();

        if(map[inFrontOfCharacter.y][inFrontOfCharacter.x] != 1) {

            if(leftORRIGHT) {
                dir = LEFT;
                //dir = RIGHT;
            }

                
                // Check if wall is in front
                // Generate random number between 0 and 3
                // Move to the direction according to the number
                

                if(dir == RIGHT) {
                    if(x <= 27) {
                            moveCounter++;
                            if(moveCounter > slowness) {
                                x++;
                                moveCounter = 0;
                        }
                    }
                    else { //Possible teleport to other side
                        if (y == 13) {
                            x = 1;
                        }
                    }
                }

                else if(dir == LEFT){
                    if(x >= 0) {
                        moveCounter++;
                        if(moveCounter > slowness) {
                            x--;
                            moveCounter = 0;
                        }
                    }
                    else { //Possible teleport to other side
                        if (y == 13) {
                            x = 26;
                        }
                    }
                }
                else if(dir == DOWN){
                    if(y <= 26) {
                        moveCounter++;
                        if(moveCounter > slowness) {
                            y++;
                            moveCounter = 0;
                        }
                    }
                }
                else if(dir == UP){
                    if(y >= 0) {
                        moveCounter++;
                        if(moveCounter > slowness) {
                            y--;
                            moveCounter = 0;
                        }
                    }
                }
        }
        
        //If a wall in front, change direction to random direction
        else {

        int randomvalue = rand()%4;
        std::array<Direction,4> directionlist = {RIGHT,LEFT,UP,DOWN};

        dir = directionlist[randomvalue];

        }
    }

};

#endif