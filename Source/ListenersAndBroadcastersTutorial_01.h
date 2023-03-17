/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2020 - Raw Material Software Limited

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             ListenersAndBroadcastersTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores listeners and broadcasters.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2019, linux_make, xcode_iphone, androidstudio

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component,
public juce::Button::Listener // ~~ Add the button listener class to the maincomponent class ~~
{
public:
    //==============================================================================
//! [MainContentComponent constructor]
    MainContentComponent()
    {
        addAndMakeVisible (checkTheTimeButton);
        checkTheTimeButton.setButtonText ("Check the time...");
        // ~~ Register the listener object with the broadcaster ~~
        checkTheTimeButton.addListener(this);

        addAndMakeVisible (timeLabel);
        timeLabel.setColour (juce::Label::backgroundColourId, juce::Colours::black);
        timeLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        timeLabel.setJustificationType (juce::Justification::centred);
        
        // ~~ Me trying to do a date button on my own ~~
        addAndMakeVisible(checkTheDateButton);
        checkTheDateButton.setButtonText("Check the date...");
        checkTheDateButton.addListener(this);
        
        addAndMakeVisible(dateLabel);
        dateLabel.setColour (juce::Label::backgroundColourId, juce::Colours::black);
        dateLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        dateLabel.setJustificationType (juce::Justification::centred);
        

        setSize (600, 110);
    }
//! [MainContentComponent constructor]
    // ~~ The deconstructor wasn't declared ~~
    ~MainContentComponent()
    {
        // ~~ technically this will happen anyway  but for completeness ~~
        checkTheTimeButton.removeListener(this);
        checkTheDateButton.removeListener(this);
    }
    void resized() override
    {
        // ~~ I adjusted the orginal code inoder to accomodate my date button ~~
        checkTheTimeButton.setBounds (10, 10, getWidth() - 320, 40);
        timeLabel         .setBounds (10, 60, getWidth() - 320, 40);
        checkTheDateButton.setBounds (300, 10, getWidth() - 320, 40);
        dateLabel         .setBounds (300, 60, getWidth() - 320, 40);
    }
    
    // ~~ Declare the button click function ~~
    void buttonClicked (juce::Button* button) override
    {
        // ~~ Compare the button pointer to the address. use same button click for mutilple buttons ~~
        if (button == &checkTheTimeButton) // ~~ Time Button ~~
        {
            // ~~ Use the time class to get the current time from the operating system ~~
            auto currentTime = juce::Time::getCurrentTime();
            // ~~ Convert the Time object into a string ~~
            auto includeDate = false;
            auto includeTime = true;
            auto currentTimeString = currentTime.toString(includeDate, includeTime);
            // ~~ Update the text within the label ~~
            timeLabel.setText(currentTimeString, juce::dontSendNotification);
        }
        // ~~ Date Button ~~
        if (button == &checkTheDateButton)
        {
            // ~~ Use the time class to get the current date from the operating system ~~
            auto currentDate = juce::Time::getCurrentTime();
            // ~~ Convert the Time object into a string ~~
            auto includeDate = true;
            auto includeTime = false;
            auto currentDateString = currentDate.toString(includeDate, includeTime);
            // ~~ Update the text within the label ~~
            dateLabel.setText(currentDateString, juce::dontSendNotification);
        }
    }

private:
    // ~~  Adding a date button and label ~~
    juce::TextButton checkTheTimeButton, checkTheDateButton;
    juce::Label timeLabel, dateLabel;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
