/*
Cayenne Thermistor Example

This sketch shows how to send temperature data to a Thermistor Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new Thermistor widget.
2. Set the widget to Value Display.
3. Select Virtual Pins and a virtual channel number.
4. Set VIRTUAL_CHANNEL below to the channel number you selected.
5. Attach a thermistor to an analog pin on your Arduino. Make sure to use an analog pin, not a digital pin.
   Schematic:
   [Ground] -- [10k-resistor] -- | -- [Thermistor] -- [5V]
                                 |
                             Analog Pin
6. Set the thermistorPin variable below to match the pin used to connect the thermistor.
7. Set the authentication token below to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard it should automatically update the Thermistor widget with data.
*/

#define CAYENNE_PRINT Serial   // Comment this out to disable prints and save space
#include <CayenneTemperature.h>
#include <CayenneEthernet.h>   // Change this to use a different communication device. See Communications examples.

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// Virtual Channel of the Thermistor widget.
#define VIRTUAL_CHANNEL V1

// Analog pin the thermistor is connected to.
const int thermistorPin = 0;

// Resistance of the resistor. Currently set to 10k but this can be set to the measured resistance of your
// resistor for greater accuracy.
const float resistance = 10000; 

Thermistor thermistor(thermistorPin, resistance);

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
}

// This function is called when the Cayenne widget requests data for the Virtual Channel.
CAYENNE_OUT(VIRTUAL_CHANNEL)
{
	// This command writes the temperature in Celsius to the Virtual Channel.
	Cayenne.celsiusWrite(VIRTUAL_CHANNEL, thermistor.getCelsius());
	// To send the temperature in Fahrenheit or Kelvin use the corresponding code below.
	//Cayenne.fahrenheitWrite(VIRTUAL_CHANNEL, thermistor.getFahrenheit());
	//Cayenne.kelvinWrite(VIRTUAL_CHANNEL, thermistor.getKelvin());
}
