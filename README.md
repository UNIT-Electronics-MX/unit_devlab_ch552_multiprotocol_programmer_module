# Multi-Protocol Programmer

<div align="center">
  <img src="https://img.shields.io/badge/version-1.0-blue.svg" />
  <img src="https://img.shields.io/badge/language-C-lightgrey.svg" />
  <img src="https://img.shields.io/badge/language-Python-lightgrey.svg" />
  <img src="https://img.shields.io/badge/license-MIT-green.svg" />
</div>

<div align="center">
  <img src="https://raw.githubusercontent.com/UNIT-Electronics-MX/unit_ch552_multiprotocol_programmer/refs/heads/main/hardware/resources/programmer.png" width="480" alt="Multi-Protocol Programmer" />
<div align="center">

## Resources

<table>
  <thead>
    <tr>
      <th>Resource</th>
      <th>Link</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Wiki</td>
      <td><a href="https://unit-electronics-mx.github.io/wiki_uelectronics/es/docs/Development_boards/devlab/multiprotocol/">Development Boards Wiki</a></td>
    </tr>
    <tr>
      <td>Documentation</td>
      <td><a href="https://unit-electronics-mx.github.io/unit_multiprotocol_programmer_platform/">unit_multiprotocol_programmer_platform</a></td>
    </tr>
    <tr>
      <td>Getting Started</td>
      <td><a href="https://unit-electronics-mx.github.io/unit_ch552_multiprotocol_programmer/index.html">Initial Setup</a></td>
    </tr>
    <tr>
      <td>Schematic & PCB</td>
      <td><a href="https://github.com/UNIT-Electronics-MX/unit_ch552_multiprotocol_programmer/tree/main/hardware">Hardware Files</a></td>
    </tr>
    <tr>
      <td>Firmware & SDK</td>
      <td><a href="https://github.com/UNIT-Electronics-MX/unit_ch55x_docker_sdk">SDK & Firmware</a></td>
    </tr>
    <tr>
      <td>Main Repository</td>
      <td><a href="https://github.com/UNIT-Electronics-MX/unit_ch552_multiprotocol_programmer">GitHub Repo</a></td>
    </tr>
  </tbody>
</table>

</div>


## Firmware Required

This programmer **requires specific firmware** depending on the protocol:

* **AVR**: USBasp & UPDI
* **ARM**: CMSIS-DAP (SWD/JTAG)
* **CPLD**: USB-Blaster (JTAG)

Load the correct `.bin` before use. Without it, the device won’t function properly.

## Overview

The **Multi-Protocol Programmer** is a USB tool based on the **CH552** microcontroller. It supports flashing and debugging of:

* **AVR microcontrollers** (ATmega, ATtiny, AVR-DA)
* **ARM Cortex-M** devices (STM32, nRF52, SAM, etc.)
* **Intel/Altera MAX II CPLDs** (EPM240, EPM570, etc.)

### Features

* USB Full-Speed (CDC/HID)
* Voltage selector: 3.3V / 5V
* SWD / JTAG / UPDI / USBasp support
* Works with popular tools (avrdude, OpenOCD, Quartus, etc.)


## Supported Protocols

| Firmware      | Protocols    | Target Devices         | Interface | Tools                |
| ------------- | ------------ | ---------------------- | --------- | -------------------- |
| **AVR**       | USBasp, UPDI | ATmega, ATtiny         | CDC/HID   | avrdude, Arduino IDE |
| **CMSIS-DAP** | SWD, JTAG    | STM32, nRF52, ESP32-C3 | HID+CDC   | OpenOCD, PyOCD, Keil |
| **CPLD**      | USB-Blaster  | EPM240, EPM570, MAX II | HID       | Quartus Prime        |

## Flashing Firmware

1. **Enter Bootloader Mode:**

   * Hold `BOOT`, plug USB, release.
2. **Flash Firmware:**

   ```bash
   python3 tools/chprog.py firmware/firmware_name.bin
   ```

   Or use WCHISPTool on Windows.




## Install Requirements

```bash
# Linux (Debian/Ubuntu)
sudo apt install build-essential sdcc python3-pip git
pip3 install pyusb
```

For Windows:
Download [SDCC](https://sdcc.sourceforge.net/), [Python 3](https://python.org/), and [Git](https://git-scm.com/).

---

## Troubleshooting

* **Device not recognized?**
  ➤ Check firmware & USB drivers (use Zadig on Windows)

* **Programming error?**
  ➤ Verify voltage level (3.3V/5V), connections & cable quality

* **Slow upload?**
  ➤ Reduce SWD/JTAG frequency or use shorter cables

---

## License

* Hardware: CC BY-SA 4.0
* Firmware & Software: MIT License
* Third-party components: see individual `LICENSE` files
