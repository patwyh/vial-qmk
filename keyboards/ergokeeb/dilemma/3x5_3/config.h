/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


#define SERIAL_USART_TX_PIN GP12

/* Handedness. */
#define SPLIT_HAND_PIN GP21
//#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP13

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

// 1. Identify the correct hardware driver for RP2040
#define SPI_DRIVER SPI0

// 2. Hardware SPI0 Pin Mapping
#define SPI_MISO_PIN GP4  // SPI0 RX
#define SPI_SCK_PIN  GP6  // SPI0 SCK
#define SPI_MOSI_PIN GP7  // SPI0 TX

// 3. Pointing device configuration
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_CS_PIN GP5        // Generic pointing CS configuration
#define CIRQUE_PINNACLE_SPI_CS_PIN GP5   // Explicitly tells the Cirque driver which CS pin to drop low

// 4. Trackpad sizing adjustments
#undef CIRQUE_PINNACLE_DIAMETER_MM
#define CIRQUE_PINNACLE_DIAMETER_MM 35

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
