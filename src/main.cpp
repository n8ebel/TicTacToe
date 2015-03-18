#include <iostream>

#include "MainMenu.h"
#include "Game.h"

class foo{
public:
    std::string mName;
};

void delete_foo(foo*){
    
}

int main(int argc, char * arg[])
{
    auto game = std::make_shared<n8::Game>("Resources.xml");
    game->DefineWindowSize(520, 520);
    game->Init();


    n8::Log::TurnOffInfoMessages();

    game->StartState(std::make_shared<MainMenu>(game));

    game->Start();


    game->Stop();

    game->Shutdown();
    
    std::cout <<"main is finished" << std::endl;
    return EXIT_SUCCESS;
}