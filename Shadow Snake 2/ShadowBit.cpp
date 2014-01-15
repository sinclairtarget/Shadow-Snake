//
//  ShadowBit.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "ShadowBit.h"
#include <iostream>

void ShadowBit::handlePacket()
{
    m_addBitAfter = false;
    m_addBitBefore = false;
    
    if (m_packet.type >= 0)
    {
        if (m_packet.type == SNAKE_BIT)
        {
            m_addBitBefore = true;
            std::cout << "ERROR: SHADOW BIT HANDLING SNAKE BIT.\n";
        }
        else if (m_packet.type == BLANK_BIT)
        {
            m_addBitBefore = true;
        }
        else if (!m_next)
        {
            m_addBitAfter = true;
        }
    }
}

void ShadowBit::move()
{
    // pause if bit is being inserted before this one
    if (!m_addBitBefore)
    {
        SnakeBit::move();
    }
}

void ShadowBit::updatePacket()
{
    // don't update if bit is being inserted before this one
    if (!m_addBitBefore)
    {
        SnakeBit::updatePacket();
    }
}