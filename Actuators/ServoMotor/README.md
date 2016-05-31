## Cayenne ServoMotor Example

This sketch sample file shows how to connect a ServoMotor with Cayenne Library.
For this example we are going to use a slider widget and the servo will move
depending on the slider value.

Steps:
1. In the Cayenne Dashboard add a new Custom Widget, and select Slider
2. Select a Virtual pin number
3. Set min value to 0 and max value of 1.
4. Make sure the Virtual pin match SERVO_VIRTUAL_PIN
5. Connect the Servo's legs to GND, VCC (5.0), and a Digital pin.
6. In the Arduino IDE, include the Servo Library
7. Compile and flash code on the arduino.
5. Once the Arduino connects to the Dashboard you can now make use of the slider
to change servo position

### Where to go from here?
Another use case for the servo is the use of a Button. By turning on the button,
the servo can be set to a specific position and back when it's off.
