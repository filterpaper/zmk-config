/*
 * Copyright (c) 2021 @filterpaper
 *
 * SPDX-License-Identifier: MIT
 */


// Layers
#define BSE 0
#define CMK 1
#define NUM 2
#define SYM 3
#define FNC 4

// OS X macros
#define Z_SLEEP	 &kp LA(LG(C_PWR))
#define Z_SHUT	 &kp LA(LG(LC(C_PWR)))

// Bottom row clipboard
#define TH(k1,k2,k3,k4) &th LG(V) k1  &th LG(C)  k2 &th LG(X) k3  &th LG(Z) k4

// Home row mods
#define HRML(k1,k2,k3,k4) &hm LSHFT k1  &hm LALT k2  &hm LCTRL k3  &hm LGUI k4
#define HRMR(k1,k2,k3,k4) &hm LGUI k1  &hm LCTRL k2  &hm LALT k3  &hm LSHFT k4

// BT shorcuts
#define Z_BT_CLR &bt BT_CLR
#define Z_BT_0   &bt BT_SEL 0
#define Z_BT_1   &bt BT_SEL 1
#define Z_BLE    &out OUT_BLE
#define Z_USB    &out OUT_USB

#define ________ &trans

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
