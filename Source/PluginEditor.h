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
#include "../Library/Gui/TonerigSlider.h"


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
    Looks looks;
    DialLookAndFeel dialLookAndFeel;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> speedAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> phaseAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    
    Label titleLabel;
    Label waveHeader;
    
    tonerig::TonerigSlider speedDial;
    Label speedLabel;
    Label speedDisplay;
    
    ToggleButton syncButton;
    Label syncLabel;
    Label syncDisplay;
    
    tonerig::TonerigSlider phaseDial;
    Label phaseLabel;
    Label phaseDisplay;
    
    tonerig::TonerigSlider depthDial;
    Label depthLabel;
    Label depthDisplay;
    
    tonerig::TonerigSlider sinSlider;
    Label sinLabel;
    Label sinDisplay;
    
    tonerig::TonerigSlider triSlider;
    Label triLabel;
    Label triDisplay;
    
    tonerig::TonerigSlider sqrSlider;
    Label sqrLabel;
    Label sqrDisplay;
    
    tonerig::TonerigSlider noiseSlider;
    Label noiseLabel;
    Label noiseDisplay;
    
    tonerig::TonerigSlider balanceSlider;
    Label balanceLabel;
    Label balanceDisplay;
    
    Label tooltipLabel;
    TextButton infoButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
