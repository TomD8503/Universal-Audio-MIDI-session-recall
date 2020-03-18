# Universal-Audio-MIDI-session-recall
This project is a workaround solution, for recalling sessions in console using MIDI program change messages.
## Hardware required:
- Arduino Leonardo or Micro Leonardo (ATmega32U4)
- Electronics:
    - DIN5 socket
    - 6N138 opto-isolator
    - 220 Ohm resistor
    - 280 Ohm resistor
    - universal PCB od breadboard
    - connection cables 
- USB cable
Alternatively instead of electronic components, you can consider using a preassembled [MIDI Shield](https://www.sparkfun.com/products/12898)

## Principle of operation:
The microcontroller is configurated as a [virtual keyboard](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/). A MIDI program change message, received through UART is translated, to a keyboard shortcut sequence, recalling a session corresponding to the program number. The software has a bonus feature - automatic logging to system. It allows using your Mac, without keyboard, mouse, or even monitor. This setup is very usefull, when you want to use Apollo + Mac mini + MIDI controller (eg. [Behringer FCB1010](https://www.behringer.com/Categories/Behringer/Accessories/Midi-Foot-Controllers/FCB1010/p/P0089#googtrans(en|en))) for playing live. 

## Hardware connections:


to be continued...
