// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "display.h"
#include "qp.h"
#include "lvgl_helpers.h"
#include "wpm.h"

/* shared styles */
lv_style_t style_screen;
lv_style_t style_container;
lv_style_t style_button;
lv_style_t style_button_active;

/* screens */
static lv_obj_t *screen_home;

/* home screen content */
static lv_obj_t *label_shift;
static lv_obj_t *label_ctrl;
static lv_obj_t *label_alt;
static lv_obj_t *label_gui;
//static lv_obj_t *label_caps;
static lv_obj_t *label_wpm;
static lv_obj_t *arc_wpm; // Arc object reference
static lv_obj_t *label_layer;
static lv_obj_t *label_key_press;


// Helper function to map layer index to a name
static const char *get_layer_name(uint8_t layer) {
    switch (layer) {
        case 0:  return "0 BASE";
        case 1:  return "1 NAV";
        case 2:  return "2 NUM";
        case 3:  return "3 SYM";
        case 4:  return "4 MEDIA";
        default: return "5 EXTRA";
    }
}

// Convert basic QMK keycodes to displayable characters/names
static const char *keycode_to_str(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z) {
        static char letter[2] = {0};
        letter[0] = 'A' + (keycode - KC_A);
        return letter;
    }
    if (keycode >= KC_1 && keycode <= KC_0) {
        static char num[2] = {0};
        num[0] = (keycode == KC_0) ? '0' : ('1' + (keycode - KC_1));
        return num;
    }
    
    switch (keycode) {
        case KC_SPACE: return "SPC";
        case KC_ENTER: return "ENT";
        case KC_BSPC:  return "BSPC";
        case KC_TAB:   return "TAB";
        case KC_ESC:   return "ESC";
        case KC_DOT:   return ".";
        case KC_COMM:  return ",";
        default:       return "---";
    }
}

void init_styles(void) {
    lv_style_init(&style_screen);
    lv_style_set_bg_color(&style_screen, lv_color_black());

    lv_style_init(&style_container);
    lv_style_set_pad_top(&style_container, 0);
    lv_style_set_pad_bottom(&style_container, 0);
    lv_style_set_pad_left(&style_container, 0);
    lv_style_set_pad_right(&style_container, 0);
    lv_style_set_bg_opa(&style_container, 0);
    lv_style_set_border_width(&style_container, 0);
    lv_style_set_width(&style_container, lv_pct(100));
    lv_style_set_height(&style_container, LV_SIZE_CONTENT);

    lv_style_init(&style_button);
    lv_style_set_pad_top(&style_button, 4);
    lv_style_set_pad_bottom(&style_button, 4);
    lv_style_set_pad_left(&style_button, 4);
    lv_style_set_pad_right(&style_button, 4);
    lv_style_set_radius(&style_button, 6);
    lv_style_set_text_color(&style_button, lv_palette_main(LV_PALETTE_AMBER));

    lv_style_init(&style_button_active);
    lv_style_set_bg_color(&style_button_active, lv_palette_main(LV_PALETTE_AMBER));
    lv_style_set_bg_opa(&style_button_active, LV_OPA_100);
    lv_style_set_text_color(&style_button_active, lv_color_black());
}

void init_screen_home(void) {
    screen_home = lv_scr_act();

    lv_obj_add_style(screen_home, &style_screen, 0);
    use_flex_column(screen_home);

    lv_obj_t *mods = lv_obj_create(screen_home);
    lv_obj_add_style(mods, &style_container, 0);
    use_flex_column(mods);

    lv_obj_t *mods_row1 = lv_obj_create(mods);
    lv_obj_add_style(mods_row1, &style_container, 0);
    use_flex_row(mods_row1);
    label_gui = create_button(mods_row1, "GUI", &style_button, &style_button_active);
    label_alt = create_button(mods_row1, "ALT", &style_button, &style_button_active);

    lv_obj_t *mods_row2 = lv_obj_create(mods);
    lv_obj_add_style(mods_row2, &style_container, 0);
    use_flex_row(mods_row2);
    label_ctrl  = create_button(mods_row2, "CTL", &style_button, &style_button_active);
    label_shift = create_button(mods_row2, "SFT", &style_button, &style_button_active);

    // lv_obj_t *label_ekbox = lv_label_create(screen_home);
    // lv_label_set_text(label_ekbox, "ekbox");
    // #if LV_FONT_MONTSERRAT_28
    //     lv_obj_set_style_text_font(label_ekbox, &lv_font_montserrat_28, LV_PART_MAIN);
    // #endif

    // --- WPM Arc Container ---
    lv_obj_t *wpm_cont = lv_obj_create(screen_home);
    lv_obj_add_style(wpm_cont, &style_container, 0);
    use_flex_column(wpm_cont);

    // Create Arc
    arc_wpm = lv_arc_create(wpm_cont);
    lv_obj_set_size(arc_wpm, 100, 100);
    lv_arc_set_rotation(arc_wpm, 135);        // Rotate to start from bottom-left
    lv_arc_set_bg_angles(arc_wpm, 0, 270);    // Background arc spans 270 degrees
    lv_arc_set_range(arc_wpm, 0, 140);        // Max WPM scale (e.g., 0 to 140 WPM)
    lv_arc_set_value(arc_wpm, 0);
    lv_obj_remove_style(arc_wpm, NULL, LV_PART_KNOB); // Hide interactive knob
    lv_obj_clear_flag(arc_wpm, LV_OBJ_FLAG_CLICKABLE);

    // Styling the Arc
    lv_obj_set_style_arc_color(arc_wpm, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN);
    lv_obj_set_style_arc_color(arc_wpm, lv_palette_main(LV_PALETTE_AMBER), LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(arc_wpm, 8, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_wpm, 8, LV_PART_INDICATOR);

    // Create WPM Text Label below the arc
    label_wpm = lv_label_create(wpm_cont);
    lv_label_set_text(label_wpm, "0");
    #if LV_FONT_MONTSERRAT_28
        lv_obj_set_style_text_font(label_wpm, &lv_font_montserrat_28, LV_PART_MAIN);
    #endif

    //label_caps = create_button(screen_home, "CAPS", &style_button, &style_button_active);
    label_layer = create_button(screen_home, "0 BASE", &style_button, &style_button_active);

    // Label for displaying active modifiers + last pressed key
    label_key_press = lv_label_create(screen_home);
    lv_label_set_text(label_key_press, "KEY: NONE");
    #if LV_FONT_MONTSERRAT_28
        lv_obj_set_style_text_font(label_key_press, &lv_font_montserrat_28, LV_PART_MAIN);
    #endif
}

void display_process_layer(layer_state_t state) {
    uint8_t highest_layer = get_highest_layer(state);
    if (label_layer) {
        lv_label_set_text(label_layer, get_layer_name(highest_layer));
    }
}

bool display_init_kb(void) {
    dprint("display_init_kb - start\n");

    backlight_enable();

    // painter_device_t display = qp_st7789_make_spi_device(240, 300, SPI_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, 16, 3);
    // qp_set_viewport_offsets(display, 0, 20);

    // 1. Pass width = 135, height = 240 to the display initializer
    painter_device_t display = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, SPI_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, 16, 3);

    // 2. Adjust offsets (Standard 135x240 ST7789 modules require X offset = 52 or 53, Y offset = 40)
    qp_set_viewport_offsets(display, LCD_OFFSETX, LCD_OFFSETY);

    if (!qp_init(display, QP_ROTATION_0) || !qp_power(display, true) || !qp_lvgl_attach(display)) return false;

    dprint("display_init_kb - initialised\n");

    lv_disp_t  *lv_display = lv_disp_get_default();
    lv_theme_t *lv_theme   = lv_theme_default_init(lv_display, lv_palette_main(LV_PALETTE_AMBER), lv_palette_main(LV_PALETTE_BLUE), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(lv_display, lv_theme);
    init_styles();

    bool res = display_init_user();
    if (res) {
        dprint("display_init_kb - adding default home screen\n");
        init_screen_home();
    }

    return true;
}

__attribute__((weak)) bool display_init_user(void) {
    return true;
}

__attribute__((weak)) void display_housekeeping_task(void) {
    dprint("display_housekeeping_task_kb\n");

    toggle_state(label_shift, LV_STATE_PRESSED, MODS_SHIFT);
    toggle_state(label_ctrl, LV_STATE_PRESSED, MODS_CTRL);
    toggle_state(label_alt, LV_STATE_PRESSED, MODS_ALT);
    toggle_state(label_gui, LV_STATE_PRESSED, MODS_GUI);
    
    if (label_wpm) {
        lv_label_set_text_fmt(label_wpm, "%u", get_current_wpm());
    }

    if (label_key_press) {
        uint8_t mods = get_mods() | get_oneshot_mods();
        uint16_t key = get_last_pressed_keycode();
        
        // Format modifier prefix dynamically
        char mod_str[32] = "";
        if (mods & MOD_MASK_CTRL)  strcat(mod_str, "C-");
        if (mods & MOD_MASK_ALT)   strcat(mod_str, "A-");
        if (mods & MOD_MASK_SHIFT) strcat(mod_str, "S-");
        if (mods & MOD_MASK_GUI)   strcat(mod_str, "G-");

        lv_label_set_text_fmt(label_key_press, "%s%s", mod_str, keycode_to_str(key));
    }
}

// __attribute__((weak)) void display_process_caps(bool active) {
//     dprint("display_process_caps\n");
//     toggle_state(label_caps, LV_STATE_PRESSED, active);
// }


