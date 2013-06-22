///////////////////////////////////////////////////////////////
//
//  CS_LEDBar.cpp
//
//  Construction Set Class - LED Bar (of variable length)
//  must use consecutive pins
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

#include "CS_LEDBar.h"

// Constructor
CS_LEDBar::CS_LEDBar (byte p, byte l)
{
  _pin = p;
  _length = l;
  for (int i=0; i<_length; i++) {
    pinMode (_pin+i, OUTPUT);
    digitalWrite (i, LOW);
  }
}

// Display number on LED Bar
void CS_LEDBar::displayNum (int n)
{
  for (int i=0; i<_length; i++) {
    digitalWrite (_pin+i, n & 1);
    n = n >> 1;
  };
}

// Clear value (set to 0)
void CS_LEDBar::clear()
{
  displayNum(0);
}
