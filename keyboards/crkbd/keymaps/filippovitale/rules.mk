RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight
# BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality

# BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
# MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
# MIDI_ENABLE = no            # MIDI controls
# AUDIO_ENABLE = no           # Audio output on port C6
# BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
# SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
