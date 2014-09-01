//
//  TestState2.cpp
//  goobar
//
//  Created by Nate Ebel on 3/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {
    //m_id = new ID(GAME_STATE);
    
    CreateSystems();
    CreateEntities();
    
    m_inputService = static_cast<n8::InputService*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::INPUT));
    
    m_renderService = static_cast<n8::RenderService*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::RENDER));
}

GameState::~GameState(){
    
}



void GameState::OnResume(){
    //Register input commands
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, &m_popStateCommand);
}
void GameState::OnPause(){
    //Unregister input commands
    
}

void GameState::Update(Uint32 currentTime){
    
}
void GameState::Render(n8::Window* p_window){
    
    m_renderService->SetDrawingColor(0, 255, 0, 255);  //set background color
    m_renderService->ColorBackground();  //color the background
        
    
    m_renderService->PostToScreen();  //draw everything to the screen
    
}

void GameState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void GameState::CreateEntities(){
    
    
}