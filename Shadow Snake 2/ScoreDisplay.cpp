//
//  ScoreDisplay.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "ScoreDisplay.h"
#include "TextureManager.h"
#include <math.h>
#include <iostream>

ScoreDisplay::ScoreDisplay(const Params& params, int digits) :
    GameObject(params),
    m_digits(digits),
    m_score(Game::score)
{
    m_font = TTF_OpenFont("FreeMonoBold.ttf", 32);
    if (!m_font)
    {
        std::cout << "TTF_OpenFont() failed: " << TTF_GetError()
                  << std::endl;
    }
}

void ScoreDisplay::update()
{
    m_score = Game::score;
    
    if (m_score < 10)
        m_digits = 1;
    else if (m_score < 100)
        m_digits = 2;
    else if (m_score < 1000)
        m_digits = 3;
}

void ScoreDisplay::draw()
{
    SDL_Surface* text;
    SDL_Color textColor = {210, 212, 207};
    std::string score = std::to_string(m_score);
    text = TTF_RenderText_Blended(m_font, score.c_str(), textColor);
    
    TextureManager::instance()->drawText(text,
                                         m_position.getX() -
                                            ((m_width * m_digits) / 2),
                                         m_position.getY(),
                                         m_width * m_digits, m_height);
}