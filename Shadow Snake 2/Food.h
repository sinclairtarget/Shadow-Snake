//
//  Food.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__Food__
#define __Shadow_Snake_2__Food__

#include "SnakeObject.h"
#include "Snake.h"

class Food : public SnakeObject
{
public:
    Food(const Params& params) : SnakeObject(params) { }
    
    virtual void draw();
    virtual void update() { }
    virtual void clean() { }
    
    void collide(Snake* snake);
};

#endif /* defined(__Shadow_Snake_2__Food__) */
