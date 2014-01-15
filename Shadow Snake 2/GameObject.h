//
//  GameObject.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_GameObject_h
#define Shadow_Snake_2_GameObject_h

#include "Vector2D.h"
#include "Params.h"
#include <string>

class GameObject
{
public:
    virtual ~GameObject() { }
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void clean() = 0;

    // setter and getter functions
    Vector2D getPosition() { return m_position; }
    virtual void setPosition(Vector2D position) { m_position = position; }
    
protected:
    GameObject(const Params& params) :
        m_position(params.getPosition()),
        m_width(params.getWidth()),
        m_height(params.getHeight()),
        m_textureID(params.getID())
    { }
    
    Vector2D m_position;
    int m_width;
    int m_height;
    std::string m_textureID;
};

#endif
