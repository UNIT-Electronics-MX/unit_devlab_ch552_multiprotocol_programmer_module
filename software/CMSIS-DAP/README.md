
# CH552 DAPLink — CMSIS-DAP Debug Probe Implementation

**CH552 DAPLink** is a CMSIS-DAP compliant debug probe built around the **CH552 microcontroller**, offering support for **SWD**, **JTAG**, and a **Virtual COM Port (VCP)**. This makes it an effective and lightweight tool for programming and debugging ARM Cortex-M microcontrollers such as STM32, SAM, and other devices via standard debug interfaces.

The firmware is based on the implementation by [Ralph Doncaster](https://github.com/nerdralph/ch554_sdcc/tree/master/examples/CMSIS_DAP) for the CH55x series, extended using [Deqing Sun's CH55xduino](https://github.com/DeqingSun/ch55xduino) platform and compiled with **SDCC**.

![programmer](../static/programmer.png)


---

## 📦 CMSIS-DAP Overview

**CMSIS-DAP** provides a standardized USB-to-Debug interface that connects development hosts to ARM Cortex debug ports through:

- **SWD (Serial Wire Debug)**
- **JTAG (IEEE 1149.1)**
- **USB CDC (Virtual COM Port)**

This protocol is widely supported by tools such as **OpenOCD**, **PyOCD**, and most IDEs that interface with ARM microcontrollers. Since CMSIS-DAP devices use the USB HID class, no drivers are typically required on modern operating systems.

More information can be found in the [CMSIS-DAP Handbook](https://os.mbed.com/handbook/CMSIS-DAP).

![CMSIS-DAP Diagram](https://raw.githubusercontent.com/wagiminator/CH552-DAPLink/main/documentation/DAPLink_CMSIS-DAP.png)

---

## 🔧 Firmware Compilation and Flashing

### Bootloader Requirements

The CH552 includes a native USB bootloader for flashing firmware without external tools. Flashing is performed using the included `tools/chprog.py` script or compatible USB loaders.

#### Linux: Set USB Permissions

```bash
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="4348", ATTR{idProduct}=="55e0", MODE="666"' | sudo tee /etc/udev/rules.d/99-ch55x.rules
sudo udevadm control --reload
sudo udevadm trigger
```

#### Windows: Install USB Driver

- Option 1: [CH372 driver](http://www.wch-ic.com/downloads/CH372DRV_EXE.html)
- Option 2: [Zadig Tool](https://zadig.akeo.ie/)
  - Enable "Options → List All Devices"
  - Select the CH55x USB device
  - Install the **libusb-win32** driver

> ⚠️ Ensure the CH552 is in **bootloader mode** when installing the driver or flashing.

### Entering Bootloader Mode

1. Disconnect USB and power from the CH552 board.
2. Press and hold the **BOOT** button.
3. Reconnect USB while keeping BOOT pressed.
4. Release the button. The device will remain in bootloader mode for a few seconds, ready for flashing.

---

### 🛠️ Compilation via Makefile

#### Prerequisites (Linux example)

```bash
sudo apt install build-essential sdcc python3 python3-pip
pip3 install pyusb
```

#### Compile and Flash Firmware

```bash
make flash
# or upload precompiled binary:
python3 ./tools/chprog.py daplink.bin
```

> Ensure that the board is in bootloader mode before flashing.

---

## ▶️ Usage Instructions

- **Power Output:** Provides 3.3V or 5V (max 400mA) to the target board.
- **Connection:** Use standard SWD or JTAG headers.
- **USB Interface:**
  - Enumerates as a **CMSIS-DAP HID** device
  - Exposes a **CDC virtual COM port** (serial debugging)

### Compatible Software

The CH552 DAPLink is compatible with any debugger or development tool that supports **CMSIS-DAP**, such as:

- [OpenOCD](http://openocd.org/)
- [PyOCD](https://github.com/pyocd/pyocd)
- Keil µVision
- SEGGER Ozone (via CMSIS-DAP interface)

For the Virtual COM Port:
- Use any standard terminal emulator (115200 8N1 or custom baud).

---

## 📚 Resources and References

| Resource | Description |
|----------|-------------|
| [EasyEDA Design](https://oshwlab.com/wagiminator/ch552g-daplink) | Hardware schematic |
| [ARMmbed CMSIS-DAP](https://github.com/ARMmbed/DAPLink) | CMSIS-DAP firmware reference |
| [CH55xduino](https://github.com/DeqingSun/ch55xduino) | CH552 development environment |
| [Doncaster's DAP](https://github.com/nerdralph/ch554_sdcc/tree/master/examples/CMSIS_DAP) | Initial CH55x CMSIS-DAP implementation |
| [CMSIS-DAP Handbook](https://os.mbed.com/handbook/CMSIS-DAP) | Protocol details |
| [SDCC Compiler](https://sdcc.sourceforge.net/) | Open-source C compiler for 8051 |
| [CH55x SDK (SDCC)](https://github.com/Blinkinlabs/ch554_sdcc) | SDK for CH552/CH554 |
| [picoDAP](https://github.com/wagiminator/CH552-picoDAP) | Minimal CMSIS-DAP alternative |

---

---

## 🪪 License

![license](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

Licensed under the **Creative Commons Attribution-ShareAlike 3.0 Unported License**.  
[http://creativecommons.org/licenses/by-sa/3.0/](http://creativecommons.org/licenses/by-sa/3.0/)

