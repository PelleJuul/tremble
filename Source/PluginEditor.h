/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Looks.h"
#include "DialLookAndFeel.h"
#include "SliderLookAndFeel.h"
#include "ButtonLookAndFeel.h"
#include "Canvas.h"
#include "Tremble.h"
#include "../Library/Gui/Gui.h"
#include "Button.h"

//==============================================================================
/**
*/
class TremoloAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TremoloAudioProcessorEditor (TremoloAudioProcessor&, AudioProcessorValueTreeState &vts);
    ~TremoloAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TremoloAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    Tremble tremble;
    Looks looks;
    DialLookAndFeel dialLookAndFeel;
    SliderLookAndFeel sliderLookAndFeel;
    ButtonLookAndFeel buttonLookAndFeel;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> speedAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> phaseAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sinAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sawAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sqrAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfnAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> balAttachment;
    
    Label titleLabel;
    Canvas canvas;
    Label waveHeader;
    
    tonerig::TonerigSlider speedDial;
    Label speedLabel;
    tonerig::TonerigLabel speedDisplay;
    
    tnrg::Button syncButton;
    Label syncLabel;
    tonerig::TonerigLabel syncDisplay;
    
    tonerig::TonerigSlider phaseDial;
    Label phaseLabel;
    tonerig::TonerigLabel phaseDisplay;
    
    tonerig::TonerigSlider depthDial;
    Label depthLabel;
    tonerig::TonerigLabel depthDisplay;
    
    tonerig::TonerigSlider sinSlider;
    Label sinLabel;
    tonerig::TonerigLabel sinDisplay;
    
    tonerig::TonerigSlider sawSlider;
    Label triLabel;
    tonerig::TonerigLabel triDisplay;
    
    tonerig::TonerigSlider sqrSlider;
    Label sqrLabel;
    tonerig::TonerigLabel sqrDisplay;
    
    tonerig::TonerigSlider lfnSlider;
    Label noiseLabel;
    tonerig::TonerigLabel noiseDisplay;
    
    tonerig::TonerigSlider balanceSlider;
    Label balanceLabel;
    tonerig::TonerigLabel balanceDisplay;
    
    Label tooltipLabel;
    tonerig::TonerigLabel infoLink;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
