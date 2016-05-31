/*
Cayenne Servo Motor Example

This sketch sample file shows how to connect a Servo Motor with Cayenne Library.
For this example we are going to use a slider widget and the servo will move
depending on the slider value.

Steps:
1. In the Cayenne Dashboard add a new Custom Widget, and select Slider.
2. Select a Virtual channel number.
3. Set min value to 0 and max value of 1.
4. Set SERVO_VIRTUAL_PIN below to the channel number you selected.
5. Connect the Servo's legs to GND, VCC (5.0), and a Digital pin.
6. Set SERVO_DIGITAL_PIN below to the pin number you selected.
7. In the Arduino IDE, include the Servo Library.
8. Set the authentication token below to match the Arduino token from the Dashboard.
9. Compile and upload this sketch.
10. Once the Arduino connects to the Dashboard you can use of the slider to change servo position.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>
#define SERVO_VIRTUAL_PIN 1
#define SERVO_DIGITAL_PIN 4

// servo util lib
#include <Servo.h>
Servo s1;

// a flag to keep track of servos last position
double lastPosition = 0;

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

void setup()
{
  Serial.begin(9600);
  Cayenne.begin(token);

  s1.attach(SERVO_DIGITAL_PIN);
}

CAYENNE_IN(SERVO_VIRTUAL_PIN)
{
  // get value sent from dashboard
  double currentValue = getValue.asDouble();
  int position = currentValue * 200;
  // actually move the servo to the specified position
  s1.write(position);

  //update last position
  lastPosition = currentValue;
}

void loop()
{
  Cayenne.run();
}
