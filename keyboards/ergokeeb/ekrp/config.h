#pragma once

#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_FULL_DUPLEX

#define USB_VBUS_PIN GP11

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP24
#define I2C1_SCL_PIN GP25

#define MASTER_LEFT

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

// Trackpad diameter (required for scaling and calibration)
#define CIRQUE_PINNACLE_DIAMETER_MM 35 //23 //35 //40

// Optional enhancements
#define CIRQUE_PINNACLE_TAP_ENABLE                  // Enable single-tap for left-click
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE        // Enable secondary tap (e.g., right-click)
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE      // Enable edge/circular scrolling
#define POINTING_DEVICE_ROTATION_90                 // Adjust if the trackpad orientation requires rotation (common in split keyboards) default left, 270 top

#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE              // (Optional) Enable inertial cursor. Cursor continues moving after a flick gesture and slows down by kinetic friction.

#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN  GP19
#define SPI_MISO_PIN  GP16

// Chip Select pin for the trackpad
#define CIRQUE_PINNACLE_SPI_CS_PIN GP17 
#define CIRQUE_PINNACLE_SPI_CS_PIN_RIGHT GP17

#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

//#define MASTER_RIGHT