//
//  GameStateMachine.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__GameStateMachine__
#define __Shadow_Snake_2__GameStateMachine__

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:
    
    GameStateMachine() {}
    ~GameStateMachine() {}
    
    void update();
    void render();
    
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
    
    void clean();
    
private:
    std::vector<GameState*> m_gameStates;
};


#endif /* defined(__Shadow_Snake_2__GameStateMachine__) */
