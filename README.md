# Esparagus Echo

![Open Source Hardware](/images/open-source-hardware-logo.png)
![Open Source Software](/images/open-source-software-logo.png)

<<a href="https://www.tindie.com/stores/sonocotta/?ref=offsite_badges&utm_source=sellers_andrey-malyshenko&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>
<br />>

[![Dev Chat](https://img.shields.io/discord/1233306441469657140?logo=discord&label=discord&style=flat-square)](https://discord.gg/PtnaAaQMpS)

{large image}

Esparagus Echo is a series of two ESP32-S3-based voice control edge devices. They designed to work with [ESPHome](https://esphome.io) as an edge part of voice control pipeline. Both devices are enclosed in a neat-looking aluminum case and expose feedback LEDs on the front panel where is it easy to spot them, leaving power and speaker connectors on the back side. 


## Table of Contents



## Why Esparagus

Then Esparagus Echo design shares a lot with earlier [Esparagus](https://github.com/sonocotta/esparagus-media-center) series of devices, using similar parts and same pinout wherver possible. I see this as a side branch of the series therefore.

## Motivation

I'm a bif fan of Alexa. I'm using it around house, my family using it all the time, including 2-years old. However, I do not need to mention privacy conserns, these are quite common. My biggest painpoint is actualy inability to integrate Alexa into the Home Assistant setup that I have at home. I'm a big fan of automations around the house and want to trigger complex flows based on the specific sensors and devices that I have. I think the freedom of the implementation is a bit like a magic of the Home Assistant. Why not to have the voice control, since everyone around the house are used to it already.

## Esparagus Solo

Esparagus Solo has all the basic necessities, Mic on the front panel, couple of feedback LEDs and a speaker at the back. Onboard is a simple and well-known MAX98357 DAC with a reasonable 5W of output audio. It uses built-in antenna for simplicity. And that's pretty much it.

{image} 

## Esparagus Duo

On top of Solo capabilities Esparagus Duo uses dual Mic setup, extra LED, and most importantly 2-channels MAX98357 channels to deliver quality stereo-audio (and thus can be used as media player device). To make sue it would stream audio without a hiccup is uses external Wifi antenna (much improved perception) and has SPI Ethernet for the most robust networking. 

{image} 


## Features

|  | Esparagus Solo | Esparagus Duo |
|---|---|---|
| Image | {image} | {image} |
| MCU | ESP32-S3-WROOM-1-N16R8 module | ESP32-S3-WROOM-1U-N16R8 module |
| MIC | Single [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic | Dual [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic |
| DAC | Single I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built in D-Class amp | Dual I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built in D-Class amp |
| Power | 5V from USB-C (Up to 1.5A) | 5V from USB-C (Up to 2.5A) |
| Output, 4Ω | 3W | 2x 3W |
| Output, 8Ω | 5W | 2x 5W |
| PSRAM | 8MB PSRAM | 8MB PSRAM |
| Peripheral | 2x XL1615 RGB LED | 3x XL1615 RGB LED |
| Wireless Connectivity | WiFi + BLE | WiFi + BLE |
| Ethernet | none | Wizznet W5500 SPI Ethernet |
| Size (excl. antenna) | 45 x 18 x 52mm | 70 x 24 x 88 mm |

## Boards Pinout

### Peripheral - Common

|       | I2S CLK | I2S DOUT | I2S DIN | I2S WS | DAC CE | RGB LED
|-------|---------|----------|--------|----------|-----------|-----------|
| Echo Solo | 14      | 16       | 21     | 15       | 17        |  36
| Echo Duo | 14     | 16       | 21     | 15       | 17        | 36


### Peripheral - W5500 Ethernet

|          | SPI CLK  |SPI MOSI| SPI MISO | LAN RES   | LAN CS    | LAN INT   | 
|----------|----------|--------|----------|-----------|-----------|-----------|
| Echo Duo |  12      |  11    |   13     |  5        |  10       |  6        |

## Software

Since both devices are designed to be primaraly used within Home Assiatnt setup, the [software](/firmware) folder contains ESPHome configurations for both devices.
- `media-player` is a simple external speaker based on the Arduino framework
- `voice-assistans` is a work in progress confugration based on esp-adf pipeline and wakeword detection. 

### Configuring Home Assistant

I will update this section as soon as I get the VA part working.

## Hardware

| Esparagus Solo  | Esparagus Duo  | 
|---|
| | 

Please visit [hardware](/hardware/) section for board schematics and PCB designs. Note that PCBs are shared as multi-layer PDFs as well as Gerber archives.

### Boxed

| Esparagus Solo  | Esparagus Duo  | 
|---|
| | 

### PCB

| Esparagus Solo  | Esparagus Duo  | 
|---|
| | 

## Where to buy

You may support our work by ordering this product at Tindie (soming soon)