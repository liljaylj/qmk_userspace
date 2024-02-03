#pragma once

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    VRSN = QK_USER,
    USER_SAFE_RANGE,
};

// EEPROM
typedef union {
    uint32_t raw;
    struct {
        bool auto_shift_enabled :1;
    };
} user_config_t;

user_config_t user_config;

enum layers {
    BASE,       // default layer
    BARE,       // gaming
    LOCK,       // lock keyboard
    SYMBOLS,    // symbols
    MEDIA,      // media keys
    SYSTEM,     // system
};

enum {
    TD_PENT_PEQL,
};

// shorter aliases
#define SYSGRV              LT(SYSTEM,KC_GRV)
#define MEHTAB              MEH_T(KC_TAB)
#define HYPRESC             HYPR_T(KC_ESC)
// home row mod-tap keys
#define LSFTA               LSFT_T(KC_A)
#define LCTLS               LCTL_T(KC_S)
#define LGUID               LGUI_T(KC_D)
#define LALTF               LALT_T(KC_F)
#define RSFTSCLN            RSFT_T(KC_SCLN)
#define RCTLL               RCTL_T(KC_L)
#define RGUIK               RGUI_T(KC_K)
#define RALTJ               RALT_T(KC_J)
// (left/right) ctrls as (home/end) on tap
#define LCTLHOM             LCTL_T(KC_HOME)
#define RCTLEND             RCTL_T(KC_END)
// right shift as enter on tap
#define RSFTENT             RSFT_T(KC_ENT)

// layer switch mod-tap keys
#define SYMQUOT             LT(SYMBOLS,KC_QUOTE)
#define MEDBSLS             LT(MEDIA, KC_BSLS)
#define SYSBSPC             LT(SYSTEM,KC_BSPC)
// layer switch
#define TTSYM               TT(SYMBOLS)
#define TTMED               TT(MEDIA)

// tap-dance keys
#define TDENEQ              TD(TD_PENT_PEQL)

#define ______________________________BASE_L1______________________________     SYSGRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ______________________________BASE_L2______________________________     MEHTAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define ______________________________BASE_L3______________________________     HYPRESC,    LSFTA,      LCTLS,      LGUID,      LALTF,      KC_G
#define ______________________________BASE_L4______________________________     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B
#define ______________________________BASE_L5__________________                 LCTLHOM,    KC_LGUI,    KC_LALT,    TTSYM,      TTMED

#define ______________________________BASE_R1______________________________     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       SYSBSPC
#define ______________________________BASE_R2______________________________     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       MEDBSLS
#define ______________________________BASE_R3______________________________     KC_H,       RALTJ,      RGUIK,      RCTLL,      RSFTSCLN,   SYMQUOT
#define ______________________________BASE_R4______________________________     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFTENT
#define             __________________BASE_R5______________________________                 KC_LBRC,    KC_RBRC,    KC_RALT,    KC_RGUI,    RCTLEND


#define ______________________________BARE_L1______________________________     SYSGRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ______________________________BARE_L2______________________________     KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define ______________________________BARE_L3______________________________     KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G
#define ______________________________BARE_L4______________________________     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B
#define ______________________________BARE_L5__________________                 KC_LCTL,    KC_LGUI,    KC_LALT,    TTSYM,      TTMED

#define ______________________________BARE_R1______________________________     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       SYSBSPC
#define ______________________________BARE_R2______________________________     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS
#define ______________________________BARE_R3______________________________     KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT
#define ______________________________BARE_R4______________________________     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFTENT
#define             __________________BARE_R5______________________________                 KC_LBRC,    KC_RBRC,    KC_RALT,    KC_RGUI,    KC_RCTL


#define ______________________________LOCK_L1______________________________     TT(SYSTEM), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L2______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L3______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L4______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L5__________________                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX

#define ______________________________LOCK_R1______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TT(SYSTEM)
#define ______________________________LOCK_R2______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_R3______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_R4______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define             __________________LOCK_R5______________________________                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX


#define _____________________________SYMBOLS_L1____________________________     XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5
#define _____________________________SYMBOLS_L2____________________________     _______,    KC_F11,     KC_F12,     KC_LCBR,    KC_RCBR,    KC_PGUP
#define _____________________________SYMBOLS_L3____________________________     _______,    KC_MINS,    KC_EQL,     KC_LPRN,    KC_RPRN,    KC_PGDN
#define _____________________________SYMBOLS_L4____________________________     _______,    KC_UNDS,    KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_INS
#define _____________________________SYMBOLS_L5________________                 _______,    _______,    _______,    _______,    KC_CAPS

#define _____________________________SYMBOLS_R1____________________________     KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL
#define _____________________________SYMBOLS_R2____________________________     KC_PAST,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,    KC_SCRL
#define _____________________________SYMBOLS_R3____________________________     KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PMNS,    _______
#define _____________________________SYMBOLS_R4____________________________     TDENEQ,     KC_P1,      KC_P2,      KC_P3,      KC_NUM,     _______
#define             _________________SYMBOLS_R5____________________________                 KC_P0,      KC_PDOT,    _______,    _______,    _______


#define ______________________________MEDIA_L1_____________________________     XXXXXXX,    XXXXXXX,    KC_BTN4,    KC_BTN3,    KC_BTN5,    XXXXXXX
#define ______________________________MEDIA_L2_____________________________     _______,    KC_F15,     KC_BTN2,    KC_MS_U,    KC_BTN1,    KC_WH_U
#define ______________________________MEDIA_L3_____________________________     _______,    QK_LOCK,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D
#define ______________________________MEDIA_L4_____________________________     _______,    KC_BRID,    KC_BRIU,    KC_F14,     KC_WH_L,    KC_WH_R
#define ______________________________MEDIA_L5_________________                 _______,    _______,    _______,    KC_APP,     _______

#define ______________________________MEDIA_R1_____________________________     XXXXXXX,    XXXXXXX,    KC_ACL0,    KC_ACL1,    KC_ACL2,    XXXXXXX
#define ______________________________MEDIA_R2_____________________________     XXXXXXX,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    _______
#define ______________________________MEDIA_R3_____________________________     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_PSCR,    _______
#define ______________________________MEDIA_R4_____________________________     XXXXXXX,    KC_MSTP,    KC_MRWD,    KC_MFFD,    XXXXXXX,    _______
#define             __________________MEDIA_R5_____________________________                 KC_MPRV,    KC_MNXT,    _______,    _______,    _______


#define _____________________________SYSTEM_L1_____________________________     _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define _____________________________SYSTEM_L2_____________________________     _______,    XXXXXXX,    NK_ON,      NK_OFF,     QK_BOOT,    XXXXXXX
#define _____________________________SYSTEM_L3_____________________________     _______,    AU_TOGG,    AS_ON,      AS_OFF,     AS_RPT,     TG(BARE)
#define _____________________________SYSTEM_L4_____________________________     _______,    CK_TOGG,    XXXXXXX,    QK_MAKE,    VRSN,       QK_RBT
#define _____________________________SYSTEM_L5_________________                 KC_LCTL,    _______,    _______,    AS_DOWN,    AS_UP

#define _____________________________SYSTEM_R1_____________________________     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______
#define _____________________________SYSTEM_R2_____________________________     MU_TOGG,    MU_NEXT,    XXXXXXX,    XXXXXXX,    KC_BRK,     KC_PWR
#define _____________________________SYSTEM_R3_____________________________     AU_ON,      AU_OFF,     XXXXXXX,    TG(LOCK),   KC_WAKE,    KC_SLEP
#define _____________________________SYSTEM_R4_____________________________     NK_TOGG,    DM_REC1,    DM_REC2,    DM_RSTP,    KC_SYRQ,    _______
#define             _________________SYSTEM_R5_____________________________                 DM_PLY1,    DM_PLY2,    _______,    _______,    KC_RCTL
