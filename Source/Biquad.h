/*
  ==============================================================================

    Biquad.h
    Created: 31 Jan 2018 9:51:22pm
    Author:  Pelle Juul  Christensen

  ==============================================================================
*/

#pragma once

enum FilterType
{
    LowPass
};

class Biquad
{
public:
    Biquad();
    void reset();
    void setCoefs(FilterType type, float sampleRate, float freq, float q);
    float process(float x);
    
private:
    float sampleRate;
    float x1;
    float x2;
    float y1;
    float y2;
    float a0;
    float a1;
    float a2;
    float b0;
    float b1;
    float b2;
};
