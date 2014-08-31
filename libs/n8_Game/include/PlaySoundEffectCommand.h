/*
 *  PlaySoundEffectCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef PLAY_SOUNDEFFECT_COMMAND_H
#define PLAY_SOUNDEFFECT_COMMAND_H

#include <iostream>
#include <string>

#include "Command.h"
#include "AudioService.h"
#include "ServiceManager.h"
#include "ResourceManager.h"
#include "SoundEffect.h"

namespace n8{
    /** \class PlaySoundEffectCommand
     *  \brief Plays sound effects on execution
     */
    class PlaySoundEffectCommand : public Command {
        
    public:
        PlaySoundEffectCommand(std::string p_effectID);
        
        ~PlaySoundEffectCommand();
        virtual bool execute();
        
    private:
        std::string m_effectID;
        
    };
    
}



#endif /* defined(PLAY_SOUNDEFFECT_COMMAND_H) */
