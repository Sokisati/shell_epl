#ifndef SHELL_EPL_SHELL_H
#define SHELL_EPL_SHELL_H

#include "WiFi.h"
#include "led.h"
#include "sensor.h"

class Shell
{
  public:
  const char *ssid = "Pip-boy 3000";
  const char *password = "135069hotspot";
  const char *hostname = "wheatley";
  Led wifiLed;
  Led buzzer; //I know it's not an LED okay?

  WiFiServer server;
  BaroSensor sensor;

  String dataToSend;

  void initialise();
  Shell(digitalPin wifiLedPin,digitalPin buzzerPin);
  void listenAndSpeak();
  int artificialAlt(int index);
  void endMission();
  String missionEndLine = "This is the part where I say goodbye. Goodbye, then!";

};


#endif