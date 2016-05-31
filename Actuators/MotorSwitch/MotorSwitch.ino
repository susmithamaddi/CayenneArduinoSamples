/*
Cayenne Motor Switch Actuator Example

This sketch shows how to set up a Motor Switch with Cayenne. The Arduino cannot
drive a motor because it does not output the needed current. As a result, in order
to make this example work, various electronic components are necessary to drive
the DC motor. To keep it simple, you will need an external power source, transistor (eg. PN2222),
diode (eg. 1N4001), and a 270 ohm resistor.

Steps:
1. In the Cayenne Dashboard add a Button using Custom Widget.
2. Select a virtual channel number.
3. Set VIRTUAL_CHANNEL below to the channel number you selected.
4. Set up your motor schematic and attach it to a PWM pin.
5. Set motorPin below to the PWM pin number you selected.
6. Set the authentication token below to match the Arduino token from the Dashboard.
7. Compile and upload this sketch.
8. Once the Arduino connects to the Dashboard you can toggle the Motor switch.

We use the virtual channel to receive data from the dashboard to enable and disable the motor.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Virtual Channel of the widget.
#define VIRTUAL_CHANNEL V1

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// motor pin
int motorPin = 4;

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

//Enable or disable the motor based on value received on virtual channel.
CAYENNE_IN(VIRTUAL_CHANNEL)
{
  int speed = 155;
  // read the integer value which should be 0 or 1
  int enabled = getValue.asInt();
  if (enabled == 1) {
    // turns on the motor at the specified speed
    analogWrite(motorPin, speed);
  } else {
    // turn motor off
    analogWrite(motorPin, 0);
  }
}

void loop()
{
	Cayenne.run();
}
