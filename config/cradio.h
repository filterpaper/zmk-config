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
#define Z_SLEEP  &kp LA(LG(C_PWR))
#define Z_SHUT   &kp LA(LG(LC(C_PWR)))
#define Z_BOOT   &bootloader
#define Z_VOL_UP &kp C_VOL_UP
#define Z_VOL_DN &kp C_VOL_DN
#define Z_BT_CLR &bt BT_CLR
#define Z_BT_0   &bt BT_SEL 0
#define Z_BT_1   &bt BT_SEL 1
#define Z_BT_2   &bt BT_SEL 2
#define NAV_UP   &kp LS(LA(UARW))
#define NAV_DN   &kp LS(LA(DARW))
#define ________ &trans

// Hold tap key timers
#define TAPPING_TERM <200>
#define QUICK_TAP <120>

// Clipboard shortcuts using hold tap
#define HT(k1,k2,k3,k4) &ht LG(V) k1  &ht LG(C)  k2 &ht LG(X) k3  &ht LG(Z) k4

// Home row mods using positional hold tap
#define HRML(k1,k2,k3,k4) &lht LSHFT k1  &lht LALT k2  &lht LCTRL k3  &lht LGUI k4
#define HRMR(k1,k2,k3,k4) &rht LGUI k1  &rht LCTRL k2  &rht LALT k3  &rht LSHFT k4

// Combo macro
#define COMBO(name, keypress, keypos) \
combo_##name {                        \
	layers = <0>;                     \
	timeout-ms = <25>;                \
	bindings = <keypress>;            \
	key-positions = <keypos>;         \
};
