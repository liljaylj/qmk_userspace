#pragma once

// layers
#define QWER    0   // BASE: qwerty
#define BARE    1   // BASE: qwerty without tap-holds

#define ERAB    2   // mirror of BARE
#define SYM     3   // symbols
#define CUR     4   // cursor keys and numpad
#define LOCK    5   // lock the keyboard
#define SYS     6   // system keys (qmk/media/etc.)

// tri layer
#define TRI_LAYER_LOWER_LAYER   SYM
#define TRI_LAYER_UPPER_LAYER   CUR
#define TRI_LAYER_ADJUST_LAYER  SYS

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define TAPPING_TOGGLE 3  // tap 3 times to switch to layer on TT maps
#define TAPPING_TERM 200

#undef MOUSEKEY_INTERVAL  // workaround for mousekey redefined in moonlander.h
#define MOUSEKEY_INTERVAL           10
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        60
#define MOUSEKEY_MAX_SPEED          7
#define MOUSEKEY_WHEEL_DELAY        400
#define MOUSEKEY_WHEEL_INTERVAL     MOUSEKEY_INTERVAL
#define MOUSEKEY_WHEEL_MAX_SPEED    MOUSEKEY_MAX_SPEED
#define MOUSEKEY_WHEEL_TIME_TO_MAX  MOUSEKEY_TIME_TO_MAX

#ifdef AUTO_SHIFT_ENABLE
#   define AUTO_SHIFT_TIMEOUT 185
#   define NO_AUTO_SHIFT_SPECIAL
#endif

#define RETRO_SHIFT 2000

#define DEBOUNCE 5

#ifdef AUDIO_ENABLE
#   define AUDIO_INIT_DELAY
#endif

#define CAPS_WORD_INVERT_ON_SHIFT

#define ORYX_CONFIGURATOR
