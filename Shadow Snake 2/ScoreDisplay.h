//
//  ScoreDisplay.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__ScoreDisplay__
#define __Shadow_Snake_2__ScoreDisplay__

#include "GameObject.h"
#include "Game.h"
#include <SDL2_ttf/SDL_ttf.h>

class ScoreDisplay : public GameObject
{
public:
    ScoreDisplay(const Params& params, int digits);
    
    virtual void update();
    virtual void draw();
    virtual void clean() { }
    
private:
    int m_score;
    int m_digits;
    TTF_Font* m_font;
};

#endif /* defined(__Shadow_Snake_2__ScoreDisplay__) */
