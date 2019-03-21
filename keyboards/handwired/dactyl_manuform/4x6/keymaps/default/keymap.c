#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_DVORAK,
    LAYER_SYMBOLS,
    LAYER_FUNCTION,
};

// Custom keycodes
enum {
    KC_CUSTOM_RESET = SAFE_RANGE
};
#define KC_CRST KC_CUSTOM_RESET

// Fillers to make layering more clear

// Left shift when held, caps lock when tapped
#define KC_SCL LSFT_T(KC_CAPSLOCK)

// Escape when tapped, switch to function layer when held
#define KC_RST LT(LAYER_FUNCTION, KC_ESCAPE)

// Layer switches
#define QWERTY DF(LAYER_QWERTY)
#define DVORAK DF(LAYER_DVORAK)
#define SYMBOLS MO(LAYER_SYMBOLS)
#define SYMBLS SYMBOLS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_QWERTY] = LAYOUT( \
    KC_RST,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,   \
    KC_TAB,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    _______, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLASH, \
                    KC_LBRC,KC_RBRC,                                            KC_PLUS,KC_EQL,                    \
                                    KC_SCL, KC_SPC,             KC_ENT,  KC_BSPC,                                  \
                                    _______,SYMBLS,             SYMBLS,  _______,                                  \
                                    _______,_______,            DVORAK,  _______                                   \
),

[LAYER_DVORAK] = LAYOUT(
    KC_RST, KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y   ,            KC_F,    KC_G,  KC_C,   KC_R,   KC_L,   _______,   \
    KC_TAB, KC_A,   KC_O,   KC_E,   KC_U,   KC_I,               KC_D,    KC_H,  KC_T,   KC_N,   KC_S,   _______,   \
    _______,KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,               KC_B,    KC_M,  KC_W,   KC_V,   KC_Z,   _______,   \
                    _______,_______,                                            _______,_______,                   \
                                    KC_SCL, KC_SPC,             KC_ENT, KC_BSPC,                                   \
                                    _______,SYMBLS,             SYMBLS, _______,                                   \
                                    _______,_______,            QWERTY, _______                                    \
),

[LAYER_SYMBOLS] = LAYOUT(
    KC_RST, _______,_______,_______,_______,_______,            KC_PEQL,KC_PPLS,KC_PMNS,KC_PAST,KC_PSLS,KC_CIRC,   \
    _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,   \
    _______,_______,_______,_______,_______,_______,            KC_LBRC,KC_RBRC,KC_LPRN,KC_RPRN,_______,_______,   \
                    _______,_______,                                            KC_LCBR,KC_RCBR,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

[LAYER_FUNCTION] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______, QWERTY,             DVORAK,_______                                    \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_CUSTOM_RESET && record->event.pressed) {
        // Send enter then reset the keyboard, so the flash script can proceed
        register_code(KC_ENTER);
        reset_keyboard();
    }
    return true;
}