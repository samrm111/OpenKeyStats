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

#include "InputListener.h"

void process_flagsChanged_event(CGEventRef event);
void process_keyUp_event(CGEventRef event);
int get_key_number_from_CGEventRef(CGEventRef event);

int currentPressedKey = -1;

/* The callBack event from the CGEventTap */
CGEventRef keyEventCallBack(CGEventTapProxy proxy, CGEventType type,
                 CGEventRef event, void *refcon)
{
    // get only keyup and flagchanged events
    if (type == kCGEventKeyUp)
        process_keyUp_event(event);
    else if (type == kCGEventFlagsChanged)
        process_flagsChanged_event(event);
    else
        // Return the event, or something bad will happen!
        return event;
    
    return event;
}

/* TODO: Save to file the data of keys that are pressed. */
void save_keys_to_file(){
    
}

/* Match a keycode to the name of the key */
/* TODO: change the way this works. A struct would be good .*/
char* key_to_string(int keyCode)
{
    
    switch (keyCode) {
        case 0: return("a");
        case 1: return("s");
        case 2: return("d");
        case 3: return("f");
        case 4: return("h");
        case 5: return("g");
        case 6: return("z");
        case 7: return("x");
        case 8: return("c");
        case 9: return("v");
        case 11: return("b");
        case 12: return("q");
        case 13: return("w");
        case 14: return("e");
        case 15: return("r");
        case 16: return("y");
        case 17: return("t");
        case 18: return("1");
        case 19: return("2");
        case 20: return("3");
        case 21: return("4");
        case 22: return("6");
        case 23: return("5");
        case 24: return("=");
        case 25: return("9");
        case 26: return("7");
        case 27: return("-");
        case 28: return("8");
        case 29: return("0");
        case 30: return("]");
        case 31: return("o");
        case 32: return("u");
        case 33: return("[");
        case 34: return("i");
        case 35: return("p");
        case 36: return("RETURN");
        case 37: return("l");
        case 38: return("j");
        case 39: return("'");
        case 40: return("k");
        case 41: return(";");
        case 42: return("\\");
        case 43: return(",");
        case 44: return("/");
        case 45: return("n");
        case 46: return("m");
        case 47: return(".");
        case 48: return("TAB");
        case 49: return("SPACE");
        case 50: return("`");
        case 51: return("DELETE");
        case 52: return("ENTER");
        case 53: return("ESCAPE");
        case 54: return("COMMAND_RIGHT");
        case 55: return("COMMAND_LEFT");
        case 56: return("SHIFT_LEFT");
        case 58: return("OPTION_LEFT");
        case 59: return("CONTROL");
        case 60: return("SHIFT_RIGHT");
        case 61: return("OPTION_RIGHT");
        case 63: return("FUNCTION");
        case 65: return(".");
        case 67: return("*");
        case 69: return("+");
        case 71: return("CLEAR");
        case 75: return("/");
        case 76: return("ENTER");   // full keyboard
        case 78: return("-");
        case 81: return("=");
        case 82: return("0");
        case 83: return("1");
        case 84: return("2");
        case 85: return("3");
        case 86: return("4");
        case 87: return("5");
        case 88: return("6");
        case 89: return("7");
        case 91: return("8");
        case 92: return("9");
        case 96: return("F5");
        case 97: return("F6");
        case 98: return("F7");
        case 99: return("F3");
        case 100: return("F8");
        case 101: return("F9");
        case 103: return("F11");
        case 105: return("F13");
        case 107: return("F14");
        case 109: return("F10");
        case 111: return("F12");
        case 113: return("F15");
        case 114: return("HELP");
        case 115: return("HOME");
        case 116: return("PGUP");
        case 117: return("DELETE");  // full keyboard
        case 118: return("F4");
        case 119: return("END");
        case 120: return("F2");
        case 121: return("PGDN");
        case 122: return("F1");
        case 123: return("LEFT");
        case 124: return("RIGHT");
        case 125: return("DOWN");
        case 126: return("UP");
            
        default:
            return ("Undefined");
    }
}

/*
 Proccess the flagsChangedEvent of a CGEventRef
 Flags are : cmd, option, control, fn, shift.
 */
void process_flagsChanged_event(CGEventRef event){
    CGEventFlags event_flag = CGEventGetFlags(event);
    int keyNumber = get_key_number_from_CGEventRef(event);
    
    switch(keyNumber){
        case 54:
            if (event_flag & kCGEventFlagMaskCommand)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 55:
            if (event_flag & kCGEventFlagMaskCommand)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 60:
            if (event_flag & kCGEventFlagMaskShift)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 56:
            if (event_flag & kCGEventFlagMaskShift)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 59:
            if (event_flag & kCGEventFlagMaskControl)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 58:
            if (event_flag & kCGEventFlagMaskAlternate)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 61:
            if (event_flag & kCGEventFlagMaskAlternate)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
        case 63:
            if (event_flag & kCGEventFlagMaskSecondaryFn)
                currentPressedKey = keyNumber;
            else
                currentPressedKey = -1;
            break;
    }
    if (currentPressedKey != -1) {
        printf("Key Pressed : %s\n", key_to_string(keyNumber));
    }
    
}

/* Proccess the key up event. */
void process_keyUp_event(CGEventRef event){
    int keyNumber = get_key_number_from_CGEventRef(event);
    printf("Key Pressed : %s\n", key_to_string(keyNumber));

}

/* Get the key Integer Value from a CGEventRef. */
int get_key_number_from_CGEventRef(CGEventRef event){
    return (int) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
}

//TODO enable logging from a paramater in cli.
void logger(){
    if (LOGGING_ENABLED) {
        
    }
    return;
}

void create_tap_listener(){
    CFMachPortRef      tapEvent;
    CFRunLoopSourceRef runLoopSource;
    
    // Initialize the event
    tapEvent = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0,
                                kCGEventMaskForAllEvents, keyEventCallBack, NULL);
    
    // verify for failure
    if (!tapEvent) {
        fprintf(stderr, "Error while creating the key listener.\n");
        exit(1);
    }
    
    // Create a run loop source.
    runLoopSource = CFMachPortCreateRunLoopSource(
                                                  kCFAllocatorDefault, tapEvent, 0);
    
    // Add to the current run loop.
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource,
                       kCFRunLoopCommonModes);
    
    // Enable the tap event.
    CGEventTapEnable(tapEvent, true);
    CFRunLoopRun();

}