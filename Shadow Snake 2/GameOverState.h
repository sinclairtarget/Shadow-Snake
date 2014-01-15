//
//  GameOverState.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__GameOverState__
#define __Shadow_Snake_2__GameOverState__

#include "GameState.h"

class GameObject;

class GameOverState : public GameState
{
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
    
    std::string getStateID() const { return gameOverID; }
    
private:
    static const std::string gameOverID;
    
    std::vector<GameObject*> m_objects;
    
    // callbacks
    static void gameOverToMain();
    static void restart();
};

#endif /* defined(__Shadow_Snake_2__GameOverState__) */
