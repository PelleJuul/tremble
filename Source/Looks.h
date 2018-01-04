/*
  ==============================================================================

    Looks.h
    Created: 4 Jan 2018 9:40:05am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

struct Looks
{
    Looks();
    void setLabelLooks(Label *label);
    
    Font titleFont;
    Font headerFont;
    Font labelFont;
    Font displayFont;
    Font tooltipFont;
    Font infoFont;
    Colour darkColor;
    Colour lightColor;
    Colour mainColor;
};
