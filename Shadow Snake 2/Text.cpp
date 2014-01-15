//
//  Text.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/14/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "Text.h"
#include "TextureManager.h"

Text::Text(const Params& params, std::string text) :
    GameObject(params),
    m_text(text)
{
    m_font = TTF_OpenFont("FreeMonoBold.ttf", 32);
    if (!m_font)
    {
        std::cout << "TTF_OpenFont() failed: " << TTF_GetError()
        << std::endl;
    }
}

void Text::update()
{
    
}

void Text::draw()
{
    SDL_Surface* text;
    SDL_Color textColor = {210, 212, 207};
    text = TTF_RenderText_Blended(m_font, m_text.c_str(), textColor);
    
    TextureManager::instance()->drawText(text, m_position.getX(),
                                         m_position.getY(),
                                         m_width, m_height);
}