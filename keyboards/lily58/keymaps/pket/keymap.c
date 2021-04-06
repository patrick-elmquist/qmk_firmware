#include QMK_KEYBOARD_H
#include <stdio.h>

#define LT_LBRC TD(TD_LT_LBRC) 
#define GT_RBRC TD(TD_GT_RBRC) 

#define RAISE_F LT(_RAISE, KC_F)
#define RAISE_J LT(_RAISE, KC_J)
#define SYM_D LT(_SYMBOL, KC_D)
#define RAISE_ENT LT(_RAISE, KC_ENT)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define RAISE_ESC LT(_RAISE, KC_ESC)

#define RAISE MO(_RAISE)
#define NUMBER MO(_NUMBER)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define CTL_ESC LCTL_T(KC_ESC)

#define NXT_TAB C(KC_TAB)
#define PRV_TAB C(LSFT(KC_TAB))

#define CTL_UP C(KC_UP)
#define CTL_DWN C(KC_DOWN)
#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RGHT)

#define SWE_AO RALT(KC_W)
#define SWE_AE RALT(KC_Q)
#define SWE_OE RALT(KC_P)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCN RCTL_T(KC_SCLN)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMBER,
  _NUMPAD,
  _SYMBOL,
};

enum custom_keycodes {
    CKC_ARW = SAFE_RANGE,
    CKC_HME,
};

enum combos {
//    CB_KL_CLN,
    CB_DIR_UP,
};

//const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM dir_up_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
 //   [CB_KL_CLN] = COMBO(kl_combo, KC_COLN),
    [CB_DIR_UP] = COMBO_ACTION(dir_up_combo),
};

enum {
    TD_LT_LBRC,
    TD_GT_RBRC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LT_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_LBRC),
    [TD_GT_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_GT, KC_RBRC),
};

// TODO
// - Should I perhaps disable the num row all together
// - Use Alt button and RGUI for something better, like layer toggle
//   for some rarely used layer like media or function keys.
// - Figure out if the left and right arrows belong on small layers
// - Add more small layers centered around the F and J
// - Create a pure media/system layer
// - Add a layer for toggling state, like Caps Lock and Win/Mac mode
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  CTL_ESC, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCN,KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LALT, KC_LGUI, NUM_TAB, LOW_SPC,  RAISE_ENT,RAISE_ESC,   KC_BSPC, KC_RALT
),

[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, PRV_TAB, NXT_TAB, _______,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, SWE_AO,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SWE_OE,  SWE_AE,
  _______, _______, _______, _______, _______, _______,  _______, _______,  CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, CKC_HME,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                     KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_EQL,  KC_LPRN, KC_RPRN, KC_DQUO, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______,  CKC_ARW, CKC_ARW,  KC_MINS, KC_PIPE, KC_AMPR, KC_UNDS, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_NUMBER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______, KC_LEFT,  _______, _______,  KC_RGHT, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

// BEGIN New stuff for home row mods
[_NUM_LEFT] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, KC_7,    KC_8,    KC_9,    KC_0,                        KC_PLUS, _______, _______, _______, _______, _______,
  _______, _______, KC_4,    KC_5,    KC_6,    KC_SLSH,                     KC_EQL,  KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
  _______, _______, KC_1,    KC_2,    KC_3,    KC_ASTR,  _______, _______,  KC_MINS, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_S_NUM_LEFT] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_EQL,                      KC_PLUS, _______, _______, _______, _______, _______,
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______,                     KC_EQL,  KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______,  _______, _______,  KC_MINS, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_SYM_RIGHT] = LAYOUT( // TODO create a system layer to put the ../ and ~/ keys on, combine with modified arrow keys
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, KC_AMPR, KC_UNDS,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                     KC_EQL,  KC_EXLM, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO,
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_MINS, KC_DLR,  LT_LBRC, GT_RBRC, KC_QUES, KC_BSLS,
                             _______, _______, _______,  _______, _______,  CKC_ARW, KC_LEFT, KC_RGHT
),
// END 

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  DM_REC1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC2,
  DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_RSTP,
  DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY2,
                             _______, _______, _______, _______, _______, _______, _______, _______
)
};

// TEMPLATE
// [_UNDEF] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
//                              _______, _______, _______,  _______, _______,  _______, _______, _______
// ),

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LGUI_T(KC_D):
        case RGUI_T(KC_K):
            return TAPPING_TERM + 75;
        case LALT_T(KC_S):
        case LALT_T(KC_L):
            return TAPPING_TERM + 75;
        case LCTL_T(KC_A):
        case RCTL_T(KC_SCLN):
            return TAPPING_TERM + 75;
        case LT(_LOWER, KC_SPC):
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
     // 'Untitled-1', 128x32px
0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x60, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03, 0x00, 0x00, 
0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0xff, 0x22, 0x41, 0x41, 0x41, 0x63, 0x1e, 0x00, 
0x00, 0xff, 0x22, 0x41, 0x41, 0x41, 0x63, 0x1e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 
0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x3e, 0x63, 0x41, 0x41, 0x63, 0x3e, 0x00, 
0x00, 0x7f, 0x22, 0x41, 0x41, 0x41, 0x63, 0x3e, 0x00, 0x00, 0x7f, 0x22, 0x41, 0x41, 0x41, 0x63, 
0x3e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
0x02, 0x01, 0x01, 0x01, 0x7e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0x7f, 
0x02, 0x01, 0x00, 0x01, 0x7f, 0x41, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x08, 0x70, 0x80, 0x00, 0x80, 0x70, 0x08, 0xc0, 0xa0, 0xa0, 0xc0, 0x00, 0x00, 0xe0, 
0x20, 0x00, 0x00, 0xa0, 0xa0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x03, 
0x00, 0x00, 0x03, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

const char *read_logo(void);

#define KEYLOG_LEN 6
#define BLINK_TIMEOUT 10000
#define BLINK_INTERVAL 500

char     keylog_str[KEYLOG_LEN] = { ' ', ' ', ' ', ' ', ' ', 0};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;
bool     blink_timeout          = false;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
    blink_timeout = false;
}

bool recording_macro    = false;
bool dm_1_set           = false;
bool dm_2_set           = false;
int macro_len           = 0;

void dynamic_macro_record_start_user(void) {
    recording_macro = true;
    macro_len = 0;
}

void dynamic_macro_record_end_user(int8_t direction) {
    if (direction == 1) {
        dm_1_set = macro_len > 0;
    } else if (direction == -1) {
        dm_2_set = macro_len > 0;
    }
    recording_macro = false;
    macro_len = 0;
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("Keys "), false);
    oled_write(keylog_str, false);
}

void render_dm_record(void) {
    static const char PROGMEM font_dm_record[2] = {0x19, 0};
    oled_write_P(font_dm_record, false);
}

void render_dynamic_macro_state(void) {
    oled_write_P(PSTR("Macro"), false);

    oled_write_P(PSTR("L"), false);
    oled_write_P(dm_1_set ? PSTR(".") : PSTR(" "), false);
    oled_write_P(PSTR("R"), false);
    oled_write_P(dm_2_set ? PSTR(".") : PSTR(" "), false);

    if (recording_macro) {
        render_dm_record();
    } else {
        oled_write_P(PSTR(" "), false);
    }
}

void render_default_layer_state(void) {
    if (timer_elapsed(log_timer) > BLINK_TIMEOUT) {
        blink_timeout = true;
    }

    bool blink = (timer_read() % 1000) < BLINK_INTERVAL || blink_timeout;
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(blink ? PSTR(">_   ") : PSTR(">    "), false);
            break;
        case _LOWER:
            oled_write_ln_P(blink ? PSTR(">lo_ ") : PSTR(">lo  "), false);
            break;
        case _RAISE:
            oled_write_ln_P(blink ? PSTR(">hi_ ") : PSTR(">hi  "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(blink ? PSTR(">adj_") : PSTR(">adj "), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(blink ? PSTR(">sym_") : PSTR(">sym "), false);
            break;
        case _NUMBER:
            oled_write_ln_P(blink ? PSTR(">num_") : PSTR(">num "), false);
            break;
        default:
            oled_write_ln_P(blink ? PSTR(">udf_") : PSTR(">udf "), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
    oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
}

void render_status_main(void) {
    oled_write_ln("", false);

    // Show keyboard layout
    render_default_layer_state();
    oled_write_ln("", false);

    // Show if macros are stored
    render_dynamic_macro_state();
    oled_write_ln("", false);

    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    oled_write_ln("", false);

    // Show modifier status
    render_mod_status(get_mods());
    oled_write_ln("", false);

    // Show key log
    render_keylogger_status();
}

void suspend_power_down_user(void) {
    oled_off();
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    render_logo();
    // oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    add_keylog(keycode);
#endif
  }
  if (recording_macro) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    } else {
        switch (keycode) {
            case DYN_REC_START1:
            case DYN_REC_START2:
            case DYN_MACRO_PLAY1:
            case DYN_MACRO_PLAY2:
            case DYN_REC_STOP:
                break;
            default:
                macro_len++;
        }
    }
  }
  switch (keycode) {
    case CKC_HME:
        if (record->event.pressed) {
            SEND_STRING("~/");
        }
        break;
    case CKC_ARW:
        // Shortcut for typing ->
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
  }
  return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case CB_DIR_UP:
            if (pressed) {
// - Add suspend block with oled off 
// - Add suspend block with oled off 
                SEND_STRING("../");
            }
            break;
    }
}
