# Summary
Personal ZMK configuration for 34-key Cradio ([Hypergolic](https://github.com/davidphilipbarr/hypergolic))

# Code Snippets
## Combos
The C preprocessor in `combos.h` simplifies combos into one-liners in the format of:
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
## Home Row Mods
Two macros to easily swap [home row mods](https://precondition.github.io/home-row-mods) position while keeping keymap bindings tidy:
```c
#define HRML(k1,k2,k3,k4) &hm LSHFT k1  &hm LALT k2  &hm LCTRL k3  &hm LGUI k4
#define HRMR(k1,k2,k3,k4) &hm LGUI k1  &hm LCTRL k2  &hm LALT k3  &hm LSHFT k4
```

# Useful Links
* nice!nano v2 [Pinout](https://nicekeyboards.com/docs/nice-nano/pinout-schematic/)
* Customizing [ZMK](https://zmk.dev/docs/customization)
* [Hypergolic PCBs](https://github.com/davidphilipbarr/hypergolic) PCBs
* [Sockets](https://github.com/joric/nrfmicro/wiki/Sockets)
* [Keymapviz](https://github.com/yskoht/keymapviz)
## Hardware Parts
* Machined [header sockets](https://www.aliexpress.com/item/32852480645.html)
* Mill-Max [pins](https://www.digikey.com/product-detail/en/3320-0-00-15-00-00-03-0/ED1134-ND/4147392)
* [301230](https://www.aliexpress.com/item/4000336497558.html) Li-po batteries
* [MSK-12C02](https://www.aliexpress.com/item/1005001398386692.html) SMD Switch
* [Silicone bumper](https://www.aliexpress.com/item/32912066603.html) feet
* Kailh [gchoc v1 switches](https://www.aliexpress.com/item/4000907409650.html)
