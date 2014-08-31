/*
 *  PlayMusicCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef PLAY_MUSIC_COMMAND_H
#define PLAY_MUSIC_COMMAND_H

#include <iostream>
#include <string>

#include "Command.h"
#include "AudioService.h"
#include "ServiceManager.h"
#include "ResourceManager.h"
#include "Music.h"

namespace n8{
    
    class PlayMusicCommand : public Command {
        
    public:
        PlayMusicCommand(std::string p_musID);
        
        ~PlayMusicCommand();
        virtual bool execute();
        
    private:
        std::string m_musicID;
        
    };
    
}



#endif /* defined(PLAY_MUSIC_COMMAND_H) */
