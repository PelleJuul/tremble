/*
  ==============================================================================

    DialLookAndFeel.h
    Created: 4 Jan 2018 10:37:39am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Looks.h"

class DialLookAndFeel : public LookAndFeel_V4
{
public:
    DialLookAndFeel(const Looks &looks);
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
    
private:
    const Looks &looks;
};
