// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

#define I2C_DRIVER I2CD1
//#define I2C1_SDA_PIN GP6
//#define I2C1_SCL_PIN GP7

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

// Cirque Trackpad Pin Definitions
#define POINTING_DEVICE_CLOCK_PIN  GP7
#define POINTING_DEVICE_DATA_PIN   GP8  // MOSI
#define POINTING_DEVICE_CS_PIN     GP6
#define POINTING_DEVICE_MISO_PIN   GP4

// Optional: Resolution and Scaling (defaults provided; adjust for 23mm/40mm trackpad)
//#define CIRQUE_PINNACLE_RESOLUTION_X 2048  // Example for TM040040; check datasheet
//#define CIRQUE_PINNACLE_RESOLUTION_Y 1792
//#define POINTING_DEVICE_SCALING 1024       // CPI scaling; tune for sensitivity

// Gesture Support (1-2 finger detection)
#define CIRQUE_PINNACLE_TAP_ENABLE yes     // Enables tap-to-click
#define CIRQUE_PINNACLE_CIRCULAR_SCROLL yes // For circular scrolling if supported
