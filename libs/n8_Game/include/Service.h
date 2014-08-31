/*
 *  Service.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <map>

#include "Values.h"
#include "Observer.h"
#include "Subject.h"

namespace n8 {

    /** \class Service
     *  \brief Abstract base class for Services.
     *
     *  Service implements both Subject and Observer allowing derived classes to act as both.
     */
class Service : public Subject, public Observer{
public:
    Service(){}
    virtual ~Service() {};
        
    virtual void OnNotify(Event* event) = 0;
    
protected:

};
    
}

#endif /* defined(SERVICE_H) */
