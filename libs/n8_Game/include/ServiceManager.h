/*
 *  ServiceManager.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <iostream>
#include <map>

#include "Singleton.h"
#include "Service.h"
#include "Values.h"

namespace n8{

/** \class ServiceManager
 *  \brief Global access point for game services.
 *
 *  Provides a global access point to registered services.
 *  This gives a less coupled way of providing access to 
 *  game systems.  Services are registered with the 
 *  ServiceManager during the game's initialization.
 */
class ServiceManager : public Singleton<ServiceManager>{ 
public:
    
    static const int RESOURCES = 0;
    static const int STATE_MANAGER = 1;
    static const int RENDER = 2;
    static const int AUDIO = 3;
    static const int LOGGING = 4;
    static const int AI = 5;
    static const int INPUT = 6;
    
    ServiceManager();
    ~ServiceManager();
    
    void RegisterService(int, Service*);
    void UnregisterService(int);
    
    void RemoveAllServices();
    
    Service* GetService(int);
    
private:
    std::map<int,Service*> m_registeredServices; /** < Map of registered services */
};
    
}

#endif /* defined(SERVICE_MANAGER_H) */
