# Esparagus Echo

![Open Source Hardware](/images/open-source-hardware-logo.png)
![Open Source Software](/images/open-source-software-logo.png)

<a href="https://www.tindie.com/stores/sonocotta/?ref=offsite_badges&utm_source=sellers_andrey-malyshenko&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>
<br />

[![Dev Chat](https://img.shields.io/discord/1233306441469657140?logo=discord&label=discord&style=flat-square)](https://discord.gg/PtnaAaQMpS)

![DSC_0030](https://github.com/user-attachments/assets/04c4431e-0fea-4343-88dc-d94e5a4eb2f3)

Esparagus Echo is a series of two ESP32-S3-based voice control edge devices. They are designed to work with [ESPHome](https://esphome.io) as an edge part of the voice control pipeline. Both devices are enclosed in a neat-looking aluminum case and expose feedback LEDs on the front panel where it is easy to spot them, leaving power and speaker connectors on the backside. 


## Table of Contents

- [Esparagus Echo](#esparagus-echo)
  - [Table of Contents](#table-of-contents)
  - [Why Esparagus](#why-esparagus)
  - [Motivation](#motivation)
  - [Esparagus Solo](#esparagus-solo)
  - [Esparagus Duo](#esparagus-duo)
  - [Features](#features)
  - [Boards Pinout](#boards-pinout)
    - [Peripheral - Common](#peripheral---common)
    - [Peripheral - W5500 Ethernet](#peripheral---w5500-ethernet)
  - [Software](#software)
    - [Home Assistant - media player](#home-assistant---media-player)
    - [Home Assistant - voice assistant](#home-assistant---voice-assistant)
  - [Hardware](#hardware)
    - [Boxed](#boxed)
    - [PCB](#pcb)
  - [Where to buy](#where-to-buy)

## Why Esparagus

The Esparagus Echo design shares a lot with the earlier [Esparagus](https://github.com/sonocotta/esparagus-media-center) series of devices, using similar parts and the same pinout whenever possible. I see this as a side branch of the series, therefore.

## Motivation

I'm a big fan of Alexa. I'm using it around the house, and my family is using it all the time, including 2 years old. However, I do not need to mention privacy concerns, these are quite common. My biggest pain point is the inability to integrate Alexa into the Home Assistant setup that I have at home. I'm a big fan of automation around the house and want to trigger complex flows based on the specific sensors and devices that I have. I think the freedom of the implementation is a bit like the magic of the Home Assistant. Why not have voice control, since everyone around the house is used to it already?

## Esparagus Solo

Esparagus Solo has all the basic necessities, a Mic on the front panel, a couple of feedback LEDs, and a speaker at the back. Onboard is a simple and well-known MAX98357 DAC with a reasonable 5W of output audio. It uses a built-in antenna for simplicity. And that's pretty much it.

![DSC_0006](https://github.com/user-attachments/assets/bd787b14-6c00-425d-862a-a078a345e4b0)

## Esparagus Duo

On top of Solo capabilities, Esparagus Duo uses a dual Mic setup, extra LED, and most importantly 2-channels MAX98357 channels to deliver quality stereo-audio (and thus can be used as a media player device). To make sure it would stream audio without a hiccup it uses an external Wifi antenna (much-improved perception) and has SPI Ethernet for the most robust networking. 

![DSC_0015](https://github.com/user-attachments/assets/fa25aedf-96f9-48c8-bf72-99b5bf84d71a)

## Features

|  | Esparagus Solo | Esparagus Duo |
|---|---|---|
| Image | {image} | {image} |
| MCU | ESP32-S3-WROOM-1-N16R8 module | ESP32-S3-WROOM-1U-N16R8 module |
| MIC | Single [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic | Dual [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic |
| DAC | Single I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp | Dual I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp |
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
| Echo Solo | 14      | 16       | 21     | 15       | 17        |  42
| Echo Duo | 14     | 16       | 21     | 15       | 17        | 42


### Peripheral - W5500 Ethernet

|          | SPI CLK  |SPI MOSI| SPI MISO | LAN RES   | LAN CS    | LAN INT   | 
|----------|----------|--------|----------|-----------|-----------|-----------|
| Echo Duo |  12      |  11    |   13     |  5        |  10       |  6        |

## Software

Since both devices are designed to be primarily used within the Home Assistant setup, the [software](/firmware) folder contains ESPHome configurations for both devices.
- `media-player` is a simple external speaker based on the Arduino framework
- `voice-assistans` is a work-in-progress configuration based on esp-adf pipeline and wake-word detection. 

### Home Assistant - media player

TODO

### Home Assistant - voice assistant

I will update this section as soon as I get the VA part working.

## Hardware

Please visit [hardware](/hardware/) section for board schematics and PCB designs. Note that PCBs are shared as multi-layer PDFs as well as Gerber archives.

### Boxed

| Esparagus Solo  | Esparagus Duo  | 
|---|---|
| ![image](https://github.com/user-attachments/assets/b650bccd-84e5-4a5e-81ac-86187e45e2ef) | ![image](https://github.com/user-attachments/assets/fe4e7137-e51a-4827-b44d-3520adf3159f) 
| ![image](https://github.com/user-attachments/assets/ad078714-8822-4c29-ad7d-3a537a74fca6) | ![image](https://github.com/user-attachments/assets/5e5fd427-333e-4336-872e-6a40ef548f83)


### PCB

| Esparagus Solo  | Esparagus Duo  | 
|---|---|
| ![image](https://github.com/user-attachments/assets/761b231c-c5f4-4479-b12b-1be4ae2b4831) | ![image](https://github.com/user-attachments/assets/9561e312-61d7-4463-8947-f37b56da8db0)

## Where to buy

You may support our work by ordering this product at Tindie (soming soon)
