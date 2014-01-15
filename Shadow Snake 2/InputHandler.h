//
//  InputHandler.h
//  Shadow Snake
//
//  Created by Sinclair Target on 1/11/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake__InputHandler__
#define __Shadow_Snake__InputHandler__

#include <assert.h>
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons { LEFT, MIDDLE, RIGHT };

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();
    
    // singleton implementation
    static InputHandler* instance()
    {
        if (s_instance == nullptr)
            s_instance = new InputHandler();
        return s_instance;
    }
    
    void update();
    
    // keyboard events
    bool pressed(SDL_Scancode key);
    
    // mouse events
    void reset();
    bool getMouseButtonState(int buttonNumber) const;
    Vector2D* getMousePosition() const;
    
    bool hasQuitEvent() { return m_hasQuit; }
    
private:
    static InputHandler* s_instance;
    
    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);
    
    bool m_hasQuit;
    
    // keyboard
    SDL_Scancode m_pressed;
    
    // mouse
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
};

#endif /* defined(__Shadow_Snake__InputHandler__) */
