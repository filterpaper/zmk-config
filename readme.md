# Summary
Personal ZMK configuration for 34-key Cradio ([Hypergolic](https://github.com/davidphilipbarr/hypergolic))

# Code Snippets
## Combos
The C preprocessor in `combos.dtsi` simplifies combos into one-liners in the format of:
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
Another set of C preprocessors to easily swap [home row mods](https://precondition.github.io/home-row-mods) positions while keeping keymap bindings tidy:
```c
#define HMS(k)	&hm LSHFT k
#define HMA(k)	&hm LALT k
#define HMC(k)	&hm LCTRL k
#define HMG(k)	&hm LGUI k
```

# Useful Links
* nice!nano v2 [Pinout](https://nicekeyboards.com/docs/nice-nano/pinout-schematic/)
* Customizing [ZMK](https://zmk.dev/docs/customization)
* @davidphilipbarr's [Hypergolic PCBs](https://github.com/davidphilipbarr/hypergolic)
* [Sockets](https://github.com/joric/nrfmicro/wiki/Sockets)
## Hardware Parts
* Mill-Max [socket pins](https://www.digikey.com/product-detail/en/3320-0-00-15-00-00-03-0/ED1134-ND/4147392)
* Machined [header sockets](https://www.aliexpress.com/item/32852480645.html)
* [301230 Li-po batteries](https://www.aliexpress.com/item/4000336497558.html)
* [MSK-12C02 SMD Switch](https://www.aliexpress.com/item/1005001398386692.html)
* [Silicone feet](https://www.aliexpress.com/item/32912066603.html)
* Kailh [gchoc v1 switches](https://www.aliexpress.com/item/4000907409650.html)
