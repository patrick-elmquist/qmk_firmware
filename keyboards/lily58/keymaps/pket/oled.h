#pragma once

#include QMK_KEYBOARD_H

// Append a keycode to the key log
void append_keylog(uint16_t keycode);

// Update the combo status
void update_combo_status(uint16_t combo_term, char id);
