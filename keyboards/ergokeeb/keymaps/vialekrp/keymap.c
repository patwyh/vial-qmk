#include QMK_KEYBOARD_H
#include <qp.h>
#include "my_image.qgf.h"
#include "print.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif


static painter_image_handle_t test;
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
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard=true;

    dprint("display_init_kb - start\n");
    // LCDのBACKLIGHT PINをHIGHにする
    setPinOutput(LCD_BACKLIGHT_PIN);
    writePinHigh(LCD_BACKLIGHT_PIN);

    //backlight_enable();
    display = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, SPI_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, SPI_DIVISOR, SPI_MODE );

    qp_init(display, QP_ROTATION_0);  // Adjust rotation: 0, 90, 180, or 270
    qp_power(display, true);          // Enable power/backlight if needed
    qp_clear(display);                // Clear screen on startup
    
    backlight_enable();
    backlight_level(4); // Sets backlight to level 3

    // 背景描画
    // qp_rect(display, startPos[X], startPos[Y], endPos[X], endPos[Y], black[HUE], black[SAT], black[VAL], true);
    
    // 5. 描画
    qp_rect(display, 0, 0, 135, 240, white[HUE], white[SAT], white[VAL], true);
    qp_circle(display, 100, 100, 100, black[HUE], black[SAT], black[VAL], true);
    qp_line(display, 120, 0, 120, 240, red[HUE], red[SAT], red[VAL]);
    qp_line(display, 0, 120, 240, 120, blue[HUE], blue[SAT], blue[VAL]);
    qp_rect(display,0,0,135, 240, 0, 0, 0, true);
    // Flush changes to the display
    qp_flush(display);

    test = qp_load_image_mem(gfx_my_image);
    if (test != NULL) {
        qp_drawimage(display, LCD_OFFSETX, LCD_OFFSETY, test);
    }

    //keyboard_post_init_user();  // Call user-level init if needed

    // cat_image = qp_load_image_mem(gfx_test);
    // if (cat_image != NULL) {
    //     qp_drawimage(display, (135 - cat_image->width), (240 - cat_image->height), cat_image);
    // }
     // Set the backlight to a specific level (e.g., 3) on startup
    //backlight_level(2); 
    //qp_set_viewport_offsets(display, 0, 52, 40, 52);  // Example: left=0, top=52, right=40, bottom=52 for some 135x240 modules
    
    // painter_image_handle_t qp_load_image_mem(const void *buffer);
    // painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
    // qp_drawimage(display, 80, 80, logo_image);

    // wait_ms(40);
    //render_red_test();
    //keyboard_post_init_user();
}



// void keyboard_post_init_user(void) {
//     setPinOutput(GP10); // LCD_BACKLIGHT_PIN
//     writePinHigh(GP10);

//     display = qp_st7789_make_spi_device(
//         240,          // panel_height
//         135,          // panel_width       
//         LED_CS_PIN,         // chip_select_pin (replace with your CS pin, e.g., GP13)
//         LED_DC_PIN,         // dc_pin (data/command pin)
//         LED_RST_PIN,         // reset_pin (optional; set to NO_PIN if not used)
//         5,            // spi_divisor (adjust for speed; higher = slower but more stable) 
//         3             // spi_mode (typically 3 for ST7789)
//     );
//     qp_init(display, QP_ROTATION_0);
//     //qp_power(display, true);
//     qp_clear(display);

//     // 背景描画
//     qp_rect(display,0,0,135,240,0,0,0, true);
//     qp_flush(display);

//     // 画像の表示処理(追記)
//     cat_image = qp_load_image_mem(gfx_test);
//     if(cat_image != NULL)
//     {
//         qp_drawimage(display, 0, 0, cat_image);
//     }
// }

// static void render_display(void) {
//     qp_clear(display);  // Clear the screen first (display is your painter_device_t from ST7789 init)

//     if (cat_image != NULL) {
//         // Draw at position (left, top); adjust coordinates as needed
//         qp_drawimage(display, 0, 0, cat_image);

//         // For recoloring (optional): 
//         //qp_drawimage_recolor(display, 0, 0, cat_image, 3, 4, 0,0,0,0);  // Example hue/sat/val adjustments
//     }
//     qp_flush(display);  // Send the rendered content to the ST7789 display
// }


// void housekeeping_task_kb(void) {
//     //render_display();
//     //render_red_test();
//     housekeeping_task_user();
// }

// bool qp_task_user(void) {
//     if (qp_begin(display)) {
//         qp_rect(display, 0, 0, 134, 239, HSV_WHITE, true);  // Background fill
//         qp_drawtext(display, 10, 10, font_name, "Hello QMK");  // Requires loaded font
//         qp_flush(display);
//     }
//     return true;
// }

// void housekeeping_task_user(void) {
//     static uint32_t last_draw = 0;
//     if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
//         last_draw = timer_read32();
//         // Draw r=4 filled circles down the left side of the display
//         for (int i = 0; i < 239; i+=8) {
//             qp_circle(display, 4, 4+i, 4, i, 255, 255, true);
//         }
//         qp_flush(display);
//     }

//     if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
//         last_draw = timer_read32();
//         // Draw 8px-wide rainbow down the left side of the display
//         for (int i = 0; i < 239; ++i) {
//             qp_line(display, 0, i, 7, i, i, 255, 255);
//         }
//         qp_flush(display);
//     }
// }


