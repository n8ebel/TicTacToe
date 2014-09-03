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
    void onBoardSquarePressed(int);
    
    n8::InputService* m_inputService;
    n8::RenderService* m_renderService;
    n8::PopStateCommand m_popStateCommand;
    
    n8::Font* m_font;
    gui::GUI* m_gui;
    
    gui::Button* m_buttonTopLeft;
    gui::Button* m_buttonTopMiddle;
    gui::Button* m_buttonTopRight;
    
    gui::Button* m_buttonMiddleLeft;
    gui::Button* m_buttonMiddleMiddle;
    gui::Button* m_buttonMiddleRight;
    
    gui::Button* m_buttonBottomLeft;
    gui::Button* m_buttonBottomMiddle;
    gui::Button* m_buttonBottomRight;
    
    gui::Button* m_gameBoardButtons[9];
    
};

#endif // GAME_STATE_H
