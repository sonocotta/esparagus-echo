# Esparagus Echo

<a href="https://lectronz.com/stores/sonocotta" alt="I sell on Lectronz"><img src="https://lectronz-images.b-cdn.net/static/badges/i-sell-on-lectronz-medium.png" /></a><a href="https://www.tindie.com/stores/sonocotta/?ref=offsite_badges&utm_source=sellers_andrey-malyshenko&utm_medium=badges&utm_campaign=badge_medium"><img src="https://static.tindie.com/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a><a class="logo" href="https://www.elecrow.com/store/Sonocotta" title="I sell at Elecrow"><img src="https://www.elecrow.com/media/logo/stores/1/ELECROW_LOGO.png" alt="elecrow logo" height="78" style="max-width: none;"></a>

[![Dev Chat](https://img.shields.io/discord/1233306441469657140?logo=discord&label=discord&style=flat-square)](https://discord.gg/PtnaAaQMpS)

![DSC_0102](https://github.com/user-attachments/assets/84f3732c-cb69-4689-89ab-f31cbbc4554e)

Esparagus Echo is a series of ESP32-S3-based voice control edge devices. They are designed to work with [ESPHome](https://esphome.io) as an edge part of the voice control pipeline. The boxed devices are enclosed in a neat-looking aluminum case and expose feedback LEDs on the front panel where it is easy to spot them, leaving power and speaker connectors on the backside. Solo C1 goes the other way and ships as a bare board that replaces the electronics inside an IKEA speaker.

> **New: Esparagus Solo C1 is a drop-in replacement PCB for the IKEA KALLSUP Bluetooth speaker.** Swap the original board for it and the speaker keeps its battery, driver, LED and buttons, but gains announcements, multi-room music and a voice assistant through Home Assistant. See [Esparagus Solo C1](#esparagus-solo-c1-ikea-kallsup-retrofit).
>
> The boxed Esparagus Solo (rev B) remains available and fully supported, and is documented below. It will be sunset eventually, but not yet.


## Table of Contents

- [Esparagus Echo](#esparagus-echo)
  - [Table of Contents](#table-of-contents)
  - [Why Esparagus](#why-esparagus)
  - [Motivation](#motivation)
  - [Esparagus Solo](#esparagus-solo)
  - [Esparagus Solo C1 (IKEA KALLSUP retrofit)](#esparagus-solo-c1-ikea-kallsup-retrofit)
  - [Esparagus Duo](#esparagus-duo)
  - [Which device is right for me](#which-device-is-right-for-me)
  - [Features](#features)
  - [Boards Pinout](#boards-pinout)
    - [Peripheral - Common](#peripheral---common)
      - [Rev A (prototypes)](#rev-a-prototypes)
      - [Rev B (distribution)](#rev-b-distribution)
      - [Rev C1 (KALLSUP retrofit)](#rev-c1-kallsup-retrofit)
    - [Peripheral - Battery and Power (Solo C1)](#peripheral---battery-and-power-solo-c1)
    - [Peripheral - W5500 Ethernet](#peripheral---w5500-ethernet)
  - [Software](#software)
    - [Home Assistant - media player](#home-assistant---media-player)
    - [Home Assistant - voice assistant](#home-assistant---voice-assistant)
    - [Button controls (Solo C1)](#button-controls-solo-c1)
    - [Battery and power entities (Solo C1)](#battery-and-power-entities-solo-c1)
    - [ESPHome - initial flashing](#esphome---initial-flashing)
    - [Walkie Talkie firmware](#walkie-talkie-firmware)
  - [Hardware](#hardware)
    - [Boxed](#boxed)
    - [PCB](#pcb)
  - [Where to buy](#where-to-buy)

## Why Esparagus

The Esparagus Echo design shares a lot with the earlier [Esparagus](https://github.com/sonocotta/esparagus-media-center) series of devices, using similar parts and the same pinout whenever possible. I see it as a side branch of the series.

## Motivation

I'm a big fan of Alexa. I'm using it around the house, and my family uses it all the time, down to our two-year-old. I hardly need to mention the privacy concerns, as they are common enough. My biggest pain point is the inability to integrate Alexa into the Home Assistant setup that I have at home. I'm a big fan of automation around the house and want to trigger complex flows based on the specific sensors and devices that I have. I think the freedom of implementation is a bit like the magic of Home Assistant. Why not have voice control, since everyone around the house is used to it already?

## Esparagus Solo

Esparagus Solo has all the basic necessities: a mic on the front panel, a couple of feedback LEDs, and a speaker at the back. Onboard is a simple and well-known MAX98357 DAC, good for a reasonable 5W of audio output. That's pretty much it.

![DSC_0108](https://github.com/user-attachments/assets/b4957751-f71e-4a23-b3bd-ac48bdb77a90)

This is the boxed product, currently on rev B, and its configs live in [firmware/esphome/echo-solo-b](/firmware/esphome/echo-solo-b).

## Esparagus Solo C1 (IKEA KALLSUP retrofit)

Solo C1 is the same idea in a different shape: instead of a boxed device of its own, it is a **drop-in replacement PCB for the IKEA KALLSUP Bluetooth speaker**. Take the KALLSUP apart, lift out the original board, drop this one in, and the speaker becomes a Home Assistant device with announcements, multi-room music and a voice assistant, while staying the speaker it was.

The board is laid out to reuse what is already in the enclosure, so the retrofit needs no rewiring and no glue:

| Part of the speaker | How Solo C1 uses it |
| --- | --- |
| Battery and its connector | Same connector and polarity. The board charges the cell and reports voltage, charge state and whether external power is present |
| Speaker driver and its connector | Same connector, driven by the onboard MAX98357 DAC |
| RGB LED | Sits in the original position on the PCB, so it lines up with the enclosure's light pipe |
| Buttons | Both original buttons are kept. One powers the speaker on and off, the other is yours to define in YAML |
| USB-C port | Charging and power, as before |

What you gain over the stock speaker:

- **Voice assistant** with on-device wake word detection, through the Home Assistant voice pipeline
- **Announcements**, so automations can speak through the speaker
- **Multi-room music** via Music Assistant, synchronised with other Esparagus devices
- **A scriptable button**, exposed to Home Assistant as an event entity

<img width="896" height="1131" alt="KALLSUP taken apart, with the Solo C1 board wired to the battery and speaker next to the open enclosure" src="https://github.com/user-attachments/assets/6af69138-d9c3-4e25-948d-b9f76ea38b7d" />

_The KALLSUP opens up into the enclosure, the speaker driver and the base plate. The board sits where the original one did, on the same battery and speaker leads._

<img width="775" height="1096" alt="The original KALLSUP board above the Solo C1 board, same orientation, showing the matching speaker and battery connectors" src="https://github.com/user-attachments/assets/04475e03-4caa-414b-b444-3f109d0aa890" />

_The original board (top) and Solo C1 (bottom). The SPK and LIPO connectors sit in the same places, which is what makes this a drop-in swap._

<img width="885" height="1145" alt="Underside of both boards, Solo C1 silkscreened Esparagus Echo Solo Rev C with PWR and IO0 buttons" src="https://github.com/user-attachments/assets/abf2561a-4ff7-470d-bd26-3b05e7e9c77e" />

_Both boards from the button side. The two tactile switches on Solo C1 line up with the lid, and are silkscreened `PWR` and `IO0`._

## Esparagus Duo

On top of the Solo capabilities, Esparagus Duo uses a dual-mic setup, an extra LED, and, most importantly, a two-channel MAX98357 DAC to deliver quality stereo audio, which also makes it usable as a media player. To make sure it streams without a hiccup, it uses an external Wi-Fi antenna for much improved reception, and has SPI Ethernet for the most robust networking.

![DSC_0015](https://github.com/user-attachments/assets/fa25aedf-96f9-48c8-bf72-99b5bf84d71a)

## Which device is right for me

<img width="1047" height="1112" alt="Esparagus Lineup-Device Select Map (ESP32) drawio (1)" src="https://github.com/user-attachments/assets/79e9bcd5-f621-416e-8a61-c49d2770f2e1" />

## Features

|  | Esparagus Solo (rev B) | Esparagus Solo C1 | Esparagus Duo |
|---|---|---|---|
| Form factor | Boxed device | Replacement PCB for IKEA KALLSUP | Boxed device |
| Image | ![DSC_0108](https://github.com/user-attachments/assets/b4957751-f71e-4a23-b3bd-ac48bdb77a90) | <img width="800" height="764" alt="Solo C1 board, top side, with SPK and LIPO connectors, USB-C and the ESP32-S3 module" src="https://github.com/user-attachments/assets/2ec257a8-15cc-4c06-bfc9-f786eb56bad3" /> | ![DSC_0015](https://github.com/user-attachments/assets/fa25aedf-96f9-48c8-bf72-99b5bf84d71a) |
| MCU | ESP32-S3-WROOM-1-N16R8 module | ESP32-S3-WROOM-1-N16R8 module | ESP32-S3-WROOM-1U-N16R8 module |
| MIC | Single [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic | Single [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic | Dual [TDK InvenSense ICS-43434](https://invensense.tdk.com/products/ics-43434/) I2S MEMS Mic |
| DAC | Single I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp | Single I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp | Dual I2S DAC ([MAX98357](https://www.analog.com/en/products/max98357a.html)) with built-in D-Class amp |
| Power | 5V from USB-C (Up to 1.5A) | 5V from USB-C, or the KALLSUP battery | 5V from USB-C (Up to 2.5A) |
| Battery monitoring | none | Battery voltage, charge status, external power presence | none |
| Controls | none | Power button and a scriptable action button | none |
| Speaker | Onboard, at the back | The KALLSUP driver, original connector | Onboard, at the back |
| Output, 4Ω | 3W | 3W | 2x 3W |
| Output, 8Ω | 5W | 5W | 2x 5W |
| PSRAM | 8MB PSRAM | 8MB PSRAM | 8MB PSRAM |
| Peripheral | 2x XL1615 RGB LED | 1x RGB LED, in the original KALLSUP position | 3x XL1615 RGB LED |
| Wireless Connectivity | Wi-Fi + BLE <br/> External antenna | Wi-Fi + BLE <br/> PCB antenna | Wi-Fi + BLE <br/> External antenna |
| Ethernet | none | none | WIZnet W5500 SPI Ethernet |
| Size (excl. antenna) | 70 x 24 x 88 mm | Fits the KALLSUP enclosure | 70 x 24 x 88 mm |

## Boards Pinout

### Peripheral - Common

#### Rev A (prototypes)

|           | I2S CLK | I2S DOUT | I2S DIN | I2S WS   | DAC CE    | RGB LED
|-----------|---------|----------|---------|----------|-----------|-----------|
| Echo Solo | 14      | 16       | 21      | 15       | 17        |  42
| Echo Duo  | 14      | 16       | 21      | 15       | 17        |  42

#### Rev B (distribution)

Current for both boxed devices, Echo Solo and Echo Duo.

|           | I2S CLK (OUT) | I2S DATA (OUT) | I2S WS (OUT) | I2S CLK (IN) | I2S DATA (IN) | I2S WS (IN) | DAC CE | RGB LED |
|-----------|---------------|----------------|--------------|--------------|---------------|-------------|--------|---------|
| Echo Solo | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  42     |
| Echo Duo  | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  42     |

#### Rev C1 (KALLSUP retrofit)

The audio pins are unchanged from rev B. The RGB LED moves to GPIO10 because it has to sit where the KALLSUP light pipe expects it, and the action button, battery sense and power sense inputs are new.

|              | I2S CLK (OUT) | I2S DATA (OUT) | I2S WS (OUT) | I2S CLK (IN) | I2S DATA (IN) | I2S WS (IN) | DAC CE | RGB LED | ACTION BTN |
|--------------|---------------|----------------|--------------|--------------|---------------|-------------|--------|---------|------------|
| Echo Solo C1 | 18            | 17             | 8            | 16           | 15            | 7           |  9     |  10     |  0         |

### Peripheral - Battery and Power (Solo C1)

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

Since these devices are designed to be used primarily within a Home Assistant setup, the [software](/firmware) folder contains ESPHome configurations for all of them. There is a folder per board: [echo-solo-b](/firmware/esphome/echo-solo-b) for the boxed Solo, [echo-solo-c](/firmware/esphome/echo-solo-c) for the KALLSUP retrofit, and [echo-duo-b](/firmware/esphome/echo-duo-b) for the Duo. Each folder holds a config per use case:

- `sendspin` is a media player built on the Sendspin protocol, for synchronised multi-room audio with Music Assistant
- `voice-assist-sendspin` adds wake word detection and a voice pipeline on top of the Sendspin player, with ducking while the assistant talks
- `media-player` is a plain Home Assistant media player
- `snapclient` turns the device into a Snapcast client

The shared building blocks live in [packages](/firmware/esphome/packages) and are pulled in by each config, so a board only has to declare its own pinout.

### Home Assistant - media player

The simplest way to use Esparagus Echo with Home Assistant is as a media player device. The [YAML configs](/firmware/esphome) will get you started. Below are the configuration steps you need to carry out in HA itself.

| Step | Screenshot |
|------|------------|
| **Add ESPHome Addon** <br/> <br/> Navigate to HA Settings > Addons > Add Addon <br/> Search for ESPHome and install it. <br/> Enable the `Show in sidebar` switch while you are there | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/9d9d0a44-ba2a-491f-bff8-e1c08b8754e0)
| **Prepare Esparagus Echo for ESPHome onboarding** <br/> <br/> Use [Web Flasher](https://web.esphome.io/?dashboard_wizard) to flash stock ESPHome into device | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/8ad222e8-d992-4a75-9a93-596d67ac8cb0)
| **Onboard Esparagus Echo ESPHome device into HA** <br/> <br/> Go to the HA ESPHome page and you should be able to find a new device. You need to onboard it with the below config (feel free to change names) <br/> This will take a moment or two | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/32b0c26a-3be1-4e15-b749-1176d46ff011)
| **Validate device in the ESPHome** | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/92df6029-c777-47ce-8ff9-debec70f7e05)
| **Add ESPHome Integration** <br /> <br/> Navigate to HA Settings > Devices & services > Integrations. Click the big + ADD INTEGRATION button, look for ESPHome, and click to add it. <br/> It should discover and add ESPHome media devices based on the previous step | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/c5d3bb12-8b07-4c49-a9e9-cdf2e6cad8ba)
| **Use your media device in the HA** | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/40067959-04ad-498c-a64d-4353e3f96228)
| **Use your media device in the MA** <br/> <br/> Add Music Assistant HA MediaPlayers provider to discover new Media device | ![image](https://github.com/sonocotta/esparagus-media-center/assets/5459747/6d19a972-83cf-4997-868c-1af0e4175c9b)

### Home Assistant - voice assistant

Originally I had trouble configuring the voice assistant setup on the Echo, despite the good examples shared [here](https://github.com/esphome/firmware/blob/main/voice-assistant) and [here](https://github.com/HA-TB303/ultimatesensor_mini/). The examples failed because a single I2S bus was handling both audio input and output. In theory that is a perfectly good configuration, since both DACs and both mics work in slave mode as they should, and I even wrote simple Arduino code that captures frames from the mic and sends them over to the speakers in stereo, which worked beautifully.

ESPHome, however, was not cooperating, so I went with a hardware fix and used extra pins to run independent I2S buses for the mics and the DACs. Note that [wake word detection](https://www.home-assistant.io/voice_control/install_wake_word_add_on/) currently does not benefit from the second mic, but I hope support will be added in the future, since the Espressif folks seem to be working on it (although they may use an external noise-reduction IC, I'm not sure).

All in all, wake word detection started to work flawlessly in revision B, and although it is not as fast as, say, Alexa, it is truly amazing to have it working on such a small device.

Please look at [this config](/firmware/esphome/echo-duo-b/echo-duo-b-idf-voice-assist.yaml) to make it work. Note that it also requires configuring Home Assistant properly; you may use [the official guide](https://www.home-assistant.io/voice_control/), [Seeed's docs](https://wiki.seeedstudio.com/respeaker_lite_ha/) or a community-created [YouTube tutorial](https://www.youtube.com/watch?v=VAFDgib95Ls).

### Button controls (Solo C1)

The KALLSUP keeps both of its buttons, with one role each:

| Button | On the board | On the KALLSUP lid | Role |
| --- | --- | --- | --- |
| Power | `PWR` | ⏻ | Switches the speaker on and off, as it did before the retrofit |
| Action | `IO0` | Bluetooth icon | Whatever you define in YAML. Wired to GPIO0 and handled by ESPHome |

The action button ships with the gestures of the [Home Assistant Voice PE](https://github.com/esphome/home-assistant-voice-pe) center button, so muscle memory carries over between the two devices. Replacing them means editing one package, [voice-assist-addon-button.yaml](/firmware/esphome/packages/voice-assist-addon-button.yaml) or [sendspin-addon-button.yaml](/firmware/esphome/packages/sendspin-addon-button.yaml), where each gesture is a plain ESPHome `on_multi_click` entry.

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

There are two ways to put the action button to work. The first keeps the firmware untouched: listen for the `Button press` event in a Home Assistant automation and do anything HA can do.

```yaml
automation:
  - trigger:
      - platform: state
        entity_id: event.esparagus_echo_solo_button_press
        attribute: event_type
        to: double_press
    action:
      - action: light.toggle
        target:
          entity_id: light.kitchen
```

The second runs on the device itself, which keeps working when Home Assistant is down. Extend the button from your board config and add a gesture of your own:

```yaml
binary_sensor:
  - id: !extend center_button
    on_multi_click:
      - timing:
          - ON for at least 3s
        then:
          - switch.toggle: relay_in_the_hallway
```

Anything ESPHome can do as an action belongs here: GPIO, a script, an HA service call, a TTS announcement, a scene.

Note that `!extend` **appends** to the gesture list rather than replacing it, so pick a timing that does not overlap one of the four above, or the overlapping gestures will both match. To change or drop a shipped gesture, edit the package itself.

<img width="1198" height="1070" alt="Home Assistant device page showing the Button press event entity and the battery sensors" src="https://github.com/user-attachments/assets/59fccb03-7986-495a-ad2c-748fa9cc0bed" />

### Battery and power entities (Solo C1)

Running on battery adds four entities:

| Entity | Type | Notes |
|--------|------|-------|
| `Battery Voltage` | Sensor, V | Averaged over six samples taken 5s apart |
| `Battery Level` | Sensor, % | Estimated from voltage, 3.3V empty to 4.2V full on a single Li-ion cell |
| `External Power` | Binary sensor | On when the USB-C supply is present |
| `Battery Charging` | Binary sensor | On while the charger is active |

The empty and full voltages are substitutions, so a different cell chemistry only takes a config change rather than a firmware patch.

### ESPHome - initial flashing

The ESP32-S3 needs a special routine for the very first ESPHome flash, which was optional on the classic ESP32. It takes a few extra steps.

| Step | Image |
|------|------------|
| Open the device box and connect it to the PC for initial flashing. <br/> It will report itself as a USB device, but it cannot go into flashing mode on its own. <br/> With the device powered on, hold the FLASH button down, press the RESET button, then release FLASH. |  ![image](https://github.com/user-attachments/assets/c3258763-b290-4d73-89ed-57f2edcb158f)
| Only after that, connect to the device from [web.esphome.io](https://web.esphome.io/) | ![image](https://github.com/user-attachments/assets/0a89316b-dba2-4f93-afa7-6752fb050ac2)
| You may press the PREPARE FOR FIRST USE button as usual. | ![image](https://github.com/user-attachments/assets/02387a81-f2be-4218-8278-66c373fbacc8)
| You will be greeted with `An error occurred. Improv Wi-Fi Serial not detected` error. That's because the device is not able to RESET over USB during the first flashing. Reset it manually using RESET button | ![image](https://github.com/user-attachments/assets/f0d037ba-9c2a-4318-bb28-1fc752c83234)
| Re-connect to the device and proceed with the initial Wi-Fi configuration | ![image](https://github.com/user-attachments/assets/8bcc6291-dece-4ec7-ae3b-695bf3444308)

### Walkie Talkie firmware

Alternative firmware that uses the ESP-NOW protocol for bi-directional communication over Wi-Fi. This is a clone of the [esp32-walkie-talkie](https://github.com/atomic14/esp32-walkie-talkie) project by atomic14. More details [here](/firmware/esp32-walkie-talkie/).

## Hardware

Please visit the [hardware](/hardware/) section for board schematics and PCB designs. Note that PCBs are shared as multi-layer PDFs as well as Gerber archives.

Rev A and Rev B files are published there. The Solo C1 schematic and PCB, including the KALLSUP connector placement and board outline, will be added once the revision is released.

### Boxed


| Esparagus Solo (Prototype) | Esparagus Solo (rev B) | Esparagus Solo C1 (in a KALLSUP) | Esparagus Duo  |
|---|---|---|---|
| ![Esparagus Solo prototype, boxed](https://github.com/user-attachments/assets/b650bccd-84e5-4a5e-81ac-86187e45e2ef) | ![Esparagus Solo rev B, boxed](https://github.com/user-attachments/assets/9cae5e9d-4d7e-48bd-a289-85b84be51282) | <img width="882" height="990" alt="Solo C1 fitted into a KALLSUP speaker" src="https://github.com/user-attachments/assets/d4364a61-4903-4242-abc9-2e4b6b326790" /> | ![Esparagus Duo, boxed](https://github.com/user-attachments/assets/fe4e7137-e51a-4827-b44d-3520adf3159f) |
| ![Esparagus Solo prototype, second view](https://github.com/user-attachments/assets/ad078714-8822-4c29-ad7d-3a537a74fca6) | ![Esparagus Solo rev B, second view](https://github.com/user-attachments/assets/de751a1a-3c80-434c-8a80-8177ae99a032) | <img width="904" height="1132" alt="Solo C1 in a KALLSUP, second view" src="https://github.com/user-attachments/assets/c5d29ba3-c587-4dee-884c-db8b21441ec9" /> | ![Esparagus Duo, second view](https://github.com/user-attachments/assets/5e5fd427-333e-4336-872e-6a40ef548f83) |


### PCB

| Esparagus Solo (Prototype) | Esparagus Solo (rev B) | Esparagus Solo C1 | Esparagus Duo  |
|---|---|---|---|
| ![Esparagus Solo prototype PCB](https://github.com/user-attachments/assets/761b231c-c5f4-4479-b12b-1be4ae2b4831) | ![Esparagus Solo rev B PCB](https://github.com/user-attachments/assets/60ff9542-6a02-4ac6-8828-350baf6fede7) | <img width="699" height="999" alt="Solo C1 PCB" src="https://github.com/user-attachments/assets/50322396-f69f-4a10-82f2-039074d8ae97" /> | ![Esparagus Duo PCB](https://github.com/user-attachments/assets/9561e312-61d7-4463-8947-f37b56da8db0) |

## Where to buy

You may support our work by ordering this product at [Lectronz](https://lectronz.com/products/esparagus-echo) or [Tindie](https://www.tindie.com/products/sonocotta/esparagus-echo/).

