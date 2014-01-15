//
//  HeadBit.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_HeadBit_h
#define Shadow_Snake_2_HeadBit_h

#include "SnakeBit.h"

class HeadBit : public SnakeBit
{
public:
    HeadBit(const Params& params) : SnakeBit(params) { }
    
    // snake needs to be able to set these for the head bit
    void setPosition(Vector2D position)
    {
        m_lastPosition = m_position;
        m_position = position;
    }
    
protected:
    // handlePassingType() is inherited from SnakeBit
    
    // move does nothing for a head bit, moving handled by snake class
    virtual void move() { }
    
    // head bit has no previous, but still needs to shift passing type along
    virtual void updatePacket()
    {
        m_lastPacket = m_packet;
        m_packet.type = -1;
    }
};

#endif
