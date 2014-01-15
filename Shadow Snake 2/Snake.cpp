//
//  Snake.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "Snake.h"
#include "InputHandler.h"
#include "BitFactory.h"
#include "Game.h"
#include "HeadBit.h"
#include "SoundManager.h"

Snake::Snake(const Params& params) :
    GameObject(params),
    m_velocity(Vector2D(0, -1)),
    m_hasShadow(false),
    m_startCount(30)
{
    m_snakeBits.push_front(new HeadBit(params));
}

void Snake::update()
{
    if (m_startCount == 0)
    {
        handleInput();
        
        updatePosition();
        
        // set head bit position to the snake position
        m_snakeBits.front()->setPosition(m_position);
        
        // update all bits
        for (auto it_b = m_snakeBits.begin(); it_b != m_snakeBits.end(); it_b++)
        {
            SnakeBit* bit = *it_b;
            
            bit->update();
            
            // add bit after if needed
            if (bit->shouldAddBitAfter())
            {
                // bit has already updated passing type, need whatever it had last
                // to get new bit type
                SnakeBit* newBit =
                    BitFactory::makeBit(bit->getLastPacket().type,
                                        bit->getPosition());
                
                // type has been made, can get rid of it
                bit->setLastPacket({-1, false});
                
                m_snakeBits.push_back(newBit);
                
                bit->setNext(newBit);
                newBit->setPrevious(bit);
            }
            
            // add bit before if needed
            if (bit->shouldAddBitBefore())
            {
                // bit has not updated passing type, can get what it has currently
                SnakeBit* newBit =
                    BitFactory::makeBit(bit->getPacket().type,
                                        bit->getPosition());
                
                if (!bit->getPacket().doubleFeed)
                {
                    // type has been made, can get rid of it
                    bit->setPacket({-1, false});
                }
                else
                {
                    bit->setPacket({SHADOW_BIT, false});
                }
                
                m_snakeBits.insert(it_b, newBit);
                
                newBit->setNext(bit);
                newBit->setPrevious(bit->getPrevious());
                bit->setPrevious(newBit);
                
                // newBit needs to be updated, as the iterator is past it
                newBit->update();
                // bit also needs to be updated again
                bit->update();
            }
        }
    }
    else
    {
        flash();
        m_startCount--;
    }
}

void Snake::draw()
{
    for (SnakeBit* bit : m_snakeBits)
        bit->draw();
}

void Snake::clean()
{
    for (SnakeBit* bit : m_snakeBits)
        bit->clean();
    m_snakeBits.clear();
}

void Snake::feed(Packet packet)
{
    m_snakeBits.front()->setPacket(packet);
}

bool Snake::doesSnakeOccupy(Vector2D position)
{   
    for (SnakeBit* bit : m_snakeBits)
    {
        if (bit->getPosition() == position)
            return true;
    }
    return false;
}

bool Snake::hasSelfCollided()
{
    // set first shadow bit
    SnakeBit* firstShadowBit = nullptr;
    for (SnakeBit* bit : m_snakeBits)
    {
        if (bit->getType() == SHADOW_BIT)
        {
            firstShadowBit = bit;
            break;
        }
    }
    
    
    // O(list.length()^2)
    for (SnakeBit* bit : m_snakeBits)
    {
        if ((bit->getPosition() == m_position)
            && bit->getType() != BLANK_BIT
            && bit->getType() != HEAD_BIT)
            return true;
        
        if (firstShadowBit)
        {
            if ((bit->getPosition() == firstShadowBit->getPosition())
                && bit->getType() != BLANK_BIT
                && bit->getType() != SHADOW_BIT)
                return true;
        }
    }
    return false;
}

void Snake::handleInput()
{
    if (InputHandler::instance()->pressed(SDL_SCANCODE_UP))
    {
        // if not going down
        if (m_velocity != Vector2D(0, 1))
            m_velocity = Vector2D(0, -1);
    }
    else if (InputHandler::instance()->pressed(SDL_SCANCODE_DOWN))
    {
        // if not going up
        if (m_velocity != Vector2D(0, -1))
            m_velocity = Vector2D(0, 1);
    }
    else if (InputHandler::instance()->pressed(SDL_SCANCODE_LEFT))
    {
        // if not going right
        if (m_velocity != Vector2D(1, 0))
            m_velocity = Vector2D(-1, 0);
    }
    else if (InputHandler::instance()->pressed(SDL_SCANCODE_RIGHT))
    {
        // if not going left
        if (m_velocity != Vector2D(-1, 0))
            m_velocity = Vector2D(1, 0);
    }
}

void Snake::updatePosition()
{
    Vector2D newPosition = (m_position + (m_velocity * m_width));
    
    // wrap game area
    if (newPosition.getX() < 0)
    {
        newPosition.setX(newPosition.getX() + Game::instance()->getGameWidth());
        std::cout << "Gone offscreen left. Moving to x = " << newPosition.getX()
        << std::endl;;
    }
    if ((newPosition.getX() + Game::instance()->getTileSize())
        > Game::instance()->getGameWidth())
    {
        newPosition.setX(newPosition.getX() - Game::instance()->getGameWidth());
        std::cout << "Gone offscreen right. Moving to x = " << newPosition.getX()
        << std::endl;;
    }
    if (newPosition.getY() < 0)
    {
        newPosition.setY(newPosition.getY() + Game::instance()->getGameHeight());
        std::cout << "Gone offscreen bottom. Moving to y = " << newPosition.getY()
        << std::endl;
    }
    if ((newPosition.getY() + Game::instance()->getTileSize()) >
        Game::instance()->getGameHeight())
    {
        newPosition.setY(newPosition.getY() - Game::instance()->getGameHeight());
        std::cout << "Gone offscreen top. Moving to y = " << newPosition.getY()
        << std::endl;
    }
    
    m_position = newPosition;
}

void Snake::flash()
{
    if (m_startCount == 1)
    {
        SoundManager::Instance()->playSound("longbeep", 0);
    }
    
    if ((m_startCount % 10) == 0)
    {
        m_snakeBits.front()->setPacket({1, false});
        SoundManager::Instance()->playSound("beep", 0);
    }
    else
        m_snakeBits.front()->setPacket({-1, false});
}