# Cayenne Generic Digital Input Example

This sketch shows how to automatically send data to a Generic Digital Input Sensor in the Cayenne Dashboard.

###### Steps:
1. In the Cayenne Dashboard add a new Generic Digital Input widget.
2. Set the widget to 2-State Display.
3. Select the Integrated GPIO and a pin number.
4. Attach a digital input device (e.g. a button) to the GPIO pin on your Arduino matching the selected pin.
5. Set the token variable to match the Arduino token from the Dashboard.
6. Compile and upload this sketch.
7. Once the Arduino connects to the Dashboard it should automatically update the Generic Digital Input widget with data.