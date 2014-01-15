//
//  BlankBit.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__BlankBit__
#define __Shadow_Snake_2__BlankBit__

#include "SnakeBit.h"

class BlankBit : public SnakeBit
{
public:
    BlankBit(const Params& params) : SnakeBit(params) { }
    
protected:
    virtual void handlePacket();
    virtual void move();
    virtual void updatePacket();
};

#endif /* defined(__Shadow_Snake_2__BlankBit__) */
