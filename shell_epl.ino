#include "shell.h"

#define wifiLedPin 2
#define buzzerPin 5

/*
LED STATUS CODES:

wifi led:
1) blinking with mild blinking frequency: trying to connect to wifi
2) blinking with high frequency: trying to connect to server
3) running continously: all is well and listening for commands to receive
4) off: connection lost

atm led:
1) blinking for 3 times and stopping for 1 second: trying to initialise
2) on: all is well
3) off: disconnected

*/

Shell shell(wifiLedPin,buzzerPin);

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  shell.initialise();
}

void loop() 
{
    if(WiFi.status() != WL_CONNECTED)
  {
     while (WiFi.status() != WL_CONNECTED) 
    {
        shell.wifiLed.blinkSpecial(250,250,1,0);
    }
    
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
  shell.listenAndSpeak();
}
