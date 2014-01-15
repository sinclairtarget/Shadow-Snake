//
//  MenuState.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "Text.h"

std::string MenuState::m_menuID = "MENU";

void MenuState::update()
{
    for (GameObject* object : m_objects)
        object->update();
}

void MenuState::render()
{
    for (GameObject* object : m_objects)
        object->draw();
}

void MenuState::onEnter()
{
    // textures
    TextureManager::instance()->load("assets/play button.png", "playButton");
    m_textureIDList.push_back("playButton");
    TextureManager::instance()->load("assets/quit button.png", "quitButton");
    m_textureIDList.push_back("quitButton");
    TextureManager::instance()->load("assets/title anim.png", "title");
    m_textureIDList.push_back("title");
    
    int play_x = 288;
    int play_y = 360;
    Params playParams(Vector2D(play_x, play_y), 128, 64, -1, "playButton");
    m_objects.push_back(new MenuButton(playParams, menuToPlay));
    
    int quit_x = 544;
    int quit_y = play_y;
    Params quitParams(Vector2D(quit_x, quit_y), 128, 64, -1, "quitButton");
    m_objects.push_back(new MenuButton(quitParams, exitFromMenu));
    
    int title_x = 224;
    int title_y = 64;
    Params titleParams(Vector2D(title_x, title_y), 512, 256, -1, "title");
    m_objects.push_back(new AnimatedGraphic(titleParams, 2, 2));
    
    int credit_x = 8;
    int credit_y = 496;
    Params creditParams(Vector2D(credit_x, credit_y), 192, 32, -1, "");
    m_objects.push_back(new Text(creditParams, "Created by Sinclair Target"));
    
    int music_x = 824;
    int muxic_y = 496;
    Params musicParams(Vector2D(music_x, muxic_y), 128, 32, -1, "");
    m_objects.push_back(new Text(musicParams, "Music by Wizwars"));
}

void MenuState::onExit()
{
    m_objects.clear();
    
    // clear the texture manager
    for(int i = 0; i < m_textureIDList.size(); i++)
    {
        TextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
    }
    
    InputHandler::instance()->reset();
}

void MenuState::menuToPlay()
{
    Game::instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu()
{
    Game::instance()->quit();
}
