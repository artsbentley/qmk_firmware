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

#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#   include "combos.h"
#endif


#define _ALPHA_COLEMAK 0
#define _NAV 1
#define _SYM 2
#define _NUM 3



enum layers
{
    _ALPHA_COLEMAK = 0,
    _SYM,
    _NAV,
    _NUM,
};

enum custom_keycodes {
    KC_THUMB_SWAP,
};

/* Space Enter swap */
bool swap_space_enter = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * QWERTY
    *
    *                                          _____________________         _____________________
    *                                       __|__                   |       |                   __|__
    *                              _____   |     |                  v       v                  |     |   _____
    *                       .-----|  E  |-----._____                                         _____.-----|  I  |-----.
    *                 .-----|  W  |_____|  R  |  T  |  __           (       )           __  |  Y  |  U  |_____|  O  |-----.
    *             __  |  Q  |-----|  D  |-----|_____|  __|--> +                   - <--|__  |_____|-----|  K  |-----|  P  |  __
    *    ESC  <--|__  |-----|  S  |_____|  F  |  G  |               [       ]               |  H  |  J  |_____|  L  |-----|  __|--> '
    *             __  |  A  |-----|  C  |-----|_____|  __                               __  |_____|-----| , < |-----| ; : |  __
    *    TAB  <--|__  |-----|  X  |_____|  V  |  B  |  __|--> *     {       }     = <--|__  |  N  |  M  |_____| . > |-----|  __|--> "
    *                 |  Z  |-----'     '-----|_____|                                       |_____|-----'     '-----| / ? |
    *                 '-----'          .-----. _____   .-.._                           _..-.   _____ .-----.        '-----'
    *                    |             | WIN ||CTRL | /     /                         \     \ | BSp || Del |           |
    *                  SHIFT           '-----':_____|/ ENT /                           \ SPC \|_____:'-----'         SHIFT
    *                                     |         '--.._/                             \_..--'  |      |
    *                                    NUM                                                    NAV    SYM
    */
    [_ALPHA_QWERTY] = LAYOUT(
        KC_Q,         KC_W   , KC_F   , KC_P   , KC_B   ,                                    KC_J   , KC_L   , KC_U   , KC_Y   , KC_CAPS           ,
        KC_A,         KC_R   , KC_S   , KC_T   , KC_G   ,                                    KC_M   , KC_N   , KC_E   , KC_I   , KC_O        ,
        LSFT_T(KC_Z), LCTL_T(KC_X)   , KC_C   , KC_D   , KC_V   ,                                    KC_H   , KC_M   , KC_COMM, LCTL_T(KC_DOT) , LSFT_T(KC_TAB),
                                LALT(KC_NO), OSL(_SYM),  LT(_NAV,KC_SPC),       KC_SPC, LT(_NUM ,KC_ENT), KC_NO
    ),

    /*
    * Symbols
    *              _____                                                   _____
    *       .-----|  #  |-----._____                           _____.-----|  *  |-----.
    * .-----|  @  |_____|  $  |  %  |                         |  ^  |  &  |_____|  (  |-----.
    * |  !  |-----|     |-----|_____|                         |_____|-----| [ { |-----|  )  |
    * |-----|     |_____|     |     |                         |  {  |  }  |_____| ] } |-----|
    * | ` ~ |-----|     |-----|_____|                         |_____|-----|     |-----| ' " |
    * |-----|     |_____|     |     |                         | - _ | = + |_____|  |  |-----|
    * |  ~  |-----'     '-----|_____|                         |_____|-----'     '-----| \ | |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *  SHIFT           |     ||CTRL | /     /         \     \ | BSp ||     |           SHIFT
    *                  '-----':_____|/ ENT /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */
    [_SYM] = LAYOUT(
        KC_EXLM,         KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                KC_LT, KC_LBRC, KC_EQL, KC_RBRC, KC_GT        ,
        KC_QUES ,         KC_QUOT, KC_DQUO, KC_SCLN, KC_TILD,                                KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR        ,
        KC_NUHS,           KC_CIRC, KC_PIPE, KC_AMPR, KC_GRV,                                KC_SLSH, KC_UNDS , KC_MINS, KC_PLUS, KC_ASTR,
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /*
    * Navigation
    *              _____                                                   _____
    *       .-----|Mute |-----._____                           _____.-----| Up  |-----.
    * .-----|VDown|_____| VUp |     |                         |     |PDown|_____| PUp |-----.
    * | Esc |-----|Play |-----|_____|                         |_____|-----|Down |-----| BSp |
    * |-----|Prev |_____|Next |     |                         |Home |Left |_____|Right|-----|
    * | Tab |-----|Stop |-----|_____|                         |_____|-----|     |-----| ' " |
    * |-----|     |_____|     |     |                         |     |     |_____| End |-----|
    * | CPS |-----'     '-----|_____|                         |_____|-----'     '-----| Del |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *  SHIFT           |     ||CTRL | /     /         \     \ | BSp ||     |           SHIFT
    *                  '-----':_____|/ ENT /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */
    [_NAV] = LAYOUT(
        KC_1         , KC_MUTE, KC_VOLD, KC_VOLU, KC_5,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PSCR,
        OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_ESC,                                KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_H,
        LSFT_T(KC_6), LALT_T(KC_7), LCTL_T(KC_8), KC_NO, KC_0,                                KC_K, KC_M, LCTL_T(KC_NO), LALT_T(KC_NO), RSFT_T(KC_SCLN) ,
                                        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_DEL, KC_TRNS
    ),

    /*
    * Numbers
    *              _____                                                   _____
    *       .-----|  3  |-----._____                           _____.-----|  8  |-----.
    * .-----|  2  |_____|  4  |  5  |                         |  6  |  7  |_____|  9  |-----.
    * |  1  |-----| F3  |-----|_____|                         |_____|-----| F8  |-----|  0  |
    * |-----| F2  |_____| F4  | F5  |                         | F6  | F7  |_____| F9  |-----|
    * | F1  |-----| Scr |-----|_____|                         |_____|-----|     |-----| F10 |
    * |-----| TMg |_____|     |Swap |                         |     |     |_____| F11 |-----|
    * |Shift|-----'     '-----|_____|                         |_____|-----'     '-----| F12 |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *                  |     ||CTRL | /     /         \     \ | BSp ||     |           SHIFT
    *                  '-----':_____|/ ENT /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */
    [_NUM] = LAYOUT(
        KC_1   , KC_2       , KC_3      , KC_4   , KC_5         ,                                KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
        KC_1,    KC_2,        KC_3      , KC_4   , KC_5        ,                                KC_6   , KC_7   , KC_8   , KC_9   , KC_0 ,
        KC_LSFT, LCA(KC_DEL), SWIN(KC_S), XXXXXXX, KC_THUMB_SWAP,                                XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 , RSFT_T(KC_F12) ,
                                             KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        /* Space Enter swap */
        case KC_THUMB_SWAP:
            if (record->event.pressed) {
                unregister_code(KC_SPC);
                unregister_code(KC_ENT);
                swap_space_enter = !swap_space_enter;
            }
            return false;
            break;

        case KC_ENT:
            if (swap_space_enter) {
                if (record->event.pressed) {
                    register_code(KC_SPC);
                } else {
                    unregister_code(KC_SPC);
                }
                return false;
            }
            break;
        case KC_SPC:
            if (swap_space_enter) {
                if (record->event.pressed) {
                    register_code(KC_ENT);
                } else {
                    unregister_code(KC_ENT);
                }
                return false;
            }
            break;
    }
    return true;
}
