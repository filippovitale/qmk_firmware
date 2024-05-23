# My personal layout, matching the one on my Reviung41

## Compile and flash

- `qmk flash -kb preonic/rev3 -km filippovitale`
- `make preonic/rev3:filippovitale:dfu-util`
- (compile only: `qmk compile {keymap}`)

## Config online and flash

- https://config.qmk.fm/
- open `keyboards/preonic/keymaps/filippovitale/preonic_rev3_drop_layout_preonic_1x2uc_mine.json`
- press the "COMPILE" button and then download the firmware
- `qmk setup`
- `cd keyboards/preonic/keymaps/filippovitale`
- `qmk flash -bl dfu-util preonic_rev3_drop_preonic_rev3_drop_filippovitale.bin`

## Convert JSON config file to a keymap.c

- `qmk json2c {keymap}`

# Resources

- [QMK config](https://config.qmk.fm/)
  - [QMK keyboard test](https://config.qmk.fm/#/test)
- [QMK codes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
  - [QMK mod tap](https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md)
- [ZMK codes](https://zmk.dev/docs/codes)
- https://maxzsol.com/step-by-step-guide-to-setting-up-qmk-for-the-planck-on-macos/
