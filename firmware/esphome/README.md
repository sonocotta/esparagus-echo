# Esparagus Echo - ESPHome configurations

ESPHome configurations for the Esparagus Echo boards. There is a folder per board revision, and a config per use case inside it. Shared functionality lives in [packages](packages) and is pulled in by each config, so a board folder only declares its own pinout and picks the packages it needs.

## Table of Contents

- [Which folder do I need](#which-folder-do-i-need)
- [Which config do I need](#which-config-do-i-need)
- [Packages](#packages)
- [Pairing with Music Assistant](#pairing-with-music-assistant)
- [Building and flashing](#building-and-flashing)
- [Secrets](#secrets)

## Which folder do I need

| Folder | Board | Status |
| --- | --- | --- |
| [echo-solo-c](echo-solo-c) | Esparagus Solo C1, the IKEA KALLSUP replacement PCB | Current |
| [echo-solo-b](echo-solo-b) | Esparagus Solo rev B, the boxed device | Current |
| [echo-duo-b](echo-duo-b) | Esparagus Duo rev B | Current |
| [echo-duo-a](echo-duo-a) | Esparagus Duo rev A | Prototype |

Solo C1 is a drop-in replacement for the board inside an IKEA KALLSUP Bluetooth speaker, so it reuses the speaker's battery, driver, LED position and buttons. Compared to rev B it adds battery and power sensing plus the action button, and moves the RGB LED to GPIO10. See the [pinout tables](../../README.md#boards-pinout) in the top-level README.

## Which config do I need

| Config | What it does |
| --- | --- |
| `*-sendspin.yaml` | Media player over the Sendspin protocol, for synchronised multi-room audio with Music Assistant |
| `*-voice-assist-sendspin.yaml` | Wake word plus voice pipeline on top of the Sendspin player, ducking the music while the assistant speaks |
| `*-voice-assist.yaml` | Wake word plus voice pipeline on top of the plain Home Assistant media player |
| `*-media-player.yaml` | Plain Home Assistant media player |
| `*-snapclient.yaml` | Snapcast client |
| `*-snapclient-with-dsp.yaml` | Snapcast client with DSP controls |

Not every revision has every config. Rev C ships `sendspin`, `voice-assist-sendspin` and `snapclient`.

## Packages

The packages are shared between revisions and between this repository and [esparagus-media-center](https://github.com/sonocotta/esparagus-media-center). Each config lists the ones it needs by URL, so a build pulls them from `main` rather than from your working copy. Each config also carries a commented block of local `!include` lines, which is how to test a package change before pushing it.

Audio and voice:

| Package | Purpose |
| --- | --- |
| `audio.yaml` | I2S audio output, speaker and mixer |
| `microphone.yaml`, `microphone-i2s.yaml` | I2S microphone |
| `sendspin.yaml` | Sendspin media player |
| `media-player.yaml` | Home Assistant media player |
| `voice-assist.yaml`, `voice-assist-sendspin.yaml` | Wake word, voice pipeline and LED feedback |

Solo C1 hardware:

| Package | Purpose |
| --- | --- |
| `battery.yaml` | Battery voltage and level, external power and charging status |
| `voice-assist-addon-button.yaml` | Action button on the voice assistant configs |
| `sendspin-addon-button.yaml` | Action button on the media-only configs |

The two button packages are mutually exclusive, since both define the button, the event entity and the `Disable physical controls` switch. Use the voice assistant one wherever a pipeline exists.

The gestures are ordinary `on_multi_click` entries, so a board config can add one of its own with `!extend` on `center_button`. Lists merge by appending, so a new gesture is added to the shipped four rather than replacing them; pick timings that do not overlap.

The `*-addon-*` packages extend a base package rather than standing on their own, so each one needs its base package in the same config.

## Pairing with Music Assistant

Music Assistant 2.11 and newer can *pair* with a Sendspin player, so the player trusts that server from then on. The Sendspin configs support this with a 6-digit pairing code that the device shows in Home Assistant.

**Pairing is optional.** The configs keep unpaired (guest) access on, so Music Assistant can still play on the device without pairing, just as before. You only need the code if you want to pair the player instead of using it as a guest.

To pair a player:

1. Install the current config on the device again, so it gets the new **Sendspin Pairing Code** sensor. The configs pull their packages from GitHub, and ESPHome caches them for up to a day, so on an existing install the sensor can take that long to appear.
2. Start pairing the player in Music Assistant. When it asks for a pairing code, open the device in Home Assistant (Settings → Devices & services → ESPHome) and read the **Sendspin Pairing Code** sensor.
3. Enter the 6-digit code in Music Assistant. The sensor clears once pairing is done.

The sensor is empty whenever no pairing is in progress. After 20 wrong codes in a row the device stops accepting new attempts; restart it to try again.

Without Home Assistant there is currently no way to read the code: it isn't logged, and these configs don't show it on a display yet. In that case keep using the player unpaired.

## Building and flashing

Over USB, with the device connected:

```sh
esphome run echo-solo-c/echo-solo-c-idf-voice-assist-sendspin.yaml
```

Over the network, once the device is on WiFi:

```sh
esphome run --device <name>.local echo-solo-c/echo-solo-c-idf-voice-assist-sendspin.yaml
```

A first flash on a factory-fresh board needs the manual download-mode dance described in the [top-level README](../../README.md#esphome---initial-flashing): hold FLASH, tap RESET, release FLASH.

To watch the logs without flashing, `esphome logs <config>`. Note that the log stream only carries what happens while you are attached, so reset the board if you want to see its boot.

## Secrets

Each board folder expects a `secrets.yaml` next to the configs. The usual arrangement is a symlink to a single `secrets.yaml` at this level, which is how `echo-solo-c` and `echo-duo-b` are set up. That file is not in the repository, and it needs three keys:

```yaml
esphome_wifi_ssid: "..."
esphome_wifi_password: "..."
esphome_ota_password: "..."
```
