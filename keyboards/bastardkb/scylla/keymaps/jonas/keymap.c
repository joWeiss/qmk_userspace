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

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_S, // reads as C(ustom) + KC_S, but you may give any name here
    CKC_T,
    CKC_R,
    CKC_ENT,
    CKC_SPC,
    CKC_D,
    CKC_I,
    CKC_E,
    CKC_A,
    CKC_N,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
};

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // mod_tap
        SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_T, KC_T, KC_LEFT_GUI)
        SMTD_MT(CKC_R, KC_R, KC_LSFT)
        SMTD_MT(CKC_D, KC_D, KC_LEFT_CTRL)
        SMTD_MT(CKC_I, KC_I, KC_LEFT_ALT)
        SMTD_MT(CKC_E, KC_E, KC_LEFT_GUI)
        SMTD_MT(CKC_A, KC_A, KC_LSFT)
        SMTD_MT(CKC_N, KC_N, KC_LEFT_CTRL)
        SMTD_MT(CKC_SPC, KC_SPC, KC_LSFT)
        // mod_tap
        SMTD_LT(CKC_ENT, KC_ENT, NUM)
    }
}

// combos
const uint16_t PROGMEM esc_combo[] = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM strdy_esc_combo[] = {KC_Q, KC_G, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_L, KC_COMM, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM strdy_enter_combo[] = {KC_H, KC_QUOT, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM strdy_bspc_combo[] = {KC_SLSH, KC_COMM, COMBO_END};
const uint16_t PROGMEM use_sturdy_combo[] = {KC_U, KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM use_workman_combo[] = {KC_V, KC_M, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(strdy_esc_combo, KC_ESC),
    COMBO(underscore_combo, KC_UNDS),
    COMBO(colon_combo, KC_COLN),
    COMBO(enter_combo, KC_ENT),
    COMBO(strdy_enter_combo, KC_ENT),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(strdy_bspc_combo, KC_BSPC),
    COMBO(use_sturdy_combo, DF(STURDY)),
		COMBO(use_workman_combo, DF(WORKMAN))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[WORKMAN] = LAYOUT_split_4x6_5( // Workman
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8,    KC_9, KC_0,      KC_ESC,
        KC_TAB,  KC_Q, KC_D, KC_R, KC_W, KC_B,                             KC_J, KC_F, KC_U,    KC_P, KC_QUOT,   KC_DEL,
        KC_LCTL, KC_A, KC_S, KC_H, KC_T, KC_G,                             KC_Y, KC_N, KC_E,    KC_O, KC_I,      KC_BSPC,
       MO(MOUSE), KC_Z, KC_X, KC_M, KC_C, KC_V,                            KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, LSG(KC_N),
                      MO(NAV), CKC_SPC, MO(SYM),               MO(FUN), CKC_ENT, MO(NUM),
                                KC_LGUI, MO(SYM),              MO(FUN), LGUI(KC_ENT)
    ),
	[STURDY] = LAYOUT_split_4x6_5( // Sturdy layer
        KC_ESC,    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                            KC_6,   KC_7,  KC_8,    KC_9,    KC_0, KC_BSPC,
        KC_TAB,    KC_V,  KC_M,  KC_L,  KC_C,  KC_P,                            KC_X,   KC_F,  KC_O,    KC_U,    KC_J, KC_DEL,
        KC_LCTL,   CKC_S, CKC_T, CKC_R, CKC_D, KC_Y,                            KC_DOT, CKC_N, CKC_A,   CKC_E,   CKC_I, KC_BSPC,
        MO(MOUSE), KC_Z,  KC_K,  KC_Q,  KC_G,  KC_W,                            KC_B,   KC_H,  KC_QUOT, KC_SLSH, KC_COMM, LSG(KC_N),
                                      MO(NAV), CKC_SPC, MO(SYM),    MO(FUN), CKC_ENT, MO(NUM),
                                                KC_LGUI, MO(SYM),   MO(FUN), LGUI(KC_ENT)
    ),
    //
	[SYM] = LAYOUT_split_4x6_5(
        _______, _______,  _______,  _______,  _______,  _______,                                 _______,   _______,  _______,  _______,  _______, _______,
        _______,    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                     KC_EQL,    KC_GRV,   KC_COLN,  KC_SCLN,  KC_PLUS, _______,
        _______,   OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL),KC_CIRC,            KC_ASTR,   KC_LPRN,  KC_LBRC,  KC_LCBR,  KC_MINS, _______,
        _______, KC_ESC, KC_NO, KC_BSLS, KC_PIPE, KC_AMPR,                                       KC_TILD,   KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_UNDS, _______,
                                _______, _______, _______,                                 _______, _______, _______,
                                        _______, _______,                                   _______, _______
    ),
    //
	[NAV] = LAYOUT_split_4x6_5(
        _______, _______,  _______,  _______,  _______,  _______,                                 _______,   _______,  _______,  _______,  _______, _______,
        _______, LCTL(KC_V), KC_NO, KC_NO, LCTL(KC_C), KC_NO,                                    KC_PGUP,   KC_HOME,  KC_UP,     KC_END,    KC_SCRL, _______,
        _______,  OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PGDN,   KC_LEFT, KC_DOWN,    KC_RGHT, KC_DEL, _______,
        _______, LCTL(KC_Z), KC_NO, KC_NO, KC_LGUI, KC_NO,                                       KC_ENT,     KC_BSPC, KC_TAB,    KC_NO, KC_PSCR, _______,
                                         _______, _______, _______,                     _______, KC_ENT, KC_NO,
                                                    _______, _______,                     _______, _______  
    ),
    //
	[NUM] = LAYOUT_split_4x6_5(
        _______, _______,  _______,  _______,  _______,  _______,                                 _______,   _______,  _______,  _______,  _______, _______,
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_PEQL, KC_7, KC_8, KC_9, KC_PLUS, _______,
        _______, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),      KC_PAST, KC_4, KC_5, KC_6, KC_MINS, _______,
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_0, KC_1, KC_2, KC_3, KC_DOT, _______,
                         _______, _______, _______,                            _______, _______, _______,
                                  _______, _______,                            _______, _______  
    ),
    //
	[FUN] = LAYOUT_split_4x6_5(
        _______, _______,  _______,  _______,  _______,  _______,                                 _______,   _______,  _______,  _______,  _______, _______,
        _______, RCS(KC_V), KC_MSTP, KC_MPLY, RCS(KC_C), RGB_VAI,                                  KC_F12, KC_F7, KC_F8, KC_F9, KC_BRIU, _______,
        _______, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), RGB_HUI,            KC_F11, KC_F4, KC_F5, KC_F6, KC_BRID, _______,
        _______, KC_MUTE, KC_VOLD, RGB_MOD, KC_VOLU, RGB_TOG,                                        KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, _______,
                               _______, _______, _______,                      _______, _______, _______,
                               _______, _______,                            _______, _______
    ),
    //
	[MOUSE] = LAYOUT_split_4x6_5(
        _______, _______,  _______,  _______,  _______,  _______,                                 _______,   _______,  _______,  _______,  _______, _______,
        _______, RCS(KC_V), KC_MSTP, KC_MPLY, RCS(KC_C), RGB_VAI,                                  KC_F12, KC_F7, KC_F8, KC_F9, KC_BRIU, _______, 
        _______, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO,            KC_F11, KC_F4, KC_F5, KC_F6, KC_BRID,  _______, 
        _______, KC_NO, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_MS_WH_UP, KC_MS_WH_DOWN,              KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, _______,
                               KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,                     _______, _______, _______,
                                              _______, _______,                         _______, _______
    ),
		
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




