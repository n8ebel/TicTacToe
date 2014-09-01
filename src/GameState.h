//
//  GameState.h
//
//
//  Created by Nate Ebel on 8/19/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>

#include "Game.h"

class GameState : public n8::State {
public:
    GameState();
    virtual ~GameState();
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(n8::Window* img);
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    
    n8::InputService* m_inputService;
    
    n8::PopStateCommand m_popStateCommand;
    
};

#endif // GAME_STATE_H
