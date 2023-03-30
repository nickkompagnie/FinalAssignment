//==============================================================
// Filename : main.cpp
// Authors : Quinten Boeve and Nick Kompagnie
// Group : 17
// License : N.A. or open source license like LGPL
// Description : The main file of the PacMan game
//==============================================================

#include "Powerup.h"
#include "BonusItem.h"
#include "CollectibleDot.h"
#include "Lives.h"
#include "Score.h"
#include "UI.h"
#include "PacmanChar.h"
#include "Ghost.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <map>
#include <array>
#include <iterator>
#include <typeinfo>

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
/// Note that this callback may happen on a different thread than the main thread.
/// You therefore have to be careful in avoiding data races. For example, you
/// should use mutexes to access shared data.
/// Read the documentation of SDL_AddTimer for more information and for tips
/// regarding multithreading issues.


int score = 0;
std::map<std::array<int,2>, GameObjectStruct> items;

Uint32 gameUpdate(Uint32 interval, void * /*param*/)
{
    // Do game loop update here
    //std::cout << "testy each update" << std::endl;

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    
    //Parameter for collisions
    bool wallinFront = false;
    int lives = 3;

    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};

    // Create a new ui object
    UI ui(map); // <-- use map from your game objects.

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(100, gameUpdate, static_cast<void *>(nullptr));

    // Example object, this can be removed later
    PacmanChar pacman;
    pacman.x = 1;
    pacman.y = 1;
    pacman.type = PACMAN;
    pacman.dir = RIGHT;

    // Powerups


    std::array<std::array<int,2>,4> powerUpCoordinates;

    std::array<int,2> upLeft = {1,1};
    std::array<int,2> upRight = {26,1};
    std::array<int,2> downLeft = {1,25};
    std::array<int,2> downRight = {26,25};
    
    powerUpCoordinates = {upLeft,upRight,downLeft,downRight};

    for(int i=0; i<4; i++) {
        Powerup energiser;

        energiser.x =powerUpCoordinates[i][0];
        energiser.y = powerUpCoordinates[i][1];
        energiser.type = ENERGIZER;
        energiser.dir = RIGHT;

        items.insert(std::pair<std::array<int,2>,GameObjectStruct>(powerUpCoordinates[i],energiser));




    }




    // Powerup upLeft;
    // upLeft.x = 1;
    // upLeft.y = 1;
    // upLeft.type = ENERGIZER;
    // upLeft.dir = RIGHT;

    // Powerup upRight;
    // upRight.x = 26;
    // upRight.y = 1;
    // upRight.type = ENERGIZER;
    // upRight.dir = RIGHT;

    // Powerup downLeft;
    // downLeft.x = 1;
    // downLeft.y = 25;
    // downLeft.type = ENERGIZER;
    // downLeft.dir = RIGHT;

    // Powerup downRight;
    // downRight.x = 26;
    // >downRight.y = 25;
    // downRight.type = ENERGIZER;
    // downRight.dir = RIGHT;





    BonusItem testBonusItem;
    testBonusItem.x = 3;
    testBonusItem.y = 1;
    testBonusItem.type = ORANGE;
    testBonusItem.dir = RIGHT;

    GameObjectStruct decorativeWall;
    decorativeWall.x = 0;
    decorativeWall.y = 0;
    decorativeWall.type = WALL;
    decorativeWall.dir = RIGHT;


    Ghost ghost1;
    ghost1.x = 12;
    ghost1.y = 13;
    ghost1.type = BLINKY;
    ghost1.dir = RIGHT;

    Ghost ghost2;
    ghost2.x = 13;
    ghost2.y = 13;
    ghost2.type = PINKY;
    ghost2.dir = RIGHT;

    Ghost ghost3;
    ghost3.x = 14;
    ghost3.y = 13;
    ghost3.type = INKY;
    ghost3.dir = RIGHT;

    Ghost ghost4;
    ghost4.x = 15;
    ghost4.y = 13;
    ghost4.type = CLYDE;
    ghost4.dir = RIGHT;

    pacman.SetStartPos();
    ghost1.SetStartPos();
    ghost2.SetStartPos();
    ghost3.SetStartPos();
    ghost4.SetStartPos();

    std::vector<GameObjectStruct> dotsvector ;
    //x= 27, y = 26

    for(int i=0;i<28;i++) {
        for(int j=0;j<27;j++) {
            if(map[j][i]==0) {
                
                // CollectibleDot (i.num2string() +j.num2sting());
                // (i.num2string() +j.num2sting()).x = i;
                // (i.num2string() +j.num2sting()).y = j;   
                // (i.num2string() +j.num2sting()).type = DOT;

                CollectibleDot dot;
                dot.x = i;
                dot.y = j;
                dot.type = DOT;
                dot.dir = RIGHT;
                

                std::array<int,2> coordinates = {i,j};


                items.insert(std::pair<std::array<int,2>,GameObjectStruct>(coordinates,dot));

                dotsvector.push_back(dot);



            }
        }
    }




    bool quit = false;
    while (!quit) {
        // set timeout to limit frame rate
        Uint32 timeout = SDL_GetTicks() + 20;

        // Handle the input
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // Quit button.
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // All keydown events
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_LEFT: // YOUR CODE HERE
                    pacman.dir = LEFT;
                    break;
                case SDLK_RIGHT: // YOUR CODE HERE
                    pacman.dir = RIGHT;
                    break;
                case SDLK_UP: // YOUR CODE HERE
                    pacman.dir = UP;
                    break;
                case SDLK_DOWN: // YOUR CODE HERE
                pacman.dir = DOWN;
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
            }
        }

        //Check if there is a wall in front of the character
        ObjectPositionStruct inFrontOfCharacter = pacman.GetPosInFront();
        // std::cout << "position in front of pacman: " << inFrontOfCharacter.x << "," << inFrontOfCharacter.y << std::endl;

        //Move the pacman player character
        // std::cout << "pacman y: " << pacman.y << " and x " << pacman.x << " and direction " << pacman.dir << std::endl;

        

        


        if(map[inFrontOfCharacter.y][inFrontOfCharacter.x] != 1) {
            
            pacman.Move();
            std::array<int,2> coordinates = {pacman.x, pacman.y};

            if(items[coordinates].type == DOT){ //Check if there is a dot at the current position
            items.erase(coordinates); //Remove dot 
            score++; //Increase score            
            }
        }

        //Ghost collisions
        if((ghost1.x == pacman.x) && (ghost1.y == pacman.y))
        {
            pacman.ResetPos();
            ghost1.ResetPos();
            lives --;
            ui.setLives(lives);
        }
        if((ghost2.x == pacman.x) && (ghost2.y == pacman.y))
        {
            pacman.ResetPos();
            ghost2.ResetPos();
            lives --;
            ui.setLives(lives);
        }
        if((ghost3.x == pacman.x) && (ghost3.y == pacman.y))
        {
            pacman.ResetPos();
            ghost3.ResetPos();
            lives --;
            ui.setLives(lives);
        }
        if((ghost4.x == pacman.x) && (ghost4.y == pacman.y))
        {
            pacman.ResetPos();
            ghost4.ResetPos();
            lives --;
            ui.setLives(lives);
        }


        //Move the ghosts
        ghost1.Move();
        ghost2.Move();
        ghost3.Move();
        ghost4.Move();  

        

        // Set the score
        ui.setScore(score); // <-- Pass correct value to the setter

        // Set the amount of lives
        ui.setLives(lives); // <-- Pass correct value to the setter

        dotsvector.clear();

        std::map<std::array<int,2>, GameObjectStruct> :: iterator iter;

        for(iter =items.begin(); iter != items.end(); ++iter){
            dotsvector.push_back(iter->second);
        }
        

        // Render the scene
        std::vector<GameObjectStruct> objects;
        // std::cout << "vector objects length at initiation: " << objects.size() << std::endl;

        std::vector<GameObjectStruct> specialty = {testBonusItem, decorativeWall, pacman, ghost1, ghost2, ghost3, ghost4};
        objects.insert(objects.end(), dotsvector.begin(), dotsvector.end() );
        objects.insert(objects.end(), specialty.begin(), specialty.end() );
        
        // ^-- Your code should provide this vector somehow (e.g.
        // game->getStructs())
        ui.update(objects);
        // std::cout << "objects rendered" << std::endl;

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}



