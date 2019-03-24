#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_DVORAK,
    LAYER_SYMBOLS,
    LAYER_ADJUST,
};

// Custom keycodes
enum {
    KC_CUSTOM_RESET = SAFE_RANGE
};
#define KC_CRST KC_CUSTOM_RESET

// Fillers to make layering more clear

// Left shift when held, caps lock when tapped
#define KC_SCL LSFT_T(KC_CAPSLOCK)

// Switch to function layer when held, escape when tapped
#define AD_ESC LT(LAYER_ADJUST, KC_ESCAPE)

// Layer switches
#define QWERTY DF(LAYER_QWERTY)
#define DVORAK DF(LAYER_DVORAK)
#define SYMBOLS MO(LAYER_SYMBOLS)
#define SYMBLS SYMBOLS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |SPACE | ENT  |                             | BCSP | DEL  |
 *                             |------+------|                             |------+------|
 *                             |RAISE |LOWER |                             | CTRL | ALT  |
 *                             |------+------|                             |------+------|
 *                             | CMD  | META |                             | FN   |SUPER |
 *                             +-------------+                             +-------------+
 */

[LAYER_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,   \
    AD_ESC,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_SCL,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_SCL,   \
                    KC_LBRC,KC_RBRC,                                            KC_PLUS,KC_EQL,                    \
                                   KC_SPC , KC_ENT,             KC_BSPC,  KC_DEL,                                  \
                                   _______, KC_LCTL,            KC_LALT,  _______,                                 \
                                   _______, _______,            _______,  _______                                  \
),
/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |  END |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | ESC  | HOME |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |SPACE | ENT  |                             | BCSP | DEL  |
 *                             |------+------|                             |------+------|
 *                             |RAISE |LOWER |                             | CTRL | ALT  |
 *                             |------+------|                             |------+------|
 *                             | CMD  | META |                             | FN   |SUPER |
 *                             +-------------+                             +-------------+
 */

/* Base (lower)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                             | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |      |      |      |      |      |                             |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |SPACE | ENT  |                             | BCSP | DEL  |
 *                             |------+------|                             |------+------|
 *                             |RAISE |LOWER |                             | CTRL | ALT  |
 *                             |------+------|                             |------+------|
 *                             | CMD  | META |                             | FN   |SUPER |
 *                             +-------------+                             +-------------+
 */

/* Base (fn)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |  f1  |  f2  |  f3  |  f4  |  f5  |                             |  f6  |  f7  |  f8  |  f9  | f10  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |      |      |      |      |      |                             |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |SPACE | ENT  |                             | BCSP | DEL  |
 *                             |------+------|                             |------+------|
 *                             |RAISE |LOWER |                             | CTRL | ALT  |
 *                             |------+------|                             |------+------|
 *                             | CMD  | META |                             | FN   |SUPER |
 *                             +-------------+                             +-------------+
 */

[LAYER_DVORAK] = LAYOUT(
    _______, KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y   ,            KC_F,    KC_G,  KC_C,   KC_R,   KC_L,   KC_UNDS,   \
    KC_TAB, KC_A,   KC_O,   KC_E,   KC_U,   KC_I,               KC_D,    KC_H,  KC_T,   KC_N,   KC_S,   KC_COLN,   \
    _______,KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,               KC_B,    KC_M,  KC_W,   KC_V,   KC_Z,   KC_SLSH,   \
                    _______,_______,                                            _______,_______,                   \
                                    KC_SCL, KC_SPC,             KC_ENT, KC_BSPC,                                   \
                                    KC_LALT,SYMBLS,             SYMBLS, KC_LCTL,                                   \
                                    _______,KC_LWIN,            _______,KC_ESC                                     \
),

[LAYER_SYMBOLS] = LAYOUT(
    _______, _______,_______,_______,_______,_______,            KC_PEQL,KC_PPLS,KC_PMNS,KC_PAST,KC_PSLS,KC_CIRC,   \
    _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,   \
    _______,_______,_______,_______,_______,_______,            KC_LBRC,KC_RBRC,KC_LPRN,KC_RPRN,_______,_______,   \
                    _______,_______,                                            KC_LCBR,KC_RCBR,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

[LAYER_ADJUST] = LAYOUT(
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
