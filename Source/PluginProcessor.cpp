/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TremoloAudioProcessor::TremoloAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
    #if ! JucePlugin_IsMidiEffect
        #if ! JucePlugin_IsSynth
                          .withInput  ("Input",  AudioChannelSet::stereo(), true)
        #endif
                          .withOutput ("Output", AudioChannelSet::stereo(), true)
    #endif
                      ),
#else
    :
#endif
    parameters(*this, nullptr)
{
    parameters.createAndAddParameter("speed",
                                     "speed",
                                     "Hz",
                                     NormalisableRange<float>(0.5, 10),
                                     4.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("phase",
                                     "phase",
                                     "rads",
                                     NormalisableRange<float>(0.0, 2.0 * M_PI),
                                     0.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("depth",
                                     "depth",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     0.5,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("sin",
                                     "sin",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     1.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("saw",
                                     "saw",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     0.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("sqr",
                                     "sqr",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     0.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("lfn",
                                     "lfn",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     0.0,
                                     nullptr,
                                     nullptr);
    parameters.createAndAddParameter("balance",
                                     "balance",
                                     "",
                                     NormalisableRange<float>(0.0, 1.0),
                                     0.5,
                                     nullptr,
                                     nullptr);
}

TremoloAudioProcessor::~TremoloAudioProcessor()
{
}

//==============================================================================
const String TremoloAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TremoloAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TremoloAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TremoloAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TremoloAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TremoloAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TremoloAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TremoloAudioProcessor::setCurrentProgram (int index)
{
}

const String TremoloAudioProcessor::getProgramName (int index)
{
    return {};
}

void TremoloAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TremoloAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    tremble.prepare(sampleRate);
}

void TremoloAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TremoloAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TremoloAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    AudioPlayHead *playHead = getPlayHead();
    
    if (playHead != nullptr)
    {
        juce::AudioPlayHead::CurrentPositionInfo currentPositionInfo;
        playHead->getCurrentPosition(currentPositionInfo);
        
        if (currentPositionInfo.isPlaying)
            time = currentPositionInfo.timeInSamples * 1.0 / getSampleRate();
    }
    
    tremble.speed = *parameters.getRawParameterValue("speed");
    tremble.phase = *parameters.getRawParameterValue("phase");
    tremble.depth = *parameters.getRawParameterValue("depth");
    tremble.sinAmp = *parameters.getRawParameterValue("sin");
    tremble.sawAmp = *parameters.getRawParameterValue("saw");
    tremble.sqrAmp = *parameters.getRawParameterValue("sqr");
    tremble.lfnAmp = *parameters.getRawParameterValue("lfn");
    tremble.balance = *parameters.getRawParameterValue("balance");

    int channel = 0;
    tremble.process(buffer.getWritePointer(channel), buffer.getNumSamples(), time);
    
    // Assume mono for now, but several tremble object should be created.
    for (int channel = 1; channel < totalNumInputChannels; ++channel)
    {
        buffer.copyFrom(channel, 0, buffer, 0, 0, buffer.getNumSamples());
    }
    
    time += buffer.getNumSamples() / getSampleRate();
}

inline float TremoloAudioProcessor::processSample(float x, float t, float speed, float phase, float depth) const
{
    float a = 1 - depth * 0.5 * (1 + sin(2 * M_PI * speed * t + phase));
    return x * a;
}

//==============================================================================
bool TremoloAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TremoloAudioProcessor::createEditor()
{
    return new TremoloAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void TremoloAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TremoloAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TremoloAudioProcessor();
}
