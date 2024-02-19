/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/ext_power.h>

#define ADJUST_LAYER 3

/ {
    keymap {
        compatible = "zmk,keymap";

        default_layer {
// ------------------------------------------------------------------------------------------------------------
// |  ESC  |  1  |  2  |  3   |  4   |  5   |                   |  6   |  7    |  8    |  9   |   0   | BSPC  |
// |  TAB  |  Q  |  W  |  E   |  R   |  T   |                   |  Y   |  U    |  I    |  O   |   P   |  "["  |
// | SHIFT |  A  |  S  |  D   |  F   |  G   |                   |  H   |  J    |  K    |  L   |   ;   |   '   |
// |  CTRL |  Z  |  X  |  C   |  V   |  B   |    -   |  |   =   |  N   |  M    |  ,    |  .   |   /   | SHIFT |
//                     | GUI  | ALT  | LOWER|  SPACE |  | ENTER | RAISE| ALT   | APP   |
            bindings = <
&kp ESC   &kp N1 &kp N2 &kp N3   &kp N4   &kp N5                      &kp N6 &kp N7   &kp N8    &kp N9  &kp N0   &kp BSPC
&kp TAB   &kp Q  &kp W  &kp E    &kp R    &kp T                       &kp Y  &kp U    &kp I     &kp O   &kp P    &kp LBKT
&kp LSHFT &kp A  &kp S  &kp D    &kp F    &kp G                       &kp H  &kp J    &kp K     &kp L   &kp SEMI &kp SQT
&kp LCTRL &kp Z  &kp X  &kp C    &kp V    &kp B  &kp MINUS  &kp EQUAL &kp N  &kp M    &kp COMMA &kp DOT &kp FSLH &kp RSHFT
                        &kp LGUI &kp LALT &mo 1  &kp SPACE  &kp RET   &mo 2  &kp LALT &kp K_CONTEXT_MENU
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN>;
        };

        lower_layer {
// ------------------------------------------------------------------------------------------------------------
// |   `   |  F1 |  F2 |  F3  |  F4  |  F5  |                  |  F6  |  F7   |  F8   |  F9  |  F10  |  DEL  |
// |       |     |     |      |      |      |                  |      |       |       |      |       |  "]"  |
// |       |     |     |      |      |      |                  |      |   <-  |   v   |  ^   |  ->   |   \   |
// | NUBS  |     |     |      |      |      |  F11  |  |  F12  |      |       |       |      |       |       |
//                     |      |      |      |       |  |       |      |       |       |
            bindings = <
&bt GRAVE &kp F1   &kp F2   &kp F3  &kp F4   &kp F5                       &kp F6    &kp F7    &kp F8      &kp F9    &kp F10   &kp DEL
&trans    &trans   &trans   &trans  &trans   &trans                       &trans    &trans    &trans      &trans    &trans    &kp RBKT
&trans    &trans   &trans   &trans  &trans   &trans                       &trans    &kp LEFT  &kp DOWN    &kp UP    &kp RIGHT &kp BACKSLASH
&kp NUBS  &trans   &trans   &trans  &trans   &trans    &kp F11   &kp F12  &trans    &trans    &trans      &trans    &trans    &trans
                            &trans  &trans   &trans    &trans    &trans   &mo 3     &trans    &trans
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN>;
        };

        raise_layer {
// ------------------------------------------------------------------------------------------------------------
// |       |     |     |      |      |      |                   |      |       |       |      |       |       |
// |   `   |  1  |  2  |  3   |  4   |  5   |                   |  6   |   7   |   8   |  9   |   0   |       |
// |   F1  |  F2 |  F3 |  F4  |  F5  |  F6  |                   |      |   <-  |   v   |  ^   |  ->   |       |
// |   F7  |  F8 |  F9 |  F10 |  F11 |  F12 |        |  |       |  +   |   -   |   =   |  [   |   ]   |   \   |
//                     |      |      |      |        |  |       |      |       |       |
            bindings = <
&trans    &trans &trans &trans  &trans  &trans                       &trans      &trans    &trans    &trans   &trans    &trans
&kp GRAVE &kp N1 &kp N2 &kp N3  &kp N4  &kp N5                       &kp N6      &kp N7    &kp N8    &kp N9   &kp N0    &trans
&kp F1    &kp F2 &kp F3 &kp F4  &kp F5  &kp F6                       &trans      &kp LEFT  &kp DOWN  &kp UP   &kp RIGHT &trans
&kp F7    &kp F8 &kp F9 &kp F10 &kp F11 &kp F12   &trans   &trans    &kp KP_PLUS &kp MINUS &kp EQUAL &kp LBKT &kp RBKT  &kp BSLH
                        &trans  &trans  &mo 3     &trans   &trans    &trans      &trans    &trans
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN>;
        };

        adjust_layer {
// ------------------------------------------------------------------------------------------------------------
// | BTCLR | BT1 | BT2 |  BT3 |  BT4 |  BT5 |                   |      |       |       |      |       |       |
// |  F1   |  F2 |  F3 |  F4  |  F5  |  F6  |                   |  F7  |  F8   |  F9   |  F10 |  F11  |  F12  |
// |   `   |  !  |  @  |  #   |  $   |  %   |                   |  ^   |  &    |  *    |  (   |   )   |   ~   |
// |       |     |     |      |      |      |        |  |       |      |  _    |  +    |  {   |   }   |  "|"  |
//                     |      |      |      |        |  |       |      |       |       |
            bindings = <
&bt BT_CLR &bt BT_SEL 0     &bt BT_SEL 1      &bt BT_SEL 2      &bt BT_SEL 3 &bt BT_SEL 4                 &trans    &trans    &trans          &trans    &trans    &trans
&kp F1     &kp F2           &kp F3            &kp F4            &kp F5       &kp F6                       &kp F7    &kp F8    &kp F9          &kp F10   &kp F11   &kp F12
&kp GRAVE  &kp EXCL         &kp AT            &kp HASH          &kp DOLLAR   &kp PRCNT                    &kp CARET &kp AMPS  &kp KP_MULTIPLY &kp LPAR  &kp RPAR  &kp TILDE
&trans     &ext_power EP_ON &ext_power EP_OFF &ext_power EP_TOG &trans       &trans    &trans   &trans    &trans    &kp MINUS &kp KP_PLUS     &kp LBRC  &kp RBRC  &kp PIPE
                                              &trans            &trans       &trans    &trans   &trans    &trans    &trans    &trans
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN>;
        };
    };
};
