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
    //assert(screen);
    
    SDL_FillRect(SDL_GetWindowSurface(p_window->GetWindow()), NULL, SDL_MapRGB(SDL_GetWindowSurface(p_window->GetWindow())->format, 0,200,0));
    /*
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = 25;
    offset.y = 25;
	
    SDL_Surface* img = static_cast<n8::ResourceManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->LoadImage("/Users/lcballa44/Projects/n8/Game/gfx/sayain2.png");
    
    //Blit the surface
    SDL_BlitSurface( img, NULL, SDL_GetWindowSurface(p_window), &offset );
    */
    
    
    //SDL_Flip(screen);
    //Update the surface
    SDL_UpdateWindowSurface( p_window->GetWindow() );
    
}

void GameState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void GameState::CreateEntities(){
    
    
}