#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WORD A(KC_RGHT)
#define BACK A(KC_LEFT)

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
  OS_LSFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
      XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
      XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
                                 XXXXXXX, KC_LGUI, LOWER,   KC_SPC,   KC_ENT,  RAISE,   KC_BSPC, XXXXXXX \
      ),

  [_LOWER] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, WORD,    _______, _______, _______,                    _______, _______, _______, _______, KC_DEL,  XXXXXXX, \
      XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, _______,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX, \
      XXXXXXX, _______, _______, _______, _______, BACK,    _______,  _______, _______, _______, _______, _______, KC_ENT,  XXXXXXX, \
                                 _______, _______, _______, _______,  _______, _______, _______, _______ \
      ),


  [_RAISE] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, XXXXXXX, \
      XXXXXXX, _______, _______, _______, _______, _______,                    _______, OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, XXXXXXX, \
      XXXXXXX, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, XXXXXXX, \
                                 _______, _______, _______, _______,  _______, _______, _______, _______ \
      ),

  [_NUM] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
      XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, XXXXXXX,                   XXXXXXX, OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, XXXXXXX, \
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
                                 _______, _______, _______, _______, _______, _______, _______, _______ \
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

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  update_oneshot( &os_shft_state, KC_LSFT, OS_LSFT, keycode, record);
  update_oneshot( &os_ctrl_state, KC_LCTL, OS_LCTL, keycode, record);
  update_oneshot( &os_alt_state, KC_LALT, OS_LALT, keycode, record);
  update_oneshot( &os_cmd_state, KC_LGUI, OS_LGUI, keycode, record);

  return true;
}
