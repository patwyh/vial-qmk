#include QMK_KEYBOARD_H
#include <qp.h>
#include "print.h"
#include "image/my_image.qgf.h"
#include "image/ekbox.qgf.h"
#include "font/arial.qff.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
  // Left Hand                                     Right Hand
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BSPC, 
                    KC_LGUI, MO(1),   KC_SPC,    KC_ENT,  MO(2),   KC_RALT
                   // Left Thumb Cluster        Right Thumb Cluster
  )
};


static painter_image_handle_t testimg;
static painter_device_t display;
//static painter_font_handle_t my_font;

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
    writePinLow(LCD_BACKLIGHT_PIN);

    display = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, SPI_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, SPI_DIVISOR, SPI_MODE );

    qp_init(display, QP_ROTATION_0);  // Adjust rotation: 0, 90, 180, or 270
    qp_power(display, true);          // Enable power/backlight if needed
    qp_clear(display);                // Clear screen on startup
    
    backlight_enable();
    backlight_level(1); // Sets backlight to level 3

    // 背景描画
    //qp_rect(display, startPos[X], startPos[Y], endPos[X], endPos[Y], black[HUE], black[SAT], black[VAL], true);
    
    // 5. 描画
    // qp_rect(display, 0, 0, 135, 240, white[HUE], white[SAT], white[VAL], true);
    // qp_circle(display, 100, 100, 100, black[HUE], black[SAT], black[VAL], true);
    // qp_line(display, 120, 0, 120, 240, red[HUE], red[SAT], red[VAL]);
    // qp_line(display, 0, 120, 240, 120, blue[HUE], blue[SAT], blue[VAL]);
     qp_rect(display,LCD_OFFSETX,LCD_OFFSETY,240, 340, 0, 0, 0, true);
    // Flush changes to the display
    qp_flush(display);

    testimg = qp_load_image_mem(gfx_ekbox);
    if (testimg != NULL) {
        qp_drawimage(display, LCD_OFFSETX, LCD_OFFSETY, testimg);
    }

    // Draw the text (device, x, y, font_handle, text)
    // my_font = qp_load_font_mem(font_arial);
    // if (my_font != NULL) {
    //     static const char *text = "EKBOX";
    //     int16_t width = qp_textwidth(my_font, text);
    //     qp_drawtext(display, (135 - width), (240 - my_font->line_height), my_font, text); 
    // }

}
