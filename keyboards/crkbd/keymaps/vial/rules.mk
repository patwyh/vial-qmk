VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

RGBLIGHT_ENABLE     = yes
RGB_MATRIX_ENABLE   = no # Can't have RGBLIGHT and RGB_MATRIX at the same time.
MOUSEKEY_ENABLE     = no
OLED_ENABLE         = no
OLED_DRIVER         = SSD1306
EXTRAKEY_ENABLE     = no
COMBO_ENABLE        = no

QMK_SETTINGS        = no

CAPS_WORD_ENABLE = no
LAYER_LOCK_ENABLE = no
REPEAT_KEY_ENABLE = no

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
CIRQUE_PINNACLE_DIAMETER_MM = 23  # Adjust to your trackpad size: 23, 35, or 40
#CIRQUE_PINNACLE_TAP_ENABLE        # Enables tap-to-click
#POINTING_DEVICE_GESTURES_SCROLL_ENABLE  # Enables scroll gestures

#CIRQUE_PINNACLE_SPI_CS_PIN = POINTING_DEVICE_CS_PIN



# Throttle pointing device updates for performance (optional, 10ms = 100Hz)
#POINTING_DEVICE_TASK_THROTTLE_MS = 10