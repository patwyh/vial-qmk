#pragma once

#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7



/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

// Trackpad diameter (required for scaling and calibration)
//#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_DIAMETER_MM 23

// Optional enhancements
#define CIRQUE_PINNACLE_TAP_ENABLE                  // Enable single-tap for left-click
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE        // Enable secondary tap (e.g., right-click)
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE      // Enable edge/circular scrolling
#define POINTING_DEVICE_ROTATION_180_RIGHT                 // Adjust if the trackpad orientation requires rotation (common in split keyboards)

#define SPI_SCK_PIN   GP6
#define SPI_MOSI_PIN  GP7
#define SPI_MISO_PIN  GP4

// Chip Select pin for the trackpad
#define CIRQUE_PINNACLE_SPI_CS_PIN GP5
#define CIRQUE_PINNACLE_SPI_CS_PIN_RIGHT GP5

#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

//#define MASTER_RIGHT