#include QMK_KEYBOARD_H

#define _BASE 0
#define _OPT 1
#define _LOC 2

// Keycodes for umlauts and eszett
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)

// Keycodes for dead keys
enum custom_keycodes {
    MC_QUOT = SAFE_RANGE,
    MC_GRV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _BASE layer, default
	*  .-----------------------------------------------------------------------------------------------------.
	*  | Esc | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|Print| Del | Home| End | PgU | PgD |
	*  .-----------------------------------------------------------------------------------------------------.
	*  |  ~` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |   0|  - |  = |    BkSpc  | NLk |  /  |  *  |  -  |
	*  .-----------------------------------------------------------------------------------------------------.
	*  | Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  { |  } |   \      |  7  |  8  |  9  |  +  |
	*  .-----------------------------------------------------------------------------------------------.     .
	*  | _LOC  |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; | '  |      Return  |  4  |  5  |  6  |     | 
	*  .-----------------------------------------------------------------------------------------------------.
	*  | LShft  |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |   RShft     | Up |  1  |  2  |  3  | En  |
	*  .--------------------/--------------------------------------------------------------------------.     .
	*  | Ctrl | LGUI | Alt |            Space               |LAlt|_OPT|Ctrl|Left|Down|Rght |  0  |  .  | ter |
	*  .-----------------------------------------------------------------------------------------------------.
	*/
    [_BASE] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_PSCR, KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
        MC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        MO(_LOC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MAC_QUO,  KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,          KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_OPT), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT
    ),

    /* _OPT layer, settings
    *  .-----------------------------------------------------------------------------------------------------.
	*  |RESET|    |    |    |    |    |    |    |    |    |    |    |    | MUTE| VOL+| VOL-|     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
	*  |     |    |    |    |    |    |    |    |    |    |    |    |    |           |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
	*  |      |RTog|    |RMod|HUE+|HUE-|SAT+|SAT-|VAL+|VAL-|    |    |    |          |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------.     .
	*  |       |    |    |    |    |    |    |    |    |    |    |    |              |     |     |     |     | 
	*  .-----------------------------------------------------------------------------------------------------.
	*  |        |    |    | BL+|BTog| BL-|    |    |    |    |    |             |    |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------.     .
	*  |      |      |     |                                |    |    |    |    |    |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
    */

    [_OPT] = LAYOUT_all(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
        _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _LOC layer, umlauts and special characters
    *  .-----------------------------------------------------------------------------------------------------.
	*  |     |    |    |    |    |    |    |    |    |    |    |    |    |     |     |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
	*  |     |    |    |    |    |    |    |    |    |    |    |  ß |    |           |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
	*  |      |    |    |    |    |    |    |  Ü |    |  Ö |    |  Ü |    |          |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------.     .
	*  |       |  Ä |  ß |    |    |    |    |    |    |    |  Ö |  Ä |              |     |     |     |     | 
	*  .-----------------------------------------------------------------------------------------------------.
	*  |        |    |    |    |    |    |    |    |    |    |    |             |    |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------.     .
	*  |      |      |     |                                |    |    |    |    |    |     |     |     |     |
	*  .-----------------------------------------------------------------------------------------------------.
    */
    [_LOC] = LAYOUT_all(
        _______  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GER_SZ,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, UML_UE,  _______, UML_OE,  _______, UML_UE,  _______, _______,          _______, _______, _______, _______,
        _______, UML_AE,  GER_SZ,  _______, _______, _______, _______, _______, _______, _______, UML_OE,  UML_AE,  _______,                   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
        }
        break;
    case MC_GRV:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
        }
        break;
    }
    return true;
};
