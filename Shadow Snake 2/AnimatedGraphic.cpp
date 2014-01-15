//
//  AnimatedGraphic.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "AnimatedGraphic.h"
#include "TextureManager.h"

void AnimatedGraphic::draw()
{
    TextureManager::instance()->drawFrame(m_textureID, m_position.getX(),
                                          m_position.getY(), m_width, m_height,
                                          m_currentFrame);
}

void AnimatedGraphic::update()
{
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed))
                          % m_numFrames));
}

void AnimatedGraphic::clean()
{
    
}