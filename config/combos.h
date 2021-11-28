// Copyright 2021 @filterpaper
// SPDX-License-Identifier: MIT

/* Key positions
    0  1  2  3  4       5  6  7  8  9
   10 11 12 13 14      15 16 17 18 19
   20 21 22 23 24      25 26 27 28 29
              30 31  32 33            */

compatible = "zmk,combos";
#define COMBO(name, keypress, keypos) \
	combo_##name {                    \
		layers = <0>;                 \
		timeout-ms = <20>;            \
		bindings = <keypress>;        \
		key-positions = <keypos>;     \
	};

COMBO(VOLU,	&kp C_VOL_UP,  5 15)
COMBO(VOLD,	&kp C_VOL_DN, 15 25)

// layer toggle
COMBO(numb,	&tog NUM, 33 25)

// vimac
COMBO(vimacf, &kp LS(LC(LA(LG(F)))), 12 13)
COMBO(vimacj, &kp LS(LC(LA(LG(J)))), 16 17)
