///////////////////////////////////////////////////////////////
//
//  CS_Switch.h
//
//  Construction Set Class - Button
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

#ifndef CS_SWITCH_h
#define CS_SWITCH_h

#include "Arduino.h"

// CLASS
class CS_Switch
{
  public:
  
    CS_Switch(byte);
    CS_Switch(byte, boolean);
    CS_Switch(byte, byte, boolean);

    int state();
    int stateDebounced();
    boolean changed();

    static const int SWITCH_LOW		= 0;
    static const int SWITCH_HIGH	= 1;

  private:
  
    void _init (byte, byte, boolean);
    byte _pin;
    byte _debounceRepeats;
    byte  _lastState;
    byte  _currentState;
  
};

#endif
