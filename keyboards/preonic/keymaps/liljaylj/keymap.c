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
#include "version.h"

enum layers {
    BASE,       // default layer
    SYMBOLS,    // symbols
    MEDIA,      // media keys
    SYSTEM,     // system
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

enum {
    TD_PENT_PEQL,
};

#define SYSGRV              LT(SYSTEM,KC_GRV)
#define MEHTAB              MEH_T(KC_TAB)
#define HYPRESC             HYPR_T(KC_ESC)
#define LCTLZ               LCTL_T(KC_Z)
#define LCTLHOM             LCTL_T(KC_HOME)
#define RCTLSLSH            RCTL_T(KC_SLSH)
#define RCTLEND             RCTL_T(KC_END)
#define RSFTENT             RSFT_T(KC_ENT)

#define SYMSCLN             LT(SYMBOLS,KC_SCLN)
#define MEDQUOT             LT(MEDIA,KC_QUOTE)
#define SYSBSPC             LT(SYSTEM,KC_BSPACE)
#define TTSYM               TT(SYMBOLS)
#define TTMED               TT(MEDIA)

#define TDENEQ              TD(TD_PENT_PEQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_preonic_grid(
        SYSGRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       SYSBSPC,
        MEHTAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLASH,
        HYPRESC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       SYMSCLN,    MEDQUOT,
        KC_LSFT,    LCTLZ,      KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     RCTLSLSH,   RSFTENT,
        LCTLHOM,    KC_LGUI,    KC_LALT,    TTSYM,      TTMED,      KC_SPC,     KC_SPC,     KC_LBRC,    KC_RBRC,    KC_RALT,    KC_RGUI,    RCTLEND
    ),

    [SYMBOLS] = LAYOUT_preonic_grid(
        XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
        _______,    KC_F11,     KC_F12,     KC_LCBR,    KC_RCBR,    KC_PGUP,    KC_PAST,    KC_P7,      KC_P8,      KC_P9,      KC_SLCK,    KC_PPLS,
        _______,    KC_MINS,    KC_EQL,     KC_LPRN,    KC_RPRN,    KC_PGDN,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      _______,    KC_PMNS,
        _______,    KC_UNDS,    KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_INS,     TDENEQ,     KC_P1,      KC_P2,      KC_P3,      KC_NLCK,    _______,
        _______,    _______,    _______,    _______,    KC_CAPS,    _______,    _______,    KC_P0,      KC_PDOT,    _______,    _______,    _______
    ),

    [MEDIA] = LAYOUT_preonic_grid(
        XXXXXXX,    XXXXXXX,    KC_BTN4,    KC_BTN3,    KC_BTN5,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    KC_BTN2,    KC_MS_U,    KC_BTN1,    KC_WH_U,    KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_MRWD,    KC_MFFD,    XXXXXXX,
        _______,    XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_MPLY,    _______,
        _______,    KC_BRID,    KC_BRIU,    KC_F14,     KC_WH_L,    KC_WH_R,    KC_MSTP,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_PSCR,    _______,
        _______,    _______,    _______,    KC_FIND,    _______,    _______,    _______,    KC_MPRV,    KC_MNXT,    _______,    _______,    _______
    ),

    [SYSTEM] = LAYOUT_preonic_grid(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    MU_TOG,     NK_ON,      NK_OFF,     RESET,      XXXXXXX,    MU_TOG,     MU_MOD,     XXXXXXX,    XXXXXXX,    KC_BRK,     KC_PWR,
        _______,    AU_TOG,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    AU_ON,      AU_OFF,     XXXXXXX,    XXXXXXX,    KC_WAKE,    KC_SLEP,
        _______,    CK_TOGG,    XXXXXXX,    XXXXXXX,    VRSN,       XXXXXXX,    NK_TOGG,    DM_REC1,    DM_REC2,    DM_RSTP,    XXXXXXX,    _______,
        _______,    _______,    _______,    XXXXXXX,    XXXXXXX,    _______,    _______,    DM_PLY1,    DM_PLY2,    _______,    _______,    _______
    ),

};

qk_tap_dance_action_t tap_dance_actions[] = {
    // 1 - KC_PENT, 2 - KC_PEQL
    [TD_PENT_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_PENT, KC_PEQL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return true;
        }
    }
    return true;
}
