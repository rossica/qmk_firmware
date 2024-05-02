// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include QMK_KEYBOARD_H

enum mitosis_layers
{
	_STD,
	_NUM,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
   * .--------------------------------------------..--------------------------------------------.
   * | Q      | W      | E      | R      | T      || Y      | U      | I      | O      | P      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | A      | S      | D      | F      | G      || J      | H      | K      | L      | ;      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | Z      | X      | C      | V      | B      || N      | M      | ,      | .      | /      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          | TAB    | ESC    | LCTRL  | DEL    || BSPC   | LEFT   | UP     | RIGHT  |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          | LALT   | LGUI   | FN     | SPACE  || ENTER  | NUM    | DOWN   | PSCR   |
   *          '-----------------------------------''-----------------------------------'
   */
  [_STD] = LAYOUT( /* Standard QWERTY */
    KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,         KC_S,    KC_D,    KC_F,    KC_G,      KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,
    SFT_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,      KC_N,      KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH),
          KC_TAB,  KC_ESC,  KC_LCTL,  KC_DEL,     KC_BSPC,  KC_LEFT, KC_UP,   KC_RGHT,
          KC_LALT, KC_LGUI, MO(_NUM), KC_SPC,     KC_ENT,   MO(_NUM),KC_DOWN, KC_PSCR
  ),

  /* Numbers and symbols
   * .--------------------------------------------..--------------------------------------------.
   * | F1     | F2     | F3     | F4     | F5     || F6     | F7     | F8     | F9     | F10    |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | 1      | 2      | 3      | 4      | 5      || 6      | 7      | 8      | 9      | 0      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | LSHIFT | F11    | `~     | =+     | [{     || ]}     | -_     | '"     | F12    | \|     |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        |        ||        | HOME   | PGUP   | END    |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        | PGDN   |        |
   *          '-----------------------------------''-----------------------------------'
   */
  [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, KC_F11,  KC_GRV,  KC_EQL,  KC_LBRC,       KC_RBRC, KC_MINS, KC_QUOT, KC_F12,  SFT_T(KC_BSLS),
             _______, _______, _______, _______,       _______, KC_HOME, KC_PGUP, KC_END,
             _______, _______, _______, _______,       _______, _______, KC_PGDN, _______
  ),

  /* blank key layout template
   * .--------------------------------------------..--------------------------------------------.
   * |        |        |        |        |        ||        |        |        |        |        |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        |        |        |        |        ||        |        |        |        |        |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        |        |        |        |        ||        |        |        |        |        |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        |        ||        |        |        |        |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        |        |
   *          '-----------------------------------''-----------------------------------'
   */

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    	case _STD:
    		set_led_off;
    		break;
      case _NUM:
        set_led_blue;
        break;
      default:
          break;
    }
};

