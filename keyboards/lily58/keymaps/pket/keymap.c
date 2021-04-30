#include QMK_KEYBOARD_H
#include <stdio.h>

// TODO
// - Have the symbol switch, either on the space button or on the other hand
//   It makes it a lot easier to type quickly, currently the thumb needs to move
//   when swapping layers.
// - 
// 

// DEBUG
#define RESUME A(G(KC_R))
#define STP_IN KC_F7
#define STP_OUT S(KC_F8)
#define STP_OVR KC_F8
#define TO_CURS A(KC_F9)
#define TO_EXPR A(KC_F10)
#define TGL_BPT G(KC_F8)
#define SHW_BPT G(S(KC_F8))
#define EVAL_EX A(KC_F8)

#define TAB_NAV LT(_NAV, KC_TAB)
#define TAB_SYM LT(_SYM, KC_TAB)
#define TAB_NUM LT(_NUM, KC_TAB)
#define TAB_SYS LT(_SYS, KC_TAB)

#define SPC_NUM LT(_NUM, KC_SPC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define SPC_SYM LT(_SYM_2, KC_SPC)

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

#define CTL_LFT C(KC_LEFT)
#define CTL_UP C(KC_UP)
#define CTL_DWN C(KC_DOWN)
#define CTL_RGT C(KC_RGHT)

#define DEBUG TG(_DBG)
#define SWE TG(_SWE)

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _SYM_2,
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
    SWE_AE,
    SWE_OE,
    SWE_AO,
    CLN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  LT(_SYM_2, KC_G),             KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCN,KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_LBRC, KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             DEBUG,   TAB_SYS, ESC_NAV,   SPC_SYM, ENT_SYM,  BSP_NUM, CLN_FN,  SWE
),

/*
 * ,-------------------,    ,-------------------.
 * | ! | # | { | | | } |    | ` | - | _ |-> | \ |
 * |---+---+---+---+---+    +---+---+---+---+---|
 * | ! | @ | ( | $ | ) |    | : | + | = | * | ; |
 * |---+---+---+---+---+    +---+---+---+---+---|
 * | % | ^ | [ | & | ] |    | ~ | / | < | > | ? |
 * `-------------------'    '-------------------'
 */                       
[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_HASH, KC_LCBR, KC_PIPE, KC_RCBR,                     KC_GRV,  KC_UNDS, KC_MINS, CKC_ARW, KC_BSLS, _______,
  _______, KC_EXLM, KC_AT,   KC_LPRN, KC_DLR,  KC_RPRN,                     KC_COLN, KC_EQL,  KC_PLUS, KC_ASTR, KC_SCLN, KC_DQUO,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_AMPR, KC_RBRC,  _______, _______,  KC_TILD, KC_SLSH, KC_LT,   KC_GT,   KC_QUES, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_SYM_2] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     KC_EXLM, KC_LPRN, KC_PIPE, KC_RPRN, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_EQL,  KC_LCBR, KC_AMPR, KC_RCBR, KC_COLN, KC_DQUO,
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_DLR,  CKC_ARW, KC_UNDS, _______, KC_QUES, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_FN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       _______, _______, _______, _______, _______, _______, 
  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                      _______, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_NAV] = LAYOUT( 
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, _______, _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______, KC_CAPS,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_SWE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, SWE_OE,  SWE_AE,
  _______, _______, _______, _______, _______, _______,  SWE_AO,  _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),


[_DBG] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, STP_OUT, RESUME,  EVAL_EX,                     _______, SHW_BPT, TGL_BPT, _______, _______, _______,
  _______, _______, _______, STP_IN,  STP_OVR, TO_EXPR,                     _______, _______, _______, _______, _______, _______,  
  _______, _______, _______, _______, _______, TO_CURS,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_SYS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  DM_REC1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC2,
  DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, DM_RSTP,
  DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY2,
                             _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LT(_SYM, KC_H):
        case LT(_FN, KC_N):
        case LGUI_T(KC_D):
        case RGUI_T(KC_K):
            return TAPPING_TERM + 100;
        case LALT_T(KC_S):
        case LALT_T(KC_L):
            return TAPPING_TERM + 100;
        case LCTL_T(KC_A):
        case RCTL_T(KC_SCLN):
            return TAPPING_TERM + 100;
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

void render_keylogger_status(void) {
    oled_write_P(PSTR("Keys "), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    if (timer_elapsed(log_timer) > BLINK_TIMEOUT) {
        blink_timeout = true;
    }

    bool blink = (timer_read() % 1000) < BLINK_INTERVAL || blink_timeout;
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(blink ? PSTR(">_   ") : PSTR(">    "), false); break;
        case _SYM:
            oled_write_ln_P(blink ? PSTR(">sym_") : PSTR(">sym "), false); break;
        case _SYM_2:
            oled_write_ln_P(blink ? PSTR(">sy2_") : PSTR(">sy2 "), false); break;
        case _NUM:
            oled_write_ln_P(blink ? PSTR(">num_") : PSTR(">num "), false); break;
        case _NAV:
            oled_write_ln_P(blink ? PSTR(">nav_") : PSTR(">nav "), false); break;
        case _FN:
            oled_write_ln_P(blink ? PSTR(">fn_ ") : PSTR(">fn  "), false); break;
        case _SYS:
            oled_write_ln_P(blink ? PSTR(">sys_") : PSTR(">sys "), false); break;
        case _DBG:
            oled_write_ln_P(blink ? PSTR(">dbg_") : PSTR(">dbg "), false); break;
        case _SWE:
            oled_write_ln_P(blink ? PSTR(">swe_") : PSTR(">swe "), false); break;
        default:
            oled_write_ln_P(blink ? PSTR(">udf_") : PSTR(">udf "), false); break;
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

    // Show layer
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
void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    render_logo();
    // oled_write(read_logo(), false);
  }
}

void suspend_power_down_user(void) {
    oled_off();
}

#endif // OLED_DRIVER_ENABLE

void log_macro_len(uint16_t keycode) {
    if (!(keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) && !(keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
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

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        add_keylog(keycode);
#endif
        if (recording_macro) {
            log_macro_len(keycode);
        }
    }

    static uint16_t my_colon_timer;
    mod_state = get_mods();
        switch (keycode) {
            case CKC_HME: 
                if (record->event.pressed) SEND_STRING("~/"); 
                break;
            case CKC_ARW: 
                if (record->event.pressed) SEND_STRING("->"); 
                break;
            case CKC_DUP:
                if (record->event.pressed) SEND_STRING("../"); 
                break;

            case SWE_AE:
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                   tap_code16(A(KC_U)); 
                   set_mods(mod_state);
                   tap_code16(KC_A);
                }
                break;
            case SWE_OE:
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                   tap_code16(A(KC_U)); 
                   set_mods(mod_state);
                   tap_code16(KC_O);
                }
                break;
            case SWE_AO:
                if (record->event.pressed) {
                   tap_code16(A(KC_A)); 
                }
                break;

            case CLN_FN:
                if (record->event.pressed)  {
                    my_colon_timer = timer_read();
                    layer_on(_FN);
                } else {
                    layer_off(_FN);
                    if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
                        SEND_STRING(":");
                    }
                }
                return false;
            // case KC_BSPC: {
            //     static bool delkey_registered;
            //     if (record->event.pressed) {
            //         if (mod_state & MOD_MASK_SHIFT) {
            //             del_mods(MOD_MASK_SHIFT);
            //             register_code(KC_DEL);
            //             delkey_registered = true;
            //             set_mods(mod_state);
            //             return false;
            //         }
            //     } else {
            //         if (delkey_registered) {
            //             unregister_code(KC_DEL);
            //             delkey_registered = false;
            //             return false; 
            //         }
            //     }
            // } break;
        }
    return true;
}
                          
                          
