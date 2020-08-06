// see drashna's configs for explanations
#pragma once

// block definitions are actually comma separated arguments so we need a wrapper
// to expand the definitions before being used as arguments to LAYOUT_xxx macro.
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define _________________COL_MOD_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _________________COL_MOD_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________COL_MOD_L3________________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________COL_MOD_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COL_MOD_R2________________       KC_K,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COL_MOD_R3________________       KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________NUMBER_LEFT_______________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_RIGHT______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________NUMPAD_1__________________       _______, KC_P7,   KC_P8,   KC_P9,   _______
#define _________________NUMPAD_2__________________       _______, KC_P4,   KC_P5,   KC_P6,   KC_P0
#define _________________NUMPAD_3__________________       _______, KC_P1,   KC_P2,   KC_P3,   _______
#define _________________NUMPAD_4__________________       _______, KC_P0,   KC_P0,   KC_PDOT, _______

#define ___________________BLANK___________________       _______, _______, _______, _______, _______
// clang-format on
