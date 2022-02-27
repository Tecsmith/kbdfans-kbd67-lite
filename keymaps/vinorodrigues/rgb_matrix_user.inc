/* Copyright 2022 u/bactaholic (https://www.reddit.com/user/bactaholic/)
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


// -------------------- STAR LIGHT -------------------- //

#ifdef ENABLE_RGB_MATRIX_STAR_LIGHT
    RGB_MATRIX_EFFECT(STAR_LIGHT)

    #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

        static void star_light_set_color(int i, effect_params_t* params) {
            if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
                HSV hsv = rgb_matrix_config.hsv;
                uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
                hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
                RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

        bool STAR_LIGHT(effect_params_t* params) {
            if (!params->init) {
                if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
                    star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
                }
                return false;
            }

            RGB_MATRIX_USE_LIMITS(led_min, led_max);
            for (int i = led_min; i < led_max; i++) {
                star_light_set_color(i, params);
            }
            return rgb_matrix_check_finished_leds(led_max);
        }

    #endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // ENABLE_RGB_MATRIX_STAR_LIGHT

// -------------------- DUAL SAT STAR LIGHT -------------------- //

#ifdef ENABLE_RGB_MATRIX_DUAL_SAT_STAR_LIGHT
    RGB_MATRIX_EFFECT(DUAL_SAT_STAR_LIGHT)

    #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

        static void dual_sat_star_light_set_color(int i, effect_params_t* params) {
            if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
                HSV hsv = rgb_matrix_config.hsv;
                uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
                hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
                hsv.s = hsv.s + (rand() % (30 + 1 - -30) + -30);
                RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

        bool DUAL_SAT_STAR_LIGHT(effect_params_t* params) {
            if (!params->init) {
                if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
                    dual_sat_star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
                }
                return false;
            }

            RGB_MATRIX_USE_LIMITS(led_min, led_max);
            for (int i = led_min; i < led_max; i++) {
                dual_sat_star_light_set_color(i, params);
            }
            return rgb_matrix_check_finished_leds(led_max);
        }

    #endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif  // ENABLE_RGB_MATRIX_DUAL_SAT_STAR_LIGHT


// -------------------- DUAL HUE STAR LIGHT -------------------- //

#ifdef ENABLE_RGB_MATRIX_DUAL_HUE_STAR_LIGHT
    RGB_MATRIX_EFFECT(DUAL_HUE_STAR_LIGHT)

    #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

        static void dual_hue_star_light_set_color(int i, effect_params_t* params) {
            if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
                HSV hsv = rgb_matrix_config.hsv;
                uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
                hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
                hsv.h = hsv.h + (rand() % (30 + 1 - -30) + -30);
                RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

        bool DUAL_HUE_STAR_LIGHT(effect_params_t* params) {
            if (!params->init) {
                if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
                    dual_hue_star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
                }
                return false;
            }

            RGB_MATRIX_USE_LIMITS(led_min, led_max);
            for (int i = led_min; i < led_max; i++) {
                dual_hue_star_light_set_color(i, params);
            }
            return rgb_matrix_check_finished_leds(led_max);
        }

    #endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif  // ENABLE_RGB_MATRIX_DUAL_HUE_STAR_LIGHT
