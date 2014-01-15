//
//  MenuButton.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "MenuButton.h"
#include "TextureManager.h"
#include "InputHandler.h"

void MenuButton::draw()
{
    TextureManager::instance()->drawFrame(m_textureID, m_position.getX(),
                              m_position.getY(), m_width, m_height,
                              m_state);
}

void MenuButton::update()
{
    Vector2D* mousePos = InputHandler::instance()->getMousePosition();
    
    if(mousePos->getX() < (m_position.getX() + m_width) && mousePos->getX() >
       m_position.getX()
       && mousePos->getY() < (m_position.getY() + m_height) && mousePos->getY() > m_position.getY())
    {
        if(InputHandler::instance()->getMouseButtonState(LEFT) && m_released)
        {
            m_state = CLICKED;
            
            if(m_callback != 0)
            {
                m_callback();
            }
            
            m_released = false;
        }
        else if(!InputHandler::instance()->getMouseButtonState(LEFT))
        {
            m_released = true;
            m_state = MOUSE_OVER;
        }
    }
    else
    {
        m_state = MOUSE_OUT;
    }
}

void MenuButton::clean()
{
    
}