/*
 
 The MIT License (MIT)
 
 Copyright (c) Samuel Rondeau-Millaire and other contributors
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 */

#ifndef __GlobalKeyboardListener__InputListener__
#define __GlobalKeyboardListener__InputListener__

#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#include <stdbool.h>

/* Finds the matching name of the keycode */
extern char* key_to_string(int keycode);

extern CGEventRef keyEventCallBack(CGEventTapProxy proxy, CGEventType type,
                                   CGEventRef event, void *refcon);

extern void create_tap_listener();

bool LOGGING_ENABLED;
#endif /* defined(__GlobalKeyboardListener__InputListener__) */
