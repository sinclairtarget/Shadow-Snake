//
//  BitParams.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_BitParams_h
#define Shadow_Snake_2_BitParams_h

#include <string>

class SnakeBit;

class Params
{
public:
    Params(Vector2D position, int width, int height, int type,
           std::string textureID) :
                m_position(position),
                m_width(width),
                m_height(height),
                m_type(type),
                m_textureID(textureID)
    { }
    
    Vector2D getPosition() const { return m_position; }
    int getSize() const { return m_width; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getType() const { return m_type; }
    std::string getID() const { return m_textureID; }
    
private:
    Vector2D m_position;
    int m_width;
    int m_height;
    int m_type;
    std::string m_textureID;
};

#endif
