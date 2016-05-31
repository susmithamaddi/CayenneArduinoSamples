/*
Cayenne VCNL4000 Example

This sketch shows how to send luminosity data to a VCNL4000 Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new VCNL4000 widget.
2. Set the widget to Value Display.
3. Select Virtual Pins and select virtual channels for the distance and luminosity.
4. Set DISTANCE_CHANNEL below to the channel number you selected for the distance.
5. Set LUMINOSITY_CHANNEL below to the channel number you selected for the luminosity.
6. Attach a VCNL4000 to your Arduino.
   Schematic:
   VCNL4000    Arduino
   [VDD] ------- [3V3]
   [IR Anode] -- [5V]
   [GND] ------- [GND]
   [SDA] ------- [Analog Pin 4] (The SDA may be different on some devices, e.g. for Arduino Mega the SDA pin is Digital Pin 20)
   [SCL] ------- [Analog Pin 5] (The SCL may be different on some devices, e.g. for Arduino Mega the SCL pin is Digital Pin 21)
7. Set the authentication token below to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard it should automatically update the VCNL4000 widget with data.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneVCNL4000.h>
#include <CayenneEthernet.h>

// Virtual Channels of the VCNL4000 widget.
#define DISTANCE_CHANNEL V1
#define LUMINOSITY_CHANNEL V2

VCNL4000 proximitySensor;

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
	if (!proximitySensor.begin())
	{
		CAYENNE_LOG("No sensor detected");
		while (1);
	}
}

void loop()
{
	Cayenne.run();
}

// This function is called when the Cayenne widget requests data for the distance Virtual Channel.
CAYENNE_OUT(DISTANCE_CHANNEL)
{
	//The getMillimeters() function only provides a rough estimate of distance. If greater accuracy is desired
	//settings can be tweaked in CayenneVCNL400.h.
	int distance = proximitySensor.getMillimeters();
	if (distance != NO_PROXIMITY) {
		Cayenne.virtualWrite(DISTANCE_CHANNEL, distance, MILLIMETERS, DISTANCE);
	}
}

// This function is called when the Cayenne widget requests data for the luminosity Virtual Channel.
CAYENNE_OUT(LUMINOSITY_CHANNEL)
{
	Cayenne.luxWrite(LUMINOSITY_CHANNEL, proximitySensor.getLux());
}