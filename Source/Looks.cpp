/*
  ==============================================================================

    Looks.cpp
    Created: 4 Jan 2018 9:40:05am
    Author:  Pelle Juul Christensen

  ==============================================================================
*/

#include "Looks.h"
#include "../JuceLibraryCode/JuceHeader.h"
/*
auto darkColor = Colour::Colour(0xFF323232);
auto lightColor = Colour::Colour(0xFFe5e5e4);
auto mainColor = Colour::Colour(0xFFfcb614);

auto titleFont = Font("Helvetica", 64, Font::bold | Font::italic);
auto titleFont2 = Font("Helvetica Bold Oblique", 64, Font::plain);
auto subtitleFont = Font("sans", 20, Font::bold | Font::italic);
auto labelFont = Font("sans", 16, Font::bold | Font::italic);
auto displayFont = Font("sans", 13, Font::italic);
auto tooltipFont = Font("sans", 14, Font::italic);
auto infoFont = tooltipFont;
*/

Looks::Looks()
{
    darkColor = Colour::Colour(0xFF323232);
    lightColor = Colour::Colour(0xFFe5e5e4);
    mainColor = Colour::Colour(0xFFffb700);
    positiveColor = Colour::Colour(0xFF19a974);

    auto montserratBlackItalic = Typeface::createSystemTypefaceFor(
        BinaryData::MontserratBlackItalic_otf,
        BinaryData::MontserratBlackItalic_otfSize);
    auto montserratBoldItalic = Typeface::createSystemTypefaceFor(
        BinaryData::MontserratBoldItalic_otf,
        BinaryData::MontserratBoldItalic_otfSize);
    auto montserratMediumItalic = Typeface::createSystemTypefaceFor(
        BinaryData::MontserratMediumItalic_otf,
        BinaryData::MontserratMediumItalic_otfSize);
    
    auto fontScale = 1.2;
    
    titleFont = Font(montserratBlackItalic);
    titleFont.setHeight(fontScale * 64);
    titleFont.setExtraKerningFactor(0.02);
    
    headerFont = Font(montserratBoldItalic);
    headerFont.setHeight(fontScale * 20);
    headerFont.setExtraKerningFactor(0.02);
    
    labelFont = Font(montserratMediumItalic);
    labelFont.setHeight(fontScale * 16);
    
    displayFont = Font(montserratMediumItalic);
    displayFont.setHeight(fontScale * 12);
    
    tooltipFont = Font(montserratBoldItalic);
    tooltipFont.setHeight(fontScale * 14);
    
    infoFont = Font(montserratBoldItalic);
    infoFont.setHeight(fontScale * 14);
}

void Looks::setLabelLooks(Label *label)
{
    label->setFont(labelFont);
    label->setColour(Label::textColourId, lightColor);
    label->setJustificationType(Justification::centred);
}

void Looks::setAltLabelLooks(Label *label)
{
    label->setFont(labelFont);
    label->setColour(Label::textColourId, darkColor);
    label->setJustificationType(Justification::centred);
}

void Looks::setDisplayLooks(Label *label)
{
    label->setFont(displayFont);
    label->setColour(Label::textColourId, lightColor);
    label->setJustificationType(Justification::centred);
}

void Looks::setAltDisplayLooks(Label *label)
{
    label->setFont(displayFont);
    label->setColour(Label::textColourId, darkColor);
    label->setJustificationType(Justification::centred);
}
