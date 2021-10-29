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
