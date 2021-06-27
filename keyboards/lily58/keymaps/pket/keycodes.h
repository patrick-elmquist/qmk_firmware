#pragma once

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_BSPC)

#define WORD A(KC_RIGHT)
#define BACK A(KC_LEFT)

// Home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCN RCTL_T(KC_SCLN)

// MacOS shortcuts
#define G_TILDE G(KC_TILDE)
#define G_LBC G(KC_LBRC)
#define G_RBC G(KC_RBRC)
#define G_S_LBC G(S(KC_LBRC))
#define G_S_RBC G(S(KC_RBRC))
#define G_Z_PLS G(KC_PLUS)
#define G_Z_MNS G(KC_MINS)
#define G_Z_ZRO G(KC_0)

#define KEY_DOWN (record->event.pressed)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    MKO_ARW = SAFE_RANGE,   // ->
    MKO_ELQ,                // ?:
    MKO_ELD,                // ?.
    SWE_TGL,
    SWE_AE,
    SWE_OE,
    SWE_AO,
};


