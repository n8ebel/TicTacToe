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
#include "State.h"
#include "InputService.h"
#include "RenderService.h"

class GameState : public n8::State {
public:
    GameState(std::shared_ptr<n8::Game> game);
    virtual ~GameState();
    
    const std::string GetName() const {
        return "GameState";
    }
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render();
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    void onBoardSquarePressed(int);
    
    enum class Player { PLAYER1, PLAYER2};
    Player mCurrentPlayer;
    short mPlayerGameBoards[2];
    
    std::string PlayerToString(Player);
    void SwitchPlayer();
    
    std::shared_ptr<n8::InputService> m_inputService;
    std::shared_ptr<n8::RenderService> m_renderService;
    
    gui::Button* m_buttonTopLeft;
    gui::Button* m_buttonTopMiddle;
    gui::Button* m_buttonTopRight;
    
    gui::Button* m_buttonMiddleLeft;
    gui::Button* m_buttonMiddleMiddle;
    gui::Button* m_buttonMiddleRight;
    
    gui::Button* m_buttonBottomLeft;
    gui::Button* m_buttonBottomMiddle;
    gui::Button* m_buttonBottomRight;
    
    std::shared_ptr<gui::Button> m_gameBoardButtons[9];
    std::shared_ptr<gui::Label> m_label;
    
    bool CheckForWinner(short);
    void ResetGameboard();
    
};

#endif // GAME_STATE_H
