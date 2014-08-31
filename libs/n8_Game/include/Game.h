/*
 *  Game.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "tinyxml2.h"

#include "Values.h"
#include "Log.h"

#include "ServiceManager.h"
#include "RenderService.h"
#include "AudioService.h"
#include "InputService.h"
#include "StateManagerService.h"
#include "ResourceManager.h"

#include "State.h"

#include "Timer.h"
#include "Window.h"

#include "GUI.h"




namespace n8 {
    
    /** \class Game
     *  \brief Core class for n8 game framework.
     *
     *  Game is the core class for the n8 game framework.  It controls timing, setup, shutdown, and the game loop.  This class also initializes core game services using configuration files.
     */
class Game{
public:
    static const int DEFAULT_FPS = 200; /** < Defaul fps value */
    
    static void Init();
    static void Shutdown();
    
    Game(const char*);
    ~Game();
    
    void Setup();
    void Start();
    void Stop();
    
    void SetFPS(unsigned);
    void DefineWindowSize(unsigned, unsigned);
    
    void RegisterState(int, State*);
    void SetStartState(int);
private:
    const std::string RESOURCE_FILE_SUFFIX = "Resources.xml";;  /** < Default resource file name */
    
    ServiceManager* m_serviceManager; /** < Game service manager */
    n8::Window m_window; /** < Game window */
    n8::Timer m_timer; /** < Game timer */
     
    
    int m_fps;  /** < value to control game loop speed **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
    unsigned m_windowWidth;  /** < Width of the game window */
    unsigned m_windowHeight; /** < Height of the game window */
    
   // std::string m_configPath;
    std::string m_directoryPath;  /** < Path to the working directory of the project */
    std::string m_resourceConfigPath;
    //std::string m_resourcesListPath; /** < Full path to the resources directory */
    
    void ProcessConfigFile();
    
    void InitializeDirectoryPath();
    void InitializeResourcesPath();
    
};

}

#endif /* defined(GAME_H) */
