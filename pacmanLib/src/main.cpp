/// \file
/// main.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author:
 *       Group:
 */

#include "Powerup.h"
#include "BonusItem.h"
#include "CollectibleDot.h"
#include "UI.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
/// Note that this callback may happen on a different thread than the main thread.
/// You therefore have to be careful in avoiding data races. For example, you
/// should use mutexes to access shared data.
/// Read the documentation of SDL_AddTimer for more information and for tips
/// regarding multithreading issues.
Uint32 gameUpdate(Uint32 interval, void * /*param*/)
{
    // Do game loop update here
    //std::cout << "testy each update" << std::endl;
    
    return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};

    // Create a new ui object
    UI ui(map); // <-- use map from your game objects.

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(100, gameUpdate, static_cast<void *>(nullptr));

    // Example object, this can be removed later
    GameObjectStruct pacman;
    pacman.x = 1;
    pacman.y = 1;
    pacman.type = PACMAN;
    pacman.dir = UP;

    // Call game init code here
    Powerup testPowerup;
    testPowerup.x = 2;
    testPowerup.y = 1;
    testPowerup.type = ENERGIZER;
    testPowerup.dir = RIGHT;

    BonusItem testBonusItem;
    testBonusItem.x = 3;
    testBonusItem.y = 1;
    testBonusItem.type = ORANGE;
    testBonusItem.dir = RIGHT;

    CollectibleDot testCollectibleDot;
    testCollectibleDot.x = 4;
    testCollectibleDot.y = 1;
    testCollectibleDot.type = DOT;
    testCollectibleDot.dir = RIGHT;


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
                    break;
                case SDLK_RIGHT: // YOUR CODE HERE
                    break;
                case SDLK_UP: // YOUR CODE HERE
                    break;
                case SDLK_DOWN: // YOUR CODE HERE
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
            }
        }

        // Set the score
        ui.setScore(12345); // <-- Pass correct value to the setter

        // Set the amount of lives
        ui.setLives(2); // <-- Pass correct value to the setter

        // Render the scene
        std::vector<GameObjectStruct> objects = {pacman, testPowerup, testBonusItem, testCollectibleDot};
        // ^-- Your code should provide this vector somehow (e.g.
        // game->getStructs())
        ui.update(objects);

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
