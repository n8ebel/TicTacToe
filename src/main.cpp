#include <iostream>

#include "Game.h"
#include "GameValues.h"
#include "MainMenu.h"
#include "GameState.h"
#include <functional>

int main(int argc, char * arg[])
{
    n8::Game::Init();
    n8::Game game("Resources.xml");
    game.DefineWindowSize(520, 520);
    game.Setup();
    
    MainMenu mainMenu(&game);
    GameState gameState(&game);
    
    game.RegisterState(0, &mainMenu);
    game.RegisterState(1, &gameState);
    
    game.SetStartState(0);
    
    game.Start();
    
    
    game.Stop();
    
    
    
    game.Shutdown();
    
    
    
    std::cout <<"main is finished" << std::endl;
    return EXIT_SUCCESS;
        
}

