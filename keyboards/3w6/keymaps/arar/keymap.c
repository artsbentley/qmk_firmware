/* Copyright 2021 HellSingCoder
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

// #include "layout.h"
// #include "stdint.h"
#include QMK_KEYBOARD_H
#include <stdint.h>
// #include "g/keymap_combo.h"


// #include "config.h"
#pragma once

#define COMBO_VARIABLE_LEN

// #define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger

enum layers
{
    _ALPHA_COLEMAK = 0,
    _SYM,
    _NAV,
    _NUM,
};

#define _ALPHA_COLEMAK 0
#define _NAV 1
#define _SYM 2
#define _NUM 3

// #define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // /*
    // */
   
    [_ALPHA_COLEMAK] = LAYOUT(
        KC_Q,         KC_W   , KC_F   , KC_P   , KC_B   ,                                    KC_J   , KC_L   , KC_U   , KC_Y   , CW_TOGG           ,
        KC_A,         KC_R   , KC_S   , KC_T   , KC_G   ,                                    KC_M   , KC_N   , KC_E   , KC_I   , KC_O        ,
        LSFT_T(KC_Z), LGUI_T(KC_X)   , KC_C   , KC_D   , KC_V   ,                            KC_K   , KC_H   , KC_COMM, LGUI_T(KC_DOT) , LSFT_T(KC_TAB),
                                LALT(KC_NO), OSL(_SYM),  LT(_NAV,KC_SPC),       LSFT_T(KC_BSPC), LT(_NUM ,KC_ENT), LALT(KC_NO)
    ),

 
    [_SYM] = LAYOUT(
        KC_EXLM,         KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                KC_LT, KC_LBRC, KC_EQL, KC_RBRC, KC_GT        ,
        KC_QUES ,         KC_QUOT, KC_DQUO, KC_SCLN, KC_TILD,                                KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR        ,
        KC_NUHS,           KC_CIRC, KC_PIPE, KC_AMPR, KC_GRV,                                KC_SLSH, KC_UNDS , KC_MINS, KC_PLUS, KC_ASTR,
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_NAV] = LAYOUT(
        KC_1         , KC_MUTE, KC_VOLD, KC_VOLU, KC_5,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PSCR,
        OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_ESC,                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_H,
        LSFT_T(KC_TRNS), LGUI_T(KC_TRNS), KC_8, KC_NO, KC_0,                                KC_K, KC_M, KC_NO, LGUI_T(KC_TRNS), RSFT_T(KC_TRNS) ,
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    LALT(KC_BSPC), KC_DEL, KC_TRNS
    ),

    [_NUM] = LAYOUT(
        KC_1   , KC_2       , KC_3      , KC_4   , KC_5         ,                                KC_6   , KC_7   , KC_UP   , KC_9   , KC_0   ,
        KC_1,    KC_2,        KC_3      , KC_4   , KC_5        ,                                KC_6   , KC_7   , KC_8   , KC_9   , KC_0 ,
        KC_LSFT, LCA(KC_DEL), SWIN(KC_S), KC_DOWN, KC_TRNS,                                XXXXXXX, KC_6, XXXXXXX, KC_F11 , RSFT_T(KC_F12) ,
                                             KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

enum combo_events {
  EM_EMAIL,

  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
COMBO_LENGTH = 3

// left hand combinations.
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM a_r_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM p_b_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM f_b_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM w_p_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM x_d_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_d_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM z_b_combo[] = {KC_Z, KC_B, COMBO_END};

// right hand combinations.
const uint16_t PROGMEM y_en_combo[] = {KC_Y, KC_ENTER, COMBO_END};
const uint16_t PROGMEM l_u_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM j_l_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM k_h_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM j_slash_combo[] = {KC_J, KC_SLASH, COMBO_END};
const uint16_t PROGMEM dot_tab_combo[] = {KC_DOT, KC_TAB, COMBO_END};


combo_t key_combos[] = {
//   [EM_EMAIL] = COMBO_ACTION(email_combo),
  COMBO(w_f_combo , KC_TAB),
	COMBO(z_x_combo, L_CTL),
	COMBO(dot_tab_combo, L_CTL)
};

// #define NXTTAB LCTL(KC_PGDN)
// #define PRVTAB LCTL(KC_PGUP)
// #define UPTAB  LCTL(LSFT(KC_PGUP))
// #define DNTAB  LCTL(LSFT(KC_PGDN))
// #define NXTWIN LALT(KC_TAB)
// #define PRVWIN LALT(LSFT(KC_TAB))
// #define TSKMGR LCTL(LSFT(KC_ESC))
// #define EXPLR  LGUI(KC_E)
// #define LCKGUI LGUI(KC_L)
// #define CONPST LSFT(KC_INS)
// #define CLSGUI LALT(KC_F4)

// combo_t key_combos[COMBO_COUNT] = {
    // left hand combinations.
//   COMBO(q_w_combo, KC_ESCAPE)};
//   COMBO(p_b_combo, KC_TAB),
//   COMBO(w_p_combo, KC_LGUI),
  
//   COMBO(w_f_combo, KC_LCTL),
//   COMBO(f_p_combo, KC_LSFT),
//   COMBO(f_b_combo, KC_LALT),
//   /*
//   COMBO(c_v_combo, KC_END),
//   COMBO(z_x_combo, KC_INSERT),
//   COMBO(x_d_combo, KC_HOME),
//   COMBO(f_p_combo, KC_UP),
//   COMBO(x_c_combo, KC_LEFT),
//   COMBO(c_d_combo, KC_DOWN),
//   COMBO(d_v_combo, KC_RIGHT),
//   */
//   COMBO(y_en_combo, KC_ENTER),
// //   COMBO(j_l_combo, KC_DELT)
// };
