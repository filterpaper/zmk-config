/*
 * Copyright (c) 2021 @filterpaper
 *
 * SPDX-License-Identifier: MIT
 */

// Tap hold and OS X shortcuts
#define TH_V	 &th LS(LG(V)) V
#define TH_M	 &th LG(V) M
#define TH_COMMA &th LG(C) COMMA
#define TH_DOT	 &th LG(X) DOT
#define TH_FSLH	 &th LG(Z) FSLH
#define Z_SLEEP	 &kp LA(LG(C_PWR))
#define Z_SHUT	 &kp LA(LG(LC(C_PWR)))

// Home row mod macros
#define HMS(k)	&hm LSHFT k
#define HMA(k)	&hm LALT k
#define HMC(k)	&hm LCTRL k
#define HMG(k)	&hm LGUI k

// Layers
#define BSE 0
#define CMK 1
#define NUM 2
#define SYM 3
#define FNC 4

// BT shorcuts
#define Z_BT_CLR &bt BT_CLR
#define Z_BT_0   &bt BT_SEL 0
#define Z_BT_1   &bt BT_SEL 1
#define Z_BLE    &out OUT_BLE
#define Z_USB    &out OUT_USB

#define ________ &trans
