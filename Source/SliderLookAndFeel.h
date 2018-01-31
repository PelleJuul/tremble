/*
  ==============================================================================

    SliderLookAndFeel.h
    Created: 4 Jan 2018 5:25:24pm
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Looks.h"

class SliderLookAndFeel : public LookAndFeel_V4
{
public:
    SliderLookAndFeel(const Looks &looks);
    void drawLinearSlider (Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,const Slider::SliderStyle, Slider &) override;
    
private:
    const Looks &looks;
};
