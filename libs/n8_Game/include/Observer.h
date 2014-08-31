/*
 *  Observer.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/20/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

#include "Event.h"

namespace n8{
    
/** \class Observer
 *  \brief Class to allow events to be handled in an uncoupled manner.  Follows the common Observer design pattern. 
 */
class Observer
{
public:
    virtual ~Observer() {}
    virtual void OnNotify(Event* event) = 0;
};
    
}

#endif /* defined(OBSERVER_H) */
