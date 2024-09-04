# Summary
This is my personal [ZMK](https://github.com/zmkfirmware/zmk) configuration for 34-key Cradio ([Hypergolic](https://github.com/davidphilipbarr/hypergolic)). It uses contextual hold-tap configuration to make home row modifiers easier to use, along with simple macros to manage the keymap.

![kb](https://github.com/filterpaper/filterpaper.github.io/raw/main/images/nice_cradio.png)

&nbsp;</br> &nbsp;</br>

# Contextual Hold-Taps
ZMK's interrupt based input detection offers a large number of configuration options for managing hold or tap keys. These are my contextual configuration setup for ease of triggering modifiers while avoiding false positives.

## Home Row Modifiers
Modifiers should not be triggered when a mod-tap key is pressed together with another key on the *same hand*. However, they should be triggered when held down and another key is tapped with the *opposite hand*. This is accomplished using `balanced` flavor with the following positional hold-tap behavior for left and right mod-taps:
```c
#define TAPPING_TERM 240
#define SHIFT_TAP_MS 170
#define QUICK_TAP_MS 140

lmt: left_mod_tap {
    compatible                 = "zmk,behavior-hold-tap";
    #binding-cells             = <2>;
    flavor                     = "preferred";
    tapping-term-ms            = <TAPPING_TERM>;
    quick-tap-ms               = <QUICK_TAP_MS>;
    bindings                   = <&kp>, <&kp>;
    require-prior-idle-ms      = <QUICK_TAP_MS>;
    hold-trigger-key-positions = <
                     5  6  7  8  9
             13     15 16 17 18 19
                    25 26 27 28 29
             30 31  32 33
    >;
};
rmt: right_mod_tap {
    compatible                 = "zmk,behavior-hold-tap";
    #binding-cells             = <2>;
    flavor                     = "preferred";
    tapping-term-ms            = <TAPPING_TERM>;
    quick-tap-ms               = <QUICK_TAP_MS>;
    bindings                   = <&kp>, <&kp>;
    require-prior-idle-ms      = <QUICK_TAP_MS>;
    hold-trigger-key-positions = <
     0  1  2  3  4
    10 11 12 13 14     16
    17 21 22 23 24
             30 31  32 33
    >;
};
```
[Hold trigger keys](https://zmk.dev/docs/keymaps/behaviors/hold-tap#positional-hold-tap-and-hold-trigger-key-positions) are setup with positions on the opposite hand of each side for ease of activation. The `require-prior-idle-ms` feature is used to prevent unintended modifier activation during regular typing.

## Home Row Shift
The home row hold-tap Shift key is setup with a shorter tapping term, using `balanced` flavor and without `require-prior-idle-ms` for quicker capitalization while typing. They are defined with the following bindings:
```c
lst: left_shift_tap {
    compatible                 = "zmk,behavior-hold-tap";
    #binding-cells             = <2>;
    flavor                     = "balanced";
    tapping-term-ms            = <SHIFT_TAP_MS>;
    quick-tap-ms               = <QUICK_TAP_MS>;
    bindings                   = <&kp>, <&kp>;
    hold-trigger-key-positions = <
                     5  6  7  8  9
                    15 16 17 18 19
                    25 26 27 28 29
             30 31  32 33
    >;
};
rst: right_shift_tap {
    compatible                 = "zmk,behavior-hold-tap";
    #binding-cells             = <2>;
    flavor                     = "balanced";
    tapping-term-ms            = <SHIFT_TAP_MS>;
    quick-tap-ms               = <QUICK_TAP_MS>;
    bindings                   = <&kp>, <&kp>;
    hold-trigger-key-positions = <
     0  1  2  3  4
    10 11 12 13 14
    20 21 22 23 24
             30 31  32 33
    >;
};
```

&nbsp;</br> &nbsp;</br>

# Preprocessor Macros
Preprocessor macros can minimize code duplication, making it easier to update and modify behavior nodes over time.
## Home Row Modifiers
Repetitive hold-tap behavior nodes can be simplified to single-line macros that allows customization of home row mod-tap actions with the following definition:
```c
#define HOLD_TAP(_name_,               \
                 _flavor_,             \
                 _tapping_term_,       \
                 _require_prior_idle_, \
                 _key_positions_)      \
_name_: hold_tap_##_name_ {                               \
    compatible                 = "zmk,behavior-hold-tap"; \
    #binding-cells             = <2>;                     \
    flavor                     = #_flavor_;               \
    quick-tap-ms               = <QUICK_TAP_MS>;          \
    tapping-term-ms            = <_tapping_term_>;        \
    require-prior-idle-ms      = <_require_prior_idle_>;  \
    hold-trigger-key-positions = <_key_positions_>;       \
    bindings                   = <&kp>, <&kp>;            \
};
#define L_SHIFT 13
#define R_SHIFT 16
#define L_KEYS 0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31 32 33
#define R_KEYS 5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 30 31 32 33

/ {
    behaviors {
        // Positional hold-tap for non-Shift modifiers
        HOLD_TAP(lmt, tap-preferred, TAPPING_TERM, QUICK_TAP_MS, L_SHIFT R_KEYS)
        HOLD_TAP(rmt, tap-preferred, TAPPING_TERM, QUICK_TAP_MS, R_SHIFT L_KEYS)
        // Positional hold-tap for Shift
        HOLD_TAP(lst, balanced, SHIFT_TAP_MS, 0, R_KEYS)
        HOLD_TAP(rst, balanced, SHIFT_TAP_MS, 0, L_KEYS)
    };
};
```
## Combos and Macros
Both combos and macros are also simplified into one-liners using the following preprocessors:
```c
#define COMBO(_name_, _bindings_, _key_positions_) \
combo_##_name_ {                                   \
    timeout-ms            = <30>;                  \
    require-prior-idle-ms = <COMBO_IDLE_MS>;       \
    bindings              = <_bindings_>;          \
    key-positions         = <_key_positions_>;     \
    layers                = <0 1>;                 \
};

/ {
    combos {
        compatible = "zmk,combos";
        COMBO(caps_w, &caps_word,   13 16)
    };
};


#define MACRO(_name_, _bindings_)          \
_name_: macro_##_name_ {                   \
    compatible     = "zmk,behavior-macro"; \
    #binding-cells = <0>;                  \
    tap-ms         = <1>;                  \
    wait-ms        = <1>;                  \
    bindings       = <_bindings_>;         \
};

/ {
    macros {
        MACRO(dir_up, &kp DOT &kp DOT &kp FSLH)
        MACRO(bt_0,   &out OUT_BLE &bt BT_SEL 0 &bt BT_DISC 1)
    };
};
```

&nbsp;</br> &nbsp;</br>

# Useful Links
* nice!nano v2 [Pinout](https://nicekeyboards.com/docs/nice-nano/pinout-schematic/)
* Customizing [ZMK](https://zmk.dev/docs/customization)
* [Hypergolic](https://github.com/davidphilipbarr/hypergolic) PCBs
* [Sockets](https://github.com/joric/nrfmicro/wiki/Sockets)
* [Keymapviz](https://github.com/yskoht/keymapviz)
* [Keymap Drawer](https://github.com/caksoylar/keymap-drawer)
## Hardware Parts
* Machined [header sockets](https://www.aliexpress.com/item/32852480645.html)
* Mill-Max [315-43-164-41-001000](https://www.digikey.com/en/products/detail/mill-max-manufacturing-corp/315-43-164-41-001000/1212142) sockets
* Mill-Max [connector pins](https://www.digikey.com/product-detail/en/3320-0-00-15-00-00-03-0/ED1134-ND/4147392)
* [301230](https://www.aliexpress.com/item/4000336497558.html) Li-po batteries
* [MSK-12C02](https://www.aliexpress.com/item/1005001398386692.html) SMD Switch
* [Silicone bumper](https://www.aliexpress.com/item/32912066603.html) feet
* Kailh [gchoc v1 switches](https://www.aliexpress.com/item/4000907409650.html)
