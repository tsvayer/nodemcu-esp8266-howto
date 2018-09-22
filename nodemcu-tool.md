# NodeMCU-tool

NodeMCU-tool allows you to manage files (list, upload, download, delete) on an ESP8266 device. It also allows you to execute LUA code stored on a development machine directly on the ESP8266 device.

## Installation

You should have [Node.js](https://nodejs.org/en/) and [Npm](https://www.npmjs.com/) (better [Yarn](https://yarnpkg.com)) installed on your machine. You can make a global installation, so that nodemcu-tool is available from any location on your machine:

```bash
$ npm install -g nodemcu-tool
$ nodemcu-tool --version
# 3.0.1
```

or you can install it locally in your project folder to avoid unnecessary pollution of your system:

```bash
$ npm init -y
$ npm install --save-dev nodemcu-tool
$ npx nodemcu-tool --version
# 3.0.1
```

## Usage

### Search for connected ESP8266 devices

```bash
$ nodemcu-tool devices

# when no ESP8266 device is connected:
# [device]      ~ No Connected Devices found | Total: 0

# when one ESP8266 device is connected:
# [device]      ~ Connected Devices | Total: 1
# [device]      ~ - /dev/tty.wchusbserial1410
```

Please note that if you are missing USB-UART converter driver nodemcu-tool will not be able to find your connected ESP8266 device. To learn more go to [Drivers](usb-uart-drivers.md) page.

Alternatively, you can list your system devices and filter by _'usb'_ keyword like:

```bash
$ ls /dev/tty* | grep usb
# /dev/tty.wchusbserial1410
```

### File operations

> TODO

### Executing code

> TODO

## LoLin modules from Wemos

There is a special case for LoLin modules (D1, D1 mini, etc) from [Wemos](https://www.wemos.cc/) manufacturer. The problem is that device is restarted every time connection is established and we need to introduce a little delay to let device to startup when using nodemcu-tool. If you see that device is connected (using `devices` command), but get the following error for file related operations

```bash
# [NodeMCU-Tool]~ Unable to establish connection
# [NodeMCU-Tool]~ No response detected - is NodeMCU online and the Lua interpreter ready ?
```

you should include additional parameter `--connection-delay`

```bash
nodemcu-tool fsinfo --port /dev/ttyUSB0 --connection-delay 100
```

In case it still does not work, try to increase delay from 100ms to 200-1000ms
