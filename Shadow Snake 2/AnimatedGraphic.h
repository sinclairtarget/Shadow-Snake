//
//  AnimatedGraphic.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__AnimatedGraphic__
#define __Shadow_Snake_2__AnimatedGraphic__

#include "GameObject.h"

class AnimatedGraphic : public GameObject
{
public:
    AnimatedGraphic(const Params& params, int animSpeed, int numFrames) :
        GameObject(params),
        m_animSpeed(animSpeed),
        m_numFrames(numFrames)
    { }
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
private:
    int m_currentFrame;
    int m_animSpeed; // updates per second
    int m_numFrames;
};

#endif /* defined(__Shadow_Snake_2__AnimatedGraphic__) */
