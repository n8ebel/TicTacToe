/*
 *  ResourceManagerService.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RESOURCE_MANAGER_SERVICE_H
#define RESOURCE_MANAGER_SERVICE_H

#include <iostream>
#include <string>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

#include "Service.h"
#include "Event.h"

namespace n8{
    class ResourceManagerService : public Service{
    public:
        ResourceManagerService(SDL_Surface* screen);
        ~ResourceManagerService();
        
        void LoadImagesFromFile(std::string filepath);
        SDL_Surface* LoadImage(std::string filename);
        
        void OnNotify(Event*);
        
    private:
        std::map<std::string,SDL_Surface*> m_loadedSprites;  /** < Stores all images loaded by the system  ***/
        
        SDL_Surface* m_screenSurface;
    };
}

#endif /* defined(RESOURCE_MANAGER_SERVICE_H) */
