/*
 *  Subject.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Observer.h"
#include "Event.h"

namespace n8{
    
/** \class Subject
 *  \brief Subjects inform other systems that an event has occured 
 *
 *  Subject acts as part of the observer pattern and allows other Observer objects to respond to events from a Subject.
 */
class Subject{
public:
    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    
    void Notify(Event*);

private:
    std::vector<Observer*> m_observers; /** < List of observers that can be notified of events > */
    
};
    
}

#endif /* defined(SUBJECT_H) */
