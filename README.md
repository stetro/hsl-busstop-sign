# hsl-busstop-sign
[![Build Status](https://travis-ci.com/stetro/hsl-busstop-sign.svg?branch=master)](https://travis-ci.com/stetro/hsl-busstop-sign)
HSL (Helsingin Seudun Liikenne) busstop sign based on NodeMCU

  - Queries data from HSL with GraphQL
  - Gets current timestamp via NTP
  - Display current waiting time on Serial and I2C LiquidCrystal Display (20x4)

```
[WIFI] connecting to wifi ...
[WIFI] not connected to wifi, retry ...
[WIFI] not connected to wifi, retry ...
[WIFI] connected

[HTTP] start query ...
[HTTP] query result code: 200

[JSON] parsing response ...
[JSON] success

[NTP] query current time ...
[NTP] timestamp 1544374441

[HSL] Station:    Erik Spåren tie
[HSL] 506 Meilahti vi 03m
[HSL]  78 Rautatiento 05m
[HSL]  79 Herttoniemi 11m
[HSL]  57 Munkkiniemi 16m
```

![](hsl-busstop-sign.png)

## Usage

This is implemented as an PlatformIO project and comes with all needed configuration in `platformio.ini`.
Change the `WIFI_SSID` and `WIFI_PASSWORD` and check if the `HSL_FINGERPRINT` is still up to date.

### Partlist

For the basic usage only the NodeMcu and LCD display is needed.

* NodeMcu 2
* LCD Display 20x4 with I2C Adapter
* [Tactile Push Button]
* [10k Resistor]
* [Lithium Ion Battery 3.7]
* [5V stepup board with charging circuit]

