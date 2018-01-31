/*
  ==============================================================================

    Tremble.cpp
    Created: 4 Jan 2018 9:40:14am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "Tremble.h"
#include <cmath>

float balancedSin(float x, float r)
{
    float w = std::fmod(x, 2 * M_PI);
    
    if (r >= 1.0)
        return std::sin(w / 2.0);
    else if (r <= 0.0)
        return -std::sin(w / 2.0);
        
    float fp = 1 / (2 * r);
    float fn = 1 / (2 * (1 - r));
    float p = r / (1-r);
    float s = p < 1 ? 1 : 1 / p;
    
    if (w < 2 * M_PI * r)
        return p * s * std::sin(w * fp);
    else
        return -s * std::sin(w * fn - p * M_PI);
}
/*
def mapRange(x, oldMin, oldMax, newMin, newMax):
    r = (x - oldMin) / (oldMax - oldMin) 
    return newMin + r * (newMax - newMin)
    */

float mapRange(float x, float oldMin, float oldMax, float newMin, float newMax)
{
    float r = (x - oldMin) / (oldMax - oldMin);
    return newMin + r * (newMax - newMin);
}

float balancedTri(float x, float r)
{
    float pi = M_PI;
    float w = fmod(x, 2 * pi);
    float p = r / (1- r);
    float s = 1;
    
    if (r > 0.5)
    {
        r = 1 - r;
        w = 2 * pi - w;
        p = 1 / p;
        s = -s;
    }
    
    if (w < 2 * pi * r)
        return s * p * mapRange(w, 0, 2 * pi * r, 1, 0);
    else
        return s * mapRange(w, 2 * pi * r, 2 * pi, 0, -1);
}

float balancedSqr(float x, float r)
{
    float w = std::fmod(x, 2 * M_PI);
    float p = r / (1 - r);
    
    if (r > 0.5)
        p = 1 / p;

    if (w < 2 * M_PI * r)
        return p;
    else
        return -1;
}

Tremble::Tremble()
{
    speed = 0;
    phase = 0.0;
    depth = 0.5;
    sinAmp = 1.0;
    sawAmp = 0.0;
    sqrAmp = 0.0;
    lfnAmp = 0.0;
    lfnCutoff = 10.0;
    balance = 0.5;
}

inline float Tremble::rawWave(float t)
{
    float w = 2 * M_PI * t * speed + phase;
    float sinWave = balancedSin(w, balance);
    float triWave = balancedTri(w, balance);
    float sqrWave = balancedSqr(w, balance);
    auto lfnCoefs = IIRCoefficients::makeLowPass(sampleRate, std::fmax(lfnCutoff, 0.0001));
    lfnFilter.setCoefficients(lfnCoefs);
    float r = rng.nextFloat();
    float lfnWave = r; //lfnFilter.processSingleSampleRaw(r);
    float ampTotal = sinAmp + sawAmp + sqrAmp; // + lfnAmp;
    
    if (ampTotal == 0)
        return 0;

    float y = sinWave * (sinAmp / ampTotal)
            + triWave * (sawAmp / ampTotal)
            + sqrWave * (sqrAmp / ampTotal);
            // + lfnWave * (lfnAmp / ampTotal);
    
    return y;
}

void Tremble::prepare(float sampleRate)
{
    if (sampleRate != this->sampleRate)
    {
        auto outputCoefs = IIRCoefficients::makeLowPass(sampleRate, 100);
        outputFilter.setCoefficients(outputCoefs);
        
        auto lfnCoefs = IIRCoefficients::makeLowPass(sampleRate, lfnCutoff);
        lfnFilter.setCoefficients(lfnCoefs);
        this->sampleRate = sampleRate;
    }
}

void Tremble::process(float *buffer, int bufferSize, float time)
{
    auto outputCoefs = IIRCoefficients::makeLowPass(sampleRate, speed + 5);
    outputFilter.setCoefficients(outputCoefs);
    
    for (int i = 0; i < bufferSize; i++)
    {
        float x = buffer[i];
        float t = time + i / sampleRate;
        float w = rawWave(t);
        w = outputFilter.processSingleSampleRaw(w);
        float a = 1 - depth * 0.5 * (1 + w);
        buffer[i] = a * x;
    }
}
