#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// IDEAS:
// - Consider moving Shift from index fingers to regular position and
//   Space or Enter button.
// - Implement NUMWORD and CAPSWORD described in this post:
//   https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/
// - Also look at the symbols sorting in the video, look logical when
//   first seeing it.
// - Have a look at this SWE keymap, I'm I overcomplicating things by
//   using the special SWE_ keycodes, could I just use the standard
//   once and still not have dead keys?
//   https://github.com/marketplace/actions/close-stale-issues
// - Could have SYS and other low-usage layers on the {[]} thumb buttons 
// - Add media keys to some layer
// - Instead of having double modifiers on the ADJUST layer, maybe use
//   one shot modifiers instead? That way media keys could go on the same
//   layer.

// DONE:
// - Add hold for double/triple character like in the blog post above. 
// - Also consider splitting the numbers like in the same post or in the
//   following video:
//   https://www.youtube.com/watch?v=yiwUjLaebuw
// - Make the : key easily accessible.
// - Add Word and Back to NAV layer by LALT(KC_LEFT/RIGHT), it makes it
//   simpler than using the home row mods while doing it.

[_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  XXXXXXX, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCN,KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_LBRC, KC_COLN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             _______, _______, LOWER,    KC_SPC,  KC_ENT,   RAISE,   _______, _______
),

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                       KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, _______,
  _______, KC_9,    KC_7,    KC_1,    KC_3,    KC_5,                        KC_4,    KC_2,    KC_0,    KC_6,    KC_8,    _______,
  _______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,  _______, _______,  KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
                             _______, _______, LOWER,    _______, KC_ENT,   _______,   _______, _______
),

[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, WORD,    _______, _______, _______,                     G(KC_C), _______, _______, _______, G(KC_V), _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, BACK,     _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, KC_ENT,   _______, _______, _______
),

// Enables quick VIM navigation with easy access to j,k and G
// Also enables the CMD - 1,2,3... that was missing in the previous version
[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_9,    KC_7,    KC_1,    KC_3,    KC_5,                        KC_4,    KC_2,    KC_0,    KC_6,    KC_8,    XXXXXXX,
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, S(KC_G),                     XXXXXXX, KC_J,    KC_K,    XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______,  _______, KC_ENT,   _______, _______, _______
),


// F-Keys and Modifiers
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                     XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_DRIVER_ENABLE
// static void render_logo(void) {
//   static const char PROGMEM my_logo[] = {
//      // 'Untitled-1', 128x32px
// 0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x60, 0xc0, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03, 0x00, 0x00, 
// 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0xff, 0x22, 0x41, 0x41, 0x41, 0x63, 0x1e, 0x00, 
// 0x00, 0xff, 0x22, 0x41, 0x41, 0x41, 0x63, 0x1e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 
// 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x3e, 0x63, 0x41, 0x41, 0x63, 0x3e, 0x00, 
// 0x00, 0x7f, 0x22, 0x41, 0x41, 0x41, 0x63, 0x3e, 0x00, 0x00, 0x7f, 0x22, 0x41, 0x41, 0x41, 0x63, 
// 0x3e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
// 0x02, 0x01, 0x01, 0x01, 0x7e, 0x00, 0x00, 0x34, 0x4b, 0x49, 0x49, 0x29, 0x7e, 0x40, 0x00, 0x7f, 
// 0x02, 0x01, 0x00, 0x01, 0x7f, 0x41, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 
// 0x00, 0x00, 0x08, 0x70, 0x80, 0x00, 0x80, 0x70, 0x08, 0xc0, 0xa0, 0xa0, 0xc0, 0x00, 0x00, 0xe0, 
// 0x20, 0x00, 0x00, 0xa0, 0xa0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x03, 
// 0x00, 0x00, 0x03, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//   };
// 
//   oled_write_raw_P(my_logo, sizeof(my_logo));
// }
// 
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (true || is_keyboard_master()) {
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
    oled_write_P(PSTR("MACRO"), false);

    oled_write_P(PSTR("l"), false);
    oled_write_P(dm_1_set ? PSTR(".") : PSTR(" "), false);
    oled_write_P(PSTR("r"), false);
    oled_write_P(dm_2_set ? PSTR(".") : PSTR(" "), false);

    if (recording_macro) {
        render_dm_record();
    } else {
        oled_write_P(PSTR(" "), false);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("LOG  "), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    if (timer_elapsed(log_timer) > BLINK_TIMEOUT) {
        blink_timeout = true;
    }

    bool blink = (timer_read() % 1000) < BLINK_INTERVAL || blink_timeout;

    oled_write_P(PSTR("$"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(blink ? PSTR("_") : PSTR(" "), false);
            oled_write_P(PSTR("   "), false); 
            return;
        case _LOWER:
            oled_write_P(PSTR("LOW"), false); 
            break;
        case _RAISE:
            oled_write_P(PSTR("RAI"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_P(PSTR("UDF"), false);
            break;
    }
    oled_write_P(blink ? PSTR("_") : PSTR(" "), false);
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("LOCK"), false);
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

void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln("", false);

    // Show layer
    render_default_layer_state();
    oled_write_ln("", false);

    // Show if macros are stored
    render_dynamic_macro_state();
    oled_write_ln("", false);

    // Show modifier status
    render_mod_status(get_mods());
    oled_write_ln("", false);
    // Show key log
    render_keylogger_status();
  } else {
    oled_write_ln("", false);

    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    oled_write_ln("", false);

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (KEY_DOWN) {
#ifdef OLED_DRIVER_ENABLE
        add_keylog(keycode);
#endif
        if (recording_macro) {
            log_macro_len(keycode);
        }
    }
    return true;
}
