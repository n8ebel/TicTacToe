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

#include "Game.h"
#include "MainMenu.h"
#include "GameValues.h"
#include "GameState.h"

#define TAG "MainMenu"

using namespace std;

MainMenu::MainMenu(shared_ptr<n8::Game> game) : n8::State(game),m_exitEvent(Test2) {
    
    m_inputService = game->getInputService();
    m_renderService = game->getRenderService();
    m_audioService = game->getAudioService();
    game->getResourceManager();
    game->getStateManagerService();
    
    CreateSystems();
    CreateEntities();
    
    auto window = m_game->getWindow();
    
    //build user interface
    auto font = game->getResourceManager()->GetFont("stocky24");
    
    std::string playerName;
    
    m_button1 = std::make_shared<gui::Button>(static_pointer_cast<n8::Window>(window), "playButton","Play", 180,370,160,40, [this, &playerName](){
        
        gui::InputDialog::Builder builder(static_pointer_cast<n8::Window>(m_game->getWindow()));
        builder.SetTitle("Enter Your Name");
        builder.SetHintText("Enter name...");
        builder.SetHeight(300);
        builder.SetPositiveButton("Enter", 120, 40, nullptr);
        builder.SetOnDismissListener([&](gui::Dialog::EResultCode result){
            if (result == gui::Dialog::EResultCode::POSITIVE){
                m_game->StartState(std::make_shared<GameState>(m_game));
            }
        });

        auto inputDialog = static_pointer_cast<gui::InputDialog>(builder.Create());
        inputDialog->SetOnPositiveClickedListener([this, inputDialog](){
            inputDialog->GetInput();
        });
        
        GetGUI()->ShowDialog(inputDialog);
    });
    
    m_label = std::make_shared<gui::Label>(static_pointer_cast<n8::Window>(window), "label", "Tic Tac Toe", 350,0);
    
    std::shared_ptr<n8::Texture> texture = game->getResourceManager()->GetTexture("logo");
    auto logoImage = std::make_shared<gui::ImageView>(static_pointer_cast<n8::Window>(window),
                                                                "",
                                                                texture, 50, 50, 100, 100);
    
    auto sayainTexture = game->getResourceManager()->GetTexture("sayainTexture");
    auto sayain = std::make_shared<gui::ImageView>(static_pointer_cast<n8::Window>(window),
                                                     "",
                                                     game->getResourceManager()->GetTexture("sayainTexture"), 150, 150, 100, 100);
    GetGUI()->AddElement(m_button1);
    GetGUI()->AddElement(m_label);
    GetGUI()->AddElement(logoImage);
    GetGUI()->AddElement(sayain);
    
    
}

MainMenu::~MainMenu(){
    std::cout << "Main Menu State Destructor Called" << std::endl;
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
    State::Update(currentTime);
}

void MainMenu::Render(){
    m_renderService->ColorBackground(255, 0, 0);  //color the background
    
    State::Render();
}

void MainMenu::RegisterEntity(Entity* newEntity){ }

void MainMenu::CreateSystems(){ }

void MainMenu::CreateEntities(){ }
