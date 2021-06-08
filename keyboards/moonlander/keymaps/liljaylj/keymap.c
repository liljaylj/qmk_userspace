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
    BASE,       // default layer
    SYMBOLS,    // symbols
    MEDIA,      // media keys
    SYSTEM,     // system
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    RGB_SLD,
};

enum {
    TD_PENT_PEQL,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [BASE] = LAYOUT_moonlander(
        LT(SYSTEM,KC_GRV),      KC_1,           KC_2,       KC_3,           KC_4,       KC_5,   XXXXXXX,                                        XXXXXXX,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,               LT(3,KC_BSPACE),
        MT(MOD_MEH,KC_TAB),     KC_Q,           KC_W,       KC_E,           KC_R,       KC_T,   XXXXXXX,                                        XXXXXXX,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,               KC_BSLASH,
        MT(MOD_HYPR,KC_ESC),    KC_A,           KC_S,       KC_D,           KC_F,       KC_G,   XXXXXXX,                                        XXXXXXX,    KC_H,       KC_J,       KC_K,       KC_L,       LT(1,KC_SCLN),      LT(2,KC_QUOTE),
        KC_LSFT,                LCTL_T(KC_Z),   KC_X,       KC_C,           KC_V,       KC_B,                                                               KC_N,       KC_M,       KC_COMM,    KC_DOT,     RCTL_T(KC_SLSH),    RSFT_T(KC_ENT),
        LCTL_T(KC_HOME),        KC_LGUI,        KC_LALT,    TT(SYMBOLS),    TT(MEDIA),                  TT(SYSTEM),             LCTL_T(KC_APP),             KC_LBRC,    KC_RBRC,    KC_RALT,    KC_RGUI,            RCTL_T(KC_END),
                                                                        KC_SPC,     KC_BSPC,    RGUI_T(KC_ENT),                 LGUI_T(KC_SPC), KC_TAB, KC_ENT
    ),


    [SYMBOLS] = LAYOUT_moonlander(
        XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      XXXXXXX,                                XXXXXXX,    KC_F6,              KC_F7,  KC_F8,      KC_F9,      KC_F10,     KC_DEL,
        _______,    KC_F11,     KC_F12,     KC_LCBR,    KC_RCBR,    KC_PGUP,    XXXXXXX,                                XXXXXXX,    KC_PAST,            KC_P7,  KC_P8,      KC_P9,      KC_SLCK,    KC_PPLS,
        _______,    KC_MINS,    KC_EQL,     KC_LPRN,    KC_RPRN,    KC_PGDN,    XXXXXXX,                                XXXXXXX,    KC_PSLS,            KC_P4,  KC_P5,      KC_P6,      _______,    KC_PMNS,
        _______,    KC_UNDS,    KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_INS,                                                         TD(TD_PENT_PEQL),   KC_P1,  KC_P2,      KC_P3,      KC_NLCK,    _______,
        _______,    _______,    _______,    _______,    KC_CAPS,                        _______,                _______,                                KC_P0,  KC_PDOT,    _______,    _______,    _______,
                                                                _______,    _______,    _______,                _______,    _______,    _______
    ),


    [MEDIA] = LAYOUT_moonlander(
        XXXXXXX,    XXXXXXX,    KC_BTN4,    KC_BTN3,    KC_BTN5,    XXXXXXX,    XXXXXXX,                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    KC_BTN2,    KC_MS_U,    KC_BTN1,    KC_WH_U,    XXXXXXX,                                XXXXXXX,    KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_MRWD,    KC_MFFD,    XXXXXXX,
        _______,    XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    XXXXXXX,                                XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_MPLY,    _______,
        _______,    KC_BRID,    KC_BRIU,    XXXXXXX,    KC_WH_L,    KC_WH_R,                                                        KC_MSTP,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_PSCR,    _______,
        _______,    _______,    _______,    KC_FIND,    _______,                        XXXXXXX,                _______,                        KC_MPRV,    KC_MNXT,    _______,    _______,    _______,
                                                                KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2,             _______,    _______,    _______
    ),


    [SYSTEM] = LAYOUT_moonlander(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,                                  RESET,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    MU_TOG,     NK_ON,      NK_OFF,     XXXXXXX,    XXXXXXX,    EEP_RST,                                EEP_RST,        MU_TOG,     MU_MOD,     LED_LEVEL,  XXXXXXX,    KC_BRK,     KC_PWR,
        _______,    AU_TOG,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    WEBUSB_PAIR,                            WEBUSB_PAIR,    AU_ON,      AU_OFF,     XXXXXXX,    XXXXXXX,    KC_WAKE,    KC_SLEP,
        _______,    CK_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                            NK_TOGG,    DM_REC1,    DM_REC2,    DM_RSTP,    XXXXXXX,    _______,
        _______,    _______,    _______,    XXXXXXX,    XXXXXXX,                        _______,                RGB_TOG,                            DM_PLY1,    DM_PLY2,    _______,    _______,    _______,
                                                                RGB_HUI,    RGB_HUD,    RGB_SAD,                RGB_SAI,    RGB_VAD,    RGB_VAI
    ),

    /* [BASE] = LAYOUT_moonlander( */
    /*     LT(3,KC_GRAVE),     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, */
    /*     MT(MOD_MEH, ,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),                     TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
    /*     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT), */
    /*     KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT, */
    /* LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB), */
    /*                                         KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT */
    /* ), */

    /* [SYMB] = LAYOUT_moonlander( */
    /*     VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, */
    /*     _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12, */
    /*     _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______, */
    /*     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______, */
    /*     EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______, */
    /*                                         RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______ */
    /* ), */

    /* [MDIA] = LAYOUT_moonlander( */
    /*     LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET, */
    /*     _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, */
    /*     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY, */
    /*     _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______, */
    /*     _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, */
    /*                                         _______, _______, _______,           _______, _______, _______ */
    /* ), */
};

void keyboard_post_init_user(void) {
    /* rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS); */
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // 1 - KC_PENT, 2 - KC_PEQL
    [TD_PENT_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_PENT, KC_PEQL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case RGB_SLD:
                rgblight_mode(1);
                return false;
        }
    }
    return true;
}
