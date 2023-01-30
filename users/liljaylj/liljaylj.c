#include "liljaylj.h"

__attribute__ ((weak))
void eeconfig_init_keymap(void) { }

void eeconfig_init_user(void) {
    // reset EEPROM
    user_config.raw = 0;

#ifdef AUTO_SHIFT_ENABLE
    user_config.auto_shift_enabled = false;
    autoshift_disable();
#endif

    eeconfig_update_user(user_config.raw);

    eeconfig_init_keymap();
}

__attribute__ ((weak))
void keyboard_post_init_keymap(void) { }

void keyboard_post_init_user(void) {
    // read EEPROM
    user_config.raw = eeconfig_read_user();

#ifdef AUTO_SHIFT_ENABLE
    autoshift_disable();
    if (user_config.auto_shift_enabled) {
        autoshift_enable();
    }
    else {
        autoshift_disable();
    }
#endif

    keyboard_post_init_keymap();
}

#ifdef AUTO_SHIFT_ENABLE
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
#endif

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
#ifdef AUTO_SHIFT_ENABLE
        case AS_ON:
        case AS_OFF:
            if (record->event.pressed) {
                user_config.auto_shift_enabled = keycode == AS_ON;
                eeconfig_update_user(user_config.raw);
                return true;
            }
            break;
#endif
    }
    return process_record_keymap(keycode, record);
}
