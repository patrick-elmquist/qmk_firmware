#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oneshot.h"
#include "swapper.h"
#include "oled.h"
#include "features/casemodes.h"

enum combos {
    L_SCLN_BSPC,
    J_K_ESC,
    K_L_TAB,
    U_I_EQL,

    S_D_LPRN,
    D_F_RPRN,
    S_F_PRN_PAIR_OUT,
    S_D_F_PRN_PAIR_IN,

    W_E_LCBR,
    E_R_RCBR,
    W_R_CBR_PAIR_OUT,
    W_E_R_CBR_PAIR_IN,

    ZX_UNDO,
    XC_COPY,
    CV_PASTE,
    XV_CUT,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// LEFT
// Paran
const uint16_t PROGMEM sd_paran_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_paran_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sf_paran_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM sdf_paran_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
// Curly braces
const uint16_t PROGMEM we_cbr_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_cbr_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wr_cbr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM wer_cbr_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
// Copy/Paste/Cut
const uint16_t PROGMEM zx_undo_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_cut_combo[] = {KC_X, KC_V, COMBO_END};

// RIGHT
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
// Esc, Tab, Bspc
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    [L_SCLN_BSPC] = COMBO(lscln_combo, KC_BSPC),
    [J_K_ESC] = COMBO(jk_combo, KC_ESC),
    [K_L_TAB] = COMBO(kl_combo, KC_TAB),
    [U_I_EQL] = COMBO(ui_combo, KC_EQL),

    [S_D_LPRN] = COMBO(sd_paran_combo, KC_LPRN),
    [D_F_RPRN] = COMBO(df_paran_combo, KC_RPRN),
    [S_F_PRN_PAIR_OUT] = COMBO_ACTION(sf_paran_combo),
    [S_D_F_PRN_PAIR_IN] = COMBO_ACTION(sdf_paran_combo),

    [W_E_LCBR] = COMBO(we_cbr_combo, KC_LPRN),
    [E_R_RCBR] = COMBO(er_cbr_combo, KC_RPRN),
    [W_R_CBR_PAIR_OUT] = COMBO_ACTION(wr_cbr_combo),
    [W_E_R_CBR_PAIR_IN] = COMBO_ACTION(wer_cbr_combo),

    [ZX_UNDO] = COMBO(zx_undo_combo, LGUI(KC_Z)),
    [XC_COPY] = COMBO(xc_copy_combo, LGUI(KC_C)),
    [CV_PASTE] = COMBO(cv_paste_combo, LGUI(KC_V)),
    [XV_CUT] = COMBO(xv_cut_combo, LGUI(KC_X)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,  \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
                                   XXXXXXX, XXXXXXX, LOWER,   KC_SPC,   ENT_SFT, RAISE,   XXXXXXX, XXXXXXX \
        ),

    // Mnemonic for Alfred and iTerm is T for Terminal and G for Goto
    [_LOWER] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_ESC,  _______, SW_WIN,  _______, ITERM,                      _______, CAPS,    SNAKE,   CAMEL,   KC_DEL,  XXXXXXX, \
        XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, ALFRED,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX, \
        XXXXXXX, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_ENT,  XXXXXXX, \
                                   _______, _______, __LOW__, _______,  _______, __RAS__, _______, _______ \
        ),

    [_RAISE] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_PIPE,                    KC_AMPR, KC_EQL,  KC_PLUS, KC_MINS, _______, XXXXXXX, \
        XXXXXXX, _______, _______, KC_LPRN, KC_RPRN, _______,                    KC_COLN, OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, XXXXXXX, \
        XXXXXXX, _______, _______, KC_LBRC, KC_RBRC, _______, _______,  _______, KC_SLSH, _______, _______, _______, _______, XXXXXXX, \
                                   _______, _______, __LOW__, _______,  _______, __RAS__, _______, _______ \
        ),

    [_NUM_NEW] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                    G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), XXXXXXX, \
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
        XXXXXXX, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, XXXXXXX, \
                                   _______, _______, __LOW__, _______,  _______, __RAS__, _______, _______ \
        ),

    // TODO Add a VIM layer toggled by ENTER
    // Add:
    // - KC_COLN and KC_SLSH on right index
    // - Perhaps add ?, # and * for easy access to navigate
    // - May possible to include more for navigation, like numbers and d, j, k, y, c
    // - Try to make some best match where as many utilities exist in the same position as on base and sym layers
    [_NUM] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
        XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, XXXXXXX,                    XXXXXXX, OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, XXXXXXX, \
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
                                   _______, _______, __LOW__, _______,  KC_BSPC, __RAS__, _______, _______ \
        )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _NUM);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

uint16_t delimiter = KC_NO; // used to keep track of which mode we are in

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_empty_line();
        render_default_layer_state();
        render_empty_line();
        render_case_mode_status(delimiter, caps_word_enabled());
        render_empty_line();
        render_mod_status(get_mods());
        render_empty_line();
        render_keylogger_status();
    } else {
        oled_write(read_logo(), false);
    }
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LOWER:
        case RAISE:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LOWER:
        case RAISE:
        case KC_LSFT:
        case OS_LSFT:
        case OS_LCTL:
        case OS_LALT:
        case OS_LGUI:
            return true;
        default:
            return false;
    }
}

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case CAPS:
        case SNAKE:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                delimiter = KC_NO;
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                delimiter = KC_NO;
                return true;
            }
            break;
    }
    return false;
}

bool sw_win_active = false;
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        append_keylog(keycode);
    }

    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);
    update_oneshot(&os_shft_state, KC_LSFT, OS_LSFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LGUI, OS_LGUI, keycode, record);

    if (!process_case_modes(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CAPS:
            if (record->event.pressed) {
                // TODO
                // - I could add a timer and check for long press to turn it on perment
                // - When adding a number layer, make dubble tapping it toggle NUMWORD
                // - Fix the combo term to avoid misfires
                toggle_caps_word();
            }
            break;
        case SNAKE:
        case CAMEL:
            if (record->event.pressed) {
                delimiter = keycode == SNAKE ? KC_UNDS : OSM(MOD_LSFT);
                enable_xcase_with(delimiter);
            }
            break;
    }
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    switch(combo_index) {
        case S_F_PRN_PAIR_OUT:
            send_string("()");
            break;
        case S_D_F_PRN_PAIR_IN:
            send_string("()");
            tap_code16(KC_LEFT);
            break;
        case W_R_CBR_PAIR_OUT:
            send_string("{}");
            break;
        case W_E_R_CBR_PAIR_IN:
            send_string("{}");
            tap_code16(KC_LEFT);
            break;
    }
}

void suspend_power_down_user(void) {
    oled_off();
}

