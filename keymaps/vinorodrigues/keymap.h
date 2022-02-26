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

#pragma once

#include QMK_KEYBOARD_H

enum keyboard_layers {
    LAYER_0 = 0,
    LAYER_1,
    LAYER_2,
    LAYER_3
};

enum custom_key_codes {
    KC_MCON = USER00,
    KC_LPAD,
    KB_VRSN = SAFE_RANGE
};

enum macos_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,  // mapped to KC_MCON
    _AC_SHOW_ALL_APPS    = 0x2A0   // mapped to KC_LPAD
};

#define LT1_C_L LT(LAYER_1, KC_CAPS)
// #define LCTL_UP C(KC_UP)
#define KC_NKRO MAGIC_TOGGLE_NKRO

#ifndef MIN
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
