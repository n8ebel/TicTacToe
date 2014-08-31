/*
 *  Rectangle.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/28/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "SDL2/SDL.h"

/** \class Rectangle
 *  \brief Wraps SDL_Rect
 *
 *  Stores rectangular coordinates used to determine the shape of many elements
 */
namespace n8 {
    class Rectangle{
    public:
        Rectangle();
        Rectangle(int p_x, int p_y, int p_w, int p_h);
        ~Rectangle();
        
        void Reposition(int p_x, int p_y);
        void Resize(int p_width, int p_height);
        void Offset(int p_xOffset, int p_yOffset);
        void RepositionAndResize(int p_x, int p_y, int p_w, int p_h);
        int GetX();
        int GetY();
        int GetW();
        int GetH();
        SDL_Rect* GetRect();
        
    private:
        SDL_Rect m_rectangle; /** < SDL_Rect object that is wrapped by class.  Needed by many SDL_functions **/
    };
}

#endif /* defined(RECTANGLE_H) */
