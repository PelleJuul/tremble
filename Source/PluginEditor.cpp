/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "DialLookAndFeel.h"
#include "../Library/Gui/Gui.h";

//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p, AudioProcessorValueTreeState &vts)
    : AudioProcessorEditor (&p),
    processor (p),
    valueTreeState(vts),
    dialLookAndFeel(looks),
    sliderLookAndFeel(looks),
    buttonLookAndFeel(looks)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << (tremble.rng.nextFloat() * 2.0 - 1) << std::endl;
    }
    
    
    titleLabel.setFont(looks.titleFont);
    titleLabel.setColour(Label::textColourId, looks.lightColor);
    titleLabel.setBounds(30, 30, 400, 72);
    titleLabel.setText("TREMBLE", dontSendNotification);
    titleLabel.setJustificationType(Justification::centredLeft);
    addAndMakeVisible(titleLabel);
    
    waveHeader.setFont(looks.headerFont);
    waveHeader.setColour(Label::textColourId, looks.darkColor);
    waveHeader.setBounds(440, 43, 190, 22);
    waveHeader.setText("wave", dontSendNotification);
    waveHeader.setJustificationType(Justification::centredRight);
    addAndMakeVisible(waveHeader);
    
    tremble.speed = 1;
    tremble.balance = 0.5;
    tremble.sinAmp = 1.0;
    tremble.sawAmp = 0.0;
    tremble.sqrAmp = 0.0;
    canvas.setBounds(630, 45, 50, 18);
    canvas.onPaint = [&](Graphics &g)
    {
        float sampleRate = 1000.0;
        tremble.rng.setSeed(42);
        tremble.prepare(sampleRate);
        tremble.speed = 1.0;
        float h = canvas.getHeight() / 2.0 - 2.0;
        Path p;
        p.startNewSubPath(0, canvas.getHeight() / 2.0 + h * tremble.rawWave(0));
        
        for (int x = 0; x < canvas.getWidth(); x += 2.0)
        {
            float t = (x / (float)canvas.getWidth());
            float w = tremble.rawWave(t);
            float y = canvas.getHeight() / 2.0 + h * w;
            p.lineTo(x, y);
        }
        
        g.setColour(looks.darkColor);
        g.strokePath(p, PathStrokeType(2.0, PathStrokeType::JointStyle::curved));
    };
    canvas.repaint();
    addAndMakeVisible(canvas);
    
    // Speed
    looks.setLabelLooks(&speedLabel);
    speedLabel.setBounds(30, 115, 80, 18);
    speedLabel.setText("speed", NotificationType::dontSendNotification);
    addAndMakeVisible(speedLabel);
    
    speedDial.setLookAndFeel(&dialLookAndFeel);
    speedDial.setBoundsWithMargin(2, 30, 150, 80, 80);
    addAndMakeVisible(speedDial);
    
    looks.setDisplayLooks(&speedDisplay);
    speedDisplay.setBounds(30, 245, 80, 14);
    speedDial.addListener(&speedDisplay);
    addAndMakeVisible(speedDisplay);
    
    // Sync
    looks.setLabelLooks(&syncLabel);
    syncLabel.setBounds(130, 115, 60, 18);
    syncLabel.setText("sync", NotificationType::dontSendNotification);
    addAndMakeVisible(syncLabel);
    
    // syncButton.setLookAndFeel(&buttonLookAndFeel);
    // syncButton.setClickingTogglesState(true);
    syncButton.isToggleMode = true;
    syncButton.setBounds(150 - 2, 170 - 2, 20 + 4, 40 + 4);
    syncButton.onStateChanged = [&]()
    {
        if (syncButton.state)
            syncDisplay.setText("on", NotificationType::dontSendNotification);
        else
            syncDisplay.setText("off", NotificationType::dontSendNotification);
    };
    syncButton.onStateChanged();
    addAndMakeVisible(syncButton);
    
    looks.setDisplayLooks(&syncDisplay);
    syncDisplay.setBounds(140, 245, 40, 14);
    addAndMakeVisible(syncDisplay);
    
    // Phase
    looks.setLabelLooks(&phaseLabel);
    phaseLabel.setBounds(210, 115, 80, 18);
    phaseLabel.setText("phase", NotificationType::dontSendNotification);
    addAndMakeVisible(phaseLabel);
    
    phaseDial.setLookAndFeel(&dialLookAndFeel);
    phaseDial.setBoundsWithMargin(2, 210, 150, 80, 80);
    phaseDial.onValueChanged = [&]()
    {
        tremble.phase = phaseDial.getValue();
        canvas.repaint();
        phaseDisplay.setText(String(phaseDial.getValue(), 1), dontSendNotification);
    };
    phaseDial.onValueChanged();
    addAndMakeVisible(phaseDial);
    
    looks.setDisplayLooks(&phaseDisplay);
    phaseDisplay.setBounds(210, 245, 80, 14);
    addAndMakeVisible(phaseDisplay);
    
    // Depth
    looks.setLabelLooks(&depthLabel);
    depthLabel.setBounds(320, 115, 80, 18);
    depthLabel.setText("depth", NotificationType::dontSendNotification);
    addAndMakeVisible(depthLabel);
    
    depthDial.setLookAndFeel(&dialLookAndFeel);
    depthDial.setBoundsWithMargin(2, 320, 150, 80, 80);
    addAndMakeVisible(depthDial);
    
    looks.setDisplayLooks(&depthDisplay);
    depthDisplay.setBounds(320, 245, 80, 14);
    depthDial.addListener(&depthDisplay);
    addAndMakeVisible(depthDisplay);
    
    // Wave/sin
    looks.setAltLabelLooks(&sinLabel);
    sinLabel.setBounds(460, 76, 40, 18);
    sinLabel.setText("sin", NotificationType::dontSendNotification);
    addAndMakeVisible(sinLabel);
    
    sinSlider.setSliderStyle(Slider::LinearVertical);
    sinSlider.setLookAndFeel(&sliderLookAndFeel);
    sinSlider.setBoundsWithMargin(2, 460, 110, 40, 120);
    sinSlider.setRange(0.0, 1.0);
    sinSlider.setValue(1.0);
    sinSlider.onValueChanged = [&]()
    {
        tremble.sinAmp = sinSlider.getValue();
        canvas.repaint();
    };
    sinSlider.onValueChanged();
    addAndMakeVisible(sinSlider);
    
    looks.setAltDisplayLooks(&sinDisplay);
    sinDisplay.setBounds(460, 245, 40, 14);
    sinSlider.addListener(&sinDisplay);
    addAndMakeVisible(sinDisplay);
    
    // Wave/tri
    looks.setAltLabelLooks(&triLabel);
    triLabel.setBounds(530, 76, 40, 18);
    triLabel.setText("tri", NotificationType::dontSendNotification);
    addAndMakeVisible(triLabel);
    
    sawSlider.setSliderStyle(Slider::LinearVertical);
    sawSlider.setLookAndFeel(&sliderLookAndFeel);
    sawSlider.setBoundsWithMargin(2, 530, 110, 40, 120);
    sawSlider.setRange(0.0, 1.0);
    sawSlider.onValueChanged = [&]()
    {
        tremble.sawAmp = sawSlider.getValue();
        canvas.repaint();
    };
    sawSlider.onValueChanged();
    addAndMakeVisible(sawSlider);
    
    looks.setAltDisplayLooks(&triDisplay);
    triDisplay.setBounds(530, 245, 40, 14);
    sawSlider.addListener(&triDisplay);
    addAndMakeVisible(triDisplay);
    
    // Wave/sqr
    looks.setAltLabelLooks(&sqrLabel);
    sqrLabel.setBounds(600, 76, 40, 18);
    sqrLabel.setText("sqr", NotificationType::dontSendNotification);
    addAndMakeVisible(sqrLabel);
    
    sqrSlider.setSliderStyle(Slider::LinearVertical);
    sqrSlider.setLookAndFeel(&sliderLookAndFeel);
    sqrSlider.setBoundsWithMargin(2, 600, 110, 40, 120);
    sqrSlider.setRange(0.0, 1.0);
    sqrSlider.onValueChanged = [&]()
    {
        tremble.sqrAmp = sqrSlider.getValue();
        canvas.repaint();
    };
    sqrSlider.onValueChanged();
    addAndMakeVisible(sqrSlider);
    
    looks.setAltDisplayLooks(&sqrDisplay);
    sqrDisplay.setBounds(600, 245, 40, 14);
    sqrSlider.addListener(&sqrDisplay);
    addAndMakeVisible(sqrDisplay);
    
    // Wave/lfn
    looks.setAltLabelLooks(&noiseLabel);
    noiseLabel.setBounds(680, 76, 40, 18);
    noiseLabel.setText("lfn", NotificationType::dontSendNotification);
    addAndMakeVisible(noiseLabel);
    
    lfnSlider.setSliderStyle(Slider::LinearVertical);
    lfnSlider.setLookAndFeel(&sliderLookAndFeel);
    lfnSlider.setBoundsWithMargin(2, 680, 110, 40, 120);
    lfnSlider.onValueChanged = [&]()
    {
        tremble.lfnAmp = lfnSlider.getValue();
        canvas.repaint();
    };
    addAndMakeVisible(lfnSlider);
    
    looks.setAltDisplayLooks(&noiseDisplay);
    noiseDisplay.setBounds(680, 245, 40, 14);
    lfnSlider.addListener(&noiseDisplay);
    addAndMakeVisible(noiseDisplay);
    
    // Wave/lfn
    looks.setAltLabelLooks(&balanceLabel);
    balanceLabel.setBounds(750, 76, 40, 18);
    balanceLabel.setText("bal", NotificationType::dontSendNotification);
    addAndMakeVisible(balanceLabel);
    
    balanceSlider.setSliderStyle(Slider::LinearVertical);
    balanceSlider.setLookAndFeel(&sliderLookAndFeel);
    balanceSlider.setBoundsWithMargin(2, 750, 110, 40, 120);
    balanceSlider.setRange(0, 1.0);
    balanceSlider.setValue(0.5);
    balanceSlider.onValueChanged = [&]()
    {
        tremble.balance = balanceSlider.getValue();
        canvas.repaint();
    };
    balanceSlider.onValueChanged();
    addAndMakeVisible(balanceSlider);
    
    looks.setAltDisplayLooks(&balanceDisplay);
    balanceDisplay.setBounds(750, 245, 40, 14);
    balanceSlider.addListener(&balanceDisplay);
    addAndMakeVisible(balanceDisplay);
    
    tooltipLabel.setFont(looks.tooltipFont);
    tooltipLabel.setColour(Label::textColourId, looks.lightColor);
    tooltipLabel.setBounds(30, 288, 500, 60);
    tooltipLabel.setJustificationType(Justification::topLeft);
    tooltipLabel.setText("Point at a control to view tooltip", NotificationType::dontSendNotification);
    addAndMakeVisible(tooltipLabel);
    
    infoLink.setFont(looks.infoFont);
    infoLink.setColour(TextButton::textColourOnId, looks.lightColor);
    infoLink.setBounds(620, 288, 200, 60);
    infoLink.setJustificationType(Justification::topRight);
    infoLink.setText("TONERIG A01", NotificationType::dontSendNotification);
    infoLink.onMouseUp = [&]() {
        URL url("http://tonerig");
        url.launchInDefaultBrowser();
    };
    addAndMakeVisible(infoLink);
    
    speedAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "speed", speedDial);
    phaseAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "phase", phaseDial);
    depthAttachment = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "depth", depthDial);
    sinAttachment   = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "sin", sinSlider);
    sawAttachment   = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "saw", sawSlider);
    sqrAttachment   = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "sqr", sqrSlider);
    lfnAttachment   = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lfn", lfnSlider);
    balAttachment   = new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "balance", balanceSlider);
    
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
    g.setColour(looks.lightColor);
    g.drawLine(660, 110, 660, 110 + 120, 2);
    g.drawLine(110, 190, 110 + 40, 190, 2);
}

void TremoloAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
