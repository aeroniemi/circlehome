# CircleHome: Home Assistant enabled IoT UI for M5Dial
A HomeAssistant device controller built into a cute 1.28" dial.

## Features
 - Control HomeAssistant devices:
     - Lights (brightness, colour, on/off)
     - Switches (on/off)
     - More may be added if requested...
 - Automatically identifies entities from your Home Assistant install - no per-device configuration required
 - Clock with timezone and daylight savings time correction
 - Captive portal for configuration

## Installation
*The software is only compatible with the [M5Dial by M5Stack](https://shop.m5stack.com/products/m5stack-dial-esp32-s3-smart-rotary-knob-w-1-28-round-touch-screen), but it would be relatively trivial to port it to other ESP32-based dials and knobs.*
- Download the latest binary (firmware_merged.bin) from [Releases](https://github.com/aeroniemi/circlehome/releases
- Open a ESPTool instance (such as [this online one from Adafruit](https://adafruit.github.io/Adafruit_WebSerial_ESPTool/))
- Erase your ESP32
- Write ``firmware_merged.bin`` at ``0x0``
- Restart your ESP

You should now be good to setup your device!

## Setup
After installing the firmware, you need to set the WiFi credentials, home assistant credentials and more. To make this as easy as possible CircleHome will create a WiFi hotspot for you to join:
- On initial startup, you'll see a green configuration message. Click "Setup"
- Connect to the open WiFi network ``M5Dial``
- Navigate to ``http://192.168.0.1``
- Fill out the details in the form.
 - Note that timezone is case sensitive, and must be one of the values found [here](https://github.com/rzeldent/micro-timezonedb/blob/main/include/timezonedb.h)
- Press submit on the form
- Wait a few moments, then click ``restart`` on your dial.

The device should now be configured.

## Operation
The interface of CircleHome should be fairly intuitive, but here's a few tips:
- To return to the main menu, long press the dial.

## Building
- The repository contains all the details you'll need to build the project using Platform-IO.
 - Install the Platform-IO plugin to Visual Studio Code.
 - Clone the repository
 - Open the VSCode workspace
 - Open a Platform-IO terminal using ``Ctrl+P``
 - A number of VSCode tasks exist to generate images and other derivative assets - you may need to run those before uploading code.
 - Run ``pio run``
  - Alternatively you can just run Platform-IO Build from the command palette
 - To upload to a device, run Platform-IO Upload
