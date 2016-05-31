/*
Cayenne SendDataOnRequest Example
Adapted from Blynk's PushDataOnRequest Example

This example sketch shows how a value can be sent from Arduino to the Cayenne Dashboard in 
response to a Virtual Channel request.

1. Create a Generic Analog Input widget attached to Virtual Channel 5 in the Cayenne Dashboard.
2. Set the authentication token below.
3. Compile and upload the sketch.
*/

#define CAYENNE_PRINT Serial
#include <CayenneEthernet.h>   // Change this to use a different communication device. See Communications examples.

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// Use Virtual Channel 5 for uptime display.
#define VIRTUAL_CHANNEL V5

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
}

// This function is called when a Cayenne widget requests data for Virtual Channel 5.
CAYENNE_OUT(VIRTUAL_CHANNEL)
{
	CAYENNE_LOG("Data requested for Virtual Channel %d", VIRTUAL_CHANNEL);
	// This command writes Arduino's uptime in seconds to the Virtual Channel.
	Cayenne.virtualWrite(VIRTUAL_CHANNEL, millis() / 1000);
}
