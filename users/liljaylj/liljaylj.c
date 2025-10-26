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

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void clear_all_mods(void) {
    clear_mods();
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
}

static bool clear_oneshot_mods_on_sym_layer_exit = true;
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case X_VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_VERSION "-" QMK_GIT_HASH " (" QMK_BUILDDATE ")");
                return false;
            }
            break;
        case X_MMUTE:  // mic mute - shift+kc_mute, but with delay after modifier (https://github.com/qmk/qmk_firmware/issues/24612)
            if (record->event.pressed) {
                register_code(KC_LGUI);
                wait_ms(5);
                register_code(KC_MUTE);
            } else {
                unregister_code(KC_MUTE);
                unregister_code(KC_LGUI);
            }
            break;
        case KC_BSPC:
            {
                static bool delkey_registered;
                if (record->event.pressed) {
                    if (mod_state & MOD_BIT(KC_LSFT)) {
                        del_mods(MOD_BIT(KC_LSFT));
                        register_code(KC_DEL);
                        delkey_registered = true;
                        set_mods(mod_state);
                        return false;
                    }
                } else {
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
            }
        case X_OSCL:
            clear_oneshot_mods_on_sym_layer_exit = true;
            clear_all_mods();
            break;
        case X_OSLV:
            clear_oneshot_mods_on_sym_layer_exit = false;
            break;
        case X_OSOFF:
            oneshot_disable();
            clear_all_mods();
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case SYM:
            clear_oneshot_mods_on_sym_layer_exit = true;
            oneshot_enable();
            break;
        default:
            if (clear_oneshot_mods_on_sym_layer_exit) {
                clear_all_mods();
            }
            break;
    }
    return state;
}
