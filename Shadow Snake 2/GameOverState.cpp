//
//  GameOverState.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "ScoreDisplay.h"

const std::string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::update()
{
    for (GameObject* object : m_objects)
        object->update();
}

void GameOverState::render()
{
    for (GameObject* object : m_objects)
        object->draw();
}

void GameOverState::onEnter()
{
    // textures
    TextureManager::instance()->load("assets/replay button.png", "replayButton");
    m_textureIDList.push_back("playButton");
    TextureManager::instance()->load("assets/menu button.png", "menuButton");
    m_textureIDList.push_back("quitButton");
    TextureManager::instance()->load("assets/score anim.png", "score");
    m_textureIDList.push_back("gameover");
    
    int replay_x = 287;
    int replay_y =  328;
    Params replayParams(Vector2D(replay_x, replay_y), 128, 64, -1, "replayButton");
    m_objects.push_back(new MenuButton(replayParams, restart));
    
    int menu_x = 544;
    int menu_y = replay_y;
    Params menuParams(Vector2D(menu_x, menu_y), 128, 64, -1, "menuButton");
    m_objects.push_back(new MenuButton(menuParams, gameOverToMain));
    
    int title_x = 352;
    int title_y = 64;
    Params titleParams(Vector2D(title_x, title_y), 256, 128, -1, "score");
    m_objects.push_back(new AnimatedGraphic(titleParams, 2, 2));
    
    int score_x = 480;
    int score_y = title_y + 32 + ((replay_y - title_y) / 2);
    Params scoreParams(Vector2D(score_x, score_y), 32, 64, -1, "score");
    int digits;
    if (Game::score < 10)
        digits = 1;
    else if (Game::score < 100)
        digits = 2;
    else 
        digits = 3;
    m_objects.push_back(new ScoreDisplay(scoreParams, digits));
}

void GameOverState::onExit()
{
    m_objects.clear();
    
    // clear the texture manager
    for(int i = 0; i < m_textureIDList.size(); i++)
    {
        TextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
    }
    
    InputHandler::instance()->reset();
}

void GameOverState::gameOverToMain()
{
    Game::instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restart()
{
    Game::instance()->getStateMachine()->changeState(new PlayState());
}