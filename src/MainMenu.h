/*
 * MainMenu.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/18/14
 * Organization:    n8Tech
 *
 */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <vector>

#include "State.h"
#include "InputService.h"
#include "RenderService.h"
#include "AudioService.h"

class Entity;

class MainMenu : public n8::State {
public:
    MainMenu(std::shared_ptr<n8::Game> game);
    virtual ~MainMenu();
    
    const std::string GetName() const {
        return "MainMenuState";
    }
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render();
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    
    virtual void CreateSystems();
    virtual void CreateEntities();
    
    std::shared_ptr<n8::InputService> m_inputService;
    std::shared_ptr<n8::RenderService> m_renderService;
    std::shared_ptr<n8::AudioService> m_audioService;
    
    n8::Event m_exitEvent;
    
    std::shared_ptr<gui::Button> m_button1;
    gui::Button* m_button2;
    gui::Container* m_toolbar;
    gui::InputBox* m_inputBox;
    std::shared_ptr<gui::Label> m_label;
    
};
#endif // MAIN_MENU_H