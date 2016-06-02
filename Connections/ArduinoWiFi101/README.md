# Cayenne WiFi Shield 101 Example

This sketch connects to the Cayenne server using an Arduino WiFi Shield 101
and runs the main communication loop.

For Cayenne Dashboard widgets using digital or analog pins this sketch will automatically
send data on those pins to the Cayenne server. If the widgets use Virtual Channels, data
should be sent to those channels using virtualWrites. Examples for sending and receiving
Virtual Channel data are under the Basics folder.