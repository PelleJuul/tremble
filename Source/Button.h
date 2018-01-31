/*
  ==============================================================================

    Button.h
    Created: 6 Jan 2018 1:10:26am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Looks.h"
#include <functional>
#include "../Library/Gui/Gui.h"

namespace tnrg
{
    class Button : public juce::Component
    {
        public:
            bool state;
            bool isToggleMode;
            std::function<void()> onStateChanged;
            std::function<void(Button &btn)> displayFunc;
            Label display;
        
            Button();
            Button(const Looks &looks);
        
            void paint(Graphics &g) override;
        
        protected:
            Looks looks;
            void mouseUp(const MouseEvent &e) override;
            void mouseDown(const MouseEvent &e) override;
    };
}
