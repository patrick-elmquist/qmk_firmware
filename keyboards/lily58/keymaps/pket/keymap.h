#pragma once

#include QMK_KEYBOARD_H

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ALFRED RGUI(KC_SPC)
#define ITERM RGUI(KC_ESC)
#define CTL_ESC LCTL_T(KC_ESC)

#define __LOW__ _______
#define __RAS__ _______
#define ENT_SFT RSFT_T(KC_ENT)

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    OS_LCTL = SAFE_RANGE,
    OS_LALT,
    OS_LGUI,
    OS_LSFT,

    SW_WIN,
    CAPS,
    CAMEL,
    SNAKE,
    SNK_SCM,

    SE_AO,
    SE_AE,
    SE_OE
};
