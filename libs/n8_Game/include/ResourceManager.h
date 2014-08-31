/*
 *  ResourceManagerService.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "tinyxml2.h"

#include "Service.h"
#include "Event.h"
#include "Resource.h"
#include "Sprite.h"
#include "Texture.h"
#include "SoundEffect.h"
#include "Music.h"
#include "Font.h"
#include "Window.h"

//class Resource;

namespace n8{
    /** \class ResourceManager
     *  \brief Loads and stores game resources
     *
     *  Loads resource information from an xml file.  Attempts to load all
     *    specified data and store the neccessary resource objects using
     *    unique keys for lookup.  The user can then request pointers to
     *    resource objects when needed.
     */
    class ResourceManager : public Service{
    public:
        ResourceManager(Window* p_window, std::string p_path);
        ~ResourceManager();
        
        Resource* GetResource(std::string);
        
        
        
        void OnNotify(Event*);
        
    private:
        const std::string RESOURCES_TAG = "Resources";
        const std::string IMAGE_RESOURCES_TAG = "ImageResources";
        const std::string TEXTURE_RESOURCES_TAG = "TextureResources";
        const std::string SOUND_EFFECT_RESOURCES_TAG = "SoundEffectResources";
        const std::string MUSIC_RESOURCES_TAG = "MusicResources";
        const std::string FONT_RESOURCES_TAG = "FontResources";
        
        const std::string IMAGE_TAG = "Image";
        const std::string TEXTURE_TAG = "Texture";
        const std::string SOUND_EFFECT_TAG = "SoundEffect";
        const std::string MUSIC_TAG = "Music";
        const std::string FONT_TAG = "Font";
        
        const std::string SIZE_TAG = "Size";
        const std::string ID_TAG = "ID";
        
        const std::string RESOURCE_DIRECTORIES_PREFIX = "Resources";
        const std::string IMAGES_DIRECTORY_SUFFIX = "Images";
        const std::string TEXTURES_DIRECTORY_SUFFIX = "Textures";
        const std::string SOUND_EFFECT_DIRECTORY_SUFFIX = "SoundEffect";
        const std::string MUSIC_DIRECTORY_SUFFIX = "Music";
        const std::string FONT_DIRECTORY_SUFFIX = "Font";
        
        std::string m_resourcesListPath; /**< Filepath to the resource list */
        /*
        std::string m_imagesDirectoryPath;
        std::string m_texturesDirectoryPath;
        std::string m_audioDirectoryPath;
        */
        
        std::map<std::string,Resource*> m_loadedResources;  /**< Stores all images loaded by the system  */
        
        Window* m_gameWindow;
        //SDL_Surface* m_screenSurface;  /**< Stores pointer to the game's screen surface.  Used to load optimized versions of images */
        
        SDL_Surface* LoadOptimizedImage(std::string filename);
        
        void LoadResources();
        void LoadSprite(std::string, std::string);
        void LoadTexture(std::string, std::string);
        void LoadMusic(std::string, std::string);
        void LoadSoundEffect(std::string, std::string);
        void LoadFont(std::string, std::string,int);
    };
}

#endif /* defined(RESOURCE_MANAGER_SERVICE_H) */
