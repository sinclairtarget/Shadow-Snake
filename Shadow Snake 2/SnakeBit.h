//
//  Bit.h
//  Shadow Snake 2
//
//  Created by Sinclair Target on 1/12/14.
//  Copyright (c) 2014 Sinclair Target. All rights reserved.
//

#ifndef Shadow_Snake_2_Bit_h
#define Shadow_Snake_2_Bit_h

#include "SnakeObject.h"
#include "Params.h"

struct Packet { int type; bool doubleFeed; };

class SnakeBit : public SnakeObject
{
public:
    SnakeBit(const Params& params) :
        SnakeObject(params),
        m_packet({-1, false}),
        m_lastPacket({-1, false}),
        m_next(nullptr),
        m_previous(nullptr),
        m_addBitAfter(false),
        m_addBitBefore(false)
    { }
    
    virtual ~SnakeBit() { }
    
    // all snake bits update, draw, clean the same way
    virtual void update() final;
    virtual void draw() final;
    virtual void clean() final;
    
    // setter and gettter functions
    void setPrevious(SnakeBit* previous) { m_previous = previous; }
    SnakeBit* getPrevious() { return m_previous; } 
    void setNext(SnakeBit* next) { m_next = next; }
    Vector2D getLastPostition() { return m_lastPosition; }
    Packet getPacket() { return m_packet; } // not used by SnakeBit
    Packet getLastPacket() { return m_lastPacket; }
    void setPacket(Packet packet) { m_packet = packet; }
    void setLastPacket(Packet packet) { m_lastPacket = packet; }
    bool shouldAddBitAfter() { return m_addBitAfter; }
    bool shouldAddBitBefore() { return m_addBitBefore; }
    
protected:
    // different bit functions, called by update()
    virtual void handlePacket(); // sets m_addBitAfter if needed
    virtual void move();
    virtual void updatePacket();
    
    SnakeBit* m_previous;
    SnakeBit* m_next;
    Vector2D m_lastPosition;
    
    // the bit type that was fed in and is moving down the line
    // -1 if there is no passing type
    Packet m_packet;
    Packet m_lastPacket;
    
    // tells snake to add bit after or before this one
    bool m_addBitAfter;
    bool m_addBitBefore; // not used by SnakeBit
};

#endif
