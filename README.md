# Esparagus Echo

<a href="https://lectronz.com/stores/sonocotta" alt="I sell on Lectronz"><img src="https://lectronz-images.b-cdn.net/static/badges/i-sell-on-lectronz-medium.png" /></a><a href="https://www.tindie.com/stores/sonocotta/?ref=offsite_badges&utm_source=sellers_andrey-malyshenko&utm_medium=badges&utm_campaign=badge_medium"><img src="https://static.tindie.com/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a><a class="logo" href="https://www.elecrow.com/store/Sonocotta" title="I sell at Elecrow"><img src="https://www.elecrow.com/media/logo/stores/1/ELECROW_LOGO.png" alt="elecrow logo" height="78" style="max-width: none;"></a>

[![Dev Chat](https://img.shields.io/discord/1233306441469657140?logo=discord&label=discord&style=flat-square)](https://discord.gg/PtnaAaQMpS)

![DSC_0102](https://github.com/user-attachments/assets/84f3732c-cb69-4689-89ab-f31cbbc4554e)

Esparagus Echo is a series of two ESP32-S3-based voice control edge devices. They are designed to work with [ESPHome](https://esphome.io) as an edge part of the voice control pipeline. Both devices are enclosed in a neat-looking aluminum case and expose feedback LEDs on the front panel where it is easy to spot them, leaving power and speaker connectors on the backside. 

> **Esparagus Solo is now on revision C1**, which replaces the earlier rev B board. Besides the usual fixes, it adds battery power with charge and external-power monitoring, and a physical button on the top panel for talk-to-assistant and media control. Rev B remains documented below for the boards already in the field.


## Table of Contents

- [Esparagus Echo](#esparagus-echo)
  - [Table of Contents](#table-of-contents)
  - [Why Esparagus](#why-esparagus)
  - [Motivation](#motivation)
  - [Esparagus Solo](#esparagus-solo)
    - [What is new in rev C1](#what-is-new-in-rev-c1)
  - [Esparagus Duo](#esparagus-duo)
  - [Which device is right for me](#which-device-is-right-for-me)
  - [Features](#features)
  - [Boards Pinout](#boards-pinout)
    - [Peripheral - Common](#peripheral---common)
      - [Rev A (prototypes)](#rev-a-prototypes)
      - [Rev B (legacy)](#rev-b-legacy)
      - [Rev C1 (distribution)](#rev-c1-distribution)
    - [Peripheral - Battery and Power (Solo rev C1)](#peripheral---battery-and-power-solo-rev-c1)
    - [Peripheral - W5500 Ethernet](#peripheral---w5500-ethernet)
  - [Software](#software)
    - [Home Assistant - media player](#home-assistant---media-player)
    - [Home Assistant - voice assistant](#home-assistant---voice-assistant)
    - [Button controls (Solo rev C1)](#button-controls-solo-rev-c1)
    - [Battery and power entities (Solo rev C1)](#battery-and-power-entities-solo-rev-c1)
    - [ESPHome - initial flashing](#esphome---initial-flashing)
    - [Walkie Talkie firmware](#walkie-talkie-firmware)
  - [Hardware](#hardware)
    - [Boxed](#boxed)
    - [PCB](#pcb)
  - [Where to buy](#where-to-buy)

## Why Esparagus

The Esparagus Echo design shares a lot with the earlier [Esparagus](https://github.com/sonocotta/esparagus-media-center) series of devices, using similar parts and the same pinout whenever possible. I see this as a side branch of the series, therefore.

## Motivation

I'm a big fan of Alexa. I'm using it around the house, and my family is using it all the time, including 2 years old. However, I do not need to mention privacy concerns, these are quite common. My biggest pain point is the inability to integrate Alexa into the Home Assistant setup that I have at home. I'm a big fan of automation around the house and want to trigger complex flows based on the specific sensors and devices that I have. I think the freedom of the implementation is a bit like the magic of the Home Assistant. Why not have voice control, since everyone around the house is used to it already?

## Esparagus Solo

Esparagus Solo has all the basic necessities, a Mic on the front panel, a feedback LED, and a speaker at the back. Onboard is a simple and well-known MAX98357 DAC with a reasonable 5W output audio. From rev C1 it also runs on battery, and carries a button on the top panel so you can talk to the assistant or control playback without a phone or a voice command.

![DSC_0108](https://github.com/user-attachments/assets/b4957751-f71e-4a23-b3bd-ac48bdb77a90)

### What is new in rev C1

Rev C1 replaces rev B as the shipping Esparagus Solo. Rev B boards keep working with the configs in [firmware/esphome/echo-solo-b](/firmware/esphome/echo-solo-b), which are kept in the repository.

| Change | Rev B | Rev C1 |
|---|---|---|
| Power | 5V USB-C only | 5V USB-C or single-cell Li-ion battery |
| Battery monitoring | none | Battery voltage, charge status, external power presence |
| Front LED | 2x RGB LED on GPIO42 | 1x RGB LED on GPIO10 |
| Controls | none | Button on the top panel (GPIO0) |

> 📷 _Image placeholders: Esparagus Solo rev C1 top panel, showing the button next to the LED; and the board with the battery fitted, case open._

## Esparagus Duo

On top of Solo capabilities, Esparagus Duo uses a dual Mic setup, extra LED, and most importantly 2-channels MAX98357 channels to deliver quality stereo-audio (and thus can be used as a media player device). To make sure it would stream audio without a hiccup it uses an external Wifi antenna (much-improved perception) and has SPI Ethernet for the most robust networking. 

![DSC_0015](https://github.com/user-attachments/assets/fa25aedf-96f9-48c8-bf72-99b5bf84d71a)

## Which device is right for me

<img width="1047" height="1112" alt="Esparagus Lineup-Device Select Map (ESP32) drawio (1)" src="https://github.com/user-attachments/assets/79e9bcd5-f621-416e-8a61-c49d2770f2e1" />

## Features

|  | Esparagus Solo (rev C1) | Esparagus Duo |
|---|---|---|
| Image | ![DSC_0108](https://github.com/user-attachments/assets/b4957751-f71e-4a23-b3bd-ac48bdb77a90) <br/> 📷 _rev C1 photo pending_ | ![DSC_0015](https://github.com/user-attachments/assets/fa25aedf-96f9-48c8-bf72-99b5bf84d71a) |
| MCU | ESP32-S3-WROOM-1-N16R8 module | ESP32-S3-WROOM-1U-N16R8 module |
| MIC | Single [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic | Dual [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic |
| DAC | Single I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp | Dual I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp |
| Power | 5V from USB-C (Up to 1.5A) or single-cell Li-ion battery | 5V from USB-C (Up to 2.5A) |
| Battery monitoring | Battery voltage, charge status, external power presence | none |
| Controls | Button on the top panel | none |
| Output, 4Ω | 3W | 2x 3W |
| Output, 8Ω | 5W | 2x 5W |
| PSRAM | 8MB PSRAM | 8MB PSRAM |
| Peripheral | 1x XL1615 RGB LED | 3x XL1615 RGB LED |
| Wireless Connectivity | WiFi + BLE <br/> External antenna | WiFi + BLE <br/> External antenna |
| Ethernet | none | Wizznet W5500 SPI Ethernet |
| Size (excl. antenna) | 70 x 24 x 88 mm | 70 x 24 x 88 mm |

Rev B Solo boards differ in three places: they carry 2x XL1615 RGB LED on GPIO42, have no button, and run from USB-C only.

## Boards Pinout

### Peripheral - Common

#### Rev A (prototypes)

|           | I2S CLK | I2S DOUT | I2S DIN | I2S WS   | DAC CE    | RGB LED
|-----------|---------|----------|---------|----------|-----------|-----------|
| Echo Solo | 14      | 16       | 21      | 15       | 17        |  42
| Echo Duo  | 14      | 16       | 21      | 15       | 17        |  42

#### Rev B (legacy)

Still current for Echo Duo. Superseded by rev C1 on Echo Solo.

|           | I2S CLK (OUT) | I2S DATA (OUT) | I2S WS (OUT) | I2S CLK (IN) | I2S DATA (IN) | I2S WS (IN) | DAC CE | RGB LED |
|-----------|---------------|----------------|--------------|--------------|---------------|-------------|--------|---------|
| Echo Solo | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  42     |
| Echo Duo  | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  42     |

#### Rev C1 (distribution)

The audio pins are unchanged from rev B. The RGB LED moves off GPIO42 to free that pin, and the button, battery and power inputs are new.

|           | I2S CLK (OUT) | I2S DATA (OUT) | I2S WS (OUT) | I2S CLK (IN) | I2S DATA (IN) | I2S WS (IN) | DAC CE | RGB LED | BUTTON |
|-----------|---------------|----------------|--------------|--------------|---------------|-------------|--------|---------|--------|
| Echo Solo | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  10     |  0     |

### Peripheral - Battery and Power (Solo rev C1)

|                  | Pin | Type          | Notes                                                                      |
|------------------|-----|---------------|----------------------------------------------------------------------------|
| Battery voltage  | 4   | ADC1 input    | Behind a 1:3 resistor divider, so the firmware multiplies the reading by 3 |
| External power   | 41  | Digital input | Open drain, active low                                                     |
| Battery charging | 40  | Digital input | Open drain, active low                                                     |

Notes on the pins above:

- **The battery divider must land on GPIO1-10.** Only those pins reach ADC1 on the ESP32-S3, and ADC2 (GPIO11-20) is unusable while WiFi is on. The firmware expects the divider on GPIO4.
- **GPIO0 is a strapping pin** and carries the pullup that role requires, so the button needs no pullup of its own. Holding the button down across a reset puts the chip into download mode, which is why no firmware gesture uses a hold through reboot.

### Peripheral - W5500 Ethernet

|          | SPI CLK  |SPI MOSI| SPI MISO | LAN RES   | LAN CS    | LAN INT   | 
|----------|----------|--------|----------|-----------|-----------|-----------|
| Echo Duo |  12      |  11    |   13     |  5        |  10       |  6        |

## Software

Since both devices are designed to be primarily used within the Home Assistant setup, the [software](/firmware) folder contains ESPHome configurations for both devices. There is a folder per board revision, [echo-solo-c](/firmware/esphome/echo-solo-c) being the current Solo one, and each folder holds a config per use case:

- `sendspin` is a media player built on the Sendspin protocol, for synchronised multi-room audio with Music Assistant
- `voice-assist-sendspin` adds wake word detection and a voice pipeline on top of the Sendspin player, with ducking while the assistant talks
- `media-player` is a plain Home Assistant media player
- `snapclient` turns the device into a Snapcast client

The shared building blocks live in [packages](/firmware/esphome/packages) and are pulled in by each config, so a board revision only has to declare its own pinout. 

### Home Assistant - media player

One simple way that Esparagus Echo can be used in the Home Assistant is by using a media player device. [Yaml config](/firmware/esphome) will get you started. Below are the configuration steps that you need to do in the HA itself.

| Step | Screenshot |
|------|------------|
| **Add ESPHome Addon** <br/> <br/> Navigate to HA Settings > Addons > Add Addon <br/> Search for SSH and install it.  <br/> Enable `Show in sidebar` switch while you there | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/9d9d0a44-ba2a-491f-bff8-e1c08b8754e0)
| **Prepare Esparagus Echo for ESPHome onboarding** <br/> <br/> Use [Web Flasher](https://web.esphome.io/?dashboard_wizard) to flash stock ESPHome into device | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/8ad222e8-d992-4a75-9a93-596d67ac8cb0)
| **Onboard Esparagus Echo ESPHome device into HA** <br/> <br/> Go to the HA ESPHome page and you should be able to find a new device. You need to onboard it with the below config (feel free to change names) <br/> This will take a moment or two | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/32b0c26a-3be1-4e15-b749-1176d46ff011)
| **Validate device in the ESPHome** | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/92df6029-c777-47ce-8ff9-debec70f7e05)
| **Add ESPHome Integration** <br /> <br/> Navigate to HA Settings > Devices & services > Integrations. Click the big + ADD INTEGRATION button, look for ESPHome, and click to add it. <br/> It should discover and add ESPHome media devices based on the previous step | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/c5d3bb12-8b07-4c49-a9e9-cdf2e6cad8ba)
| **Use your media device in the HA** | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/40067959-04ad-498c-a64d-4353e3f96228)
| **Use your media device in the MA** <br/> <br/> Add Music Assistant HA MediaPlayers provider to discover new Media device | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/6d19a972-83cf-4997-868c-1af0e4175c9b)

### Home Assistant - voice assistant

Originally I had an issue configuring the voice-assistant setup on the echo, despite having good examples shared [here](https://github.com/esphome/firmware/blob/main/voice-assistant) and [here](https://github.com/HA-TB303/ultimatesensor_mini/). The reason for the examples to fail was a single I2S bus handling both audio input and output. In theory, this is a perfectly good configuration, since both DACs and both MICs work in slave mode as they should, and I even made a simple Arduino code that captures frames from MIC and sends them over to the Speakers in stereo mode, working beautifully. 

ESPHome however was not collaborating, so I decided to go with a hardware fix and use extra pins to run independent I2S buses for both MICs and DACs. Note that currently [wakeword](https://www.home-assistant.io/voice_control/install_wake_word_add_on/) does not benefit from the second MIC, but I hope support will be added in the future since Espressiff folks seem to work on that (although they may use external noise-reduction IC, I'm not sure). 

All in all, wakeword started to work flawlessly in revision B, and although it is not as fast as say, Alexa, it is truly amazing to have it working on such a small device. 

Please look at [this config](/firmware/esphome/echo-duo-b/echo-duo-b-idf-voice-assist.yaml) to make it work. Note that it will also require to configure Home Assistant properly, you may use [this official guide](https://www.home-assistant.io/voice_control/), [Seeeds docs](https://wiki.seeedstudio.com/respeaker_lite_ha/) or community created [Youtube tutorial](https://www.youtube.com/watch?v=VAFDgib95Ls)

### Button controls (Solo rev C1)

The top-panel button follows the gestures of the [Home Assistant Voice PE](https://github.com/esphome/home-assistant-voice-pe) center button, so muscle memory carries over between the two devices.

On the voice assistant configs:

| Gesture | Action |
|---------|--------|
| Single click | Stops whatever is active, in order: a ringing timer, a running pipeline, an announcement. If nothing is active, starts the voice assistant |
| Double click | Next track, and fires a `double_press` event |
| Triple click | Fires a `triple_press` event |
| Long press (1s) | Mutes or unmutes the voice assistant, and fires a `long_press` event |

On the plain media player configs, where there is no pipeline to talk to:

| Gesture | Action |
|---------|--------|
| Single click | Play or pause |
| Double click | Next track, and fires a `double_press` event |
| Triple click | Previous track, and fires a `triple_press` event |
| Long press (1s) | Stop, and fires a `long_press` event |

The double, triple and long presses are published to Home Assistant as a `Button press` event entity, so you can hang automations off them. The single click is not exposed, because it drives the device itself. A `Disable physical controls` switch turns the button off entirely, and is hidden by default.

> 📷 _Image placeholder: Home Assistant device page for Solo rev C1, showing the Button press event entity and the battery sensors._

### Battery and power entities (Solo rev C1)

Running on battery adds four entities:

| Entity | Type | Notes |
|--------|------|-------|
| `Battery Voltage` | Sensor, V | Averaged over six samples taken 5s apart |
| `Battery Level` | Sensor, % | Estimated from voltage, 3.3V empty to 4.2V full on a single Li-ion cell |
| `External Power` | Binary sensor | On when the USB-C supply is present |
| `Battery Charging` | Binary sensor | On while the charger is active |

The empty and full voltages are substitutions, so a different cell chemistry only takes a config change rather than a firmware patch.

### ESPHome - initial flashing

The ESP32-S3 has a special routine to flash initial ESPHome firmware, which was very optional on the classic ESP32. It requires a bit more work to perform the initial flashing of the ESPHome firmware. 

| Step | Image |
|------|------------|
| Open the device box and connect it to the PC for initial flashing. <br/>  It will report itself as a USB device, but it is not able to go into flashing mode on its own. <br/> While device is powered on, while keeping the FLASH button pressed, press the RESET button, and release the FLASH button. |  ![image](https://github.com/user-attachments/assets/c3258763-b290-4d73-89ed-57f2edcb158f)
| Only after that, connect to the device from the [web.esphome.io](https://web.esphome.io/) | ![image](https://github.com/user-attachments/assets/0a89316b-dba2-4f93-afa7-6752fb050ac2)
| You may press the REPARE FOR FIRST USE button as usual. | ![image](https://github.com/user-attachments/assets/02387a81-f2be-4218-8278-66c373fbacc8)
| You will be greeted with `An error occurred. Improv Wi-Fi Serial not detected` error. That's because the device is not able to RESET over USB during the first flashing. Reset it manually using RESET button | ![image](https://github.com/user-attachments/assets/f0d037ba-9c2a-4318-bb28-1fc752c83234)
| Re-connect to the device again and proceed with initial WIFI configuration | ![image](https://github.com/user-attachments/assets/8bcc6291-dece-4ec7-ae3b-695bf3444308)

### Walkie Talkie firmware

Alternative firmware that uses ESPNOW protocol (based on UDP packets) for bi-directional communication over Wifi. This is a clone of the [esp32-walkie-talkie](https://github.com/atomic14/esp32-walkie-talkie) project by atomic14. 
More details [here](/firmware/esp32-walkie-talkie/)  

## Hardware

Please visit [hardware](/hardware/) section for board schematics and PCB designs. Note that PCBs are shared as multi-layer PDFs as well as Gerber archives.

Rev A and Rev B files are published there. The Rev C1 schematic and PCB will be added once the revision is released.

### Boxed


| Esparagus Solo (Prototype) | Esparagus Solo (rev B) | Esparagus Solo (rev C1) | Esparagus Duo  | 
|---|---|---|---|
| ![image](https://github.com/user-attachments/assets/b650bccd-84e5-4a5e-81ac-86187e45e2ef) | ![image](https://github.com/user-attachments/assets/9cae5e9d-4d7e-48bd-a289-85b84be51282) | 📷 _placeholder: boxed rev C1, top panel with button_ | ![image](https://github.com/user-attachments/assets/fe4e7137-e51a-4827-b44d-3520adf3159f) 
| ![image](https://github.com/user-attachments/assets/ad078714-8822-4c29-ad7d-3a537a74fca6) | ![image](https://github.com/user-attachments/assets/de751a1a-3c80-434c-8a80-8177ae99a032) | 📷 _placeholder: boxed rev C1, back panel_ | ![image](https://github.com/user-attachments/assets/5e5fd427-333e-4336-872e-6a40ef548f83)


### PCB

| Esparagus Solo (Prototype) | Esparagus Solo (rev B) | Esparagus Solo (rev C1) | Esparagus Duo  | 
|---|---|---|---|
| ![image](https://github.com/user-attachments/assets/761b231c-c5f4-4479-b12b-1be4ae2b4831) | ![image](https://github.com/user-attachments/assets/60ff9542-6a02-4ac6-8828-350baf6fede7) | 📷 _placeholder: rev C1 PCB, battery connector and charger visible_ | ![image](https://github.com/user-attachments/assets/9561e312-61d7-4463-8947-f37b56da8db0)

## Where to buy

You may support our work by ordering this product at [Lectronz](https://lectronz.com/products/esparagus-echo) and [Tindie](https://www.tindie.com/products/sonocotta/esparagus-echo/)

