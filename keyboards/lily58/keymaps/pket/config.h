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
//#define TAPPING_TERM_PER_KEY
#define TAPPING_FORCE_HOLD
// according to a discussion on discord, TAPPING_TERM_HOLD seems to be the reason
// for tap toggle not working properly when I tried it...

// TODO replace this by defining it in dynamically in code instead
#define COMBO_COUNT 13
// TODO add combo term per key instead
#define COMBO_TERM 50
#define COMBO_ALLOW_ACTION_KEYS

#define DISABLE_LEADER
