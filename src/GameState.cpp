//
//  TestState2.cpp
//  goobar
//
//  Created by Nate Ebel on 3/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GameState.h"
#include "MainMenu.h"

#define TAG "Game State"

GameState::GameState(n8::Game* game) : n8::State(game) {
    
    
    CreateSystems();
    CreateEntities();
    
    m_inputService = game->getInputService();
    
    m_renderService = game->getRenderService();
    
    n8::Window* window = const_cast<n8::Window*>(m_renderService->GetWindow());
    
    m_font = (n8::Font*)(game->getResourceManager()->GetResource("stocky24"));
    
    int currentIndex = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m_gameBoardButtons[currentIndex] = new gui::Button(window,
                                                               "button"+to_string(currentIndex), " ",
                                                               100+100*j+j*10,
                                                               100+100*i+i*10,
                                                               100,100,
                                                               nullptr);
            GetGUI()->AddElement(m_gameBoardButtons[currentIndex]);
            currentIndex++;
        }
    }
    
    ResetGameboard();

}

GameState::~GameState(){
    State::~State();
}



void GameState::OnResume(){
    //Register input commands
    m_inputService->RegisterKeyDownAction(SDLK_ESCAPE, [this](){m_game->EndState();});
}
void GameState::OnPause(){
    m_inputService->UnregisterMouseButtonDownAction();
    m_inputService->UnregisterMouseButtonUpAction();
}

void GameState::Update(Uint32 currentTime){
    GetGUI()->Update(currentTime);
}
void GameState::Render(n8::Window* p_window){
    
    m_renderService->SetDrawingColor(0, 255, 0, 255);  //set background color
    m_renderService->ColorBackground();  //color the background
    
    State::Render(p_window);
    
}

void GameState::CreateSystems(){ }

void GameState::CreateEntities(){ }

void GameState::onBoardSquarePressed(int boardSquareIndex){
    n8::Log::Debug(TAG, "Board Square " + to_string(boardSquareIndex) + " was pressed by " + PlayerToString(mCurrentPlayer));
    
    // Remove the click handler for the pressed board space
    m_gameBoardButtons[boardSquareIndex]->setClickHandler(nullptr);
    
    // Update the draw color of the clicked space to indicate who clicked it
    if (mCurrentPlayer == Player::PLAYER1) {
        m_gameBoardButtons[boardSquareIndex]->SetColor(gui::Style::EStyleColor::Selected, 255, 100, 0);
        mPlayerGameBoards[static_cast<int>(mCurrentPlayer)] |= 1 << boardSquareIndex;
        n8::Log::Debug(TAG, std::to_string(mPlayerGameBoards[static_cast<int>(mCurrentPlayer)]));
    }else if (mCurrentPlayer == Player::PLAYER2){
        m_gameBoardButtons[boardSquareIndex]->SetColor(gui::Style::EStyleColor::Selected, 255, 100, 100);
        mPlayerGameBoards[static_cast<int>(mCurrentPlayer)] |= 1 << boardSquareIndex;
        n8::Log::Debug(TAG, std::to_string(mPlayerGameBoards[static_cast<int>(mCurrentPlayer)]));
    }
    
    if(CheckForWinner(mPlayerGameBoards[static_cast<int>(mCurrentPlayer)])){
        n8::Log::Debug(TAG, PlayerToString(mCurrentPlayer) + " won!!");
        
        gui::Dialog::Builder* builder = new gui::Dialog::Builder(const_cast<n8::Window*>(m_renderService->GetWindow()));
        builder->SetHeight(300);
        builder->SetPositiveButton("Play Again", 120, 40, [this](){
            ResetGameboard();
        });
        builder->SetNegativeButton("Menu", 120, 40, [this](){
            m_game->EndState();
        });
        
        GetGUI()->ShowDialog(builder->SetTitle(PlayerToString(mCurrentPlayer) + " won!!")->Create());
    }
    
    // Update the current player
    SwitchPlayer();
    
}

std::string GameState::PlayerToString(Player player){
    switch (player) {
        case Player::PLAYER1:
            return "Player 1";
            break;
        case Player::PLAYER2:
            return "Player 2";
        default:
            return "No Player";
            break;
    }
}

void GameState::SwitchPlayer(){
    if (mCurrentPlayer == Player::PLAYER1) {
        mCurrentPlayer = Player::PLAYER2;
    }else if(mCurrentPlayer == Player::PLAYER2){
        mCurrentPlayer = Player::PLAYER1;
    }
}

bool GameState::CheckForWinner(short playerBoard){
    if(    (((playerBoard & 1 << 0) != 0) && ((playerBoard & 1 << 1) != 0) && ((playerBoard & 1 << 2) != 0)) ||
           (((playerBoard & 1 << 3) != 0) && ((playerBoard & 1 << 4) != 0) && ((playerBoard & 1 << 5) != 0)) ||
           (((playerBoard & 1 << 6) != 0) && ((playerBoard & 1 << 7) != 0) && ((playerBoard & 1 << 8) != 0)) ||
           (((playerBoard & 1 << 0) != 0) && ((playerBoard & 1 << 3) != 0) && ((playerBoard & 1 << 6) != 0)) ||
           (((playerBoard & 1 << 1) != 0) && ((playerBoard & 1 << 4) != 0) && ((playerBoard & 1 << 7) != 0)) ||
           (((playerBoard & 1 << 2) != 0) && ((playerBoard & 1 << 5) != 0) && ((playerBoard & 1 << 8) != 0)) ||
           (((playerBoard & 1 << 0) != 0) && ((playerBoard & 1 << 4) != 0) && ((playerBoard & 1 << 8) != 0)) ||
           (((playerBoard & 1 << 6) != 0) && ((playerBoard & 1 << 4) != 0) && ((playerBoard & 1 << 2) != 0)) 
       
       
    )
    {
        return true;
    }
    
    return false;
}

void GameState::ResetGameboard(){
    // Set the starting player
    mCurrentPlayer = Player::PLAYER1;
    
    mPlayerGameBoards[0] = 0;
    mPlayerGameBoards[1] = 0;
    
    int currentIndex = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m_gameBoardButtons[currentIndex]->setClickHandler([this, currentIndex]( ){
                onBoardSquarePressed(currentIndex);
            });
            m_gameBoardButtons[currentIndex]->SetColor(gui::Style::EStyleColor::Button, 250, 250, 50);
            m_gameBoardButtons[currentIndex]->SetState(gui::GUIElement::State::Neutral);
            currentIndex++;
        }
    }
}