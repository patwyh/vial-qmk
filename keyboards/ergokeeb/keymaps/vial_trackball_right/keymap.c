#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

enum custom_layers {
    _BASE = 0,
    _NAV  = 1,
    _NUM  = 2,
    _SYM  = 3,
    _MOUSE = 4,
    _EXTRA = 5,
};

// Thumb cluster layer-taps
#define NAV_SPC LT(_NAV, KC_SPC)
#define NUM_ENT LT(_NUM, KC_ENT)
#define SYM_BSP LT(_SYM, KC_BSPC)
#define MSE_TAB LT(_MOUSE, KC_TAB)
#define EXT_ESC LT(_EXTRA, KC_ESC)

// Home row mods
#define GUI_A  LGUI_T(KC_A)
#define ALT_S  LALT_T(KC_S)
#define CTL_D  LCTL_T(KC_D)
#define SFT_F  LSFT_T(KC_F)

#define SFT_J  RSFT_T(KC_J)
#define CTL_K  RCTL_T(KC_K)
#define ALT_L  RALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0 BASE (QWERTY + home row mods) */
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_CAPS,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   XXXXXXX,   XXXXXXX, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_PSCR,
        KC_LCTL,     GUI_A,  ALT_S,  CTL_D,  SFT_F,  KC_G,   XXXXXXX,   XXXXXXX, KC_H,   SFT_J,  CTL_K,  ALT_L,  GUI_SCL, KC_DEL,
        KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                                  KC_RCTL, MSE_TAB, NAV_SPC,                     NUM_ENT, SYM_BSP, EXT_ESC
    ),

    /* 1 NAV (navigation + editing) */
    [_NAV] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      _______, _______, _______, _______, _______, _______
    ),

    /* 2 NUM (numpad) */
    [_NUM] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_7,    KC_8,   KC_9,   KC_PMNS, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_4,    KC_5,   KC_6,   KC_PPLS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,   KC_EQL, KC_DOT,
                                     _______, _______, _______, _______, _______, _______
    ),

    /* 3 SYM (symbols) */
    [_SYM] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        XXXXXXX, KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_PPLS, KC_LCBR, KC_RCBR, XXXXXXX,
        XXXXXXX, KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,
                                     _______, _______, _______, _______, _______, _______
    ),

    /* 4 MOUSE (trackball + mouse clicks) */
    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_UP, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, KC_MS_WH_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                     _______, _______, _______, _______, _______, _______
    ),

    /* 5 EXTRA (extra functions) */
    [_EXTRA] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
        XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT, XXXXXXX,
                                     _______, _______, _______, _______, _______, _______
    )
};

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

#if defined(AUTO_MOUSE_ENABLE)
void keyboard_post_init_user(void) {
    set_auto_mouse_timeout(300);
}
#endif
