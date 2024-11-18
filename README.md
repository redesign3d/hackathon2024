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
The ones controlling our LEDs will simultaneously be used as anchors, another one will be mounted with the LeapMotion and act as a Tag.

The distance between each anchor and the tag can be measured.
With one anchor (and one distance measurement), the tag could be at any position along a circle where the radius equals the distance measured around the anchor:
<img width="885" alt="1anchor" src="https://github.com/user-attachments/assets/7a1c7280-2408-410c-b6a2-528c6e334535">
</br>

Using two anchors narrows it down to two possible positions:
<img width="885" alt="2anchors" src="https://github.com/user-attachments/assets/f44b2f5c-36ff-478b-8acd-1cf1666bcf97">
</br>

And a third anchor should allow us to calculate a relatively precise local position:
<img width="885" alt="3anchors" src="https://github.com/user-attachments/assets/9a7bac47-2a2e-409b-bba5-0856acae7ee6">
</br></br>

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
