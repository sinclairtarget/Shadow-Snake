//
//  Game.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__Game__
#define __Shadow_Snake_2__Game__

#include <SDL2/SDL.h>
#include "GameStateMachine.h"

class Game
{
public:
    static Game* instance()
    {
        if (s_instance == nullptr)
            s_instance = new Game();
        return s_instance;
    }
    
    static int score;
    
    // game loop functions
    bool init(const char* title, int width, int height, int tileSize,
              SDL_Color drawColor, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    void quit() { m_running = false; }
    
    // getter functions
    int getGameWidth() { return m_gameWidth; }
    int getGameHeight() { return m_gameHeight; }
    int getTileSize() { return m_tileSize; }
    bool isRunning() { return m_running; }
    GameStateMachine* getStateMachine() { return m_stateMachine; }
   
private:
    static Game* s_instance;
    
    // private functions
    Game() : m_running(false), m_stateMachine(new GameStateMachine()) { }
    
    GameStateMachine* m_stateMachine;
    
    // boolean members
    bool m_running;
    
    // other members
    int m_gameWidth;
    int m_gameHeight;
    int m_tileSize;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};


#endif /* defined(__Shadow_Snake_2__Game__) */
