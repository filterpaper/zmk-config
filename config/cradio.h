// Copyright 2022 @filterpaper
// SPDX-License-Identifier: MIT

// Adjust pins for Hypergolic 1.2
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
#define Z_SHUT   &kp LC(LA(LG(C_PWR)))
#define Z_SSAVE  &kp LC(LA(LS(LG(S))))
#define NAV_UP   &kp LS(LA(UARW))
#define NAV_DN   &kp LS(LA(DARW))
#define ________ &trans

// Hold tap macros
#define TAPPING_TERM 210
#define QUICK_TAP    125
// Clipboard shortcuts
#define HT(k1,k2,k3,k4) &ht LG(V) k1  &ht LG(C) k2  &ht LG(X) k3  &ht LG(Z) k4
// Home row mods hold tap
#define HRML(k1,k2,k3,k4) &lht LSHFT k1  &lht LALT k2  &lht LCTRL k3  &lht LGUI k4
#define HRMR(k1,k2,k3,k4) &rht RGUI k1  &rht RCTRL k2  &rht RALT k3  &rht RSHFT k4

#define LEFT_HOLD_TRIGGER_KEYS    \
					5  6  7  8  9 \
	10 11 12 13    15 16 17 18 19 \
				   25 26 27 28 29 \
		  30 31 32 33

#define RIGHT_HOLD_TRIGGER_KEYS   \
	 0  1  2  3  4                \
	10 11 12 13 14    16 17 18 19 \
	20 21 22 23 24                \
				30 31 32 33

// Combo macro
#define COMBO(name, keypress, keypos) \
combo_##name {                        \
	layers = <0>;                     \
	timeout-ms = <30>;                \
	bindings = <keypress>;            \
	key-positions = <keypos>;         \
};

// Macro macro
#define MACRO(name, keys)             \
name: name##_macro {                  \
	label = #name;                    \
	compatible = "zmk,behavior-macro";\
	#binding-cells = <0>;             \
	tap-ms = <1>;                     \
	wait-ms = <1>;                    \
	bindings = <keys>;                \
};
