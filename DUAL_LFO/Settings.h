// Settings 

// Comment out the following #define to deactivate SYNC input(s)
// Specify whether HIGH or LOW is the trigger state using "TRIGGER" constants
// To use a common pin for syncing both LFOs, define SYNC_COMMON (uncomment the #define)
// The common pin/trigger are taken from SYNC1

#define SYNC
#if defined(SYNC)
//#define SYNC_COMMON
const byte SYNC1_PIN =            6;
const byte SYNC1_TRIGGER =        HIGH;
const byte SYNC2_PIN =            4;
const byte SYNC2_TRIGGER =        HIGH;
#endif

// Uncomment this to initialize and update a user-supplied display
//#define DISPLAY

// KNOBS (analog pins)

const byte FREQ1_KNOB_PIN =         0;
const byte DEPTH1_KNOB_PIN =        4;

const byte FREQ2_KNOB_PIN =         1;
const byte DEPTH2_KNOB_PIN =        5;

// SWITCHES (digital pins)

const byte WAVE1_SWITCH_PIN =      10;
const byte WAVE2_SWITCH_PIN =      12;

// LFO SETTINGS
const double LFO1_FREQ_MIN =      0.1;
const double LFO1_FREQ_MAX =      100;

const double LFO2_FREQ_MIN =      0.1;
const double LFO2_FREQ_MAX =      100;
