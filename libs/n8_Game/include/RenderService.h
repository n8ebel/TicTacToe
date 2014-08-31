/*
 *  RenderService.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RENDER_SERVICE
#define RENDER_SERVICE

#include <iostream>
#include <assert.h>

#include "Service.h"
#include "Window.h"
#include "Sprite.h"
#include "Texture.h"
#include "LTexture.h"
#include "Font.h"
#include "Log.h"

namespace n8 {
    /** \class RenderService
     *  \brief Handles game rendering
     *
     *  This class handles rendering of game images by providing
     *   rendering methods for both sprites and texture.
     *
     *  @see Sprite, @see Texture
     */
    class RenderService : public Service{
    public:
        /** \enum ERenderMode
         *  \brief Indicates rendering modes
         *
         */
        enum ERenderMode{   ESprite, /**< Indicates sprite rendering mode with SDL_Surface **/
                            ETexture /**< Indicates texture rendering mode with SDL_Texture **/
                        };
        
        enum class EColor{Black,White};
        
        RenderService(Window*);
        ~RenderService();
        
        void SetRenderMode(ERenderMode);
        
        void OnNotify(Event*);
        
        void Draw(Sprite*, int, int);
        
        //renders texture at position with default size
        void Draw(Texture* p_texture, int p_x, int p_y);
        //renders texture over a specified area
        void Draw(Texture* p_texture, int p_x, int p_y, int p_w, int p_h);
        
        void DrawText(std::string p_text, Font* p_font, EColor p_color,int p_x, int p_y);
        
        void SetDrawingColor(int p_r, int p_g, int p_b, int p_a);
        
        void ColorBackground();
        void PostToScreen();
        
        const Window* GetWindow(){return m_gameWindow;}
        
    private:
        
        Window* m_gameWindow; /**< Pointer to the game window object **/
        ERenderMode m_renderMode; /**< The current rendering mode **/
        
        int m_red; /**< red value for drawing color **/
        int m_green; /**< green value for drawing color **/
        int m_blue; /**< blue value for drawing color **/
        int m_alpha; /**< alpha value for drawing color **/
        
    };
}

#endif /* defined(RENDER_SERVICE) */
