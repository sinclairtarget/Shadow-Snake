//
//  InputHandler.cpp
//  Shadow Snake
//
//  Created by Sinclair Target on 1/11/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "InputHandler.h"

InputHandler* InputHandler::s_instance = nullptr;

InputHandler::InputHandler() :
    m_pressed(SDL_SCANCODE_UNKNOWN),
    m_mousePosition(new Vector2D(0,0))
{
    // create button states for the mouse
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}

InputHandler::~InputHandler()
{
    delete m_mousePosition;
    
    m_mouseButtonStates.clear();
}

void InputHandler::update()
{
    m_pressed = SDL_SCANCODE_UNKNOWN;
    
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_hasQuit = true;
                break;
                
            case SDL_KEYDOWN:
                m_pressed = event.key.keysym.scancode;
                break;
                
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
                
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            default:
                break;
        }
    }
}

bool InputHandler::pressed(SDL_Scancode key)
{
   if (m_pressed == key)
        return true;
    else
        return false;
}

void InputHandler::reset()
{
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}

bool InputHandler::getMouseButtonState(int buttonNumber) const
{
    return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() const
{
    return m_mousePosition;
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

