/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum layers {
    BASE,  // default layer
    CLMK,  // Colemak
    GAME,  // Gaming
    SYMB,  // symbols
    MOVE,  // Movement, and also symbols again
    MDIA,  // media keys
    KEYB,  // Keyboard functions
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_DEL,            KC_MEH,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,MO(MDIA),           KC_LGUI,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
 LCTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_EQL,           KC_MINS,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
        KC_LEFT, KC_LCTL, KC_LGUI, KC_LALT,MO(SYMB),   LALT_T(KC_APP),            KC_ENT,         TT(MOVE), KC_LBRC, KC_RBRC, KC_RGUI, KC_RGHT,
                                             KC_SPC,  KC_BSPC, KC_ENT,          MO(MDIA),MO(SYMB),MO(MOVE)
    ),

    [CLMK] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, _______,           _______,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
        _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G, _______,           _______,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O, _______,
        _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                KC_M,    KC_H, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [GAME] = LAYOUT_moonlander(
         KC_ESC, _______, _______, _______, _______, _______, _______,          MO(MDIA),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F12,
         KC_TAB, _______, _______, _______, _______, _______, KC_SCLN,            KC_EQL, _______, _______, _______, _______, _______, KC_PSCR,
        KC_LCTL, _______, _______, _______, _______, _______,    KC_N,           _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______,LT(SYMB, KC_V),                       _______, _______, _______, _______, _______, _______,
        _______, KC_NUBS, _______, _______, _______,             KC_M,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SYMB] = LAYOUT_moonlander(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,           _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_HOME, KC_PGUP,           _______, KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_PSLS,  KC_F12,
        _______, KC_HASH,  KC_DLR, KC_LBRC, KC_RBRC,  KC_END, KC_PGDN,            KC_INS, KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PENT,
        _______, KC_PERC, KC_AMPR, KC_CIRC, KC_ASTR, XXXXXXX,                             KC_PEQL,   KC_P1,   KC_P2,   KC_P3, KC_PEQL, XXXXXXX,
        _______, _______, _______, _______, _______,         MO(KEYB),           KC_PENT,            KC_P0, KC_PDOT, KC_PENT, XXXXXXX, XXXXXXX,
                                            KC_LCBR, KC_LBRC, KC_HASH,          TG(SYMB), _______, _______
    ),

    [MOVE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           KC_LBRC, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_RBRC, _______,
        _______, _______, _______, _______, _______, _______, _______,           KC_LCBR, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_RCBR, XXXXXXX,
        _______, _______, _______, _______, _______, XXXXXXX,                             KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,         MO(KEYB),           _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______,           _______, _______, XXXXXXX
    ),

    [MDIA] = LAYOUT_moonlander(
      LED_LEVEL, _______, _______, _______, _______, KC_MPLY, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_MPRV, KC_MNXT, XXXXXXX,           _______, KC_VOLU, _______,G(KC_UP), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_VOLD,G(KC_LEFT),G(KC_DOWN),G(KC_RGHT), _______, _______,
        _______, _______, _______, _______, _______, _______,                             KC_MUTE, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,
        _______, _______, _______, _______, _______,          KC_LSFT,           KC_MSEL,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [KEYB] = LAYOUT_moonlander(
        XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW,RGB_M_SN, RGB_M_K,           RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
        XXXXXXX, RGB_MOD, RGB_HUI,RGB_RMOD, RGB_VAI, RGB_SPI, RGB_TOG,           XXXXXXX, XXXXXXX,DF(BASE),DF(CLMK),DF(GAME), XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_SAD, RGB_HUD, RGB_SAI, RGB_VAD, RGB_SPD, XXXXXXX,           KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
