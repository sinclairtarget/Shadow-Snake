//
//  Game.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "PlayState.h"
#include "MenuState.h"
#include "SoundManager.h"
#include <iostream>
#include <SDL2_ttf/SDL_ttf.h>

Game* Game::s_instance = nullptr;

int Game::score = 0;

bool Game::init(const char* title, int width, int height, int tileSize,
                SDL_Color drawColor, bool fullscreen)
{
    using namespace std;
    
    m_gameWidth = width;
    m_gameHeight = height;
    m_tileSize = tileSize;
    
    int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    
    // attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "SDL initialization failed.\n";
        return false;
    }
    cout << "SDL initialized.\n";
    
    // attempt to initialize SDL fonts
    if (TTF_Init() != 0)
    {
        cout << "TFF initialization failed.\n";
        return false;
    }
    
    // create centered or fullscreen window, depending on flags
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, m_gameWidth,
                                m_gameHeight, flags);
    if (m_window == nullptr)
    {
        cout << "Window creation failed.\n";
        return false;
    }
    cout << "Window created.\n";
    
    // create renderer, using first available rendering driver (-1)
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    
    if (m_renderer == nullptr)
    {
        cout << "Renderer initialization failed.\n";
        return false;
    }
    cout << "Renderer initialized.\n";
    
    SDL_SetRenderDrawColor(m_renderer, drawColor.r, drawColor.g, drawColor.b,
                           255);
    
    TextureManager::instance()->setRenderer(m_renderer);
    
    m_stateMachine->pushState(new MenuState());
    
    // play music
    SoundManager::Instance()->load("assets/hero.ogg", "music", SOUND_MUSIC);
    SoundManager::Instance()->playMusic("music", 20);
    
    m_running = true;
    return true;
}

void Game::handleEvents()
{
    InputHandler::instance()->update();
    if (InputHandler::instance()->hasQuitEvent())
        quit();
}

void Game::update()
{
    m_stateMachine->update();
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    
    m_stateMachine->render();
    
    SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
    m_stateMachine->clean();
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}