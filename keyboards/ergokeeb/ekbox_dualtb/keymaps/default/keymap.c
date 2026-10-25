#include QMK_KEYBOARD_H
#include "print.h"
#include "pointing_device.h"

enum custom_layers {
    _BASE = 0,   // 0 BASE
    _NAV = 1,    // 1 NAV
    _NUM = 2,    // 2 NUM
    _SYM = 3,    // 3 SYM
    _MOUSE = 4,  // 4 MOUSE
    _EXTRA = 5   // 5 EXTRA
};

// Thumb cluster layer-taps
#define NAV_SPC  LT(_NAV, KC_SPC)
#define NUM_ENT  LT(_NUM, KC_ENT)
#define SYM_BSP  LT(_SYM, KC_BSPC)
#define MSE_TAB  LT(_MOUSE, KC_TAB)
#define EXT_ESC  LT(_EXTRA, KC_ESC)

// Home Row Mods
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)    
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   RALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0 BASE (QWERTY with Home Row Mods)
   * ,----------------------------------.      ,----------------------------------.
   * |  Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |  P  |
   * |GUI/A|ALT/S|CTL/D|SFT/F|  G  |      |  H  |SFT/J|CTL/K|ALT/L|GUI/;|
   * |  Z  |  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  |  /  |
   * `----------------------------------'      `----------------------------------'
   *             | GUI | MSE/TAB| NAV/SPC|    | NUM/ENT| SYM/BSP| EXTRA/ESC |
   */
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    GUI_A,   ALT_S,   CTL_D,   SFT_F   ,   KC_G,       KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SCL,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      KC_RCTL, MSE_TAB, NAV_SPC,    NUM_ENT, SYM_BSP, EXT_ESC
  ),

  /* 1 NAV (Navigation & Editing)
   * ,----------------------------------.      ,----------------------------------.
   * |     |     |     |     |     |      | PgUp| Home| Up  | End |     |
   * |Shift|Ctrl | Alt | GUI |     |      | PgDn| Left| Down|Right|     |
   * |Undo | Cut |Copy |Paste|     |      |     |     |     |     |     |
   * `----------------------------------'      `----------------------------------'
   *             |     |     |        |    |        | Delete|     |
   */
  [_NAV] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,    _______, KC_DEL,  _______
  ),

  /* 2 NUM (Numpad)
   * ,----------------------------------.      ,----------------------------------.
   * |     |     |     |     |     |      |  /  |  7  |  8  |  9  |  -  |
   * |Shift|Ctrl | Alt | GUI |     |      |  *  |  4  |  5  |  6  |  +  |
   * |     |     |     |     |     |      |  0  |  1  |  2  |  3  |  =  |
   * `----------------------------------'      `----------------------------------'
   *             |     |     |        |    |        |       |  .  |
   */
  [_NUM] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,
                      _______, _______, _______,    _______, _______, KC_DOT
  ),

  /* 3 SYM (Symbols)
   * ,----------------------------------.      ,----------------------------------.
   * |  !  |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  (  |  )  |
   * |  \  |  |  |  -  |  _  |     |      |     |  =  |  +  |  {  |  }  |
   * |  `  |  ~  |     |     |     |      |     |     |     |  [  |  ]  |
   * `----------------------------------'      `----------------------------------'
   *             |     |     |        |    |        |       |     |
   */
  [_SYM] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, XXXXXXX,    XXXXXXX, KC_EQL,  KC_PPLS, KC_LCBR, KC_RCBR,
    KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,
                      _______, _______, _______,    _______, _______, _______
  ),

  /* 4 MOUSE (Trackball & Mouse Clicks)
   */
  [_MOUSE] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_UP,                XXXXXXX, KC_MS_WH_UP, KC_MS_UP,  KC_MS_WH_DOWN , XXXXXXX, 
    KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, KC_MS_WH_DOWN,   XXXXXXX,  KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   XXXXXXX, 
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                      _______, _______, _______,    _______,     _______,    _______
  ),

  /* 5 EXTRA (F-Keys, Media, Board Settings)
   * ,----------------------------------.      ,----------------------------------.
   * | F1  | F2  | F3  | F4  | F5  |      | F6  | F7  | F8  | F9  | F10 |
   * | F11 | F12 |     |     |     |      |VolUp| Mute|VolDn|     |     |
   * |BT1  |BT2  |BT3  |BT CLR|    |      |Prev |Play |Next |     |Reset|
   * `----------------------------------'      `----------------------------------'
   *             |     |     |        |    |        |       |     |
   */
  [_EXTRA] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,    KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT,
                      _______, _______, _______,    _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 800); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 2000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
// --- RIGHT TRACKBALL ROTATION (Mouse) ---
    // Store original values before modifying
    int8_t r_x = right_report.x;
    int8_t r_y = right_report.y;
    
    // Example: Rotate Right Trackball 90° Clockwise
    // (For 90° CCW, use: .x = -r_y, .y = r_x)
    // (For 180°, use: .x = -r_x, .y = -r_y)
    right_report.x = -r_y;
    right_report.y = -r_x;

    // --- LEFT TRACKBALL ROTATION (Scroll) ---
    // Store original values before modifying
    int8_t l_x = left_report.x;
    int8_t l_y = left_report.y;

    // Example: Rotate Left Trackball 90° Counter-Clockwise
    left_report.x = -l_y;
    left_report.y = l_x;
    
    // Convert the newly rotated left movement into scroll H/V movement
    left_report.h = left_report.x;
    left_report.v = -left_report.y; 
    left_report.x = 0;              // Prevent left trackball from moving the cursor
    left_report.y = 0;
    
    return pointing_device_combine_reports(left_report, right_report);
}