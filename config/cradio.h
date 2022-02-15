// Copyright 2021 @filterpaper
// SPDX-License-Identifier: MIT

// Adjusted pin arrangement
&kscan0 {
	input-gpios
	= <&pro_micro_d  6 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_a  0 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_a  1 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_a  2 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_a  3 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d 15 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d 14 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d 16 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d 10 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  1 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  2 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  3 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  4 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  5 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  7 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  8 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	, <&pro_micro_d  9 (GPIO_ACTIVE_LOW | GPIO_PULL_UP)>
	;
};

// Layers
#define BSE 0
#define CMK 1
#define NUM 2
#define SYM 3
#define FNC 4

// Keymap macros
#define Z_SLEEP	 &kp LA(LG(C_PWR))
#define Z_SHUT	 &kp LA(LG(LC(C_PWR)))
#define NAV_UP &kp LS(LA(UARW))
#define NAV_DN &kp LS(LA(DARW))

#define Z_BT_CLR &bt BT_CLR
#define Z_BT_0   &bt BT_SEL 0
#define Z_BT_1   &bt BT_SEL 1
#define Z_BT_2   &bt BT_SEL 2

#define ________ &trans

// Clipboard shortcuts
#define TH(k1,k2,k3,k4) &th LG(V) k1  &th LG(C)  k2 &th LG(X) k3  &th LG(Z) k4

// Home row mods
#define HRML(k1,k2,k3,k4) &th LSHFT k1  &th LALT k2  &th LCTRL k3  &th LGUI k4
#define HRMR(k1,k2,k3,k4) &th LGUI k1  &th LCTRL k2  &th LALT k3  &th LSHFT k4

// Combos
#define COMBO(name, keypress, keypos) \
combo_##name {                        \
	layers = <0>;                     \
	timeout-ms = <25>;                \
	bindings = <keypress>;            \
	key-positions = <keypos>;         \
};
