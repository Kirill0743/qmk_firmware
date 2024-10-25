// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    DL_COPY = SAFE_RANGE,
	DL_PASTE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DL_COPY:
        if (record->event.pressed) {
			SEND_STRING(SS_LCTL("c"));
        } else {

        }
        break;

	case DL_PASTE:
        if (record->event.pressed) {
			SEND_STRING(SS_LCTL("v"));
        } else {

        }
        break;

    }
	return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//split keyboard here, double matrix
	//M1 = FN
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │ESC│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ [ │ Q │ W │ E │ R │ T │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sup|Cap│ A │ S │ D │ F │ G │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │LCt│LSh│ Z │ X │ C │ V │ B │Ent|
	 * ├───┼───┼───┼───┼───┼───┼───┼───┤
	 * │   │   │   │   │   │LAl│SPC│FN │
     * └───┴───┴───┴───┴───┴───┴───┴───┘
     */
	 /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │ 6 │ 7 │ 8 │ 9 │ 0 │ = │BPS│
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Y │ U │ I │ O │ P │ - │ ] │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │   | H │ J │ K │ L │ ; │ ' │COP│
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ent│ N │ M │ , │ . │ / │ \ │PAS|
	 * ├───┼───┼───┼───┼───┼───┼───┼───┤
	 * │FN │SPC│RAl│   │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
         	KC_ESC,		KC_GRV, 	KC_1, 	KC_2, 	KC_3, 	KC_4, 			KC_5, 		KC_NO,\
		 	KC_TAB, 	KC_LBRC, 	KC_Q, 	KC_W, 	KC_E, 	KC_R, 			KC_T, 		KC_NO,\
		 	KC_LGUI, 	KC_CAPS, 	KC_A, 	KC_S, 	KC_D, 	KC_F, 			KC_G, 		KC_NO,\
		 	KC_LCTL, 	KC_LSFT, 	KC_Z, 	KC_X, 	KC_C, 	KC_V, 			KC_B, 		KC_ENTER,\
		 	KC_NO, 		KC_NO, 		KC_NO, 	KC_NO, 	KC_NO, 	KC_LALT, 		KC_SPACE, 	MO(1),\
			
		 	KC_NO, 		KC_6, 		KC_7, 	KC_8, 	KC_9, 	KC_0, 			KC_EQUAL, 	KC_BACKSPACE,\
		 	KC_NO, 		KC_Y, 		KC_U, 	KC_I, 	KC_O, 	KC_P, 			KC_MINUS, 	KC_RIGHT_BRACKET,\
		 	KC_NO, 		KC_H, 		KC_J, 	KC_K, 	KC_L, 	KC_SEMICOLON, 	KC_QUOTE, 		DL_COPY,\
		 	KC_ENTER, 	KC_N,	 	KC_M, 	KC_COMMA, 	KC_DOT, 	KC_SLASH, 			KC_BACKSLASH, 		DL_PASTE,\
		 	MO(1), 		KC_SPACE, 	KC_RALT, 	KC_NO, 	KC_NO, 	KC_NO, 			KC_NO, 		KC_NO),
	[1] = LAYOUT(
         	KC_TRNS, 	KC_F1,	 	KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,		KC_F6,		KC_TRNS,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_UP, 	KC_TRNS, 	KC_TRNS,	KC_TRNS,    KC_TRNS,\
		 	KC_TRNS, 	KC_TRNS, 	KC_LEFT, 	KC_DOWN, 	KC_RIGHT, 	KC_TRNS,	KC_TRNS,    KC_TRNS,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,	KC_TRNS,    KC_TRNS,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,	KC_TRNS,    KC_TRNS,\
			
		 	KC_TRNS, 	KC_F7,	 	KC_F8,	 	KC_F9,	 	KC_F10,	 	KC_F11,		KC_F12,		KC_DELETE,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,	KC_UP, 	KC_TRNS, 	KC_TRNS,    KC_TRNS,    KC_TRNS,\
		 	KC_TRNS, 	KC_TRNS, 	KC_LEFT, 	KC_DOWN, 	KC_RIGHT, 	KC_TRNS,    KC_TRNS,    KC_HOME,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,    KC_TRNS,    KC_END,\
		 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,    KC_TRNS,    KC_TRNS)
};
