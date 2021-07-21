#pragma once

#include QMK_KEYBOARD_H

// Render the case mode state: Caps, Snake, SNAKE, Camel
void render_case_mode_status(uint16_t delimiter, bool caps);

// Render Control, Alt, GUI, Shift indicators (2 lines)
void render_mod_status(uint8_t modifiers);

// Render an empty line (1 line)
void render_empty_line(void);

// Render the keylogger (2 lines)
void render_keylogger_status(void);

// Render the layer status (2 lines)
void render_default_layer_state(void);

// Append a keycode to the key log
void append_keylog(uint16_t keycode);

