#include QMK_KEYBOARD_H
#include <qp.h>
#include "print.h"
#include "image/my_image.qgf.h"
#include "image/ekss.qgf.h"
#include "font/arial.qff.h"

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
  /* 0 BASE (4x6 + 4 Thumb Keys) */
  [_BASE] = LAYOUT_4x6_4(
    // Left Half                                                    Right Half
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_MINS, KC_EQL,  KC_LBRC,         KC_RBRC, KC_BSLS, KC_GRV,  KC_RGUI, KC_RALT, KC_RCTL,

    // Left Thumbs                                                  Right Thumbs
                      KC_RCTL, MSE_TAB, NAV_SPC, EXT_ESC,         EXT_ESC, NUM_ENT, SYM_BSP, KC_DEL
  ),

  /* 1 NAV (Navigation & Editing) */
  [_NAV] = LAYOUT_4x6_4(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                      _______, _______, _______, _______,         _______, KC_DEL,  _______, _______
  ),

  /* 2 NUM (Numpad) */
  [_NUM] = LAYOUT_4x6_4(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,         KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                      _______, _______, _______, _______,         _______, _______, KC_DOT,  _______
  ),

  /* 3 SYM (Symbols) */
  [_SYM] = LAYOUT_4x6_4(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    XXXXXXX, KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, XXXXXXX,         XXXXXXX, KC_EQL,  KC_PPLS, KC_LCBR, KC_RCBR, XXXXXXX,
    XXXXXXX, KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                      _______, _______, _______, _______,         _______, _______, _______, _______
  ),

  /* 4 MOUSE (Trackball & Mouse Clicks) */
  [_MOUSE] = LAYOUT_4x6_4(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_UP,     XXXXXXX, KC_MS_WH_UP, KC_MS_UP,   KC_MS_WH_DOWN, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, KC_MS_WH_DOWN, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,         XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX,

                      _______, _______, _______, _______,         _______, _______,    _______,    _______
  ),

  /* 5 EXTRA (F-Keys, Media, Board Settings) */
  [_EXTRA] = LAYOUT_4x6_4(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,         KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                      _______, _______, _______, _______,         _______, _______, _______, _______
  )
};

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}

static bool is_v_scroll_active = false;
static bool is_h_scroll_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    
    is_v_scroll_active = (mods & MOD_MASK_SHIFT);
    is_h_scroll_active = (mods & MOD_MASK_CTRL);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return mouse_report;
}

static painter_image_handle_t testimg;
static painter_device_t display;

enum HSL
{
    HUE,
    SAT,
    VAL,
};

const uint8_t black[] = {0,   0,   0};
const uint8_t white[] = {0,   0,   255};
const uint8_t red[]   = {0,   255, 127};
const uint8_t blue[]  = {170, 255, 127};

void keyboard_post_init_user(void) {
    set_auto_mouse_timeout(500);

    debug_enable = true;
    debug_matrix = true;
    debug_keyboard=true;

    dprint("display_init_kb - start\n");
    setPinOutput(LCD_BACKLIGHT_PIN);
    writePinLow(LCD_BACKLIGHT_PIN);

    display = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, SPI_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, SPI_DIVISOR, SPI_MODE );

    qp_init(display, QP_ROTATION_0);
    qp_power(display, true);
    qp_clear(display);
    
    backlight_enable();
    backlight_level(1);

    qp_rect(display, LCD_OFFSETX, LCD_OFFSETY, 240, 340, 0, 0, 0, true);
    qp_flush(display);

    testimg = qp_load_image_mem(gfx_ekss);
    if (testimg != NULL) {
        qp_drawimage(display, LCD_OFFSETX, LCD_OFFSETY, testimg);
    }
}