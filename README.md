# hackathon2024



### Hardware

|manufacturer       |name                            |price per unit (EUR)|quantity |
|:---               |:---                            |---:                |---:     |    
|makerfabs          |ESP32 UWB DW3000 (WROVER core)  | 43,44              | x4      |
|UltraLeap          |Leap Motion Controller (2nd Gen)| -                  | x1      |
|BTF-Lighting       |WS2812B LED-strips (60LEDs/m)   | -                  | 1m      |
|Hornaxy            |MPU6500 (6DOF)                  | 1,32               | x1      |
|                   |                                |                    |         |
|+ shipping 30,39€  |                                | sum:               | 205,41€ |


### Approach


### Local Positioning
All ESP-32s are connected to a DW3000 UWB chip.
The ones controlling our LEDs will be used as anchors, another one will be mounted with the LeapMotion and act as a Tag.

The distance between each anchor and the tag can be measured. With those three distances, the position of the tag can be calculated, relative to the anchors.
In order to determine the direction of a user's gestures, we need to calculate their orientation.
Since the LeapMotion does not have an inbuilt gyroscope, a MPU6500 6-axis sensor is connected to the user's tag.


### Wiring:
This is part of the ESP32s schematics:
![Bildschirmfoto 2024-11-18 um 15 55 07](https://github.com/user-attachments/assets/890285f7-860c-481b-9470-6e1148bf145d)


