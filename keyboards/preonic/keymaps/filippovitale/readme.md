# My personal layout, matching the one on my Reviung41

## Compile and flash

- `qmk flash -kb preonic/rev3 -km filippovitale`
- `make preonic/rev3:filippovitale:dfu-util`


## Config online and flash

- https://config.qmk.fm/
- open `keyboards/preonic/keymaps/filippovitale/preonic_rev3_drop_layout_preonic_1x2uc_mine.json`
- press the "COMPILE" button and then download the firmware
- `qmk setup`
- `qmk flash -bl dfu-util ~/Downloads/preonic_rev3_drop_preonic_rev3_drop_layout_preonic_1x2uc_mine.bin`


# Resources

- https://maxzsol.com/step-by-step-guide-to-setting-up-qmk-for-the-planck-on-macos/
