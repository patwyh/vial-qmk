// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

// #define I2C_DRIVER I2CD1
// #define I2C1_SDA_PIN GP6
// #define I2C1_SCL_PIN GP7

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64


// Cirque Pinnacle SPI Settings
#define CIRQUE_PINNACLE_SPI_SCK_PIN  GP6
#define CIRQUE_PINNACLE_SPI_MISO_PIN GP4
#define CIRQUE_PINNACLE_SPI_MOSI_PIN GP7
#define CIRQUE_PINNACLE_SPI_CS_PIN   GP5

// Data Ready (Interrupt) Pin
#define CIRQUE_PINNACLE_INT_PIN      GP8

// Optional: Trackpad Orientation/Sensitivity
#define CIRQUE_PINNACLE_DIAMETER_MM  35
#define POINTING_DEVICE_ROTATION    90

#define SPI_DRIVER SPID0 // Ties to RP2040_SPI_USE_SPI0