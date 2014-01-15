//
//  Snake.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__Snake__
#define __Shadow_Snake_2__Snake__

#include "GameObject.h"
#include "SnakeBit.h"
#include <list>
#include <map>

class Snake : public GameObject
{
public:
    Snake(const Params& params);
    
    virtual void update();
    virtual void draw();
    virtual void clean();
    
    void feed(Packet packet);
    
    // help with collision detection
    bool doesSnakeOccupy(Vector2D position); // entire snake, including blanks
    bool hasSelfCollided();
    
    // getter and setter functions
    bool isShadowed() { return m_hasShadow; }
    void shadow() { m_hasShadow = true; }
    size_t getLength() { return m_snakeBits.size(); }
    
private:
    void handleInput();
    void updatePosition();
    void refreshList();
    void flash();
    
    std::list<SnakeBit*> m_snakeBits;
    Vector2D m_velocity;
    
    bool m_hasShadow;
    int m_startCount;
};

#endif /* defined(__Shadow_Snake_2__Snake__) */
