/*
  ==============================================================================

    ButtonLookAndFeel.h
    Created: 4 Jan 2018 8:25:04pm
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Looks.h"

class ButtonLookAndFeel : public LookAndFeel_V4
{
public:
    ButtonLookAndFeel(const Looks &looks);
    void drawToggleButton (Graphics &, ToggleButton &, bool isMouseOverButton, bool isButtonDown) override;
    
private:
    const Looks &looks;
};
