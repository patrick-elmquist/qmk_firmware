#pragma once

#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _NUM,
};

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
