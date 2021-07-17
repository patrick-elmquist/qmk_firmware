#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oneshot.h"
#include "swapper.h"
#include "features/casemodes.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ALFRED RGUI(KC_SPC)
#define ITERM RGUI(KC_ESC)

#define __LOW__ _______
#define __RAS__ _______
#define __CTL__ _______
#define __ALT__ _______
#define __GUI__ _______
#define __SFT__ _______
#define ENT_SFT RSFT_T(KC_ENT)
#define Z_SFT LSFT_T(KC_Z)
#define SLH_SFT RSFT_T(KC_SLSH)

// Left-hand home row mods
#define HME_A LCTL_T(KC_A)
#define HME_S LALT_T(KC_S)
#define HME_D LGUI_T(KC_D)
#define HME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HME_J RSFT_T(KC_J)
#define HME_K RGUI_T(KC_K)
#define HME_L LALT_T(KC_L)
#define HME_SCL RCTL_T(KC_SCLN)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NUM,
};

enum custom_keycodes {
  OS_LCTL = SAFE_RANGE,
  OS_LALT,
  OS_LGUI,
  OS_LSFT,

  SW_WIN,
  CAPSWRD,
  SNAKEWD
};

enum combos {
  L_SCLN_BSPC,
  J_K_ESC,
  K_L_TAB,
  U_I_EQL,
  M_COM_COLN,
  S_D_PARAN,
  D_F_PARAN,
  SPC_R_CBR,
  SPC_F_PRN
};

const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM sd_paran_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_paran_combo[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM spc_f_prn[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM spc_r_cbr[] = {KC_SPC, KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [L_SCLN_BSPC] = COMBO(lscln_combo, KC_BSPC),
  [J_K_ESC] = COMBO(jk_combo, KC_ESC),
  [K_L_TAB] = COMBO(kl_combo, KC_TAB),
  [U_I_EQL] = COMBO(ui_combo, KC_EQL),
  [S_D_PARAN] = COMBO(sd_paran_combo, KC_LPRN),
  [D_F_PARAN] = COMBO(df_paran_combo, KC_RPRN),
  [M_COM_COLN] = COMBO(mcom_combo, KC_COLN),

  [SPC_F_PRN] = COMBO_ACTION(spc_f_prn),
  [SPC_R_CBR] = COMBO_ACTION(spc_r_cbr),
};

// Main gripes with the new layout:
// - Shift does not feel intuitive
// - Backspac on layer works, but would probably work better closer to the index finger
// - Numbers should probably not be on Adjust layer, needs to be easier to access.
//
// Things I like about the new layout:
// - Having the possibility to use Combos again
// - Love the Esc combo
// - The shortcuts for Alfred and iTerm are nice
// - CMD TAB switcher is also nice
// 
// VIM related:
// - The C highlighting really sucks, try install some plugin for it (like polyglot I think it was called)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,  \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  SLH_SFT, KC_MINS, \
                                 XXXXXXX, XXXXXXX, LOWER,   KC_SPC,   ENT_SFT, RAISE,   XXXXXXX, XXXXXXX \
      ),

  // Mnemonic for Alfred and iTerm is T for Terminal and G for Goto
  [_LOWER] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, KC_ESC,  _______, SW_WIN,  _______, ITERM,                      _______, CAPSWRD, SNAKEWD, _______, KC_DEL,  XXXXXXX, \
      XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, ALFRED,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX, \
      XXXXXXX, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_ENT,  XXXXXXX, \
                                 _______, _______, __LOW__, _______,  KC_BSPC, __RAS__, _______, _______ \
      ),

  [_RAISE] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_PIPE,                    KC_AMPR, KC_EQL,  KC_PLUS, KC_MINS, _______, XXXXXXX, \
      XXXXXXX, _______, _______, KC_LPRN, KC_RPRN, _______,                    KC_COLN, OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, XXXXXXX, \
      XXXXXXX, _______, _______, KC_LBRC, KC_RBRC, _______, _______,  _______, KC_SLSH, _______, _______, _______, _______, XXXXXXX, \
                                 _______, _______, __LOW__, _______,  KC_BSPC, __RAS__, _______, _______ \
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
  if (!is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
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
            case CAPSWRD:
            case SNAKEWD:
                // If mod chording disable the mods
                if (record->event.pressed && (get_mods() != 0)) {
                    return true;
                }
                break;
            default:
                if (record->event.pressed) {
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
    set_keylog(keycode, record);
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
    case CAPSWRD:
      if (record->event.pressed) {
        // TODO probably need to add SNAKE and CAPS as exceptions to the
        //      different types of cases so they don't cancel each other
        //      Also: 
        //      - Add camelCase 
        //      - Support BSPC in all cases
        // I could add a timer and check for long press to turn it on perment
        toggle_caps_word();
      }
      break;
    case SNAKEWD:
      if (record->event.pressed) {
        enable_xcase_with(KC_UNDS);
      }
      break;
  }
  return true;
}


void process_combo_event(uint16_t combo_index, bool pressed) {
  if (!pressed) return;

  switch(combo_index) {
    case SPC_F_PRN:
      send_string("()");
      break;
    case S_D_PARAN:
      send_string("(");
      break;
    case D_F_PARAN:
      send_string("()");
      tap_code16(KC_LEFT);
      break;
    case SPC_R_CBR:
      send_string("{}");
      tap_code16(KC_LEFT);
      break;
  }
}

// OLED
void suspend_power_down_user(void) {
    oled_off();
}

