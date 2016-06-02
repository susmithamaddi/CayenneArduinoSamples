# Cayenne Generic Analog Output Example

This sketch shows how to set up a Generic Analog Output with Cayenne.

###### Steps:
1. In the Cayenne Dashboard add a new Generic Analog Output.
2. Select an ADC (Analog) pin number.
3. Attach an analog ouput device to the analog pin on your Arduino matching the selected pin.
4. Set the token variable to match the Arduino token from the Dashboard.
5. Compile and upload this sketch.

Notice that there isn't much coding involved to interact with the analog pins.
Most of it is handled automatically from the Cayenne library.