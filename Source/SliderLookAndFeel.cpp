/*
  ==============================================================================

    SliderLookAndFeel.cpp
    Created: 4 Jan 2018 5:25:24pm
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "SliderLookAndFeel.h"

SliderLookAndFeel::SliderLookAndFeel(const Looks &looks) : looks(looks)
{

}

void SliderLookAndFeel::drawLinearSlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,const Slider::SliderStyle style, Slider &slider)
{
    x = 0;
    y = 0;
    width = slider.getWidth();
    height = slider.getHeight();
    
    g.setColour(looks.darkColor);
    g.fillRect(x, y, width, height);
    
    float pos = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
    float h = pos * height;
    g.setColour(looks.lightColor);
    g.fillRect((float)x, y + (height - h), (float)width, h);
    g.drawRect(x, y, width, height, 4);
}
