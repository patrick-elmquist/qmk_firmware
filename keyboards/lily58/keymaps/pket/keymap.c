#include QMK_KEYBOARD_H
#include <stdio.h>

#define RAISE_F LT(_RAISE, KC_F)
#define RAISE_J LT(_RAISE, KC_J)
#define SYM_D LT(_SYMBOL, KC_D)
#define SFT_ENT RSFT_T(KC_ENT)

#define RAISE OSL(_RAISE)
#define NUMBER OSL(_NUMBER)
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

#define SCLN_OE TD(TD_OE)
#define QUOT_AE TD(TD_AE)
#define MINS_AO TD(TD_AO)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMBER,
  _SYMBOL,
};

enum custom_keycodes {
    CKC_ARW = SAFE_RANGE
};

enum combos {
    CB_KL_CLN,
};

const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CB_KL_CLN] = COMBO(kl_combo, KC_COLN),
};

// TAP DANCE
typedef struct {
    uint16_t keycode;
} test_user_data_t;

#define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) \
        { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)user_user_data, }

void td_swe_each_tap(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = ((test_user_data_t*)user_data)->keycode;
    switch (state->count) {
        case 1 ... 2:
            break;
        case 3:
            tap_code16(keycode);
            tap_code16(keycode);
            break;
        default:
            tap_code16(keycode);
            break;
    }
}

void td_swe_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = ((test_user_data_t*)user_data)->keycode;
    if (state->count == 1) {
        register_code16(keycode);
    } else if (state->count == 2) {
        register_mods(MOD_BIT(KC_RALT));
        switch(keycode) {
            case KC_SCLN:
                register_code16(KC_P);
                break;
            case KC_QUOT:
                register_code16(KC_Q);
                break;
            case KC_MINS:
                register_code16(KC_W);
                break;
        }
    }
}

void td_swe_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = ((test_user_data_t*)user_data)->keycode;
    if (state->count == 1) {
        unregister_code16(keycode);
    } else if(state->count == 2) {
        unregister_mods(MOD_BIT(KC_RALT));
        switch(keycode) {
            case KC_SCLN:
                unregister_code16(KC_P);
                break;
            case KC_QUOT:
                unregister_code16(KC_Q);
                break;
            case KC_MINS:
                unregister_code16(KC_W);
                break;
        }
    } 
}

enum {
    TD_OE,
    TD_AE,
    TD_AO
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_OE] = ACTION_TAP_DANCE_FN_ADVANCED_USER(td_swe_each_tap, td_swe_finished, td_swe_reset, &((test_user_data_t){KC_SCLN})),
    [TD_AE] = ACTION_TAP_DANCE_FN_ADVANCED_USER(td_swe_each_tap, td_swe_finished, td_swe_reset, &((test_user_data_t){KC_QUOT})),
    [TD_AO] = ACTION_TAP_DANCE_FN_ADVANCED_USER(td_swe_each_tap, td_swe_finished, td_swe_reset, &((test_user_data_t){KC_MINS})),
};

// TODO
// - Move SWE handling to tap dance?
// - Should I perhaps disable the num row all together
// - Move Ctrl and Alt to Mod tap
// - Use Alt button and RGUI for something better, like layer toggle
//   for some rarely used layer like media or function keys.
// - Figure out if the left and right arrows belong on small layers
// - Add more small layers centered around the F and J
// - Add suspend block with oled off 
// - Create a pure media/system layer
// - Add a layer for toggling state, like Caps Lock and Win/Mac mode
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MINS_AO,
  CTL_ESC, KC_A,    KC_S,    SYM_D,   RAISE_F, KC_G,                        KC_H,    RAISE_J, KC_K,    KC_L,    SCLN_OE, QUOT_AE,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LALT, KC_LGUI, NUMBER,  LOW_SPC,  SFT_ENT,  RAISE,   KC_BSPC, KC_RALT
),

[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, PRV_TAB, NXT_TAB, _______,                     CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, _______, SWE_AO,
  _______, _______, _______, _______, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SWE_OE,  SWE_AE,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                     KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_EQL,  KC_LPRN, KC_RPRN, KC_DQUO, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______,  CKC_ARW, CKC_ARW,  KC_MINS, KC_PIPE, KC_AMPR, KC_UNDS, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_SYMBOL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_PLUS, _______,                     _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, _______, _______, _______, KC_EQL,  _______,                     _______, KC_LPRN, KC_RPRN, _______, _______, _______,
  _______, _______, _______, _______, KC_MINS, KC_LEFT,  _______, _______,  KC_RGHT, KC_PIPE, KC_AMPR, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_NUMBER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______, KC_LEFT,  _______, _______,  KC_RGHT, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

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
        case TD(TD_OE):
            return TAPPING_TERM;
        case TD(TD_AE):
        case TD(TD_AO):
            return TAPPING_TERM + 25;
        case LT(_LOWER, KC_SPC):
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

const char *read_logo(void);

#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

// int current_wpm = 0;

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
}

void update_log(void) {
    // if (timer_elapsed(log_timer) > 750) {
    //     add_keylog(0);
    // }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("Keys "), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ  "), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYM  "), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("NUM  "), false);
            break;
        default:
            oled_write_P(PSTR("undef"), false);
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
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR(" "), false);
}

// void render_wpm_status(void) {
//     oled_write_ln_P(PSTR("WPM"), false);
//     char wpm_str[8];
//     sprintf(wpm_str, "%03d", current_wpm);
//     oled_write_ln(wpm_str, false); 
// }


void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("     "), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("     "), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("     "), false);
    
    // Show WPM
    // render_wpm_status();
    
    // Add a empty line
    oled_write_P(PSTR("     "), false);
    // Show key log
    render_keylogger_status();
}

void suspend_power_down_user(void) {
    oled_off();
}

void oled_task_user(void) {
  // current_wpm = get_current_wpm();
  update_log();
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set_keylog(keycode, record);
    add_keylog(keycode);
#endif
  }

  mod_state = get_mods();
  switch (keycode) {
    case CKC_ARW:
        // Shortcut for typing ->
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;
  }
  return true;
}
