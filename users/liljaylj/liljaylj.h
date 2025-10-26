#pragma once

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    X_VRSN = SAFE_RANGE,
    X_MMUTE,
    X_OSCL, // clear one-shot modifiers on leave CUR layer + clear mods now
    X_OSLV, // do not clear (leave) one-shot modifiers on leave CUR layer
    X_OSOFF, // OS_OFF + clear mods now
};

// EEPROM
typedef union {
    uint32_t raw;
    struct {
        bool auto_shift_enabled :1;
    };
} user_config_t;

user_config_t user_config;

// home row mod-tap keys
#define LSFTA               LSFT_T(KC_A)
#define LCTLS               LCTL_T(KC_S)
#define LGUID               LGUI_T(KC_D)
#define LALTF               LALT_T(KC_F)
#define RSFTSCLN            RSFT_T(KC_SCLN)
#define RCTLL               RCTL_T(KC_L)
#define RGUIK               RGUI_T(KC_K)
#define RALTJ               RALT_T(KC_J)

// right shift as enter on tap
#define RSFTENT             RSFT_T(KC_ENT)

// layer switch tap-hold keys
#define SYMQUOT             LT(SYM,KC_QUOTE)
#define SYMESC              LT(SYM,KC_ESC)

#define CURB                LT(CUR,KC_B)
#define CURN                LT(CUR,KC_N)

#define SYMLBRC             LT(SYM,KC_LBRC)
#define CURRBRC             LT(CUR,KC_RBRC)

#define SYSTAB              LT(SYS,KC_TAB)
#define SYSBSLS             LT(SYS,KC_BSLS)

#define ERABGRV             LT(ERAB,KC_GRV)
#define ERABBSPC            LT(ERAB,KC_BSPC)

// middle button(s) function on SYM layer
#define SYMMID              _______
// middle button(s) function on CUR layer
#define CURMID              QK_LLCK
// middle button(s) function on SYS layer
#define SYSMID              KC_MPLY


#define ______________________________QWER_L1______________________________     KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ______________________________QWER_L2______________________________     SYSTAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define ______________________________QWER_L3______________________________     SYMESC,     LSFTA,      LCTLS,      LGUID,      LALTF,      KC_G
#define ______________________________QWER_L4______________________________     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       CURB
#define ______________________________QWER_L5__________________                 KC_LCTL,    KC_LGUI,    KC_LALT,    TL_LOWR,    TL_UPPR

#define ______________________________QWER_R1______________________________     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC
#define ______________________________QWER_R2______________________________     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       SYSBSLS
#define ______________________________QWER_R3______________________________     KC_H,       RALTJ,      RGUIK,      RCTLL,      RSFTSCLN,   SYMQUOT
#define ______________________________QWER_R4______________________________     CURN,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFTENT
#define             __________________QWER_R5______________________________                 SYMLBRC,    CURRBRC,    KC_RALT,    KC_RGUI,    KC_RCTL


#define ______________________________BARE_L1______________________________     ERABGRV,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define ______________________________BARE_L2______________________________     SYSTAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T
#define ______________________________BARE_L3______________________________     KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G
#define ______________________________BARE_L4______________________________     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B
#define ______________________________BARE_L5__________________                 KC_LCTL,    KC_LGUI,    KC_LALT,    TL_LOWR,    TL_UPPR

#define ______________________________BARE_R1______________________________     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       ERABBSPC
#define ______________________________BARE_R2______________________________     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       SYSBSLS
#define ______________________________BARE_R3______________________________     KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT
#define ______________________________BARE_R4______________________________     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFTENT
#define             __________________BARE_R5______________________________                 KC_LBRC,    KC_RBRC,    KC_RALT,    KC_RGUI,    KC_RCTL


#define ______________________________ERAB_L1______________________________     _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define ______________________________ERAB_L2______________________________     KC_BSLS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P
#define ______________________________ERAB_L3______________________________     KC_QUOT,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN
#define ______________________________ERAB_L4______________________________     RSFTENT,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH
#define ______________________________ERAB_L5__________________                 KC_RCTL,    KC_RALT,    KC_RGUI,    KC_LBRC,    KC_RBRC

#define ______________________________ERAB_R1______________________________     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______
#define ______________________________ERAB_R2______________________________     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_TAB
#define ______________________________ERAB_R3______________________________     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_ESC
#define ______________________________ERAB_R4______________________________     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LSFT
#define             __________________ERAB_R5______________________________                 TL_LOWR,    TL_UPPR,    KC_LGUI,    KC_LALT,    KC_LCTL


#define _______________________________SYM_L1______________________________     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6
#define _______________________________SYM_L2______________________________     KC_TAB,     KC_CAPS,    KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_GRV
#define _______________________________SYM_L3______________________________     _______,    KC_SLSH,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_DLR
#define _______________________________SYM_L4______________________________     _______,    KC_INS,     KC_AMPR,    KC_ESC,     KC_SCLN,    KC_QUOT
#define _______________________________SYM_L5__________________                 _______,    _______,    _______,    _______,    _______

#define _______________________________SYM_R1______________________________     KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12
#define _______________________________SYM_R2______________________________     KC_SCRL,    KC_LT,      KC_GT,      KC_PLUS,    KC_UNDS,    KC_BSLS
#define _______________________________SYM_R3______________________________     KC_HASH,    KC_LPRN,    KC_RPRN,    KC_EQL,     KC_MINS,    _______
#define _______________________________SYM_R4______________________________     KC_BSPC,    KC_DEL,     KC_TILD,    KC_EXLM,    KC_QUES,    _______
#define             ___________________SYM_R5______________________________                 _______,    _______,    _______,    _______,    _______


#define _______________________________CUR_L1______________________________     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6
#define _______________________________CUR_L2______________________________     X_OSOFF,    X_OSCL,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP
#define _______________________________CUR_L3______________________________     QK_LLCK,    X_OSLV,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN
#define _______________________________CUR_L4______________________________     OS_ON,      OS_LSFT,    OS_LCTL,    OS_LGUI,    OS_LALT,    _______
#define _______________________________CUR_L5__________________                 _______,    _______,    _______,    _______,    _______

#define _______________________________CUR_R1______________________________     KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12
#define _______________________________CUR_R2______________________________     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     X_OSCL,     X_OSOFF
#define _______________________________CUR_R3______________________________     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    X_OSLV,     QK_LLCK
#define _______________________________CUR_R4______________________________     _______,    OS_RALT,    OS_RGUI,    OS_RCTL,    OS_RSFT,    OS_ON
// #define _______________________________CUR_R4______________________________     KC_NUM,     KC_CALC,    QK_LOCK,    CW_TOGG,    _______,    _______
// TODO: `()/*-+.=<enter>` from numpad on SYM layer
#define             ___________________CUR_R5______________________________                 _______,    _______,    _______,    _______,    _______


#define ______________________________LOCK_L1______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L2______________________________     MO(SYS),    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L3______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L4______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_L5__________________                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX

#define ______________________________LOCK_R1______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_R2______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    MO(SYS)
#define ______________________________LOCK_R3______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define ______________________________LOCK_R4______________________________     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
#define             __________________LOCK_R5______________________________                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX


#define _______________________________SYS_L1______________________________     XXXXXXX,    XXXXXXX,    MS_BTN4,    MS_BTN3,    MS_BTN5,    XXXXXXX
#define _______________________________SYS_L2______________________________     _______,    MS_WHLU,    MS_BTN2,    MS_UP,      MS_BTN1,    MS_WHLD
#define _______________________________SYS_L3______________________________     XXXXXXX,    MS_WHLL,    MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLR
#define _______________________________SYS_L4______________________________     _______,    DF(QWER),   DF(BARE),   XXXXXXX,    X_VRSN,     QK_BOOT
#define _______________________________SYS_L5__________________                 _______,    _______,    _______,    KC_VOLD,    KC_VOLU

#define _______________________________SYS_R1______________________________     KC_BRK,     XXXXXXX,    MS_ACL0,    MS_ACL1,    MS_ACL2,    KC_SLEP
#define _______________________________SYS_R2______________________________     AU_OFF,     AU_ON,      KC_BRID,    KC_BRIU,    KC_MPLY,    _______
#define _______________________________SYS_R3______________________________     KC_NUM,     KC_CAPS,    KC_SCRL,    TG(LOCK),   QK_MAKE,    KC_SYRQ
#define _______________________________SYS_R4______________________________     X_MMUTE,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_PSCR,    _______
#define             ___________________SYS_R5______________________________                 KC_MPRV,    KC_MNXT,    _______,    _______,    _______
