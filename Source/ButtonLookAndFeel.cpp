/*
  ==============================================================================

    ButtonLookAndFeel.cpp
    Created: 4 Jan 2018 8:25:04pm
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "ButtonLookAndFeel.h"

ButtonLookAndFeel::ButtonLookAndFeel(const Looks &looks) : looks(looks)
{

}

void ButtonLookAndFeel::drawToggleButton (Graphics &g, ToggleButton &button, bool isMouseOverButton, bool isButtonDown)
{
    float margin = 2.0;
    float x = margin;
    float y = margin;
    float width = button.getWidth() - margin * 2;
    float height = button.getHeight() - margin * 2;
    
    if (button.getToggleState())
        g.setColour(looks.positiveColor);
    else
        g.setColour(looks.darkColor);
    g.fillRoundedRectangle(x, y, width, height, width / 2);
    g.setColour(looks.lightColor);
    g.drawRoundedRectangle(x, y, width, height, width / 2, 4.0);
    
    float diameter = width;
    float circleY = y;
    
    if (button.getToggleState()) {
        circleY = height - diameter;
    }
    
    g.setColour(looks.mainColor);
    g.fillEllipse(x, circleY, diameter, diameter);
    g.setColour(looks.lightColor);
    g.drawEllipse(x, circleY, diameter, diameter, 4.0);
}
