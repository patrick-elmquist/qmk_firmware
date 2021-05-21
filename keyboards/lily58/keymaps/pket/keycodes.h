#pragma once

#define TAB_NAV LT(_NAV, KC_TAB)
#define TAB_SYM LT(_SYM, KC_TAB)
#define TAB_NUM LT(_NUM, KC_TAB)
#define TAB_SYS LT(_SYS, KC_TAB)

#define SPC_NUM LT(_NUM, KC_SPC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define SPC_SYM LT(_SYM, KC_SPC)

#define ENT_SYM LT(_SYM, KC_ENT)
#define ENT_NUM LT(_NUM, KC_ENT)

#define BSP_NUM LT(_NUM, KC_BSPC)
#define BSP_SYM LT(_SYM, KC_BSPC)

#define ESC_SYS LT(_SYS, KC_ESC)
#define ESC_NAV LT(_NAV, KC_ESC)

// Home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCN RCTL_T(KC_SCLN)

#define DEBUG TG(_DBG)
#define SWE TG(_SWE)

// Debug shortcuts
#define RESUME A(G(KC_R))
#define STP_IN KC_F7
#define STP_OUT S(KC_F8)
#define STP_OVR KC_F8
#define TO_CURS A(KC_F9)
#define TO_EXPR A(KC_F10)
#define TGL_BPT G(KC_F8)
#define SHW_BPT G(S(KC_F8))
#define EVAL_EX A(KC_F8)

// MacOS shortcuts
#define G_TILDE G(KC_TILDE)
#define G_LBC G(KC_LBRC)
#define G_RBC G(KC_RBRC)
#define G_S_LBC G(S(KC_LBRC))
#define G_S_RBC G(S(KC_RBRC))
#define G_PLUS G(KC_PLUS)
#define G_MINUS G(KC_MINS)

#define KEY_DOWN (record->event.pressed)

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _SYS,
  _NAV,
  _NUM,
  _SWE,
  _FN,
  _DBG,
};

enum custom_keycodes {
    CKC_ARW = SAFE_RANGE,
    CKC_HME,
    CKC_DUP,
    SWE_TGL,
    SWE_AE,
    SWE_OE,
    SWE_AO,
    CLN_FN
};


