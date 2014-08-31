/*
 *  PushStateCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef PUSH_STATE_COMMAND_H
#define PUSH_STATE_COMMAND_H

#include <iostream>

#include "Command.h"
#include "StateManagerService.h"
#include "ServiceManager.h"
#include "Values.h"

namespace n8{

    /** \class PushStateCommand
     *  \brief Reusable command to push a state onto the state stack
     */
class PushStateCommand : public Command {
    
public:
    PushStateCommand(int);
    
    ~PushStateCommand();
    virtual bool execute() override;
    
private:
    int m_state; /** < Enumerated state identifier */
    
    
};

}



#endif /* defined(__DevApp__PopStateCommand__) */
