ArduinoDualLFO
==============

Use PWM, interrupts and simple low-pass filters on the output to create two simultaneous waveforms from an Arduino

The LFO's are designed to drive a Voltage-Controlled Oscillator (LFO2) and a Voltage-Controlled Amplitude module (LF01).
The particular settings of frequency and relative modulation are chosen for this application.

This sketch assumes that you have certain hardware hooked up to Arduio pins:

1 A switch for changing modes  
2 Two potentiometers and a switch for each LFO  
3 Two LEDs for displaying the mode (0-3)  

For more information on the physical connections, see the Fritzing files. I've included the native Fritzing file (Arduino Dual LFO.fzz) as well
as PNG copies of both the schematic and possible breadboard layout (PNG files).

The Arduino sketch is in the Dual_LFO folder. You can copy it to your Arduino Sketches folder. Or,
you can open the sketch directly from the Arduino IDE using File > Open...

