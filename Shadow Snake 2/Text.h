//
//  Text.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/14/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__Text__
#define __Shadow_Snake_2__Text__

#include "GameObject.h"
#include "Game.h"
#include <SDL2_ttf/SDL_ttf.h>

class Text : public GameObject
{
public:
    Text(const Params& params, std::string text);
    
    virtual void update();
    virtual void draw();
    virtual void clean() { }
    
private:
    std::string m_text;
    TTF_Font* m_font;
};

#endif /* defined(__Shadow_Snake_2__Text__) */
