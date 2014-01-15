//
//  GameState.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_GameState_h
#define Shadow_Snake_2_GameState_h

#include <string>
#include <vector>

class GameState
{
public:
    virtual ~GameState() { }
    
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    
    virtual std::string getStateID() const = 0;
    
protected:
    std::vector<std::string> m_textureIDList;
};

#endif
