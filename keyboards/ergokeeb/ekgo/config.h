#pragma once

#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_FULL_DUPLEX

#define USB_VBUS_PIN GP11

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP24
#define I2C1_SCL_PIN GP25

#define MASTER_RIGHT
//#define EE_HANDS

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

// Trackpad diameter (required for scaling and calibration)
#define CIRQUE_PINNACLE_DIAMETER_MM 23 //23 //35 //40

// Optional enhancements
#define CIRQUE_PINNACLE_TAP_ENABLE                  // Enable single-tap for left-click
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE        // Enable secondary tap (e.g., right-click)
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE      // Enable edge/circular scrolling
#define POINTING_DEVICE_ROTATION_90                 // Adjust if the trackpad orientation requires rotation (common in split keyboards) default left, 270 top

#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE              // (Optional) Enable inertial cursor. Cursor continues moving after a flick gesture and slows down by kinetic friction.

// Chip Select pin for the trackpad
#define CIRQUE_PINNACLE_SPI_CS_PIN GP17 
#define CIRQUE_PINNACLE_SPI_CS_PIN_RIGHT GP17

#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

// ST7789 Display configuration
#define ST7789_NUM_DEVICES 1
#define QUANTUM_PAINTER_NUM_DEVICES 1  // Default is 1; increase for multiple displays
#define QP_ST7789_WIDTH 172 //135
#define QP_ST7789_HEIGHT 320 //240
// Optional offsets if content is misaligned:
// #define QP_ST7789_OFFSET_X 0
// #define QP_ST7789_OFFSET_Y 52  // Example for some 240x240 panels cropped to smaller area

// #define BACKLIGHT_LEVELS 5     // Number of brightness steps (max 31)
// #define BACKLIGHT_DEFAULT_LEVEL 5    // Default brightness level (out of 5)
// #define BACKLIGHT_DEFAULT_ON true    // Ensure backlight is ON by default
// #define BACKLIGHT_ON_STATE 1   // Use 1 for high-active (common) or 0 for low-active

/* SPI Setting */
#define SPI_DRIVER      SPID0
#define SPI_CS_PIN      GP15     // Chip Select
#define SPI_SCK_PIN     GP18     // Clock
#define SPI_MOSI_PIN    GP19     // Master -> Slave
#define SPI_MISO_PIN    GP16     // Master <- Slave
#define SPI_DIVISOR     1    // SPI Clock Divisor
#define SPI_MODE        3

/* LCD setting */
#define LCD_RESET_PIN       GP24
#define LCD_BACKLIGHT_PIN   GP10
#define LCD_DC_PIN          GP25
#define LCD_HEIGHT          320//240
#define LCD_WIDTH           172//135
#define LCD_OFFSETX         0//52
#define LCD_OFFSETY         0//40

#define BACKLIGHT_PWM_DRIVER PWMD5
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A
//#define BACKLIGHT_PWM_COUNTER_FREQUENCY 1000000 

#define BACKLIGHT_LEVELS 5     // Number of brightness steps (max 31)
#define BACKLIGHT_DEFAULT_LEVEL 3    // Default brightness level (out of 5)
#define BACKLIGHT_ON_STATE 0   // Use 1 for high-active (common) or 0 for low-active
#define BACKLIGHT_DEFAULT_ON true    // Ensure backlight is ON by default

//#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
