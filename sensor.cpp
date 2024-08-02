#include <string>
#include "sensor.h"

void BaroSensor::initialise()
{
   while(!mpl3115a2.begin()) 
   {
    Serial.println("Could not find a valid MPL3115A2 sensor, check wiring!");
  }
}

   int BaroSensor::readAltitude() {
    float altitude = mpl3115a2.getAltitude();
    return (int)altitude; 
  }

  int BaroSensor::readPressure() {
    float pressure = mpl3115a2.getPressure();
    return (int)pressure;
  }

  void BaroSensor::calculateAltitudeOffset()
  {
    int sum = 0;
    for(int i=0; i<offsetCalcSampleSize; i++)
    {
      sum += readAltitude();
      delay(100);
    }
    altitudeOffset = sum / offsetCalcSampleSize;
  }

  String BaroSensor::parseData(int altitude, int pressure)
  {
    String str1 = String(altitude);
    String str2 = String(pressure);
    String result = str1+","+str2;
    Serial.println(result);
    return result;
  }

  String BaroSensor::getDataPacket()
  {
    int alt = readAltitude()-altitudeOffset;
    int pressure = readPressure();
    Serial.println(alt);
    Serial.println(pressure);
    String parsedData = parseData(alt,pressure);

    return parsedData;
  }
