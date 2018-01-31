/*
  ==============================================================================

    Canvas.h
    Created: 7 Jan 2018 10:03:32pm
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <functional>

class Canvas : public Component
{
    public:
        std::function<void(Graphics &g)> onPaint;
        void paint(Graphics &g) override;
};
