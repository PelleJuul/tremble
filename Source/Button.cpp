/*
  ==============================================================================

    Button.cpp
    Created: 6 Jan 2018 1:10:26am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "Button.h"

namespace tnrg
{
    Button::Button()
    {
    }

    Button::Button(const Looks &looks) : looks(looks)
    {
    }

    void Button::paint(Graphics &g)
    {
        float margin = 2.0;
        float x = margin;
        float y = margin;
        float width = getWidth() - margin * 2;
        float height = getHeight() - margin * 2;
        
        if (state)
            g.setColour(looks.positiveColor);
        else
            g.setColour(looks.darkColor);
            
        g.fillRoundedRectangle(x, y, width, height, width / 2);
        g.setColour(looks.lightColor);
        g.drawRoundedRectangle(x, y, width, height, width / 2, 4.0);
        
        float diameter = width;
        float circleY = y;
        
        if (state) {
            circleY = height - diameter;
        }
        
        g.setColour(looks.mainColor);
        g.fillEllipse(x, circleY, diameter, diameter);
        g.setColour(looks.lightColor);
        g.drawEllipse(x, circleY, diameter, diameter, 4.0);
    }

    void Button::mouseUp(const MouseEvent &e)
    {
        if (!isToggleMode)
        {
            onStateChanged();
            state = false;
        }
    }
    
    void Button::mouseDown(const MouseEvent &e)
    {
        state = !state;
        onStateChanged();
        repaint();
    }
};
