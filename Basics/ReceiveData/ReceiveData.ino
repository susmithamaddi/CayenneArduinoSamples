/*
Cayenne ReceiveData Example
Adapted from Blynk's GetData Example

This example sketch shows how a value can be sent from the Cayenne Dashboard to the Arduino on a Virtual Channel.

1. Create a Generic Digital Output Actuator attached to Virtual Channel 4 in the Cayenne Dashboard.
2. Set the authentication token below.
3. Compile and upload the sketch.
*/

#define CAYENNE_PRINT Serial    // Comment this out to disable prints and save space
#include <CayenneEthernet.h>    // Change this to use a different communication device. See Communications examples.

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

// This function will be called every time a Dashboard widget writes a value to Virtual Channnel 4.
CAYENNE_IN(V4)
{
	CAYENNE_LOG("Got a value: %s", getValue.asStr());
	// You can also use:
	// int i = getValue.asInt() or
	// double d = getValue.asDouble()
}


