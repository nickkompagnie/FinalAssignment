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

#include <iostream>
#include "Character.h"

std::array<Direction,4> directionlist = {RIGHT,LEFT,UP,DOWN};




/// Class of pacman player character
class Ghost : public Character
{
private:
    
public:
    int slowness = 3; //Opposite of speed (it does the same, but higher is slower)
    int moveCounter = 0;
    int direction = 0;
    int turnLeftTimer = 0;



    void Respawn() {


    }

    void Move() 

    {
        ObjectPositionStruct inFrontOfCharacter = GetPosInFront();
        ObjectPositionStruct leftOfCharacter= GetPosLeft();
        turnLeftTimer++;

        if(map[inFrontOfCharacter.y][inFrontOfCharacter.x] != 1) { //If no wall in front

            if(map[leftOfCharacter.y][leftOfCharacter.x] != 1) { //If no wall to the left
                if(turnLeftTimer > 60) {
                    turnLeftTimer = rand()%10;
                    int randomvalue = rand()%1;
                    if(randomvalue ==0) {
                        // std::cout << "turning left" << std::endl;
                        dir = turnLeft(dir); 
                    }
                    else {
                        std::cout << "not turning left this time" << std::endl;
                    }
                }
                
            }

                
                // Check if wall is in front
                // Generate random number between 0 and 3
                // Move to the direction according to the number
                

            if(dir == RIGHT) {
                if(x <= 27) {
                    x++;
                    moveCounter = 0;
                }
                else { //Possible teleport to other side
                    if (y == 13) {
                        x = 0;
                        moveCounter = 0;
                    }
                }
            }

            else if(dir == LEFT){
                if(x >= 0) {
                    x--;
                    moveCounter = 0;
                }
                else { //Possible teleport to other side
                    if (y == 13) {
                        x = 27;
                        moveCounter = 0;
                    }
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