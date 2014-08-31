/*
 * Style.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/28/14
 * Organization:    n8Tech
 *
 */

#ifndef STYLE_H
#define STYLE_H

#include <iostream>

#include "Font.h"
#include "Color.h"
#include "Window.h"

namespace gui {
    
    /** \class Style
     *  \brief Defines default styles for gui elements
     *
     *  Defines default color and font styles for gui elements.
     */
    
    class Style{
    public:
        
        /** Enum for Style color elements
         *  Each enum represents an available color defined in the class.  These eneums are used to access particular color elements
         */
        enum class EStyleColor{ Container,
                                Button,
                                Hover,
                                Focus,
                                Pressed,
                                Font,
                                Hint,
                                InputBackground,
                                Cursor,
                                Default /** < Default enum value corresponding to default color */
        };
            
        
        Style(n8::Window* p_window, n8::Font* p_font);
        ~Style();
        
        void SetFont(n8::Font* p_font);
        
        void SetColor(EStyleColor p_color, int p_r, int p_g, int p_b);
        void SetColor(EStyleColor p_color, int p_r, int p_g, int p_b, int p_a);
        
        n8::Window* GetWindow();
        n8::Font* GetFont() const;
        
        n8::Color GetColor(EStyleColor p_color);
        
    
    private:
        const Uint8 DEFAULT_ALPHA = 255;
        
        n8::Window* m_window; /** < Pointer to window object */
        
        n8::Font* m_font;  /** < Pointer to a Font resource object */
        n8::Color m_containerColor;  /** < Color of gui container objects */
        
        n8::Color m_buttonColor;  /** < Base color for buttons in default state */
        n8::Color m_hoverColor;  /** < Color for buttons in the hover state */
        n8::Color m_pressedColor;  /** < Color for buttons that are pressed down */
        
        n8::Color m_fontColor;  /** < Color to render fonts */
        n8::Color m_hintColor;  /** < Color to render hint text of input boxes */
        
        n8::Color m_focusColor;  /** < Color used to indicate an element has focus */
        n8::Color m_inputBackgroundColor;  /** < Color used to render the text inputbox backgroudn */
        n8::Color m_cursorColor;  /** < Color for input box cursor */
        
        n8::Color m_defaultColor;  /** < Default element color */
        
    };
}


#endif /* defined(STYLE_H) */
