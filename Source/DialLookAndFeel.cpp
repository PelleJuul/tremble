/*
  ==============================================================================

    DialLookAndFeel.cpp
    Created: 4 Jan 2018 10:37:39am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "DialLookAndFeel.h"
#include <cmath>

DialLookAndFeel::DialLookAndFeel(const Looks &looks) : looks(looks)
{
    
}
    
void DialLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    float margin = 2.0;
    x += margin;
    y += margin;
    width -= margin * 2;
    height -= margin * 2;
    
    float diameter = std::min(width, height);
    float angle = 3 * double_Pi / 4 + sliderPos * 1.5 * double_Pi;
    float cx = x + diameter / 2;
    float cy = y + diameter / 2;
    
    g.setColour(looks.mainColor);
    g.fillEllipse(x, y, diameter, diameter);
    g.setColour(looks.lightColor);
    g.drawEllipse(x, y, diameter, diameter, 4);
    float l = diameter / 4;
    float sina = std::sin(angle);
    float cosa = std::cos(angle);
    g.setColour(looks.darkColor);
    g.drawLine(cx + l * cosa, cy + l * sina, cx + (2 * l - 2.5) * cosa , cy + (2 * l - 2.5) * sina, 4);
}
