/*
Cayenne Generic Analog Input Example

This sketch shows how to automatically send data to a Generic Analog Input Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new Generic Analog Input widget.
2. Set the widget to Value Display.
3. Select the Integrated ADC and a channel number.
4. Attach an analog input device (e.g. a potentiometer) to the analog pin on your Arduino matching the selected channel.
   Make sure to use an analog pin, not a digital pin.
5. Set the authentication token below to match the Arduino token from the Dashboard.
6. Compile and upload this sketch.
7. Once the Arduino connects to the Dashboard it should automatically update the Generic Analog Input widget with data.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
}
