# Cayenne Digital Motion Sensor Example

This sketch shows how to automatically send data to a Digital Motion Sensor in the Cayenne Dashboard.

###### Steps:
1. In the Cayenne Dashboard add a new Digital Motion Sensor widget.
2. Set the widget to 2-State Display.
3. Select Virtual Pins and a virtual channel number.
4. Set VIRTUAL_CHANNEL to the channel number you selected.
5. Attach a Digital Motion Sensor to a digital pin on your Arduino.
   * Schematic:
   ```
   [Ground] -- [Digital Motion Sensor] -- [5V]
                         |
                     Digital Pin
   ```
6. Set the motionSensorPin variable to match the pin used to connect the motion sensor.
7. Set the token variable to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard it should automatically update the Digital Motion Sensor widget with data.