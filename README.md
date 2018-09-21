# NodeMCU ESP8266 How-To

> Quick start information on programming ESP8266 in NodeMCU environment

# Note: Work in Progress...

## NodeMCU Documentation

https://nodemcu.readthedocs.io/en/master/

## Main Tools

https://github.com/espressif/esptool
https://github.com/AndiDittrich/NodeMCU-Tool
https://github.com/marcelstoer/docker-nodemcu-build

### Related tools

- python
- node.js + npm
- docker

## USB Drivers

You may need to install a driver in order to be able to communicate with your ESP8266 module over USB. It depends on a specific USB-UART converter chip, but you most probably will see one of those below:

- CHP340G - https://sparks.gogo.co.nz/ch340.html
- CP2102 - https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers

## Quick Start to Hello World

- Install USB Drivers
- Install _nodemcu-tool_ (assuming you know what is NPM
- Install _esptool_ (assuming you know what is PIP)
- Download default firmware image from https://nodemcu-build.com/
- Connect your ESP8266 module to development machine over USB
- Find out where your device is connected

```bash
nodemcu-tool devices
```

note port where your device is connected

- Flash your downloaded firmware image to the device

```bash
esptool.py --port [device port /dev/tty.wchusbserial1410] write_flash -fm dio 0x0000 [path to your firmware image bin file]
```

- Run LUA script on device

```bash
echo "print('hello world')" > ./hello.lua
nodemcu-tool -p [device port] run ./hello.lua
```
