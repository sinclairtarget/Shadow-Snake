//
//  main.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Game.h"

// WINDOW PARAMETERS
const char* TITLE = "Shadow Snake";
const int WIDTH = 960;
const int HEIGHT = 528;
const bool FULLSCREEN = false;
const int FPS = 20;
const int FRAME_PERIOD = 1000.0f / FPS; // milliseconds per frame

// BACKGROUND COLOR
const SDL_Color DRAW_COLOR = {.r = 129, .g = 163, .b = 140};

// TILE SIZE
const int TILE_SIZE = 16;

int main(int argc, char *argv[])
{
    // seed random number generator
    srand(time(NULL));
    
    Uint32 framestart, frameTime;
    
    std::cout << "Attempting game intitalization...\n";
    if (Game::instance()->init(TITLE, WIDTH, HEIGHT, TILE_SIZE, DRAW_COLOR,
                               FULLSCREEN))
        std::cout << "Game initialized. Width: "
        << WIDTH << " Height: " << HEIGHT << std::endl;
    else
        std::cout << "Game initialization failed.\n";
    
    // Game loop
    while (Game::instance()->isRunning())
    {
        framestart = SDL_GetTicks();
        
        Game::instance()->handleEvents();
        Game::instance()->update();
        Game::instance()->render();
        
        frameTime = SDL_GetTicks() - framestart;
        if (frameTime < FRAME_PERIOD)
        {
            if ((int)(FRAME_PERIOD - frameTime) < 0)
            {
                std::cout << "(FPS - frameTime) is negative!\n";
                std::cout << ((int)(FRAME_PERIOD - frameTime));
            }
            SDL_Delay((int)(FRAME_PERIOD - frameTime));
        }
    }
    
    std::cout << "Game closing...\n";
    Game::instance()->clean();
}
