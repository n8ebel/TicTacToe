/*
 * Label.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/27/14
 * Organization:    n8Tech
 *
 */

#ifndef LABEL_H
#define LABEL_H

#include <iostream>

#include "GUIElement.h"

#include "Window.h"
#include "Log.h"

namespace gui {
    
    /** \class Label
     *  \brief A drawable text element
     */
class Label : public GUIElement{
    public:
        enum class EColor{Black,White};
    
        Label(std::string p_text, int p_x, int p_y);
        ~Label();
    
        virtual void Build() override;
        virtual void Draw(n8::Window*) override;
        virtual bool CheckMouseClickDown(int p_x, int p_y)override;
        virtual bool CheckMouseClickUp(int p_x, int p_y)override;
        virtual bool CheckMouseMove(int p_x, int p_y) override;
        virtual bool Update(Uint32 p_currentTime)override;
        
        void OffsetPosition(int p_x, int p_y) override;
    protected:
        LTexture m_textTexture; /** < Texture used to store text */
        std::string m_labelText; /** < String holding the text to render */
    
    };
}

#endif /* defined(LABEL_H) */
