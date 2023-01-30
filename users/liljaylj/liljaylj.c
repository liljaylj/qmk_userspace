#include "liljaylj.h"

__attribute__ ((weak))
void eeconfig_init_keymap(void) { }

void eeconfig_init_user(void) {
    // reset EEPROM
    user_config.raw = 0;
    user_config.auto_shift_enabled = false;
    eeconfig_update_user(user_config.raw);

    autoshift_disable();

    eeconfig_init_keymap();
}

__attribute__ ((weak))
void keyboard_post_init_keymap(void) { }

void keyboard_post_init_user(void) {
    // read EEPROM
    user_config.raw = eeconfig_read_user();

    if (user_config.auto_shift_enabled) {
        autoshift_enable();
    }
    else {
        autoshift_disable();
    }

    keyboard_post_init_keymap();
}

__attribute__ ((weak))
bool get_custom_auto_shifted_key_keymap(uint16_t keycode, keyrecord_t *record) {
    return false;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTLZ:
            return true;
    }
    return get_custom_auto_shifted_key_keymap(keycode, record);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // 1 - KC_PENT, 2 - KC_PEQL
    [TD_PENT_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_PENT, KC_PEQL),
};

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            }
            break;
        case AS_ON:
        case AS_OFF:
            if (record->event.pressed) {
                user_config.auto_shift_enabled = keycode == AS_ON;
                eeconfig_update_user(user_config.raw);
                return true;
            }
            break;
    }
    return process_record_keymap(keycode, record);
}
