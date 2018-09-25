# Hello World module in C

Example most simplistic NodeMCU module written in C.

## Prerequisites

You should be familiar with the topics below:

- [Build your own firmware](../../docker-nodemcu.md)
- [Flash firmware](../../esptool.md)
- [Run code on device](../../nodemcu-tool.md)

## Step 1 - develope your module

It's a simple `hello` module with one single function `world()` that prints _"Hello World!"_ message to the standard output. It's a single [hello.c](hello.c) file. You need to put it under `app/modules` folder in your nodemcu-firmware repository.

## Step 2 - enable your module

As explained in prerequisites section, to make some module available in a firmware build you need to enable it. Include the following line in `app/include/user_modules.h` file in your nodemcu-firmware repository:

```c
#define LUA_USE_MODULES_HELLO
```

## Step 3 - build and flash your firmware

Just follow the prerequisites section.

## Step 4 - try you module

Open serial terminal and execute `hello.world()` module:

```bash
$ nodemcu-tool terminal
$ hello.world()
# Hello World!
```
