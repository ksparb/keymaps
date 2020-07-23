#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

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

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// ANYTHING BELOW HERE IS YOUR OWN WORK

#define DYNAMIC_MACRO_NO_NESTING // Turns off macros recording macros. Will avoid infinite loops

#define TAPPING_TERM 150 // Controls how long the window for "tap dancing" is

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

 /* MOVE BELOW TO ANOTHER FILE LATER */

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

#define GUI_L LT(GUI_LAYER, KC_LBRC)
#define GUI_R LT(GUI_LAYER, KC_RBRC)

#define HYPER_L ALL_T(KC_LBRC)
#define HYPER_R ALL_T(KC_RBRC)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_ENT CTL_T(KC_ENT)

#define GUI_GRV LGUI(KC_GRV)

#define QUOTSFT RSFT_T(KC_QUOT)

#define QNAVCLN LT(NAV_LAYER, KC_SCLN)
#define CNAVCLN LT(NAV_LAYER, KC_O)

// Unify backlight controls
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#define LIT_TOG RGB_TOG
#define LIT_DEC RGB_VAD
#define LIT_INC RGB_VAI
#else
#define LIT_TOG BL_TOGG
#define LIT_DEC BL_DEC
#define LIT_INC BL_INC
#endif

// Alias layout macros that expand groups of keys.
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_planck_mit_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)
#define LAYOUT_preonic_grid_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAK_L1________________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________ KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________ KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________ KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________LOWER_L1__________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________LOWER_L2__________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________LOWER_L3__________________ KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_LPRN

#define _________________LOWER_R1__________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________LOWER_R2__________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________LOWER_R3__________________ KC_RPRN, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH

#define _________________RAISE_L1__________________ KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15
#define _________________RAISE_L2__________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L3__________________ KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_LPRN

#define _________________RAISE_R1__________________ KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
#define _________________RAISE_R2__________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR
#define _________________RAISE_R3__________________ KC_RPRN, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH

#define __________________NAV_L1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L2___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L3___________________ XXXXXXX, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT)

#define __________________NAV_R1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_R2___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_R3___________________ LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), XXXXXXX

#define __________________GUI_L1___________________ KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, XXXXXXX
#define __________________GUI_L2___________________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX
#define __________________GUI_L3___________________ KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX

#define __________________GUI_R1___________________ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX
#define __________________GUI_R2___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define __________________GUI_R3___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

 /* MOVE ABOVE TO ANOTHER FILE LATER */
