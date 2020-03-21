#define login false                     // log in to system true/false
#if login
  #define password "MyPassword"         // Your system password
  #define system_startup_time 30000     // time in miliseconds after powerup to login window
  #define app_startup_time 40000        // time in miliseconds after login to startup all apps
#endif

#define omni_mode false                 // receive midi program change on all channels true/false (if true, overrides midi channel)
#define midi_channel 1                  // select midi channel from 1 to 16 (disabled if omni_mode true)
#define midi_timeout 100                // maximum delay in miliseconds between receiving two midi bytes (default 100ms)
