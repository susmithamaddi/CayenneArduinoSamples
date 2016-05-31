# Cayenne Motor Switch Actuator Example

This sketch shows how to setup a Motor Switch with Cayenne. The Arduino cannot
drive a motor because it does not output the needed current. As a result, in order
to make this example work, various electronic components are necessary to drive
the DC motor. To keep it simple, the we will need a **transistor (PN2222)**,
**diode (1N4001)**, and a **270 ohm resistor**.

Steps:
1. In the Cayenne Dashboard add a Button using Custom Widget
2. Select a virtual pin number
3. Setup the schematic and wires.
4. Compile and upload this sketch.
5. Once the Arduino connects to the Dashboard you can toggle Motor switch

We are using the virtual pin to received data from the dashboard when to enable
or disable the motor.

## Schematic
![https://cdn-learn.adafruit.com/assets/assets/000/002/346/medium640/learn_arduino_breadboard.jpg?1396782072]()
