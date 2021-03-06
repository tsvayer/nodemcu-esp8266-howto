# NodeMCU ESP8266 How-To

> Quick start information on programming [ESP8266](https://www.espressif.com/en/products/hardware/esp8266ex/overview) in [NodeMCU](https://github.com/nodemcu/nodemcu-firmware) environment

## Quick Start to Hello World

Get me to the Hello World as quick as possible -> [RUN](quick-start-helloworld.md)

For something more interesting try [Wi-Fi Detector](examples/wifi_detector)

Not looking for easy ways? Write a [new module in C](examples/hello_world_c).

## Documentation

[Official NodeMCU documentation](https://nodemcu.readthedocs.io/en/master/) is good and if you want to understand the details you should go and read it completely. This repository contains some distilled and often biased quick lookup information on the topic.

## Main Tools

- [nodemcu-tool](nodemcu-tool.md) - file management, code execution, serial terminal and LUA REPL
- [esptool.py](esptool.md) - bootloader interaction, flashing firmware
- [docker-nodemcu-build](docker-nodemcu.md) - Docker based firmware builder
- [Lua](https://www.lua.org/) programming language

### Related tools

- [Python](https://www.python.org/) + [pip](https://pypi.org/project/pip/)
- [Node.js](https://nodejs.org) + [Npm](https://www.npmjs.com/)
- [Docker](https://www.docker.com/)

## USB Drivers

You may need to install a driver in order to be able to communicate with your ESP8266 module over USB. It depends on a specific USB-UART converter chip, but you most probably will see one of those below:

- CH340G - [drivers](https://sparks.gogo.co.nz/ch340.html)
- CP2102 - [drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

For more detailed information look at [Drivers](usb-uart-drivers.md) page

## Examples

- [Wi-Fi Detector](examples/wifi_detector) - LUA example to detect Wi-Fi devices around
- [Example Module in C](examples/hello_world_c) - simple module to show how to write new extensions in C
