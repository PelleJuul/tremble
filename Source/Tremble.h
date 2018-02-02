/*
  ==============================================================================

    Tremble.h
    Created: 4 Jan 2018 9:40:14am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Biquad.h"

float balancedSin(float x, float r);
float balancedTri(float x, float r);
float balancedSqr(float x, float r);

class Tremble
{
    public:
    float sampleRate;
    float speed;
    float phase;
    float depth;
    float sinAmp;
    float sawAmp;
    float sqrAmp;
    float lfnAmp;
    float lfnCutoff;
    float balance;
    Random rng;
    Biquad lfnFilter;
    Biquad outputFilter;
    
    Tremble();
    float rawWave(float t);
    void prepare(float sampleRate);
    void process(float *buffer, int bufferSize, float t);
};
