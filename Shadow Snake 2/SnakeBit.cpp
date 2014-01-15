//
//  SnakeBit.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "SnakeBit.h"
#include "TextureManager.h"

void SnakeBit::update()
{
    handlePacket();
    
    move();
    
    updatePacket();
}

void SnakeBit::draw()
{
    if (m_packet.type >= 0)
    {
        TextureManager::instance()->drawSquareBloated(m_position.getX(),
                                                      m_position.getY(),
                                                      m_size, m_type);
    }
    else
    {
        TextureManager::instance()->drawSquare(m_position.getX(),
                                               m_position.getY(),
                                               m_size, m_type);
    }
}

void SnakeBit::clean()
{
    
}

void SnakeBit::handlePacket()
{
    m_addBitAfter = false;
    
    if (m_packet.type >= 0)
    {
        if (!m_next)
        {
            m_addBitAfter = true;
        }
    }
}

void SnakeBit::move()
{
    m_lastPosition = m_position;
    m_position = m_previous->getLastPostition();
}

void SnakeBit::updatePacket()
{
    m_lastPacket = m_packet;
    m_packet = m_previous->getLastPacket();
}