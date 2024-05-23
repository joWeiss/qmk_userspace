#include QMK_KEYBOARD_H

// combos
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_G, COMBO_END};
const uint16_t PROGMEM dash_combo[] = {KC_DOT, KC_A, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(dash_combo, KC_MINS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(
        KC_V, KC_M, KC_L, KC_C, KC_P,                  KC_X, KC_F, KC_O, KC_U, KC_J,
        KC_S, KC_T, KC_R, KC_D, KC_Y,                  KC_DOT, KC_N, KC_A, KC_E, KC_I,
        KC_Z, KC_K, KC_Q, KC_G, KC_W,                  KC_B, KC_H, KC_QUOT, KC_SLSH, KC_COMM,
                      MO(2), SC_SENT, MO(4),    MO(3), KC_SPC, MO(1)
    ),
    //
	[1] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                       KC_EQL, KC_GRV, KC_COLN, KC_SCLN, KC_PLUS,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL),     KC_CIRC, KC_ASTR, KC_LPRN, KC_LBRC, KC_LCBR, KC_MINS,
        KC_ESC, KC_NO, KC_BSLS, KC_PIPE, KC_AMPR,                       KC_TILD, KC_RPRN, KC_RBRC, KC_RBRC, KC_UNDS,
                                KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //
	[2] = LAYOUT_split_3x5_3(
        LCTL(KC_V), KC_NO, KC_NO, LCTL(KC_C), KC_NO,                                    KC_PGUP, KC_HOME, KC_UP, KC_END, KC_SCRL,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
        LCTL(KC_Z), KC_NO, KC_NO, KC_LGUI, KC_NO,                                       KC_ENT, KC_BSPC, KC_TAB, KC_NO, KC_PSCR,
                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_ENT, KC_NO
    ),
    //
	[3] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_PEQL, KC_7, KC_8, KC_9, KC_PLUS,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PAST, KC_4, KC_5, KC_6, KC_MINS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_0, KC_1, KC_2, KC_3, KC_DOT,
                         KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //
	[4] = LAYOUT_split_3x5_3(
        RCS(KC_V), KC_MSTP, KC_MPLY, RCS(KC_C), RGB_VAI,                                  KC_F12, KC_F7, KC_F8, KC_F9, KC_BRIU,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), RGB_HUI,            KC_F11, KC_F4, KC_F5, KC_F6, KC_BRID,
        KC_MUTE, KC_VOLD, RGB_MOD, KC_VOLU, RGB_TOG,                                        KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,
                               KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




