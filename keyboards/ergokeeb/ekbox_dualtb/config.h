#pragma once

#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_FULL_DUPLEX

#define USB_VBUS_PIN GP11

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP24
#define I2C1_SCL_PIN GP25

#define MATRIX_ROWS 8
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 5

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

//handness
#define MASTER_LEFT 

// Trackball configurationf
// Set the layer activated when moving the trackball
#define PMW33XX_CS_PIN      GP17    
#define PMW3389_CPI         1000  // Sets default tracking speed (CPI range: 50-16000 
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 4 
#define AUTO_MOUSE_TIME 650     // Timeout in milliseconds before returning to the previous layer
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define SPLIT_POINTING_ENABLE

/* SPI Setting */
#define SPI_DRIVER      SPID0
#define SPI_CS_PIN      GP15     // Chip Select
#define SPI_SCK_PIN     GP18     // Clock
#define SPI_MOSI_PIN    GP19     // Master -> Slave
#define SPI_MISO_PIN    GP16     // Master <- Slave
#define SPI_DIVISOR     1    // SPI Clock Divisor
#define SPI_MODE        3

