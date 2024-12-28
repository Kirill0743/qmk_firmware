# handwired/darkline/decapitator

![handwired/darkline/decapitator](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Darkine](https://github.com/Kirill0743)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make handwired/darkline/decapitator:default

Flashing example for this keyboard (with qmk tools installed):
    
For left half:

    qmk flash -kb handwired/darkline/decapitator -km default -bl dfu-util-split-left

For right half:

    qmk flash -kb handwired/darkline/decapitator -km default -bl dfu-util-split-right

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
