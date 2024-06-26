# CircleHome: Home Assistant enabled IoT UI for M5Dial
A HomeAssistant device controller built into a cute 1.28" dial.

## Features
 - Control HomeAssistant devices:
     - Lights (brightness, colour, on/off)
     - Switches (on/off)
     - More may be added if requested...
 - Create timers which alert using the on-board buzzer 
 - Automatically identifies entities from your Home Assistant install - no per-device configuration required
 - Clock with timezone and daylight savings time correction
 - Little configuration required - authenticate in your browser with HomeAssistant

## Installation
*The software is only compatible with the [M5Dial by M5Stack](https://shop.m5stack.com/products/m5stack-dial-esp32-s3-smart-rotary-knob-w-1-28-round-touch-screen), but it would be relatively trivial to port it to other ESP32-based dials and knobs.*
- Flash the latest release at [https://aeroniemi.github.io/circlehome/]
- Set the WiFi details using the tool (Improv Serial/WiFi)
- Visit the device URL to authenticate with your Home Assistant instance
- You're good to go!

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
