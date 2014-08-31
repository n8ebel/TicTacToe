/*
 *  PopStateCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef __DevApp__PopStateCommand__
#define __DevApp__PopStateCommand__

#include <iostream>

#include "Command.h"
#include "StateManagerService.h"
#include "ServiceManager.h"

namespace n8{
    
    /** \class PopStateCommand
     *  \brief  A reusable command to pop a state off the game's state stack
     */
    class PopStateCommand : public Command {
    
public:
    PopStateCommand();
    
    ~PopStateCommand();
    virtual bool execute() override;
    
private:
    
    
};

}



#endif /* defined(__DevApp__PopStateCommand__) */
