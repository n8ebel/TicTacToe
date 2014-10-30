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

#include "Game.h"

#include "GameState.h"

class Entity;

class MainMenu : public n8::State {
public:
    MainMenu(n8::Game* game);
    virtual ~MainMenu();
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(n8::Window* window);
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    
    virtual void CreateSystems();
    virtual void CreateEntities();
    
    n8::InputService* m_inputService;
    n8::RenderService* m_renderService;
    n8::AudioService* m_audioService;
    
    n8::Event m_exitEvent;
    
    n8::Font* m_font;
    gui::GUI* m_gui;
    gui::Button* m_button1;
    gui::Button* m_button2;
    gui::Container* m_toolbar;
    gui::InputBox* m_inputBox;
    gui::Label* m_label;
    
};
#endif // MAIN_MENU_H