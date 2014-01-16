//
//  PlayState.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameOverState.h"
#include "SoundManager.h"

const int INTERVAL_STEP = 8;

const std::string PlayState::playID = "PLAY";

void PlayState::update()
{
    m_snake->update();
    m_food->update();
    m_scoreDisplay->update();
    checkCollisions();
    
    // feed snake
    if (!m_packetQueue.empty())
    {
        m_snake->feed(m_packetQueue.front());
        m_packetQueue.pop();
    }
}

void PlayState::render()
{
    m_snake->draw();
    m_food->draw();
    m_scoreDisplay->draw();
}

void PlayState::onEnter()
{
    // load textures
    TextureManager::instance()->load("assets/squares.png", "squares");
    
    // place player
    int width = Game::instance()->getGameWidth();
    int height = Game::instance()->getGameHeight();
    int tileSize = Game::instance()->getTileSize();
    int x = ((width / 2) - ((width / 2) % tileSize)) - tileSize;
    int y = ((height / 2) - ((height / 2) % tileSize)) - tileSize;
    Params params(Vector2D(x,y), tileSize, tileSize, HEAD_BIT, "squares");
    m_snake = new Snake(params);
    
    // place food
    m_food = new Food(Params(Vector2D(64, 64), tileSize, tileSize, FOOD,
                             "squares"));
    
    // create score display
    Game::score = 0;
    Params displayParams(Vector2D(896, 16), 16, 32, -1, "");
    m_scoreDisplay = new ScoreDisplay(displayParams, 1);
    
    // load sounds
    SoundManager::Instance()->load("assets/beep.wav", "beep", SOUND_SFX);
    SoundManager::Instance()->load("assets/longbeep.wav", "longbeep", SOUND_SFX);
    SoundManager::Instance()->load("assets/shadow.wav", "shadow", SOUND_SFX);
    SoundManager::Instance()->load("assets/lose.wav", "lose", SOUND_SFX);
}

void PlayState::onExit()
{
    m_snake->clean();
    m_food->clean();
    m_scoreDisplay->clean();
    
    // clear the texture manager
    for(int i = 0; i < m_textureIDList.size(); i++)
    {
        TextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
    }
}

void PlayState::checkCollisions()
{
    // food collision
    if (m_snake->getPosition() == m_food->getPosition())
    {
        // feed snake
        if (m_food->getType() == FOOD)
        {
            SoundManager::Instance()->playSound("longbeep", 0);
            if (!m_snake->isShadowed())
            {
                m_packetQueue.push({SNAKE_BIT, false});
            }
            else
            {
                m_packetQueue.push({SNAKE_BIT, true});
            }
        }
        else if (m_food->getType() == SHADOW_FOOD)
        {
            SoundManager::Instance()->playSound("shadow", 0);
            // grow interval
            for (int i = 0; i < INTERVAL_STEP; i++)
            {
                m_packetQueue.push({BLANK_BIT, false});
            }
            
            // if shadow snake does not exist, create it
            if (!m_snake->isShadowed())
            {
                for (size_t i = 0; i < m_snake->getLength(); i++)
                {
                    m_packetQueue.push({SHADOW_BIT, false});
                }
                
                m_snake->shadow();
            }
        }
        
        // must happen after feeding
        m_food->collide(m_snake);
        
        Game::score++;
    }
    
    // snake collision
    if (m_snake->hasSelfCollided())
    {
        std::cout << "COLLISION!\n";
        SoundManager::Instance()->playSound("lose", 0);
        Game::instance()->getStateMachine()->changeState(new GameOverState());
    }
}
