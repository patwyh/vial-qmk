#pragma once


#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

// /* USB Device descriptor parameter */
// #define VENDOR_ID 0x7111
// #define PRODUCT_ID 0x6224
// #define DEVICE_VER 0x0001
// #define MANUFACTURER "ergokeeb"
// #define PRODUCT "trackpadtest"

// Configure the RP2040 SPI Driver
#define SPI_DRIVER SPID0
#define SPI_MISO_PIN GP4  // RX
#define SPI_SCK_PIN  GP6  // SCK
#define SPI_MOSI_PIN GP7  // TX

// Configure the Cirque Trackpad
#define POINTING_DEVICE_CS_PIN GP5
#define CIRQUE_PINNACLE_SPI_CS_PIN GP5

// Trackpad Physical Dimensions (Change to 40 if you have the larger one)
#define CIRQUE_PINNACLE_DIAMETER_MM 23
//#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_DEVICE_GESTURES_SCROLL_ENABLE // Circular scroll.
#define CIRQUE_PINNACLE_TAP_ENABLE

// Optional: Adjust sensitivity/speed if it feels too slow or fast
#define POINTING_DEVICE_ROTATION_180 // Uncomment if your ribbon cable exits to the right
