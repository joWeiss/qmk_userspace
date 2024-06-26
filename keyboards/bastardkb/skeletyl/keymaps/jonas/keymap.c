#include QMK_KEYBOARD_H

// define layers
enum LAYER {
  WORKMAN = 0,
  STURDY = 1,
  SYM = 2,
  NAV = 3,
  NUM = 4,
  FUN = 5,
  MOUSE = 6,
};

// combos
const uint16_t PROGMEM esc_combo[] = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM strdy_esc_combo[] = {KC_Q, KC_G, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_L, KC_COMM, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM use_sturdy_combo[] = {KC_U, KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM use_workman_combo[] = {KC_V, KC_M, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(strdy_esc_combo, KC_ESC),
    COMBO(underscore_combo, KC_UNDS),
    COMBO(colon_combo, KC_COLN),
    COMBO(enter_combo, KC_ENT),
    COMBO(use_sturdy_combo, DF(STURDY)),
		COMBO(use_workman_combo, DF(WORKMAN))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[WORKMAN] = LAYOUT_split_3x5_3( // Workman
        KC_Q, KC_D, KC_R, KC_W, KC_B,                             KC_J, KC_F, KC_U, KC_P, KC_QUOT,
        KC_A, KC_S, KC_H, KC_T, KC_G,                             KC_Y, KC_N, KC_E, KC_O, KC_I,
        LT(MOUSE, KC_Z), KC_X, KC_M, KC_C, KC_V,                  KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH,
                      MO(NAV), KC_SPC, MO(FUN),    MO(NUM), SC_SENT, MO(SYM)
    ),
	[STURDY] = LAYOUT_split_3x5_3( // Sturdy layer
        KC_V, KC_M, KC_L, KC_C, KC_P,                             KC_X, KC_F, KC_O, KC_U, KC_J,
        KC_S, KC_T, KC_R, KC_D, KC_Y,                             KC_DOT, KC_N, KC_A, KC_E, KC_I,
        LT(MOUSE, KC_Z), KC_K, KC_Q, KC_G, KC_W,                  KC_B, KC_H, KC_QUOT, KC_SLSH, KC_COMM,
                      MO(NAV), KC_SPC, MO(FUN),    MO(NUM), SC_SENT, MO(SYM)
    ),
    //
	[SYM] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                       KC_EQL, KC_GRV, KC_COLN, KC_SCLN, KC_PLUS,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL),KC_CIRC,             KC_ASTR, KC_LPRN, KC_LBRC, KC_LCBR, KC_MINS,
        KC_ESC, KC_NO, KC_BSLS, KC_PIPE, KC_AMPR,                                       KC_TILD, KC_RPRN, KC_RBRC, KC_RCBR, KC_UNDS,
                                KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //
	[NAV] = LAYOUT_split_3x5_3(
        LCTL(KC_V), KC_NO, KC_NO, LCTL(KC_C), KC_NO,                                    KC_PGUP, KC_HOME, KC_UP, KC_END, KC_SCRL,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
        LCTL(KC_Z), KC_NO, KC_NO, KC_LGUI, KC_NO,                                       KC_ENT, KC_BSPC, KC_TAB, KC_NO, KC_PSCR,
                                KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_ENT, KC_NO
    ),
    //
	[NUM] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_PEQL, KC_7, KC_8, KC_9, KC_PLUS,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PAST, KC_4, KC_5, KC_6, KC_MINS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_0, KC_1, KC_2, KC_3, KC_DOT,
                         KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //
	[FUN] = LAYOUT_split_3x5_3(
        RCS(KC_V), KC_MSTP, KC_MPLY, RCS(KC_C), RGB_VAI,                                  KC_F12, KC_F7, KC_F8, KC_F9, KC_BRIU,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), RGB_HUI,            KC_F11, KC_F4, KC_F5, KC_F6, KC_BRID,
        KC_MUTE, KC_VOLD, RGB_MOD, KC_VOLU, RGB_TOG,                                        KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,
                               KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS
    ),
    //
	[MOUSE] = LAYOUT_split_3x5_3(
        RCS(KC_V), KC_MSTP, KC_MPLY, RCS(KC_C), RGB_VAI,                                  KC_F12, KC_F7, KC_F8, KC_F9, KC_BRIU,
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO,            KC_F11, KC_F4, KC_F5, KC_F6, KC_BRID,
        KC_NO, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_MS_WH_UP, KC_MS_WH_DOWN,                                        KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,
                               KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,                      KC_TRNS, KC_TRNS, KC_TRNS
    ),
		
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




