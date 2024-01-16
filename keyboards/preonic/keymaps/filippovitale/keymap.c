/* Copyright 2015-2017 Jack Humbert, Filippo Vitale
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Reviung41
// --------------------------------------------------------------------------------------------------------------------
// | LALT  (TAB) |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U   |  I  |  O  |  P  | LALT  (BSPC) |
// | LCTRL (ESC) |  A  |  S  |  D  |  F  |  G  |   |  H  |  J   |  K  |  L  |  ;  | LCTRL ( RET) |
// |  SHFT ( ` ) |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M   |  ,  |  .  |  /  | SHFT  (   ') |
//                          | LGUI ([) | LWR |  SPC  | RSE  | LGUI (]) |
//
//   &mt  LALT   TAB &kp Q &kp W &kp E &kp R &kp T   &kp Y &kp U &kp I     &kp O   &kp P    &mt  LALT BSPC
//   &mt LCTRL   ESC &kp A &kp S &kp D &kp F &kp G   &kp H &kp J &kp K     &kp L   &kp SEMI &mt LCTRL  RET
//   &mt LSHFT GRAVE &kp Z &kp X &kp C &kp V &kp B   &kp N &kp M &kp COMMA &kp DOT &kp FSLH &mt RSHFT  SQT
//           &mt LGUI LBKT &mo LOWER_LAYER   &kp SPACE   &mo RAISE_LAYER  &mt LGUI RBKT

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ctrl/'|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shft/E|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Vol+ | LAlt | LGUI |Lower |    Space    |Raise |AltGr | Play | PgDn | PgUp |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  LALT_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RALT_T(KC_BSLS),  \
  KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  MT(MOD_LSFT | MOD_LALT | MOD_LGUI, KC__VOLDOWN), \
           MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC__VOLUP), \
                 KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_ALGR, KC_MPLY, KC_PGDN, KC_PGUP  \
),

// Reviung41
// ------------------------------------------------------------------------------
// |    |     |     |     |     |     |   |     |     |  -  |  =  |  \  | BSPC |
// |    |     |     |     |     |     |   |  6  |  7  |  8  |  9  |  0  |      |
// |    |     |     |     |     |     |   |     |     |     |     |     |      |
//                       |     |     |     | ADJ |     |
//
//   &trans  &trans  &trans  &trans  &trans  &trans  &trans  &trans  &kp MINUS  &kp EQUAL  &kp BACKSLASH &kp BSPC
//   &trans  &trans  &trans  &trans  &trans  &trans  &kp N6  &kp N7  &kp N8     &kp N9     &kp N0        &trans
//   &trans  &trans  &trans  &trans  &trans  &trans  &trans  &trans  &trans     &trans     &trans        &trans
//                  &trans      &trans       &trans        &mo ADJUST_LAYER       &trans

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |   -  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   -  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQUAL, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQUAL,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  \
  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

// Reviung41
// -----------------------------------------------------------------------------------------
// |    |     |     |     |     |     |   |     |      |      |     |       | DEL |
// |    |  1  |  2  |  3  |  4  |  5  |   |     | Left | Down |  Up | Right |     |
// |    |     |     |     |     |     |   |     |      |      |     |       |     |
//                       |     | ADJ |     |     |     |
//
//   &trans  &trans  &trans &trans  &trans  &trans  &trans  &trans    &trans    &trans  &trans     &kp DEL
//   &trans  &kp N1  &kp N2 &kp N3  &kp N4  &kp N5  &trans  &kp LEFT  &kp DOWN  &kp UP  &kp RIGHT  &trans
//   &trans  &trans  &trans &trans  &trans  &trans  &trans  &trans    &trans    &trans  &trans     &trans
//                  &trans      &mo ADJUST_LAYER       &trans        &trans       &trans


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |      |      |      |  [   |  ]   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,   \
  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,  \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  \
  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

// Reviung41
// -----------------------------------------------------------------------------------------
// |    F1    |    F2    |    F3    |    F4       |     F5         |    F6           |    |  F7 |     F8      |  F9  | F10  | F11  | F12    |
// |          |          |          |             | Spectacle+F    |                 |    | BT1 |     BT2     | BT3  | BT4  | BT5  | BT CLR |
// |   Mute   | Vol_Down |  Vol_Up  | Spectacle+C | Spectacle+Left | Spectacle+Right |    |     | Spectacle+M | PREV | PLAY | NEXT |        |
//                                               |     |     |      |     |     |
//
//   &kp F1     &kp F2       &kp F3       &kp F4            &kp F5               &kp F6                &kp F7       &kp F8            &kp F9       &kp F10      &kp F11      &kp F12
//   &none      &none        &none        &none             &kp LA(LS(LG(F)))    &none                 &bt BT_SEL 0 &bt BT_SEL 1      &bt BT_SEL 2 &bt BT_SEL 3 &bt BT_SEL 4 &bt BT_CLR
//   &kp K_MUTE &kp C_VOL_DN &kp K_VOL_UP &kp LA(LS(LG(C))) &kp LA(LS(LG(LEFT))) &kp LA(LS(LG(RIGHT))) &none        &kp LA(LS(LG(M))) &kp C_PREV   &kp C_PP     &kp C_NEXT   &none
//                                          &trans      &trans       &trans        &trans       &trans

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
  c,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  \
  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
