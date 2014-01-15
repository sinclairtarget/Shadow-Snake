//
//  PlayState.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef __Shadow_Snake_2__PlayState__
#define __Shadow_Snake_2__PlayState__

#include "GameState.h"
#include "Snake.h"
#include "Food.h"
#include "ScoreDisplay.h"
#include <queue>

class GameObject;

class PlayState : public GameState
{
public:
    virtual ~PlayState() { }
    
    virtual void update();
    virtual void render();

    virtual void onEnter();
    virtual void onExit();
    
    virtual std::string getStateID() const { return playID; }

    Snake* getSnake() { return m_snake; }

private:
    static const std::string playID;

    void checkCollisions();

    Snake* m_snake;
    Food* m_food;
    // holds packets to be fed to the snake using feed(int type)
    std::queue<Packet> m_packetQueue;

    ScoreDisplay* m_scoreDisplay;
};

#endif /* defined(__Shadow_Snake_2__PlayState__) */
