/*
 * Font.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/17/14
 * Organization:    n8Tech
 *
 */

#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <string>

#include "Resource.h"
#include "Log.h"

namespace n8{
    
    /** \class Font
     *  \brief Font resource used to render text.
     *
     *  Font wraps TTF.Font.  Used to render text to the screen.
     */
    class Font : public Resource{
    public:
        Font(std::string p_id, TTF_Font* p_ttfFont);
        ~Font();
        
        TTF_Font* GetFont();
        
    private:
        std::string m_id; /** < Identifier of the font */
        TTF_Font* m_font; /** < The loaded font data */
        
        friend class RenderService;
    };
    
}

#endif /* defined(FONT_H) */