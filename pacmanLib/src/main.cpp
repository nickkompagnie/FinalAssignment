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
int scaredtimer = 0;
std::map<std::array<int,2>, GameObjectStruct> items;

Uint32 gameUpdate(Uint32 interval, void * /*param*/)
{

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    
    //Parameter for lives
    int lives = 3;

    //Create a 2D vector in which the walls an pathways are imported
    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};

    // Create a new ui object
    UI ui(map); 

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(100, gameUpdate, static_cast<void *>(nullptr));


    // Create the pacman
    PacmanChar pacman;
    pacman.x = 13;
    pacman.y = 5;
    pacman.type = PACMAN;
    pacman.dir = RIGHT;



    //Array to store every coordinate for the powerups
    std::array<std::array<int,2>,4> powerUpCoordinates;

    std::array<int,2> upLeft = {1,1};
    std::array<int,2> upRight = {26,1};
    std::array<int,2> downLeft = {1,25};
    std::array<int,2> downRight = {26,25};
    
    //Save all the coordinates in the array
    powerUpCoordinates = {upLeft,upRight,downLeft,downRight};

    //Vector to store the bonusses in
    std::vector<GameObjectStruct> bonusses;

    //Create every ENERGIZER, based on the previously defined coordinates
    for(int i=0; i<4; i++) {
        Powerup energiser;
        energiser.x =powerUpCoordinates[i][0];
        energiser.y = powerUpCoordinates[i][1];
        energiser.type = ENERGIZER;
        energiser.dir = RIGHT;

        //Insert these objects in the ITEMS map, with the according coordinates
        items.insert(std::pair<std::array<int,2>,GameObjectStruct>(powerUpCoordinates[i],energiser));
    }

    //Quick bug fix
    GameObjectStruct decorativeWall;
    decorativeWall.x = 0;
    decorativeWall.y = 0;
    decorativeWall.type = WALL;
    decorativeWall.dir = RIGHT;

    //Initialize all ghosts

    //Array to store every coordinate for the powerups


    std::array<int,2> blinky = {12,13};
    std::array<int,2> pinky = {13,13};
    std::array<int,2> inky = {14,13};
    std::array<int,2> clyde = {15,13};
    
    //Save all the coordinates in the array
    std::array<std::array<int,2>,4> ghostCoordinates = {blinky,pinky,inky,clyde};
    std::array<Type,4> typeArray = {BLINKY,PINKY,INKY,CLYDE};

    std::array<Ghost,4> ghostArray;


    //Make all 4 ghosts
    for(int i=0; i<4; i++){
        Ghost ghost;
        ghost.x = ghostCoordinates[i][0];
        ghost.y = ghostCoordinates[i][1];
        ghost.type = typeArray[i];
        ghost.dir = RIGHT;
        ghostArray[i] = ghost;

    }



    //Set start position for PACMAN
    pacman.SetStartPos();

    //Set start position for Ghosts
    for(int i = 0; i<4;i++){
        ghostArray[i].SetStartPos();
    }

    //Create the dots in the board:
    std::vector<GameObjectStruct> dotsvector ;

    //Check in every entry of the map if a wall is present. If not, create a dot object and insert it with the coordinates in the items map.
    for(int i=0;i<28;i++) {
        for(int j=0;j<27;j++) {
            if(map[j][i]==0) {

                CollectibleDot dot;
                dot.x = i;
                dot.y = j;
                dot.type = DOT;
                dot.dir = RIGHT;

                std::array<int,2> coordinates = {i,j};
                items.insert(std::pair<std::array<int,2>,GameObjectStruct>(coordinates,dot));

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


        //Every 25 points, an orange will appear which, if eaten, will increase the points
        if(score % 25 == 0) {

            score++; //Increase score by 1 to ensure this only will happen once every 25 points

            //Initiate bonus item
            BonusItem bonus;
            bonus.type = ORANGE;

            bool placeFound = false;

            //A random x and y coordinate will be checked for the presence of a wall. If no wall is present, the orange will be placed and the while loop is exited.
            while(!placeFound) {

                int x = rand()%25;
                int y = rand()%25;
                
                //Check for wall
                if(map[y][x] != 1) {
                    bonus.x = x;
                    bonus.y = y;
                    bonus.dir = RIGHT;
                    std::array<int,2> coordinatesBonus = {x,y};

                    //Remove the current item, if there is any.
                    items.erase(coordinatesBonus);

                    //Insert new item
                    items.insert(std::pair<std::array<int,2>,GameObjectStruct>(coordinatesBonus,bonus));

                    //Set boolean to true to indicate that while loop can be exited.
                    placeFound = true;

                    

                }

            }

        }
        

        //Check if there is a wall in front of the character, if not, proceed.
        if(map[inFrontOfCharacter.y][inFrontOfCharacter.x] != 1) {
            
            pacman.Move();

            std::array<int,2> coordinates = {pacman.x, pacman.y};

            //Collision check for DOT
            if(items[coordinates].type == DOT){ //Check if there is a dot at the current position
            items.erase(coordinates); //Remove dot 
            score++; //Increase score            
            }

            //Collision check for ENERGIZER
            if(items[coordinates].type == ENERGIZER){
                items.erase(coordinates);               //Remove the item
                scaredtimer = 300;                      

                for(int i = 0; i<4;i++){                //Set all ghosts to SCARED mode
                ghostArray[i].type = SCARED;
                }

                
            }
            
            //Collision check for ORANGE
            if(items[coordinates].type == ORANGE){
                items.erase(coordinates);               //Remove the item
                score= score+20;                        //Gain 20 points

            }
              

    
                
        }

        //Logic to decrease the running timer.
        if(scaredtimer>0) {
            scaredtimer--;
        }

        //If the timer is not running, make sure that the ghosts are not scared. This is mainly when the timer has expired.
        else{
            
            for(int i=0;i<4;i++){
                ghostArray[i].type = typeArray[i];
            }
      

        }

        
        //For every Ghost, check if the coordinates of the pacman are equal.
        for(int i = 0; i<4;i++){
            if((ghostArray[i].x == pacman.x) && (ghostArray[i].y == pacman.y)) {
                
                //If ghosts are scared:
                if(ghostArray[i].type == SCARED) {
                    ghostArray[i].ResetPos();           //Reset the position
                    score = score+10;                   //Player gains 10 points
                    ghostArray[i].type = typeArray[i];  //Reset the type mode to default for this ghost
                }

                //If ghosts are not scared
                else{
                    pacman.ResetPos();                    //Place pacmanplayer back to starting position           
                    ghostArray[i].ResetPos();             //Place ghost back to starting position
                    lives --;                             //Reduce lives by 1
                    ui.setLives(lives);                   
                }


            }


                
        }

    
        //Move the ghosts
        for(int i = 0; i<4;i++){
            ghostArray[i].Move();
        }

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

        //Collect the specialties
        std::vector<GameObjectStruct> specialty = {decorativeWall, pacman, ghostArray[0], ghostArray[1], ghostArray[2], ghostArray[3]};

        //Objects placed in the objects container in a specific order, to ensure that the objects are rendered correctly. 
        objects.insert(objects.end(), dotsvector.begin(), dotsvector.end() );
        objects.insert(objects.end(), specialty.begin(), specialty.end() );
        objects.insert(objects.end(),bonusses.begin(),bonusses.end());

        ui.update(objects);
        

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
           
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}



