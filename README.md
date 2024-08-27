# Overview
The Shell Project is a system that provides WiFi connectivity and atmospheric data logging using the ESP32 microcontroller, an MPL3115A2 barometric sensor, and a series of LEDs for status indication. It allows for remote commands to be received and processed via a WiFi connection. The system can respond to commands, send sensor data, and signal mission status through visual indicators.

# Features
- WiFi Connectivity: The system connects to a specified WiFi network and listens for incoming commands from a server.
- Status Indicators: The WiFi status and operational status are indicated by LEDs with different blinking patterns.
- Barometric Sensor Integration: Atmospheric data such as altitude and pressure are gathered using the MPL3115A2 sensor.
- Command Handling: The system can process various commands, such as sending data and ending a mission.
- Mission End Signal: A specific sequence of LED blinks and buzzer sounds is used to indicate the end of the mission.

# Hardware Requirements
- ESP32 microcontroller
- MPL3115A2 barometric sensor
- 1 LED
- 1 buzzer (used in the same context as an LED for mission status)
- Connection cables and resistors as needed

# Installation and Setup
## Hardware Setup:
- Connect the MPL3115A2 sensor to the ESP32 using I2C connections.
- Attach LEDs to designated GPIO pins on the ESP32 for status indicators.
- Connect a buzzer to the specified pin if needed for mission end signals.

## Software Setup:
- Open the Arduino IDE and install necessary libraries (WiFi, Wire, Adafruit MPL3115A2).
- Load the provided code into the Arduino IDE.
- Set up the WiFi credentials by modifying the ssid and password variables in the Shell class.
- Compile and upload the code to the ESP32.

# Usage
- Power up the ESP32. The system will begin the initialization process, indicated by the status LED.
- The WiFi LED will blink, showing attempts to connect to the specified WiFi network.
- Once connected, the WiFi LED will turn solid, indicating the system is ready to listen for commands.
- Send commands to the ESP32 via a connected client to:
- "SEND_DATA": Retrieve current altitude and pressure data.
- "END_MISSION": End the mission, stop WiFi, and trigger the end mission sequence.
