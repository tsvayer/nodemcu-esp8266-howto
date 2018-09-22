# Quick Start to Hello World

If you don't want to understand how it actually works and just want to get to Hello World state as quick as possible then follow the steps below:

1. Install USB [Drivers](usb-uart-drivers.md)
1. Install [_nodemcu-tool_](nodemcu-tool.md) (assuming you know what is [Npm](https://www.npmjs.com/))
1. Install [_esptool_](esptool.md) (assuming you know what is [pip](https://pypi.org/project/pip/))
1. Download default firmware image from [nodemcu-build](https://nodemcu-build.com/)
1. Connect your ESP8266 module to development machine over USB
1. Find out where your device is connected

```bash
nodemcu-tool devices
```

note port where your device is connected. Example: _/dev/ttyUSB0_

1. Flash your downloaded firmware image to the device

```bash
$ esptool.py --port [device port name] write_flash -fm dio 0x0000 [firmware image file]
# example device port name: /dev/ttyUSB0
# example firmware image file: nodemcu-master-11-modules-float.bin
```

- Run LUA script on device

```bash
$ echo "print('hello world')" > ./hello.lua
$ nodemcu-tool -p [device port name] upload ./hello.lua
$ nodemcu-tool -p [device port name] run hello.lua
# example device port name: /dev/ttyUSB0
```

**BONUS**: for something more interesting try [Wi-Fi Detector](examples/wifi_detector) example.
