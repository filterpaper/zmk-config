// Copyright 2022 @filterpaper
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
#define Z_VOL_UP &kp C_VOL_UP
#define Z_VOL_DN &kp C_VOL_DN
#define Z_BT_CLR &bt BT_CLR
#define Z_BT_0   &bt BT_SEL 0
#define Z_BT_1   &bt BT_SEL 1
#define Z_BT_2   &bt BT_SEL 2
#define NAV_UP   &kp LS(LA(UARW))
#define NAV_DN   &kp LS(LA(DARW))
#define Z_BOOT   &bootloader
#define ________ &trans

// Hold tap key timers
#define QUICK_TAP    <180>
#define TAPPING_TERM <200>
#define PHT_TERM     <250>

// Clipboard shortcut hold tap
#define HT(k1,k2,k3,k4) &ht LG(V) k1  &ht LG(C)  k2 &ht LG(X) k3  &ht LG(Z) k4

// Home row mods positional hold tap
#define HRML(k1,k2,k3,k4) &lht LSHFT k1  &lht LALT k2  &lht LCTRL k3  &lht LGUI k4
#define HRMR(k1,k2,k3,k4) &rht RGUI k1  &rht RCTRL k2  &rht RALT k3  &rht RSHFT k4

// Hyper modifier
#define HYPR(k) LS(LC(LA(LG(k))))

// Combo macro
#define COMBO(name, keypress, keypos) \
combo_##name {                        \
	layers = <0>;                     \
	timeout-ms = <25>;                \
	bindings = <keypress>;            \
	key-positions = <keypos>;         \
};

// Macro macro
#define MACRO(name, keys)             \
name: name##_macro {                  \
	label = #name;                    \
	compatible = "zmk,behavior-macro";\
	#binding-cells = <0>;             \
	wait-ms = <1>;                    \
	tap-ms = <1>;                     \
	bindings = <keys>;                \
};
