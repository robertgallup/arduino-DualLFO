// Settings 

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

const byte DEPTH_KNOB1_PIN =        4;
const byte FREQ_KNOB1_PIN =         0;

const byte DEPTH_KNOB2_PIN =        5;
const byte FREQ_KNOB2_PIN =         1;

// SWITCHES (digital pins)

const byte WAVE_SWITCH1_PIN =      10;
const byte WAVE_SWITCH2_PIN =      12;

const byte TRIGGER_PIN =            6;

// Output Pins (PWM - digital pins)
// WARNING: Don't change these!
const byte LFO1_OUTPUT_PIN =       11;
const byte LFO2_OUTPUT_PIN =        3;
