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

---
### Local Positioning.
All ESP-32s are connected to a DW3000 UWB chip.
Contrary to the traditional approach using anchors and a tag, we implement a node-based positioning system, which allows us to calculate the relative positions of our "anchors" as well.
This is derived from NoopLoop's system used in their LinkTrack devices. (https://ftp.nooploop.com/downloads/linktrack/LinkTrack_Datasheet_V2.3_zh.pdf)


---
### calculating the orientation of the tag.
Basically. there are two ways to calculate the angle of a sensor, such as the MPU6500:
- gyro integration (drags past errors alog, inprecise over time)
- accelerometer trigonometry (prone to errors from vibration) </br>
-> Solution: 1-dimensional Kalman-Filter (modified version of [CarbonAeronautics 1DKalmanFilter](https://github.com/CarbonAeronautics/Part-XV-1DKalmanFilter))

---
### Wiring.
This is part of the ESP32s schematics:
![Bildschirmfoto 2024-11-18 um 15 55 07](https://github.com/user-attachments/assets/890285f7-860c-481b-9470-6e1148bf145d)

Anchors & LEDs - Required Pins:
- 5V -> 5V (GPIO1)
- GND -> GND (GPIO2)
- DATA/DIN -> GPIO16 

Tag - Required Pins:
- VCC -> 3V3
- GND -> GND
- SCL -> GPIO22
- SDA -> GPIO21

---
### 3D-printed parts:
The mount for all ESP32s and LEDs were modeled and printed to make it more visually appealing and more comfortable to work with.
The same was done for the combination of LeapMotion, ESP32 and MPU6500.
