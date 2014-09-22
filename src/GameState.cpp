//
//  TestState2.cpp
//  goobar
//
//  Created by Nate Ebel on 3/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GameState.h"

#define TAG "Game State"

GameState::GameState(n8::Game* game) : n8::State(game) {
    //m_id = new ID(GAME_STATE);
    
    CreateSystems();
    CreateEntities();
    
    m_inputService = game->getInputService();
    
    m_renderService = game->getRenderService();
    
    m_font = (n8::Font*)(game->getResourceManager()->GetResource("stocky24"));
    
    m_gui = new gui::GUI(const_cast<n8::Window*>(m_renderService->GetWindow()), m_font);
    
    int currentIndex = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m_gameBoardButtons[currentIndex] = new gui::Button("button"+to_string(currentIndex), " ",
                                                               100+100*j+j*10,
                                                               100+100*i+i*10,
                                                               100,100,
                                                               [this, currentIndex]( ){
                                                                   onBoardSquarePressed(currentIndex);
                                                                });
            
            m_gui->AddElement(m_gameBoardButtons[currentIndex]);
            currentIndex++;
        }
    }
    
    m_gui->RemoveElement(m_gameBoardButtons[8]);
    m_gui->Build();
    
    m_inputService->RegisterUserInterface(m_gui);

}

GameState::~GameState(){
    if (m_gui) {
        delete m_gui;
        m_gui = nullptr;
    }
}



void GameState::OnResume(){
    //Register input commands
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, &m_popStateCommand);
    
    //register mouse actions
    m_inputService->RegisterMouseMoveAction( [this](int x, int y){
        if (m_gui) {
            m_gui->CheckMove(x,y);
        }
    });
    
    m_inputService->RegisterMouseButtonUpAction( [this](int x, int y){
        if (m_gui) {
            m_gui->CheckClickUp(x, y);
        }
    });
    
    m_inputService->RegisterMouseButtonDownAction( [this](int x, int y){
        if (m_gui) {
            m_gui->CheckClickDown(x, y);
        }
    });
}
void GameState::OnPause(){
    //Unregister input commands
    
}

void GameState::Update(Uint32 currentTime){
    if (m_gui){
        m_gui->Update(currentTime);
    }
}
void GameState::Render(n8::Window* p_window){
    
    m_renderService->SetDrawingColor(0, 255, 0, 255);  //set background color
    m_renderService->ColorBackground();  //color the background
    
    if (m_gui) {
        m_gui->Draw(p_window);
    }
    
    if(goo != nullptr)
        m_renderService->Draw(goo, 100, 100);
    
    m_renderService->PostToScreen();  //draw everything to the screen
    
}

void GameState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void GameState::CreateEntities(){
    
    
}

void GameState::onBoardSquarePressed(int boardSquareIndex){
    n8::Log::Debug(TAG, "Board Square " + to_string(boardSquareIndex) + " was pressed");
    m_gameBoardButtons[boardSquareIndex]->setClickHandler(nullptr);
    m_gameBoardButtons[boardSquareIndex]->SetColor(gui::Style::EStyleColor::Button, 255, 100, 0);
}