/*

/m TEMPLATE
// [_UNDEF] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
//                              _______, _______, _______,  _______, _______,  _______, _______, _______
// ),

This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

// #define COMBO_COUNT 1
// #define COMBO_TERM 75

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Added to save space, remove if feature is needed
#define DISABLE_LEADER

#ifdef OLED_FONT_H
    #undef OLED_FONT_H
#endif
#define OLED_FONT_H "keyboards/lily58/keymaps/pket/glcdfont.c"
