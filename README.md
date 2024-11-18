# hackathon2024



### Hardware

|manufacturer       |name                            |price per unit (EUR)|quantity |
|:---               |:---                            |---:                |---:     |    
|makerfabs          |ESP32 UWB DW3000                | 43,44              | x4      |
|UltraLeap          |Leap Motion Controller (2nd Gen)| -                  | -       |
|BTF-Lighting       |WS2812B LED-strips (60/m)       | -                  | -       |
|Hornaxy            |MPU6500 (6DOF)                  | 1,32               |         |
|                   |                                |                    |         |
|+ shipping 30,39€  |                                | sum:               | 205,41€ |


### Approach


### Local Positioning
All ESP-32s are connected to a DW3000 UWB chip.
The ones controlling our LEDs will be used as anchors, another one will be mounted with the LeapMotion and act as a Tag.

The distance between each anchor and the tag can be measured. With those three distances, the position of the tag can be calculated, relative to the anchors.
In order to determine the direction of a user's gestures, we need to calculate their orientation.
Since the LeapMotion does not have an inbuilt gyroscope, a MPU6500 6-axis sensor is connected to the user's tag.

