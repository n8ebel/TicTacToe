/*
 * InputBox.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/24/14
 * Organization:    n8Tech
 *
 */

#ifndef INPUT_BOX_H
#define INPUT_BOX_H

#include <iostream>
#include <string>

#include "GUIElement.h"
#include "LTexture.h"

namespace gui {
    
    /** \class InputBox
     *  \brief Gui element that allows a user to enter input, and then use or store that input.
     */
    class InputBox : public GUIElement{
    public:
        InputBox(int p_x, int p_y, int p_w, int p_h);
        InputBox(int p_x, int p_y, int p_w, int p_h, std::string p_hint);
        ~InputBox();
        
        void Build();
        void Draw(n8::Window*) override;
        
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove(int p_x, int p_y) override;
        virtual void HandleKeyboardInput(SDL_Event*);
        virtual bool Update(Uint32 p_currentTime) override;
        
        std::string GetText();
    
    private:
        const unsigned M_TEXT_OFFSET_X = 10;  /** < X offset for drawing text within the input region of the element */
        const unsigned M_TEXT_OFFSET_Y = 10;  /** < Y offset for drawing text within the input region of the element */
        const unsigned M_CURSOR_OFFSET_X = 2; /** < X offset for drawing cursor after drawn text */
        
        LTexture m_textTexture; /** < Texture used to draw input text */
        
        
        std::string m_hintString;  /** < String to hold hint message */
        std::string m_inputString; /** < Holds the user input */
        bool m_updateTexture;  /** < Flag to indicate if text texture needs updated */
        bool m_cursorShown;  /** < Flag to indicate if the cursor should be drawn */
        
        unsigned m_lastTime; /** < Tracks time since cursor was toggled on or off */
        
        void UpdateTexture(n8::Window*);
    };
}

#endif /* defined(INPUT_BOX_H) */
