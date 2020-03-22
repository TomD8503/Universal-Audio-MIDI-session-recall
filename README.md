# Universal-Audio-MIDI-session-recall
This project is a workaround solution, for recalling sessions in console using MIDI program change messages.

# Disclaimer:
I do not take any responsibility if it doesn't work, or you damage your hardware.

## Hardware required:
- Arduino Leonardo or Micro Leonardo (ATmega32U4)
- Electronics:
    - DIN5 socket
    - 6N138 opto-isolator
    - 220 Ohm resistor
    - 280 Ohm resistor
    - 1N914 diode
    - universal PCB od breadboard
    - connection cables 
- USB cable

Alternatively instead of electronic components, you can consider using a preassembled [MIDI Shield](https://www.sparkfun.com/products/12898)

## Principle of operation:
The microcontroller is configurated as a [virtual keyboard](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/). A MIDI program change message, received through UART is translated, to a keyboard shortcut sequence, recalling a session corresponding to the program number. The software has a bonus feature - automatic logging to system. It allows using your Mac, without keyboard, mouse, or even monitor. This setup is very usefull, when you want to use Apollo + Mac mini + MIDI controller (eg. [Behringer FCB1010](https://www.behringer.com/Categories/Behringer/Accessories/Midi-Foot-Controllers/FCB1010/p/P0089#googtrans(en|en))) for playing live. 

## Hardware connections:

Connect the electronic components according to the [schematic](https://www.midi.org/specifications-old/item/midi-din-electrical-specification) from midi.org
"To UART" should be connected to Pin0(Rx) of the Arduino Leonardo. You can omit the output part of the schematic, it won't be used.

[Here](https://youtu.be/GxfHijjn0ZM) is a nice video tutorial on connecting the hardware using a breadboard.

If you are using the MIDI Shield, make sure the SJ1 jumper (Rx sel) is set to HARD-RX (it should be by default).

## Building and uploading:
Install [Arduino IDE](https://www.arduino.cc/en/main/software), clone or download the repository. Launch the .ino file. 
### configuration:
go to the tab "configuration.h". Edit the following lines:
- `define login` - set `false` for no login operation. If set to `true`, after powerup, your password will be automatically typed in the login window. This function allows for operation without mouse or/and keyboard.
    - `#define password "MyPassword"` Enter the password, to login to your system, inside the quotation marks.
    - `#define system_startup_time` Enter the time elapsing after powerup, until the login screen shows. use miliseconds. 1 second = 1000 miliseconds.
    - `#define app_startup_time` Enter the time elapsing after typing your password, until all the apps have started and your UA hardware is connected.
- `#define omni_mode` set `true` for receiving MIDI program change messages on all channels. Set `false` if you want to select a specific channel.
- `#define midi_channel` select MIDI channel, from 1 to 16 for receiving program change messages. 
- `#define midi_timeout` it is recomended to leave the default value of 100ms. A MIDI program change message consists of two bytes, which should be sent immediately one after another. `midi_timeout` specifies the maximum delay between the two bytes. If exceeded, the program change message is ignored, and the software is ready to receive another program change message. 

### uploading:
Follow the standard procedure for [uploading to Arduino Leonardo](https://www.arduino.cc/en/Guide/ArduinoLeonardoMicro).

Beware that if you set `define login true` after `system_startup_time` your password will by automatically typed, followed by `enter`, and after `app_startup_time` you will get `Ctrl+F4` followed by `Command+o`.

## Session file names:
**It is absolutley essential to have the session folder, and file names configured, as described below !**

There are 128 MIDI programs, all of which correspond to their session files. Each session file has it's own coressponding midi program. The session files are given names begining with program number in `HEX` format, starting from `00` ending at `7F`. It is Important not to have other files in the session directory. The order from `00` to `7F` must remain undisturbed. After the preset number, you can write a short description of the preset. 

Example of how it should look:
```
00_plexi_clean
01_plexi_drive
02_plexi_hi_gain
03_plexi_hi_gain_solo_boost
04_plexi_clean_chorus
05_plexi_drive_chorus
06_plexi_hi_gain_chorus
07_plexi_hi_gain_solo_boost_chorus
08_plexi_clean_flanger
09_plexi_drive_flanger
0A_plexi_hi_gain_flanger
0B_plexi_hi_gain_solo_boost_flanger
0C_name_of_preset
0D_name_of_preset
0E_name_of_preset
0F_name_of_preset
10_name_of_preset
11_name_of_preset
...
...
...
6C_name_of_preset
6D_name_of_preset
6E_name_of_preset
6F_name_of_preset
70_name_of_preset
71_name_of_preset
72_name_of_preset
73_name_of_preset
74_name_of_preset
75_name_of_preset
76_name_of_preset
77_name_of_preset
78_name_of_preset
79_name_of_preset
7A_name_of_preset
7B_name_of_preset
7C_name_of_preset
7D_name_of_preset
7E_name_of_preset
7F_last_preset
```

## How to use:
To be continued...

