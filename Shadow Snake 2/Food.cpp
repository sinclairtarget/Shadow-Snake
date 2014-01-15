//
//  Food.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "Food.h"
#include "TextureManager.h"
#include "Game.h"

void Food::draw()
{
    TextureManager::instance()->drawSquare(m_position.getX(), m_position.getY(),
                                           m_size, m_type);
}

void Food::collide(Snake* snake)
{
    // ensures food does not end up in the same place or in the snake
    Vector2D tempPosition;
    do
    {
        int x = rand() % Game::instance()->getGameWidth();
        int y = rand() % Game::instance()->getGameHeight();
        tempPosition = Vector2D::snap(Vector2D(x, y), m_size);
    } while (snake->doesSnakeOccupy(tempPosition));
    
    // moves food
    m_position = tempPosition;
    std::cout << "Food moved to (" << m_position.getX() << ", "
    << m_position.getY() << ")\n";
    
    // no shadow food until score 3
    if (Game::score > 3)
    {
        // shadow food some of the time
        if (rand() > (RAND_MAX / 4))
            m_type = FOOD;
        else
            m_type = SHADOW_FOOD;
    }
    
    std::cout << "Food is type: ";
    
    if (m_type == FOOD)
        std::cout << "FOOD\n";
    else
        std::cout << "SHADOW FOOD\n";
}