/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  QWERTY_LAYER,
  COLEMAK_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  NAV_LAYER,
  GUI_LAYER,
  ADJUST_LAYER
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  PLOVER,
  BACKLIT,
  EXT_PLV  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ DEL │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │ '/" │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │Enter│ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ GUI │Hyper│  ⌘  │  ⌥  │  ↓  │Space│ Nav │  ↑  │  ⌥  │  ⌘  │Hyper│ GUI │ -- Tap for ]
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                         /         Tap for Backspace __/                       /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
[QWERTY_LAYER] = LAYOUT_planck_mit_wrapper(
    KC_TAB , _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_ENT,
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, QUOTSFT,
    GUI_L,   HYPER_L, KC_LGUI, KC_LALT, LOWER,        KC_SPC,        RAISE, KC_RALT, KC_RGUI, HYPER_R, GUI_R
),

  /* Base layer (Colemak)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
[COLEMAK_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, _______,
    _______, _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, _______,
    _______, _________________COLEMAK_L3________________, _________________COLEMAK_R3________________, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  Application -- │ ⌘-` │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │  #  │
   *       window    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *     switcher    │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  -  │  =  │  `  │  \  │  :  │ndash│mdash│  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
[LOWER_LAYER] = LAYOUT_planck_mit_wrapper(
    GUI_GRV, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_HASH,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
    _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
    _______, _______, _______, _______, _______,      KC_BSPC,     _______, _______, _______, _______, _______
),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │ ⌘-` │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │ BSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │ \
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version
   *                 │     │  _  │  +  │  ~  │  |  │  :  │ndash│mdash│  ,  │  .  │  /  │     │ /    of lower layer
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  Delete   ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
[RAISE_LAYER] = LAYOUT_planck_mit_wrapper(
    GUI_GRV, _________________RAISE_L2__________________, _________________RAISE_R1__________________, _______,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, _______,      KC_DEL,      _______, _______, _______, _______, _______
),

  /* Directional navigation layer
   *
   *          Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     ┃     ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
[NAV_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, __________________NAV_L1___________________, __________________NAV_R1___________________, _______,
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │Home │PgDn │PgUp │ End │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Undo │ Cut │Copy │Paste│     │     │     │     │     │     │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃Prev │Play │Next │Brig-│Sleep│Wake │Brig+│Mute │Vol- │Vol+ ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
[GUI_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, __________________GUI_L1___________________, __________________GUI_R1___________________, _______,
    _______, __________________GUI_L2___________________, __________________GUI_R2___________________, _______,
    _______, __________________GUI_L3___________________, __________________GUI_R3___________________, _______,
    _______, __________MEDIA__________, KC_BRID,     KC_SLEP,      KC_BRIU, __________VOLUME_________, _______
),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *     Firmware -- │     │Reset│Make │     │     │Qwert│Colem│     │     │RBri-│RBri+│ Ins │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *          RGB -- │Caps │     │     │Mode-│Mode+│Hue -│Hue +│Sat -│Sat +│     │Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *        Audio -- │     │     │     │     │     │     │     │     │     │     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │Steno│     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
/* [ADJUST_LAYER] = LAYOUT_planck_mit_wrapper( */
/*     _______ , RESET   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RGB_VAD , RGB_VAI , KC_DEL  , */
/*     QWERTY  , _______ , MU_MOD  , RGB_RMOD, RGB_MOD , RGB_HUD , RGB_HUI , RGB_SAD , RGB_SAI , XXXXXXX , DM_PLY1 , DM_REC1 , */
/*     COLEMAK , MUV_DE  , MUV_IN  , MU_ON   , MU_OFF  , MI_ON   , MI_OFF  , AU_ON   , AU_OFF  , XXXXXXX , DM_PLY2 , DM_REC2 , */
/*     XXXXXXX , XXXXXXX , AG_SWAP , AG_NORM , LOWER   ,      LIT_TOG,       RAISE   , LIT_TOG , LIT_DEC , LIT_INC , DM_RSTP */
/* ) */
[ADJUST_LAYER] = LAYOUT_planck_mit_wrapper(
    _______ , RESET   , DEBUG   , XXXXXXX , XXXXXXX , QWERTY  , COLEMAK , XXXXXXX , XXXXXXX , RGB_VAD , RGB_VAI , KC_INS  ,
    KC_CAPS , _______ , XXXXXXX , RGB_RMOD, RGB_MOD , RGB_HUD , RGB_HUI , RGB_SAD , RGB_SAI , XXXXXXX , DM_PLY1 , DM_REC1 ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DM_PLY2 , DM_REC2 ,
    XXXXXXX , XXXXXXX , AG_SWAP , AG_NORM , LOWER   ,      LIT_TOG,       RAISE   , LIT_TOG , LIT_DEC , LIT_INC , DM_RSTP
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        /* print("mode just switched to qwerty and this is a huge string\n"); */ /* Apparently breaks the keyboard on entering this mode. Nice work, QMK */
        set_single_persistent_default_layer(QWERTY_LAYER);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(COLEMAK_LAYER);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(NAV_LAYER);
        layer_off(RAISE_LAYER);
        layer_off(ADJUST_LAYER);
        layer_on(GUI_LAYER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(GUI_LAYER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(NAV_LAYER)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(ADJUST_LAYER);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(ADJUST_LAYER);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
