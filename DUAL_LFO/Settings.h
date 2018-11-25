// Settings 


// Comment out the following #define to deactivate the trigger input
// Change default state for trigger polarity (default of LOW means trigger HIGH)
#define SYNC
#if defined(SYNC)
const byte SYNC1_PIN =            6;
const byte SYNC1_TRIGGER =        CS_Switch::SWITCH_HIGH;
const byte SYNC2_PIN =            6;
const byte SYNC2_TRIGGER =        CS_Switch::SWITCH_HIGH;

  #if (SYNC1_PIN == SYNC2_PIN)
    #define COMMON_SYNC
  #endif
#endif

// Optional LED Display of Modes (0-3), and startup eye-candy
// Un-commenting the LEDMODEDISPLAY define, will enable LED Mode Display
// A number of consequtive pins (deifned below) will be used to display mode
// in binary format.
// Additionally, if you want the startup eye-candy to run until you press the Mode button,
// un-comment the STARTUPEYECANDY define.
//#define LEDMODEDISPLAY
#if defined(LEDMODEDISPLAY)
//#define STARTUPEYECANDY
const byte MODE_DISPLAY_PIN =       7;
const byte NUM_MODE_DISPLAY_PINS =  2;
#endif

// PERFORMANCE MODES
#define NUM_PERFORMANCE_MODES 4
#define PM_NORMAL    0
#define PM_INVERT1   1
#define PM_INVERT2   2
#define PM_INVERTALL 3

// Pins related to performance modes (digital pins)
const byte MODE_SWITCH_PIN =        9;

// KNOBS (analog pins)

const byte FREQ_KNOB1_PIN =         0;
const byte DEPTH_KNOB1_PIN =        4;

const byte FREQ_KNOB2_PIN =         1;
const byte DEPTH_KNOB2_PIN =        5;

// SWITCHES (digital pins)

const byte WAVE_SWITCH1_PIN =      10;
const byte WAVE_SWITCH2_PIN =      12;

// LFO PARAMETERS
const double LFO1_FREQ_BASE =     0.1;
const double LFO1_FREQ_MAX =      100;
const double LFO1_FREQ_RANGE =    LFO1_FREQ_MAX - LFO1_FREQ_RANGE;

const double LFO2_FREQ_BASE =     0.1;
const double LFO2_FREQ_MAX =      100;
const double LFO2_FREQ_RANGE =    LFO2_FREQ_MAX - LFO2_FREQ_RANGE;
