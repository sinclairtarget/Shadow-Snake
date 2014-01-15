//
//  MenuState.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_MenuState_h
#define Shadow_Snake_2_MenuState_h

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState : public GameState
{
public:
    virtual ~MenuState() {}
    
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
    
    std::string getStateID() const { return m_menuID; }
    
private:
    std::vector<GameObject*> m_objects;
    
    static std::string m_menuID;
    
    // callbacks functions
    static void menuToPlay();
    static void exitFromMenu();
};


#endif
