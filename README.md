# ArduinoDualLFO
---

ArduinoDualLFO uses PWM, interrupts and simple low-pass filters on output pins to create two simultaneous waveforms from an Arduino. The initial design was intended to provide LFO control signals for a musical instrument.

## What's New in V2.0

In V2.0 of ArduinoDualLFO, the LFOs are much more generic and suitable in a wider range of applications.

Changes include:

* Code has been restructured for clarity
* *Settings.h* provides an easy way to control some parameters and compilation options
* A *trigger* input has been added to restart both LFOs at zero
* LFO modes have been removed
* Depth now control has much better resolution
* Improved frequency tracking with the LFO frequency knob

## Description

ArduinoDualLFO assumes that you have certain hardware hooked up to Arduio pins:

* Two potentiometers and a switch for each LFO (frequency, depth, waveform)
* Floating input pin for the trigger input (the default state is determined on startup. Trigger is activated when the state changes)

For more information on the physical connections, see the Fritzing files. I've included the native Fritzing file (Arduino Dual LFO.fzz) as well
as PDF copies the schematic and breadboard layout.

The Arduino sketch is in the Dual_LFO folder. You can copy it to your Arduino Sketches folder. Or,
you can open the sketch directly from the Arduino IDE using File > Open...

Also included is an Excel worksheet that calculates the various waveforms used in the LFOs. Sample data is copied
from the worksheet by selecting the relevant column and copy/pasting it to a sketch header (with variable definition
before and after the data -- see the other wave headers for reference). You can use the worksheet to calculate and add your own waveforms.

