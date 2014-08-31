/*
 * GUI.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>

#include "Window.h"
#include "Container.h"
#include "InputBox.h"
#include "Style.h"
#include "Button.h"
#include "GUIElement.h"
#include "Label.h"
#include "Widget.h"

namespace gui{
    
    /** \class GUI
     *  \brief Object used to define user interface
     *
     *  GUI allows gui elements to be added and interacted with.  Also maintains
     *  a style object to define how objects should look.
     */
    class GUI {
    public:
        GUI(n8::Window* p_window, n8::Font* p_font);
        ~GUI();
        
        void AddElement(GUIElement*);
        
        bool CheckClickDown(int p_x, int p_y);
        bool CheckClickUp(int p_x, int p_y);
        bool CheckMove(int p_x, int p_y);
        bool HasFocus();
        
        Style GetStyle(){return m_style;}
        
        void Build();
        void Draw(n8::Window*);
        void ProcessInput(SDL_Event*);
        bool Update(Uint32 p_currentTime);
    private:
        Style m_style;  /** < Style object used to maintain common style between added elements.  When elements are added to the gui, if they don't have their own style this element is used.  */
        
        std::vector<GUIElement*> m_guiElements; /** < List of gui elements that have been added and can be interacted with.  */
        
        bool m_built;  /** < Flag to determine if the gui has been built by the user. */
        bool m_hasFocus; /** < Flag to indicate if the gui has the user focus. */
    };
}

#endif /* defined(GUI_H) */
