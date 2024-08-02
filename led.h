#ifndef SHELL_PROJECT_LED_H
#define SHELL_PROJECT_LED_H

typedef unsigned short int digitalPin;
#include <Arduino.h> 

class Led
{
  public:
  bool status = false;
  digitalPin pin;
  Led(digitalPin pinToAttach);
  void action();
  void on();
  void off();
  void blinkSpecial(unsigned int onTime, unsigned int delayBetweenWave, unsigned int waveCount, unsigned int delayBetweenSignal);
  void initialise();
};



#endif