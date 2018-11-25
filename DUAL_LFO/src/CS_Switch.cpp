///////////////////////////////////////////////////////////////
//
//  CS_Switch.cpp
//
//  Simple class for switches/buttons
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2013 Robert W. Gallup (www.robertgallup.com)
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// 

#include "CS_Switch.h"

// Constructor
CS_Switch::CS_Switch (byte pin)
{
  _init (pin, 3, true);
}

CS_Switch::CS_Switch (byte pin, boolean pullup)
{
  _init (pin, 3, pullup);
}

CS_Switch::CS_Switch (byte pin, byte repeats, boolean pullup)
{
  _init (pin, repeats, pullup);
}

void CS_Switch::_init (byte pin, byte repeats, boolean pullup)
{
  _debounceRepeats = repeats;                // Number of repeats for debouncing
  _pin = pin;                                // Save pin number
  pinMode (_pin, INPUT);                     // Set pin to input
  digitalWrite (_pin, pullup ? HIGH : LOW);  // Activate internal pullup resistor depending on input param
  _lastState = SWITCH_LOW;
  _currentState = SWITCH_LOW;
}

// Read Switch state
int CS_Switch::state ()
{
  _lastState = _currentState;
  _currentState = digitalRead(_pin);
  return (_currentState);
}

// Read Switch state (debounced by taking "n" readings)
int CS_Switch::stateDebounced ()
{
  _lastState = _currentState;
  byte accumulator = 0;
  for (int i = 0; i<_debounceRepeats; i++) {
    accumulator += digitalRead(_pin);
  }
  _currentState = (accumulator == _debounceRepeats) ? SWITCH_HIGH : SWITCH_LOW;
  return (_currentState);
}

// Returns true if state changed since last read
boolean CS_Switch::changed()
{
  return (_currentState != _lastState);
}
