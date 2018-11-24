# ArduinoDualLFO
---

ArduinoDualLFO uses PWM, interrupts and simple low-pass filters on output pins to create two simultaneous waveforms from an Arduino. The initial design was intended to provide LFO control signals for a musical instrument.

## What's New in V2.0

In V2.0 of ArduinoDualLFO, the LFOs are much more generic and suitable in a wider range of applications.

Changes include:

* Code has been restructured for clarity
* *Settings.h* provides an easy way to control some parameters and compilation options
* LFO1 and LFO2 can now be more easily customized using *Settings.h*
* A *trigger* input has been added to restart both LFOs at zero
* Mode display using LEDs can be deactivated in *Settings.h*
* If the mode display is active, the startup eye-candy can be deactivated (LEDs flash until the *mode* button is pressed)
* New modes have been implemented (controlled by the "mode" switch) to replace the ones in V1.0. The new modes are:
	* 0: Both LFO1/LFO2 are normal
	* 1: LFO1 is inverted, LFO2 is normal
	* 2: LFO1 is normal, LFO2 is inverted
	* 3: Both LFO1/LFO2 are inverted
* Depth now control has much better resolution
* Improved frequency tracking with the LFO frequency knob

## Description

ArduinoDualLFO assumes that you have certain hardware hooked up to Arduio pins:

1. A switch for changing modes. Each press cyclically increments the mode.
2. Two potentiometers and a switch for each LFO (frequency, depth, waveform)
3. Two LEDs for displaying the mode (0-3)
4. Floating input pin for the trigger input (the default state is determined on startup. Trigger is activated when the state changes)

For more information on the physical connections, see the Fritzing files. I've included the native Fritzing file (Arduino Dual LFO.fzz) as well
as PDF copies the schematic and breadboard layout.

The Arduino sketch is in the Dual_LFO folder. You can copy it to your Arduino Sketches folder. Or,
you can open the sketch directly from the Arduino IDE using File > Open...

Also included is an Excel worksheet that calculates the various waveforms used in the LFOs. Sample data is copied
from the worksheet by selecting the relevant column and copy/pasting it to a sketch header (with variable definition
before and after the data -- see the other wave headers for reference). You can use the worksheet to calculate and add your own waveforms.

