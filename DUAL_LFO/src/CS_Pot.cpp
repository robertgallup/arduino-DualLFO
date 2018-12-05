///////////////////////////////////////////////////////////////
//
//  CS_Pot.cpp
//
// Simple class for potentiometers
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

#include "CS_Pot.h"

// Macro to increment pointer to circular buffer
#define next(x) {x+=1;if(x>=_buffLen)x=0;}

// Constructor : clear queues
CS_Pot::CS_Pot (byte p, byte smooth)
{
  _smooth = 0;
  _pin = p;

  // If smoothing value is in range, initialize smoothing
  if ((smooth>0)&&(smooth<=MAXSMOOTH)) {
  	_smooth = smooth;

  	// Buffer length is 2^smooth. Ptr starts at beginning
  	_buffLen = (1<<_smooth);
  	_ptr = 0;

  }
}

// Initialize controls
void CS_Pot::begin()
{
  // Initialize sum and fill buffer with current reading
  _sum = 0;
  for (byte i=0; i<_buffLen; i+=1) {
    _values[i]=analogRead(_pin);
    _sum += _values[i];
  }
}

// Read potentiometer value
int CS_Pot::value ()
{

  // Take a pot reading. If there's no smoothing, return the raw value
  int reading = analogRead(_pin);
  if (0==_smooth) return reading;

  // Otherwise, update the running sum by adding the new value and subtracting the oldest previous value
  _sum = _sum + reading - _values[_ptr];
  // Increment the pointer, save the new value, and return the "smoothed" value (divided by 2^smooth)
  _values[_ptr] = reading;
  next(_ptr);
  return (_sum>>_smooth);

}

