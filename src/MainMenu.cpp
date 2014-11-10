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
#include "GameState.h"

#define TAG "MainMenu"

using namespace std;

MainMenu::MainMenu(n8::Game* game) : n8::State(game),m_exitEvent(Test2) {
    
    m_inputService = game->getInputService();
    m_renderService = game->getRenderService();
    m_audioService = game->getAudioService();
    game->getResourceManager();
    game->getStateManagerService();
    
    CreateSystems();
    CreateEntities();
    
    n8::Window* window = const_cast<n8::Window*>(m_renderService->GetWindow());

    //build user interface
    m_font = (n8::Font*)(game->getResourceManager()->GetResource("stocky24"));
    
    std::string playerName;
    
    m_button1 = new gui::Button(window, "playButton","Play", 180,370,160,40, [this, &playerName](){
        gui::InputDialog::Builder builder(const_cast<n8::Window*>(m_renderService->GetWindow()));
        builder.SetTitle("Enter Your Name");
        builder.SetHintText("Enter name...");
        builder.SetHeight(300);
        builder.SetPositiveButton("Enter", 120, 40, nullptr);
        builder.SetOnDismissListener([&](gui::Dialog::EResultCode result){
            if (result == gui::Dialog::EResultCode::POSITIVE){
                m_game->StartState(new GameState(m_game));
            }
        });

        gui::InputDialog* inputDialog = (gui::InputDialog*) builder.Create();
        inputDialog->SetOnPositiveClickedListener([inputDialog](){
            cout << inputDialog->GetX() << endl;
            inputDialog->GetInput();
        });
        
        GetGUI()->ShowDialog(inputDialog);
    });
    
    m_label = new gui::Label(window, "label", "Tic Tac Toe", 350,0);
    
    
    GetGUI()->AddElement(m_button1);
    GetGUI()->AddElement(m_label);
    
}

MainMenu::~MainMenu(){
    State::~State();
}



void MainMenu::OnResume(){
    
    //register keyboard commands
    m_inputService->RegisterKeyDownAction(SDLK_ESCAPE, [this](){m_game->EndState();});
    
//start music

    //m_audioService->PlayMusic(static_cast<n8::Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::RESOURCES))->GetResource("beat")));
    
    //m_audioService->PlaySoundEffect(static_cast<n8::SoundEffect*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("beat")));
}

void MainMenu::OnPause(){
    m_inputService->UnregisterKeyActions();
    m_inputService->UnregisterMouseButtonDownAction();
    m_inputService->UnregisterMouseButtonUpAction();
    m_inputService->UnregisterMouseMoveAction();
    
    m_audioService->StopMusic();
}

void MainMenu::Update(Uint32 currentTime){
    GetGUI()->Update(currentTime);
}

void MainMenu::Render(n8::Window* p_window){
    m_renderService->SetDrawingColor(255, 0, 0, 255);  //set background color
    m_renderService->ColorBackground();  //color the background
    
    n8::Texture* background = (n8::Texture*)static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::RESOURCES))->GetResource("menuLogo");
    if ( background != nullptr){
        m_renderService->Draw(background, -20, -20, 680, 620);
    }
   
    State::Render(p_window);
    
}

void MainMenu::RegisterEntity(Entity* newEntity){ }

void MainMenu::CreateSystems(){ }

void MainMenu::CreateEntities(){ }
