#include "oled.h"
#include "keymap.h"

void render_empty_line(void) {
    oled_write_ln("", false);
}

void render_case_mode_status(uint16_t delimiter, bool caps) {
    oled_write_ln_P(PSTR("Mode"), false);
    if (delimiter == KC_UNDS) {
        if (caps) {
            oled_write_P(PSTR("SN_KE"), false);
        } else {
            oled_write_P(PSTR("sn_ke"), false);
        }
    } else if (delimiter == OSM(MOD_LSFT)) {
        oled_write_P(PSTR("cAmEl"), false);
    } else if (caps) {
        oled_write_P(PSTR("CAPS "), false);
    } else {
        oled_write_P(PSTR("-    "), false);
    }
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
}

#define KEYLOG_LEN 6
#define BLINK_TIMEOUT 10000
#define BLINK_INTERVAL 500

static char     keylog_str[KEYLOG_LEN] = { ' ', ' ', ' ', ' ', ' ', 0};
static uint16_t log_timer              = 0;
static bool     blink_timeout          = false;

static const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void append_keylog(uint16_t keycode) {
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

void render_keylogger_status(void) {
    oled_write_P(PSTR("Hist."), false);
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
        case _NUM:
            oled_write_P(PSTR("NUM"), false);
            break;
        default:
            oled_write_P(PSTR("UDF"), false);
            break;
    }
    oled_write_P(blink ? PSTR("_") : PSTR(" "), false);
}
