# Summary
Personal ZMK configuration for 34-key Cradio ([Hypergolic](https://github.com/davidphilipbarr/hypergolic))

# Macros
A couple of C preprocessors are defined in `cradio.h` to keep the keymap file tidy.
## Home Row Mods
Two macros to easily swap [home row mods](https://precondition.github.io/home-row-mods) positions in the layout:
```c
#define HRML(k1,k2,k3,k4) &hm LSHFT k1  &hm LALT k2  &hm LCTRL k3  &hm LGUI k4
#define HRMR(k1,k2,k3,k4) &hm LGUI k1  &hm LCTRL k2  &hm LALT k3  &hm LSHFT k4
```
## Combos
Shortcut to simplify combos into one-liners:
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
Shortcut for simple key press macros:
```c
#define MACRO(name, keys)                  \
    name: name##_macro {                   \
        label = #name;                     \
        compatible = "zmk,behavior-macro"; \
        #binding-cells = <0>;              \
        wait-ms = <1>;                     \
        tap-ms = <1>;                      \
        bindings = <keys>;                 \
    };

MACRO(dir_up, &kp DOT &kp DOT &kp FSLH)
```

# Useful Links
* nice!nano v2 [Pinout](https://nicekeyboards.com/docs/nice-nano/pinout-schematic/)
* Customizing [ZMK](https://zmk.dev/docs/customization)
* [Hypergolic](https://github.com/davidphilipbarr/hypergolic) PCBs
* [Sockets](https://github.com/joric/nrfmicro/wiki/Sockets)
* [Keymapviz](https://github.com/yskoht/keymapviz)
## Hardware Parts
* Machined [header sockets](https://www.aliexpress.com/item/32852480645.html)
* Mill-Max [315-43-164-41-001000](https://www.digikey.com/en/products/detail/mill-max-manufacturing-corp/315-43-164-41-001000/1212142) sockets
* Mill-Max [connector pins](https://www.digikey.com/product-detail/en/3320-0-00-15-00-00-03-0/ED1134-ND/4147392)
* [301230](https://www.aliexpress.com/item/4000336497558.html) Li-po batteries
* [MSK-12C02](https://www.aliexpress.com/item/1005001398386692.html) SMD Switch
* [Silicone bumper](https://www.aliexpress.com/item/32912066603.html) feet
* Kailh [gchoc v1 switches](https://www.aliexpress.com/item/4000907409650.html)
