/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "DialLookAndFeel.h"

//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p, AudioProcessorValueTreeState &vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts), dialLookAndFeel(looks)
{
    titleLabel.setFont(looks.titleFont);
    titleLabel.setColour(Label::textColourId, looks.lightColor);
    titleLabel.setBounds(30, 35, 400, 72);
    titleLabel.setText("TREMBLE", dontSendNotification);
    titleLabel.setJustificationType(Justification::centredLeft);
    addAndMakeVisible(titleLabel);
    
    waveHeader.setFont(looks.headerFont);
    waveHeader.setColour(Label::textColourId, looks.darkColor);
    waveHeader.setBounds(597, 43, 57, 22);
    waveHeader.setText("wave", dontSendNotification);
    waveHeader.setJustificationType(Justification::centred);
    addAndMakeVisible(waveHeader);
    
    looks.setLabelLooks(&speedLabel);
    speedLabel.setBounds(30, 115, 80, 18);
    speedLabel.setText("speed", NotificationType::dontSendNotification);
    addAndMakeVisible(speedLabel);
    
    speedDial.setLookAndFeel(&dialLookAndFeel);
    speedDial.setBounds(30, 150, 80, 80);
    addAndMakeVisible(speedDial);
    
    looks.setLabelLooks(&phaseLabel);
    phaseLabel.setBounds(210, 115, 80, 18);
    phaseLabel.setText("phase", NotificationType::dontSendNotification);
    addAndMakeVisible(phaseLabel);
    
    phaseDial.setLookAndFeel(&dialLookAndFeel);
    phaseDial.setBounds(210, 150, 80, 80);
    addAndMakeVisible(phaseDial);
    
    looks.setLabelLooks(&depthLabel);
    depthLabel.setBounds(320, 115, 80, 18);
    depthLabel.setText("depth", NotificationType::dontSendNotification);
    addAndMakeVisible(depthLabel);
    
    depthDial.setLookAndFeel(&dialLookAndFeel);
    depthDial.setBounds(320, 150, 80, 80);
    addAndMakeVisible(depthDial);
    
    setSize(850, 320);
}

TremoloAudioProcessorEditor::~TremoloAudioProcessorEditor()
{

}

//==============================================================================
void TremoloAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(looks.darkColor);
    g.setColour(looks.mainColor);
    g.fillRoundedRectangle(430, 30, 390, 240, 4);
}

void TremoloAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
