/*
 * MainMenu.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/18/14
 * Organization:    n8Tech
 *
 */

#include <iostream>

#include "MainMenu.h"
#include "GameValues.h"

using namespace std;

MainMenu::MainMenu(n8::Game* game) : n8::State(game), m_gui(nullptr),m_exitEvent(Test2), m_pushStateCommand(1) {
    
    m_inputService = game->getInputService();
    m_renderService = game->getRenderService();
    m_audioService = game->getAudioService();
    
    CreateSystems();
    CreateEntities();
    
    
    //build user interface
    m_font = (n8::Font*)(game->getResourceManager()->GetResource("stocky24"));
    
    m_gui = new gui::GUI(const_cast<n8::Window*>(m_renderService->GetWindow()),m_font);
    
    m_button1 = new gui::Button("playButton","Play", 230,440,160,40, [this](){
        m_pushStateCommand.execute();
    });
    
    
    m_label = new gui::Label("Tic Tac Toe", 350,0);
    
    
    m_gui->AddElement(m_button1);
    m_gui->AddElement(m_label);
    
    m_gui->Build();
    
    m_inputService->RegisterUserInterface(m_gui);
}

MainMenu::~MainMenu(){
    if (m_gui) {
       delete m_gui;
       m_gui = nullptr;
    }
}



void MainMenu::OnResume(){
    
    //register keyboard commands
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
    
//start music

    m_audioService->PlayMusic(static_cast<n8::Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::RESOURCES))->GetResource("scratch")));
    
    //m_audioService->PlaySoundEffect(static_cast<n8::SoundEffect*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("beat")));
}

void MainMenu::OnPause(){
    m_inputService->UnregisterKeyCommands();
    m_inputService->UnregisterMouseButtonDownAction();
    m_inputService->UnregisterMouseButtonUpAction();
    m_inputService->UnregisterMouseMoveAction();
    
    m_audioService->StopMusic();
}

void MainMenu::Update(Uint32 currentTime){
    if (m_gui){
        m_gui->Update(currentTime);
    }
}

void MainMenu::Render(n8::Window* p_window){
    m_renderService->SetDrawingColor(255, 0, 0, 255);  //set background color
    m_renderService->ColorBackground();  //color the background
    
    n8::Texture* background = (n8::Texture*)static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::RESOURCES))->GetResource("menuLogo");
    if ( background != nullptr){
        m_renderService->Draw(background, -20, -20, 680, 620);
    }
    
    
    
    
    if (m_gui) {
         m_gui->Draw(p_window);
    }
   
    m_renderService->PostToScreen();  //draw everything to the screen
                                              
}

void MainMenu::RegisterEntity(Entity* newEntity){ }

void MainMenu::CreateSystems(){ }

void MainMenu::CreateEntities(){ }
