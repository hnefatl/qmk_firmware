#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_ADJUST,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_FN,
};

// Custom keycodes
enum {
    KC_CUSTOM_RESET = SAFE_RANGE
};
#define KC_CRST KC_CUSTOM_RESET

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Fillers to make layering more clear

// Left shift when held, caps lock when tapped
#define KC_SCL LSFT_T(KC_CAPSLOCK)

// Switch to function layer when held, escape when tapped
#define AD_ESC LT(LAYER_ADJUST, KC_ESCAPE)

// Layer switches
#define QWERTY DF(LAYER_QWERTY)
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define FN MO(LAYER_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |  `   |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |  '   |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |SHIFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |SHIFT |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |   \  |   =  |                                                         | STIC |   -  |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |ETNER |SPACE |                             | BCSP | DEL  |
 *                             |------+------|                             |------+------|
 *                             |RAISE |LOWER |                             | CTRL | ALT  |
 *                             |------+------|                             |------+------|
 *                             | CMD  |SUPER |                             | FN   | META |
 *                             +-------------+                             +-------------+
 */

[LAYER_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,   \
    AD_ESC,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_SCL,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_SCL,   \
                    KC_BSLS,KC_EQL,                                             _______,KC_MINUS,                  \
                                   KC_ENT , KC_SPC ,            KC_BSPC,  KC_DEL ,                                 \
                                    RAISE ,  LOWER ,            KC_LCTL,  KC_LALT,                                 \
                                   _______, _______,              FN   ,  KC_LGUI                                 \
),

/* Base (lower)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                             | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |      |      |      |      |      |                             |      |  [{  | }]   |  up  | right|      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |      |      |                                                         | left | down |
 *               +-------------+                                                         +-------------+
 */
[LAYER_LOWER] = LAYOUT(
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,XXXXXXX,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,XXXXXXX,XXXXXXX,  \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,KC_LBRC,KC_RBRC, KC_UP , KC_RIGHT,_______, \
                    XXXXXXX,XXXXXXX,                                            KC_LEFT,KC_DOWN,                   \
                                    _______,_______,            _______,_______,                                   \
                                    XXXXXXX,XXXXXXX,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (raise)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                             | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |      |      |      |      |      |                             |      |  [{  | }]   |  up  | right|      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |      |      |                                                         | left | down |
 *               +-------------+                                                         +-------------+
 */
[LAYER_RAISE] = LAYOUT(
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,XXXXXXX,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,XXXXXXX,XXXXXXX,  \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,KC_LBRC,KC_RBRC, KC_UP , KC_RIGHT,_______, \
                    XXXXXXX,XXXXXXX,                                            KC_LEFT,KC_DOWN,                   \
                                    _______,_______,            _______,_______,                                   \
                                    XXXXXXX,XXXXXXX,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (fn)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |  f1  |  f2  |  f3  |  f4  |  f5  |                             |  f6  |  f7  |  f8  |  f9  | f10  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                             | MUTE | VOL- | VOL+ | MUTE |      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |      |      |      |      |      |                             |      | BRI- | BRI+ |      |      |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |      |      |                                                         |      |      |
 *               +-------------+                                                         +-------------+
 */
[LAYER_FN] = LAYOUT(
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,XXXXXXX,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_MUTE,KC_VOLD,KC_VOLU,KC_MUTE,XXXXXXX,XXXXXXX,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,KC_BRID,KC_BRIU,XXXXXXX,XXXXXXX,_______,   \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    XXXXXXX,XXXXXXX,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),


[LAYER_ADJUST] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
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
