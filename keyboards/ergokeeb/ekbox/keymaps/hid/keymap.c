// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "hid_display.h"
#include "raw_hid.h"
#include "transactions.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
  // Left Hand                                     Right Hand
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BSPC, 
                    KC_LGUI, MO(1),   KC_SPC,    KC_ENT,  MO(2),   KC_RALT
                   // Left Thumb Cluster        Right Thumb Cluster
  )
};;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("process_record_user %u %s %s %d\n", keycode, record->event.pressed ? "pressed" : "depressed", record->tap.interrupted ? "interrupted" : "not interrupted", record->tap.count);

    if (record->event.pressed) {
        uint8_t data[32];
        data[0] = 0;

        switch (keycode) {
            // send hid commands
            case KC_VOLU:
            case KC_VOLD:
                data[0] = _VOLUME;
                break;
        }

        if (data[0]) {
            dprintf("raw_hid_send %u\n", data[0]);
            raw_hid_send(data, sizeof(data));
        }
    }

    return true;
}

/* Caps Word processing */
#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    if (is_display_enabled()) {
        display_process_caps_word(active);
    } else if (is_keyboard_master() && !is_keyboard_left()) {
        dprintf("RPC_ID_USER_CAPS_WORD_SYNC: %s\n", active ? "active" : "inactive");
        transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
    }
}
#endif

/* Active Layer processing */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    } else if (is_keyboard_master() && !is_keyboard_left()) {
        uint8_t layer = get_highest_layer(state);
        dprintf("RPC_ID_USER_LAYER_SYNC: %u\n", layer);
        transaction_rpc_send(RPC_ID_USER_LAYER_SYNC, 1, &layer);
    }

    return state;
}

/* Raw HID processing*/
void raw_hid_receive(uint8_t *data, uint8_t length) {
    dprintf("raw_hid_receive - received %u bytes \n", length);

    if (is_display_enabled()) {
        display_process_raw_hid_data(data, length);
    } else if (is_keyboard_master() && !is_keyboard_left()) {
        dprint("RPC_ID_USER_HID_SYNC \n");
        transaction_rpc_send(RPC_ID_USER_HID_SYNC, length, data);
    }
}

void hid_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_raw_hid_data((uint8_t *)initiator2target_buffer, initiator2target_buffer_size);
    }
}

void layer_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_layer_state(*(uint8_t *)initiator2target_buffer);
    }
}

void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_caps_word(*(bool *)initiator2target_buffer);
    }
}

void keyboard_post_init_user() {
    // sync received hid data
    transaction_register_rpc(RPC_ID_USER_HID_SYNC, hid_sync);
    // sync highest layer (a bit more performant than standard SPLIT_LAYER_STATE_ENABLE)
    transaction_register_rpc(RPC_ID_USER_LAYER_SYNC, layer_sync);
    // sync caps word state
    transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);
}
