# picoDAP — CMSIS-DAP Debug Probe for ARM Cortex via CH552E

**picoDAP** is a lightweight CMSIS-DAP compliant debug probe based on the **CH552E** microcontroller. It supports **Serial Wire Debug (SWD)** for programming and debugging ARM Cortex-M microcontrollers, such as STM32 and SAM series.

The firmware is based on [Ralph Doncaster’s CMSIS-DAP implementation](https://github.com/nerdralph/ch554_sdcc/tree/master/examples/CMSIS_DAP), enhanced with the [CH55xduino](https://github.com/DeqingSun/ch55xduino) environment and compiled using the **SDCC** toolchain.

![programmer](../static/programmer.png)

---

## CMSIS-DAP Overview

**CMSIS-DAP** defines a USB HID-based protocol for accessing the **Coresight Debug Access Port (DAP)** of ARM Cortex microcontrollers via **SWD** or **JTAG**.

### Features:
- Native USB HID interface (no driver needed on most OSes)
- Seamless integration with:
  - [OpenOCD](http://openocd.org/)
  - PyOCD
  - Keil µVision
  - SEGGER Ozone (CMSIS-DAP interface)
- Optional **Virtual COM Port** via USB CDC for UART communication

![CMSIS-DAP Diagram](https://raw.githubusercontent.com/wagiminator/CH552-picoDAP/main/documentation/picoDAP_CMSIS-DAP.png)

---

## Firmware Compilation & Installation

### 1. Bootloader Access on CH552

#### Linux: Configure USB Access

```bash
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="4348", ATTR{idProduct}=="55e0", MODE="666"' | sudo tee /etc/udev/rules.d/99-ch55x.rules
sudo udevadm control --reload
sudo udevadm trigger
```

#### Windows: Install Driver

- Option A: [CH372 Driver](http://www.wch-ic.com/downloads/CH372DRV_EXE.html)
- Option B: [Zadig Tool](https://zadig.akeo.ie/)
  - Enable **Options → List All Devices**
  - Select the bootloader device
  - Install `libusb-win32`

Ensure the board is in **bootloader mode** before flashing.

### 2. Entering Bootloader Mode

1. Disconnect all power/USB from the board.  
2. Hold down the **BOOT** button.  
3. Connect USB while holding the button.  
4. Release the button. The device will stay in bootloader mode for several seconds.

---

## Compiling with Makefile

### Requirements

```bash
sudo apt install build-essential sdcc python3 python3-pip
pip3 install pyusb
```

### Build and Flash

```bash
cd firmware/
make flash
```

Or flash a precompiled binary:

```bash
python3 tools/chprog.py picodap.bin
```

---

## Usage & Integration

- **Power Output:**
  - 3.3V (max 150 mA)
  - 5V (max 400 mA)
- **Target Connections:**
  - Standard 10-pin SWD header
  - Alternative pinout: RST / DIO / CLK / GND
- **Host Interface:**
  - USB HID (CMSIS-DAP)
  - USB CDC (VCP serial monitor)

### Compatible Debug Software

- **OpenOCD**
- **PyOCD**
- Any tool supporting **CMSIS-DAP** via HID or CDC interface

---

## Resources

| Resource | Description |
|----------|-------------|
| [CH552 SWD Programmer on EasyEDA](https://oshwlab.com/wagiminator/ch552-swd-programmer) | Hardware schematic |
| [ARMmbed DAPLink](https://github.com/ARMmbed/DAPLink) | CMSIS-DAP official reference |
| [CH55xduino](https://github.com/DeqingSun/ch55xduino) | CH552 dev framework |
| [Original CMSIS-DAP Port (Doncaster)](https://github.com/nerdralph/ch554_sdcc/tree/master/examples/CMSIS_DAP) | CH55x source base |
| [CMSIS-DAP Handbook](https://os.mbed.com/handbook/CMSIS-DAP) | Protocol documentation |
| [SDCC Compiler](https://sdcc.sourceforge.net/) | C compiler for 8051/CH55x |
| [Blinkinlabs CH55x SDK](https://github.com/Blinkinlabs/ch554_sdcc) | Peripheral SDK for CH552 |
| [OpenOCD](http://openocd.org/) | Debug server support |

---

## License

![license](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)  
This project is licensed under the **Creative Commons Attribution-ShareAlike 3.0 Unported License**.  
[http://creativecommons.org/licenses/by-sa/3.0/](http://creativecommons.org/licenses/by-sa/3.0/)
