# Quick Start to Hello World

If you don't want to understand how it actually works and just want to get to Hello World state as quick as possible then follow the steps below:

- Install USB Drivers
- Install _nodemcu-tool_ (assuming you know what is NPM
- Install _esptool_ (assuming you know what is PIP)
- Download default firmware image from [nodemcu-build](https://nodemcu-build.com/)
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
