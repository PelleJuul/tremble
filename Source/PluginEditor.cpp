/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "../../Library/Tonerig.h"


//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p, AudioProcessorValueTreeState &vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
    // Make attachments
    //speedAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "speed", sliderSpeed);
    //phaseAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "phase", sliderPhase);
    //depthAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "depth", sliderDepth);
    
    float marginX = 15;
    float marginY = 10;
    float labelHeight = 25;
    float mainDialSize = 100;
    float smallDialSize = 60;
    float mainDialDivide = 30;
    float topRowWidth = mainDialSize * 2 + mainDialDivide;
    
    float x = marginX;
    float y = marginY;
    
    titleLabel.setBounds(x, y, topRowWidth, labelHeight);
    titleLabel.setFont(Font("Georgia", 28, Font::italic));
    titleLabel.setText("Tremolo", NotificationType::dontSendNotification);
    addAndMakeVisible(titleLabel);
    
    titleLabelShadow.setBounds(x + 2, y + 2, topRowWidth, labelHeight);
    titleLabelShadow.setFont(Font("Georgia", 28, Font::italic));
    titleLabelShadow.setText("Tremolo", NotificationType::dontSendNotification);
    titleLabelShadow.setColour(Label::ColourIds::textColourId, tonerig::Colors::highlight);
    addAndMakeVisible(titleLabelShadow);
    titleLabel.toFront(false);
    
    x = marginX;
    y += titleLabel.getHeight() + 10;
    speedLabel.setBounds(x, y, mainDialSize, labelHeight);
    speedLabel.setText("Speed", NotificationType::dontSendNotification);
    addAndMakeVisible(speedLabel);
    
    x += mainDialSize + mainDialDivide;
    depthLabel.setBounds(x, y, mainDialSize, labelHeight);
    depthLabel.setText("Depth", NotificationType::dontSendNotification);
    addAndMakeVisible(depthLabel);
    
    x = marginX;
    y += labelHeight;
    speedSlider.setBounds(x, y, mainDialSize, mainDialSize);
    addAndMakeVisible(speedSlider);
    
    x += mainDialSize + mainDialDivide;
    depthSlider.setBounds(x, y, mainDialSize, mainDialSize);
    addAndMakeVisible(depthSlider);
    
    float outerDist = (topRowWidth - smallDialSize * 3) / 4.0;
    float innerDist = (topRowWidth - smallDialSize * 3 - outerDist * 2) / 2.0;
    x = marginX + outerDist;
    y += mainDialSize + 15;
    syncLabel.setBounds(x, y, smallDialSize, labelHeight);
    syncLabel.setText("Sync", NotificationType::dontSendNotification);
    addAndMakeVisible(syncLabel);
    
    x += smallDialSize + innerDist;
    phaseLabel.setBounds(x, y, smallDialSize, labelHeight);
    phaseLabel.setText("Phase", NotificationType::dontSendNotification);
    addAndMakeVisible(phaseLabel);
    
    x += smallDialSize + innerDist;
    shapeLabel.setBounds(x, y, smallDialSize, labelHeight);
    shapeLabel.setText("Shape", NotificationType::dontSendNotification);
    addAndMakeVisible(shapeLabel);
    
    x = marginX + outerDist;
    y += labelHeight;
    syncButton.setBounds(x, y, smallDialSize, smallDialSize);
    syncButton.setClickingTogglesState(true);
    addAndMakeVisible(syncButton);
    
    x += smallDialSize + innerDist;
    phaseSlider.setBounds(x, y, smallDialSize, smallDialSize);
    addAndMakeVisible(phaseSlider);
    
    x += smallDialSize + innerDist;
    shapeSlider.setBounds(x, y, smallDialSize, smallDialSize);
    addAndMakeVisible(shapeSlider);
    
    float rulerHeight = 1;
    y += smallDialSize + marginY + 5;
    x = 0;
    ruler.setBounds(x, y, topRowWidth + marginX * 2, rulerHeight);
    addAndMakeVisible(ruler);
    
    float logoSize = 30;
    y += 5;
    x = marginX + topRowWidth / 2.0 - logoSize / 2.0;
    logo.setBounds(x, y, logoSize, logoSize);
    addAndMakeVisible(logo);
    
    y += logoSize + 5;
    setSize(topRowWidth + marginX * 2, y);
}

TremoloAudioProcessorEditor::~TremoloAudioProcessorEditor()
{
}

//==============================================================================
void TremoloAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(tonerig::Colors::backgroud);

}

void TremoloAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
