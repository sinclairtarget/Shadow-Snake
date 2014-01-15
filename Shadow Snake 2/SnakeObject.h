//
//  SnakeObject.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_SnakeObject_h
#define Shadow_Snake_2_SnakeObject_h

#include "GameObject.h"

enum { HEAD_BIT, SNAKE_BIT, BLANK_BIT, SHADOW_BIT, FOOD, SHADOW_FOOD };

class SnakeObject : public GameObject
{
public:
    SnakeObject(const Params& params) :
        GameObject(params),
        m_size(m_width),
        m_type(params.getType())
    { }
    
    virtual ~SnakeObject() { }
    int getType() { return m_type; }
    
protected:
    int m_size;
    int m_type;
};

#endif
