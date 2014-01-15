//
//  MenuButton.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__MenuButton__
#define __Shadow_Snake_2__MenuButton__

#include "GameObject.h"

typedef void(*Callback)();

class MenuButton : public GameObject
{
public:
    enum buttonState { MOUSE_OUT, MOUSE_OVER, CLICKED };
    
    MenuButton(const Params& params, Callback callback) :
        GameObject(params),
        m_callback(callback),
        m_state(MOUSE_OUT)
    { }
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
private:
    bool m_released;
    Callback m_callback;
    int m_state;
};

#endif /* defined(__Shadow_Snake_2__MenuButton__) */
