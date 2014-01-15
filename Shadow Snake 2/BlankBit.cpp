//
//  BlankBit.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "BlankBit.h"

void BlankBit::handlePacket()
{
    m_addBitAfter = false;
    m_addBitBefore = false;
    
    if (m_packet.type >= 0)
    {
        if (m_packet.type == SNAKE_BIT)
        {
            m_addBitBefore = true;
        }
        else if (!m_next)
        {
            m_addBitAfter = true;
        }
    }
}

void BlankBit::move()
{
    // pause if bit is being inserted before this one
    if (!m_addBitBefore)
    {
        SnakeBit::move();
    }
}

void BlankBit::updatePacket()
{
    // don't update if bit is being inserted before this one
    if (!m_addBitBefore)
    {
        SnakeBit::updatePacket();
    }
}