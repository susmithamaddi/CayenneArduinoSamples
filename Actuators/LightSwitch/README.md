# Cayenne Light Switch Example

This sketch shows how to set up a Light Switch with Cayenne

###### Steps:
1. In the Cayenne Dashboard add a new Light Switch Widget.
2. Select a GPIO pin number.
3. Attach the positive leg of an LED to ground and the other leg to the selected digital pin.
   Schematic:
   [Ground] -- [LED] -- [Resistor] -- [Digital Pin]
4. Set the token variable to match the Arduino token from the Dashboard.
5. Compile and upload this sketch.
6. Once the Arduino connects to the Dashboard you can toggle the LED switch.

Notice that there isn't much coding involved to interact with the digital pins.
Most of it is handled automatically from the Cayenne library.