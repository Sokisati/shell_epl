#ifndef SHELL_EPL_SENSOR_H
#define SHELL_EPL_SENSOR_H

#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

class BaroSensor 
{
private:
  Adafruit_MPL3115A2 mpl3115a2;

public:
  int altitudeOffset = 0;
  int offsetCalcSampleSize = 5;

  void initialise();
  int readAltitude();
  int readPressure();
  void calculateAltitudeOffset();
  
  String parseData(int altitude, int pressure);
  String getDataPacket();
};


#endif