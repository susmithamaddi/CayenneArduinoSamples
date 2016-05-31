/*
Cayenne Generic Digital Input Example

This sketch shows how to automatically send data to a Generic Digital Input Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new Generic Digital Input widget.
2. Set the widget to 2-State Display.
3. Select the Integrated GPIO and a channel number.
4. Attach a digital input device (e.g. a button) to the GPIO pin on your Arduino matching the selected channel.
5. Set the authentication token below to match the Arduino token from the Dashboard.
6. Compile and upload this sketch.
7. Once the Arduino connects to the Dashboard it should automatically update the Generic Digital Input widget with data.
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
