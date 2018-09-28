# NodeMCU Firmware Build

NodeMCU firmware is based on LUA programming langugage and it's programming model is similar to [Node.js](https://nodejs.org). This allows you to develope applications on a much higher level of abstraction. The firmware and optional modules, which are built in C, isolate you from much of low level technical details. Although you can start with some default firmware image, sooner or later you will need a custom firmware with exact modules you need for a project.

## Online Build Service

One option is to use an online firmware build service, where you can select the modules you need and get a download link in your email inbox. Just go to [nodemcu-build.com](https://nodemcu-build.com/) and follow the instructions there.

## Docker Build

Online service above is an easy way to get to you first image. As you start active development it becomes much more handy to be able to build your firmware locally.

> TODO...

```bash
$ git clone https://github.com/nodemcu/nodemcu-firmware.git
$ cd nodemcu-firmware
$ docker run --rm -it -v `pwd`:/opt/nodemcu-firmware marcelstoer/nodemcu-build build
```
