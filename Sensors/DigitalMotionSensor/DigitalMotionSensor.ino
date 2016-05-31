/*
Cayenne Digital Motion Sensor Example

This sketch shows how to automatically send data to a Digital Motion Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new Digital Motion Sensor widget.
2. Set the widget to 2-State Display.
3. Select Virtual Pins and a virtual channel number.
4. Set VIRTUAL_CHANNEL below to the channel number you selected.
5. Attach a Digital Motion Sensor to a digital pin on your Arduino.
   Schematic:
   [Ground] -- [Digital Motion Sensor] -- [5V]
                         |
                     Digital Pin
6. Set the motionSensorPin variable below to match the pin used to connect the motion sensor.
7. Set the authentication token below to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard it should automatically update the Digital Motion Sensor widget with data.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// Virtual Channel of the Digital Motion Sensor widget.
#define VIRTUAL_CHANNEL V1

// Digital pin the motion sensor is connected to.
const int motionSensorPin = 0;

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
	checkSensor();
}

int previousState = -1;
int currentState = -1;

void checkSensor()
{
	// Check the sensor state and send data when it changes.
	currentState = digitalRead(motionSensorPin);
	if (currentState != previousState) {
		Cayenne.virtualWrite(VIRTUAL_CHANNEL, currentState);
		previousState = currentState;
	}
}