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

### Open serial terminal

```bash
nodemcu-tool --port [device port] terminal
```

You should specify _device port_ that you got from the previous `devices` command. On successfull connection you should get something similar to:

```bash
powered by Lua 5.1.4 on SDK 2.2.1
> _
```

At this point you are interacting with your ESP8266 device through LUA REPL. For instance, print some message:

```lua
> print('hello')
# hello
```

or get an IP address (in case you have already connected your device to some access point):

```lua
> print(wifi.sta.getip())
# 192.168.1.27 255.255.255.0 192.168.1.1
```

Please note, that in order to exit from a terminal you press ^C instead of ^D that we are used to on Linux/Unix.

### Note: Environment configuration

To communicate with your ESP8266 device you always need to specify which port it is connected to. For instance, in the previous `terminal` command we specified it through `--port` parameter. There are other parameters that you probably will specify for every command you run. It becomes tedious really quickly. There is an easier way:

```bash
nodemcu-tool init
```

it will ask you for the parameters once and save them in `.nodemcu` configuration file in a current directory. Next time you execute some nodemcu-tool command you can skip those common parameters.

Note that by default, [--connection-delay](#lolin-modules-from-wemos) parameter is not saved. In case you need it, you can edit the configuration file manually:

```json
{
  "connectionDelay": 100
}
```

### File operations

Upload files to ESP8266 filesystem:

```bash
nodemcu-tool upload script.lua
```

Download files from ESP8266 filesystem:

```bash
nodemcu-tool download script.lua
```

Remove a file from ESP8266 filesystem:

```bash
nodemcu-tool remove script.lua
```

List files and get other file system related information:

```bash
nodemcu-tool fsinfo
```

### Executing code

To execute some LUA code on ESP8266 you first need to upload it. For instance, let's assume you have a `script.lua` code on your development machine. Then, to execute it you would run the following commands:

```bash
nodemcu-tool upload script.lua
nodemcu-tool run script.lua
```

Another way to execute some code in a file stored on a device filesystem is through a serial [terminal](#open-serial-terminal). Assuming you have uploaded `script.lua` file and opened a terminal to your device, the following command will execute it:

```lua
> dofile('script.lua')
```

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
