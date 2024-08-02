#include "shell.h"

Shell::Shell(digitalPin wifiLedPin,digitalPin buzzerPin) : wifiLed(wifiLedPin), buzzer(buzzerPin), server(12345)
{
}

void Shell::initialise()
{
    sensor.initialise();
    sensor.calculateAltitudeOffset();
    wifiLed.initialise();
    WiFi.setHostname(hostname);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) 
    {
        wifiLed.blinkSpecial(250, 250, 1, 0);
    }

    Serial.println("");
    Serial.print(hostname);
    Serial.println(" connected to Wifi.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    wifiLed.on();
    server.begin();
    dataToSend = sensor.getDataPacket();
}
void Shell::endMission()
{
  Serial.println(missionEndLine);
  this->wifiLed.off();
  this->wifiLed.action();
  while(true)
{
  buzzer.blinkSpecial(1000, 1000, 1, 0);
}
  
}

void Shell::listenAndSpeak()
{
      wifiLed.action();
      while (WiFi.status() != WL_CONNECTED) 
    {
        wifiLed.blinkSpecial(250, 250, 1, 0);
    }
    WiFiClient client = server.available();
    wifiLed.blinkSpecial(25, 50, 2, 50);
    if (client)
    {
        wifiLed.on();
        wifiLed.action();
        Serial.println("Client connected");

        while (client.connected())
        {
            if (WiFi.status() != WL_CONNECTED) 
            {
                wifiLed.off();
                client.stop();
                return;
            }
          
             String command = client.readStringUntil('\n');
             Serial.println(command);

            if (command=="SEND_DATA")
            {
                client.print(dataToSend);
                dataToSend = sensor.getDataPacket();
            }
            else if(command=="END_MISSION")
            {
               client.print(dataToSend);
               dataToSend = sensor.getDataPacket();
               endMission();
            }
        }

        Serial.println("Client disconnected");
        wifiLed.off();
        client.stop();
    }
}
