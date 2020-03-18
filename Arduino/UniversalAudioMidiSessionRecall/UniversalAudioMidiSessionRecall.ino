/*
  Universal Audio MIDI session recall
  https://github.com/TomD8503/Universal-Audio-MIDI-session-recall
*/
#include "Keyboard.h"
#include "configuration.h"

uint8_t incomingByte = 0;
bool received_valid_program_change = false;
uint8_t program_change_char = 0xC0;
uint8_t _midi_channel;
unsigned long timeout; 



void setup() 
{
  Keyboard.begin();
  Serial1.begin(31250);
  if (omni_mode==true) _midi_channel = 1;
    else _midi_channel = midi_channel;
  _midi_channel = _midi_channel - 1;
  program_change_char = program_change_char + _midi_channel;
}

void loop() 
  {
#if (login==true)
        delay(system_startup_time);
        Keyboard.println(password);
        delay(app_startup_time);
        
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_F4);
        delay(100);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('o');
        delay(100);
        Keyboard.releaseAll();      
#endif
     
   while(true)
   {
    if (Serial1.available()) 
      {
        incomingByte=Serial1.read();
        if ((omni_mode==true) and (received_valid_program_change==false)) incomingByte = incomingByte & 0b11110000;
        
        if((incomingByte == program_change_char) and (received_valid_program_change==false)) 
          {
            timeout = millis() + midi_timeout;
            received_valid_program_change=true;
          } 
          else
            {
              if((received_valid_program_change==true) and (incomingByte < 128))
                {
                   if (millis() < timeout) 
                    {
                      if (incomingByte < 16) Keyboard.print("0");
                      Keyboard.println(incomingByte,HEX);
                      delay(500);
                      Keyboard.press(KEY_LEFT_CTRL);
                      Keyboard.press(KEY_F4);
                      delay(100);
                      Keyboard.releaseAll();
    
                      Keyboard.press(KEY_LEFT_GUI);
                      Keyboard.press('o');
                      delay(100);
                      Keyboard.releaseAll();
                      delay(500);
                    }
                }
               received_valid_program_change=false;
            }
      }
    
    
      }
   }


  
    
  
