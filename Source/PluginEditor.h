/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "../Library/Gui/Gui.h"


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
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> speedAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> phaseAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    
    tonerig::Grid grid;
    tonerig::TonerigLabel titleLabel;
    tonerig::TonerigLabel titleLabelShadow;
    tonerig::TonerigLabel speedLabel;
    tonerig::TonerigLabel depthLabel;
    tonerig::TonerigLabel syncLabel;
    tonerig::TonerigLabel shapeLabel;
    tonerig::TonerigLabel phaseLabel;
    tonerig::TonerigSlider speedSlider;
    tonerig::TonerigSlider depthSlider;
    tonerig::TonerigButton syncButton;
    tonerig::TonerigSlider shapeSlider;
    tonerig::TonerigSlider phaseSlider;
    tonerig::Ruler ruler;
    tonerig::Logo logo;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
