# esptool.py

In order to operate, ESP8266 needs some code to execute. It can be some system code from real-time OS ([RTOS](https://www.espressif.com/en/products/hardware/esp8266ex/overview)) or some application code. Anyway, it has to be uploaded to the device. Every ESP8266 module has some onboard flash memory. It's most probably 4Mb nowadays (end of 2018). esptool.py lets you write to and read from the flash memory of ESP8266 module.

Detailed technical information can be found at [esptool.py repository](https://github.com/espressif/esptool).

## Installation

You should have [Python](https://www.python.org/) and [pip](https://pypi.org/project/pip/) installed. I would advice to optionally create a [python virtual environment](https://docs.python.org/3/tutorial/venv.html) instead of installing it system wide:

```bash
python -m venv esptool-env
source esptool-env/bin/activate
pip install esptool
```

## Writing binary data to flash

Although you are supposed to write some meaningfull structured data on a device flash memory, you are free to write any binary data at any address. You generally need to specify 3 parameters: device port, binary data file to write and address of flash memory where to start write operation. You can find a correct device port as [explained here](nodemcu-tool.md#search-for-connected-esp8266-devices). Normally, you will write some [custom firmware](docker-nodemcu.md) image or pre-built file system image. In the example below we are writing binary content from _some_data.bin_ file starting at 0x10000:

```bash
esptool.py --port [device port] write_flash 0x10000 some_data.bin
```

## Reading binary data from flash

Concepts are the same as in _writing_ operation above. Data flow direction changes. For instance, below we are reading 64KB of data starting from 0x30000 address into _some_data.bin_ file:

```bash
esptool.py --port [device port] read_flash 0x30000 0x10000 some_data.bin
```

## Erase flash

Sometimes you will need to erase all the data from ESP8266 flash memory to clean things up and start from scratch or maybe you need to erase some sensitive information:

```bash
# erase whole flash memory
$ esptool.py erase_flash --port [device port]
# erase 128KB region starting at 0x10000
$ esptool.py erase_region 0x10000 0x20000
```

## Addressing explained

Above examples use hexadecimal addresses like 0x10000 instead of decimals like 65536. Why is that?

As you probably know already, 1 KByte equals 1024 Bytes. Thus, 64 KB equals 1024 \* 64 = 65536 Bytes. Which is simply 0x10000 in hex. See? It's much easier to remember and write. Other examples:

- 4KB - 0x1000 (instead of 4096)
- 16KB - 0x4000 (instead of 16384)
- 128KB - 0x20000 (instead of 131072)
- 1MB - 0x100000 (instead of 1024\*1024 = 1048576)
- 2MB - 0x200000 (instead of 2097152)

etc.
