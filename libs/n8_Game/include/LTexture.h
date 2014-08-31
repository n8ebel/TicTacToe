//
//  LTexture.h
//  DevApp
//
//  Created by Nate Ebel on 4/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__LTexture__
#define __DevApp__LTexture__

#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( SDL_Renderer* p_renderer, std::string path );
    
    //Creates image from font string
    bool loadFromRenderedText( SDL_Renderer* p_renderer,TTF_Font* p_font, std::string textureText, SDL_Color textColor );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render( SDL_Renderer* p_renderer,int x, int y );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
    bool HasTexture();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif /* defined(__DevApp__LTexture__) */
