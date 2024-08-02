#include "led.h"

Led::Led(digitalPin pinToAttach)
{
  pin = pinToAttach;
  pinMode(pinToAttach,OUTPUT);
}

void Led::initialise()
{
  pinMode(pin,OUTPUT);
}

void Led::on()
{
  status = true;
}

void Led::off()
{
  status = false;
}

void Led::action()
{
  if(status)
  {
    digitalWrite(pin,HIGH);
  }
  else
  {
    digitalWrite(pin,LOW);
  }
}

void Led::blinkSpecial(unsigned int onTime, unsigned int delayBetweenWave, unsigned int waveCount, unsigned int delayBetweenSignal)
{
  for(unsigned int i=0; i<waveCount; i++)
  {
    digitalWrite(pin,HIGH);
    delay(onTime);
    digitalWrite(pin,LOW);
    delay(delayBetweenWave);
  }
  delay(delayBetweenSignal);
}