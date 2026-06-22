// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

/* trackball settings*/
#define POINTING_DEVICE_RIGHT //POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

#define SPI_SCK_PIN   GP6
#define SPI_MOSI_PIN  GP7
#define SPI_MISO_PIN  GP4
#define SPI_CS_PIN    GP5     

#define SPI_DRIVER      SPID0
#define SPI_DIVISOR     1    // SPI Clock Divisor
#define SPI_MODE        3

#define PMW33XX_CS_PIN      GP5    
#define PMW3389_CPI         16000  // Sets default tracking speed (CPI range: 50-16000 
#define POINTING_DEVICE_INVERT_Y