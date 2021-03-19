/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "mappings.h"
enum layers {
    _COLEMAK = 0, // Colemak Mod-DH https://colemakmods.github.io/mod-dh/
    _NUMBER,
    _SYMBOL,
    _CODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
      KC_GRV,   KC_Q,    KC_W,   KC_F,    KC_P,    KC_B,                                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
      CTL_BS,   GUI_A,   ALT_R,  CTL_S,   SHFT_T,  KC_G,                                           KC_K,    SHFT_N,  CTL_E,   ALT_I,   GUI_O,   KC_QUOT,
      KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_D,    KC_V,    KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                 _______, _______, KC_ESC,  KC_SPC,  KC_TAB,     NUM_ENT, SYM_BSP, CDE_DEL, _______, _______
    ),
    [_NUMBER] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_SYMBOL] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, KC_PLUS,
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_CODE] = LAYOUT(
      _______, _______, _______, KC_LCBR, KC_RCBR, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_LPRN, KC_RPRN, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    )
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 *   [_OLD_SYM] = LAYOUT(
 *     _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                        _______, _______, _______, _______, _______, KC_BSLS,
 *     _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                         KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
 *     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,    _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
 *                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
 *   )
 */
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
