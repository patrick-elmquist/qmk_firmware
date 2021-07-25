/*
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

#define TAPPING_TERM 200
#define TAPPING_FORCE_HOLD
// according to a discussion on discord, TAPPING_TERM_HOLD seems to be the reason
// for tap toggle not working properly when I tried it...

// TODO add combo term per key instead
#define COMBO_TERM 40
#define COMBO_TERM_PER_COMBO

#define COMBO_ONLY_FROM_LAYER 0

// #define COMBO_ALLOW_ACTION_KEYS
// #define COMBO_VARIABLE_LEN

// Should reduce the total firmware footprint according to some blog post
#define DISABLE_LEADER
