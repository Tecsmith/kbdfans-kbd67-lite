/* Copyright 2022 Vino Rodrigues (https://github.com/vinorodrigues)
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
#include <version.h>
#include "keymap.h"

#ifdef RGB_MATRIX_ENABLE
    #include "rgb_matrix_keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT_65_ansi_blocker(
        KC_GESC,  KC_1,     KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_GRAVE, \
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLASH, KC_DELETE, \
        LT1_C_L,  KC_A,     KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,    KC_PGUP, \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,     KC_PGDN, \
        KC_LCTL,  KC_LALT,  KC_LGUI,                    KC_SPC,                    FN_MO13,          FN_MO23, KC_LEFT,          KC_DOWN,   KC_RIGHT \
    ),
    [LAYER_1] = LAYOUT_65_ansi_blocker(
        KC_GRAVE, KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_ERAS,   KC_ESC, \
        _______,  _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_EJCT,   KC_INS, \
        KC_CAPS,  _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,          KC_PENT,   KC_HOME, \
        KC_RSFT,  _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_MENU,          _______,   KC_END, \
        KC_RCTL,  KC_RALT,  KC_RGUI,                    _______,                   _______,          MO(3),   _______,          _______,   _______ \
    ),
    [LAYER_2] = LAYOUT_65_ansi_blocker(
        KC_ESC,   KC_BRID,  KC_BRIU, KC_MCON, KC_LPAD,  RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_OUT,    KC_SLEP, \
        RGB_TOG,  RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PSCR, \
        XXXXXXX,  RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI,          XXXXXXX,   KC_SLCK, \
        XXXXXXX,  XXXXXXX,  KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, XXXXXXX,          RGB_VAI,   KC_PAUS, \
        XXXXXXX,  XXXXXXX,  XXXXXXX,                    XXXXXXX,                   MO(3),            _______, RGB_SPD,          RGB_VAD,   RGB_SPI \
    ) ,
    [LAYER_3] = LAYOUT_65_ansi_blocker(
        MACRO00,  MACRO01,  MACRO02, MACRO03, MACRO04,  MACRO05, MACRO06, MACRO07, MACRO08, MACRO09, MACRO10, MACRO11, MACRO12, XXXXXXX,   KC_POWER, \
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, \
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,   XXXXXXX, \
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KB_VRSN,  RESET,   KC_NKRO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,   XXXXXXX, \
        XXXXXXX,  XXXXXXX,  XXXXXXX,                    _______,                   _______,          _______, XXXXXXX,          XXXXXXX,   XXXXXXX \
    ),
};

/*
 * ----------- RGB Stuff -----------
 */
#ifdef RGB_MATRIX_ENABLE
    // switch of Caps-Lock LED function
    #ifdef CAPS_LOCK_LED_INDEX
        #undef CAPS_LOCK_LED_INDEX
    #endif

    #ifdef RGBLIGHT_VAL_STEP
        #define KBD67_RGB_BRIGHTER_BY RGBLIGHT_VAL_STEP
    #else
        #define KBD67_RGB_BRIGHTER_BY 26  // about 10% of 255
    #endif

    void matrix_init_user(void) {
        rgb_matrix_init_user();
    }

    void rgb_matrix_indicators_user(void) {
        // do nothing / override default behaviour
    }

    // #define KBD67_CAPS_LOCK_KEY_INDEX 30  // position of Caps Lock key

    // #define LED_FLAG_ALPHA_KEY 0x10  // Alpha keys (for Caps Lock)
    // #define LED_FLAG_LAYER_IND 0x20  // Layer indicator

    // const uint8_t g_led_config_new_flags[DRIVER_LED_TOTAL] = {
    //     // Extended LED Index to Flag
    //     0x21, 0x04, 0x04, 0x04, 0x04, 0x24, 0x24, 0x24, 0x24, 0x04, 0x04, 0x04, 0x04, 0x01, 0x21,
    //     0x21, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04, 0x04, 0x21,
    //     0x29, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04, 0x01,       0x21,
    //     0x21, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04, 0x04, 0x01, 0x01,       0x21,
    //     0x21, 0x01, 0x01,             0x04,             0x01,       0x01, 0x01,       0x01, 0x21
    // };

    bool isRGBOff = false;

    // void keyboard_pre_init_user(void) {
    //     // override config.flags with new values
    //     for (int i = 0; i < DRIVER_LED_TOTAL; i++) g_led_config.flags[i] = g_led_config_new_flags[i];
    // }

    // void keyboard_post_init_user(void) {
    //     isRGBOff = false;
    // }

    // bool isCapsBlink = false;
    // static uint16_t recording_timer;

    // void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    //     uint8_t v = MIN( rgblight_get_val() + KBD67_RGB_BRIGHTER_BY, 0xFF );
    //     uint8_t current_layer = get_highest_layer(layer_state);

    //     // Caps Lock key stuff

    //     if (host_keyboard_led_state().caps_lock) {
    //         if (isRGBOff) {
    //             rgb_matrix_set_color(KBD67_CAPS_LOCK_KEY_INDEX, v, v, v);  // white
    //         } else {
    //             // Caps Lock key/LED blink code
    //             if (timer_elapsed(recording_timer) > 500) {
    //                 isCapsBlink = !isCapsBlink;
    //                 recording_timer = timer_read();
    //             }
    //             if (isCapsBlink) {
    //                 rgb_matrix_set_color(KBD67_CAPS_LOCK_KEY_INDEX, v, v, v);  // white
    //             }

    //             // Alpha keys/LEDs
    //             for (uint8_t i = led_min; i <= led_max; i++) {
    //                 if (g_led_config.flags[i] & LED_FLAG_ALPHA_KEY) {
    //                     rgb_matrix_set_color(i, v, 0, 0);  // red
    //                 }
    //             }
    //         }
    //     } else if (isRGBOff) {
    //         uint8_t r = 0;
    //         uint8_t g = 0;
    //         uint8_t b = 0;

    //         if ((g_led_config.flags[KBD67_CAPS_LOCK_KEY_INDEX] & LED_FLAG_LAYER_IND) != 0) {
    //             switch (current_layer) {
    //                 case LAYER_1: b = v; break;  // blue
    //                 case LAYER_2: g = v; break;  // green
    //                 case LAYER_3: r = v; break;  // red
    //             }
    //         }

    //         rgb_matrix_set_color(KBD67_CAPS_LOCK_KEY_INDEX, r, g, b);  // off
    //     }

    //     // Layer indicator stuff

    //     switch (current_layer) {
    //         case LAYER_1:
    //             for (uint8_t i = led_min; i <= led_max; i++) {
    //                 if ((g_led_config.flags[i] & LED_FLAG_LAYER_IND) != 0) {
    //                     rgb_matrix_set_color(i, 0, 0, v);  // blue
    //                 }
    //             }
    //             break;

    //         case LAYER_2:
    //             for (uint8_t i = led_min; i <= led_max; i++) {
    //                 if ((g_led_config.flags[i] & LED_FLAG_LAYER_IND) != 0) {
    //                     rgb_matrix_set_color(i, 0, v, 0);  // green
    //                 }
    //             }
    //             break;

    //         case LAYER_3:
    //             for (uint8_t i = led_min; i <= led_max; i++) {
    //                 if ((g_led_config.flags[i] & LED_FLAG_LAYER_IND) != 0) {
    //                     rgb_matrix_set_color(i, v, 0, 0);  // red
    //                 }
    //             }
    //             break;

    //         default:
    //             if (isRGBOff) {
    //                 // switch layer indicators off only if in OFF mode
    //                 for (uint8_t i = led_min; i <= led_max; i++) {
    //                     if ((g_led_config.flags[i] & LED_FLAG_LAYER_IND) != 0) {
    //                         rgb_matrix_set_color(i, 0, 0, 0);  // red
    //                     }
    //                 }
    //             }
    //             break;
    //     }
    // }

    // void suspend_power_down_user(void) {
    //     rgb_matrix_set_suspend_state(true);
    // }

    // void suspend_wakeup_init_user(void) {
    //     rgb_matrix_set_suspend_state(false);
    // }

#endif

/*
 * Mac Fn-key stuff
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // handle RGB toggle key
        // case RGB_TOG:
        //     if (record->event.pressed) {
        //         switch (rgb_matrix_get_flags()) {
        //             case LED_FLAG_ALL:
        //                 isRGBOff = true;
        //                 rgb_matrix_set_flags(LED_FLAG_INDICATOR | LED_FLAG_LAYER_IND);
        //                 rgb_matrix_set_color_all(0, 0, 0);
        //                 break;
        //             default:
        //                 isRGBOff = false;
        //                 rgb_matrix_set_flags(LED_FLAG_ALL);
        //                 rgb_matrix_enable_noeeprom();
        //         }
        //     }
        //     return false;

        // print firmware version
        case KB_VRSN:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                }
            }
            return false;

        // @see: https://github.com/qmk/qmk_firmware/issues/10111#issuecomment-752300353
        // ***NB***: this will only work if `NKRO_ENABLE = no` in the `rules.mk` file
        case KC_MCON:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_WINDOWS);
            }
            return false;

        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_APPS);
            }
            return false;

        default:
            return true; /* Process all other keycodes normally */
    }
}
