///////////////////////////////////////////////////////////////
//
//  Debug.h
//
//  Simple Debug macros
//
//  NOTE: Make sure to define DEBUG_ON before including this file
//  to enable the macros
//
//  The MIT License (MIT)
//  
//  Copyright (c) 2016 Robert W. Gallup
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
///////////////////////////////////////////////////////////////

#ifndef DEBUG_h
#define DEBUG_h

  #if defined(DEBUG)
      
    #define DEBUG_DO(...) {(__VA_ARGS__);}
    #define DEBUG_BEGIN(...) {while (!Serial); Serial.begin((#__VA_ARGS__=="")?9600:atoi(#__VA_ARGS__));}
    #define DEBUG_PRINTS(s)  {Serial.println (s);}
    #define DEBUG_PRINTS2(s, s2)  {Serial.print(s); Serial.println(s2);}
    #define DEBUG_PRINTSV(s,v) {Serial.print(s); Serial.println(v);}
    #define DEBUG_PRINTSVH(s,v) {Serial.print(s); Serial.println(v, HEX);}
    #define DEBUG_PRINTSVB(s,v) {Serial.print(s); Serial.println(v, BIN);}
    #define DEBUG_PRINTSTS(s) {Serial.print(s); Serial.print(" :: "); Serial.println(millis());}
    #define DEBUG_ASSERTS(t, s)  {if (t) DEBUG_PRINTS(s);}
    #define DEBUG_ASSERTSV(t, s, v) {if (t) DEBUG_PRINTSV(s,v);}
      
  #else

    #define DEBUG_DO(...)
    #define DEBUG_BEGIN(...) 
    #define DEBUG_PRINTS(...)
    #define DEBUG_PRINTS2(...)
    #define DEBUG_PRINTSV(...)
    #define DEBUG_PRINTSVB(...)
    #define DEBUG_PRINTSVH(...)
    #define DEBUG_PRINTSTS(...)
    #define DEBUG_ASSERTS(...)
    #define DEBUG_ASSERTSV(...)

  #endif

#endif
