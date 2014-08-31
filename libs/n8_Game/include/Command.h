//
//  Command.h
//  DevApp
//
//  Created by Nate Ebel on 4/13/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "Event.h"

namespace n8{
    
    /** \class Command
     *  \brief Abstract base class for reusable objects that encapsulate functions in an object.
     *
     *  Command objects provide an execute method that allow a peice of logic or functionality to be carried out at a specified time such as on a button click.  This offers similar functionality to lambda functions, but can be reused across states, and can be reassigned to things like buttons or key presses.
     */
class Command
{
public:
    virtual ~Command() {}
    virtual bool execute() = 0;
};
    
}


#endif
