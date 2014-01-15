//
//  BitFactory.cpp
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/13/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#include "BitFactory.h"
#include "Game.h"
#include "BlankBit.h"
#include "ShadowBit.h"
#include <iostream>

SnakeBit* BitFactory::makeBit(int type, Vector2D position)
{
    SnakeBit* bit;
    
    switch (type)
    {
        case SNAKE_BIT:
            bit = new SnakeBit(Params(position,
                                      Game::instance()->getTileSize(),
                                      Game::instance()->getTileSize(),
                                      type, "squares"));
            std::cout << "Snake Bit created.\n";
            break;
            
        case BLANK_BIT:
            bit = new BlankBit(Params(position,
                                      Game::instance()->getTileSize(),
                                      Game::instance()->getTileSize(),
                                      type, "squares"));
            std::cout << "BlankBit created.\n";
            break;
            
        case SHADOW_BIT:
            bit = new ShadowBit(Params(position,
                                       Game::instance()->getTileSize(),
                                       Game::instance()->getTileSize(),
                                       type, "squares"));
            std::cout << "ShadowBit created.\n";
            break;
            
        default:
            bit = nullptr;
            std::cout << "ERROR: BitFactory returning null.\n";
            break;
    }
    
    return bit;
}