# Summary
This is my personal [ZMK](https://github.com/zmkfirmware/zmk) configuration for 34-key Cradio ([Hypergolic](https://github.com/davidphilipbarr/hypergolic)). It uses contextual hold-tap configuration to make home row modifiers easier to use, along with simple macros to manage the keymap.

&nbsp;</br> &nbsp;</br>

# Contextual Hold-Taps
ZMK's interrupt based input detection offers a large number of configuration options for managing hold or tap keys. These are my contextual configuration setup for ease of triggering modifiers while avoiding false positives.

## Thumb keys
Layer-tap keys are shared with Tab and Backspace, and they are typically not "rolled" with other overlapping key presses. The `&lt` binding is modified with the `hold-preferred` flavor for quicker layer activation
```c
&lt {
    flavor          = "hold-preferred";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
};
```
The Ctrl+Alt mod-tap key with Enter is configured with the `balanced` flavor to allow intentional trigger of both modifiers with another overlapping key press. The `&mt` binding is changed to the following:
```c
&mt {
    flavor          = "balanced";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
};
```
Lastly, a hold-tap behavior is setup for Shift with Space thumb key and clipboard shortcuts. These keys are subjected to frequent overlap with other keys, so the `tap-preferred` flavor is used to ensure that taps are triggered even if they are pressed together with other keys to avoid false positives.
```c
ht: hold_tap {
    label           = "hold_tap";
    compatible      = "zmk,behavior-hold-tap";
    flavor          = "tap-preferred";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
    #binding-cells  = <2>;
    bindings        = <&kp>, <&kp>;
};
```

## Home row non-Shift modifiers
Modifiers should not be triggered when a mod-tap key is pressed together with another key on the *same hand*. However, they should be triggered when held down and another key is tapped with the *opposite hand*. This is accomplished using `tap-preferred` flavor with the following positional hold-tap behavior (mirrored for the right side):
```c
lmt: left_mod_tap {
    label           = "left_mod_tap";
    compatible      = "zmk,behavior-hold-tap";
    flavor          = "tap-preferred";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
    global-quick-tap;
    #binding-cells  = <2>;
    bindings        = <&kp>, <&kp>;
    hold-trigger-key-positions = <
                     5  6  7  8  9
             13     15 16 17 18 19
                    25 26 27 28 29
             30 31  32 33
    >;
};
rmt: right_mod_tap {
    label           = "right_mod_tap";
    compatible      = "zmk,behavior-hold-tap";
    flavor          = "tap-preferred";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
    global-quick-tap;
    #binding-cells  = <2>;
    bindings        = <&kp>, <&kp>;
    hold-trigger-key-positions = <
     0  1  2  3  4
    10 11 12 13 14     16
    17 21 22 23 24
             30 31  32 33
    >;
};
```
A mod-tap key will send its tap key code if it overlaps with another key index that is **not in** the `hold-trigger-key-positions`. If it overlaps with a key index **listed in** the `hold-trigger-key-positions`, the mod-tap behavior will be as defined. Two home row mod positions on the same side is included to allow chording of frequently used modifiers. The `global-quick-tap` setting is also defined to disable the hold function while typing quickly.

## Home row Shift
The home row mod-tap Shift key is configured differently than the other modifiers. It is set with the `balanced` flavor, but only for keys on the opposite hand using `hold-trigger-key-positions`. The `global-quick-tap` feature is excluded to avoid Shift from being deactivated while typing quickly. They are configured with the following binding (also mirrored for the right side):
```c
lst: left_shift_tap {
    label           = "left_shift_tap";
    compatible      = "zmk,behavior-hold-tap";
    flavor          = "balanced";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
    #binding-cells  = <2>;
    bindings        = <&kp>, <&kp>;
    hold-trigger-key-positions = <
                     5  6  7  8  9
                    15 16 17 18 19
                    25 26 27 28 29
             30 31  32 33
    >;
};
rst: right_shift_tap {
    label           = "right_shift_tap";
    compatible      = "zmk,behavior-hold-tap";
    flavor          = "balanced";
    tapping-term-ms = <TAPPING_TERM>;
    quick-tap-ms    = <QUICK_TAP>;
    #binding-cells  = <2>;
    bindings        = <&kp>, <&kp>;
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
## Home row mod-taps
A wrapper macro is used to apply the aforementioned home row mod-taps to the keymap in a way that makes them easier to read:
```c
#define HRML(k1,k2,k3,k4) &lmt LCTRL k1  &lmt LALT k2  &lmt LGUI k3  &lst LSHFT k4
#define HRMR(k1,k2,k3,k4) &rst RSHFT k1  &rmt RGUI k2  &rmt RALT k3  &rmt RCTRL k4
```
## Combos
Combos are simplified into one-liners using the following code:
```c
#define COMBO(name, keypress, keypos) \
    combo_##name {                    \
        layers = <0>;                 \
        timeout-ms = <20>;            \
        bindings = <keypress>;        \
        key-positions = <keypos>;     \
    };

COMBO(name, bindings, key positions)
```
## Macros
Macros are also simplified into one-liners using the following code:
```c
#define MACRO(name, keys)                  \
    name: name##_macro {                   \
        label = #name;                     \
        compatible = "zmk,behavior-macro"; \
        wait-ms = <1>;                     \
        tap-ms = <1>;                      \
        #binding-cells = <0>;              \
        bindings = <keys>;                 \
    };

MACRO(dir_up, &kp DOT &kp DOT &kp FSLH)
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
