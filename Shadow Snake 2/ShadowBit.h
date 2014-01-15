//
//  ShadowBit.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__ShadowBit__
#define __Shadow_Snake_2__ShadowBit__

#include "SnakeBit.h"

class ShadowBit : public SnakeBit
{
public:
    ShadowBit(const Params& params) : SnakeBit(params) { }
    
protected:
    virtual void handlePacket();
    virtual void move();
    virtual void updatePacket();
};

#endif /* defined(__Shadow_Snake_2__ShadowBit__) */
