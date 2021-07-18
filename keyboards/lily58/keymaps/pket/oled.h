#pragma once

#include QMK_KEYBOARD_H

void render_keylock_status(led_t led_state);

void render_mod_status(uint8_t modifiers);

void render_empty_line(void);

void render_keylogger_status(void);

void render_debug_status(void);

void add_keylog(uint16_t keycode);

void add_debug(uint16_t keycode);
