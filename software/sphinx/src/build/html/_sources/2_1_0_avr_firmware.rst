AVR Firmware Overview
=====================

The CH552 Multi-Protocol Programmer relies on the PICO-AVR firmware to operate correctly. This firmware works with the CH552 USB-to-ISP bridge and is a critical part of the programmer's functionality. The CH55x-based picoAVR acts as a combined ISP, TPI, and UPDI programmer for AVR microcontrollers. It is compatible with both USBasp and SerialUPDI interfaces and integrates seamlessly with the Arduino IDE (accessible via Tools → Programmer → USBasp or Tools → Programmer → SerialUPDI).

.. warning::

    The PICO-AVR firmware is available under the
    `Creative Commons Attribution-ShareAlike 3.0 Unported License <http://creativecommons.org/licenses/by-sa/3.0/>`_.

    Additional resources:

    - Github: `wagiminator <https://github.com/wagiminator>`_
    - EasyEDA: `wagiminator at EasyEDA <https://easyeda.com/wagiminator>`_
    - License details: `Creative Commons Attribution-ShareAlike 3.0 Unported License <http://creativecommons.org/licenses/by-sa/3.0/>`_

Resources
---------

1. `EasyEDA Design Files <https://oshwlab.com/wagiminator>`_
2. `WCH: CH552 Datasheet <http://www.wch-ic.com/downloads/CH552DS1_PDF.html>`_
3. `SDCC Compiler <https://sdcc.sourceforge.net/>`_
4. `Blinkinlabs: CH55x SDK for SDCC <https://github.com/Blinkinlabs/ch554_sdcc>`_
5. `Thomas Fischl: USBasp <https://www.fischl.de/usbasp/>`_
6. `Ralph Doncaster: USBasp <https://github.com/nerdralph/usbasp>`_
7. `Deqing Sun: CH55xduino <https://github.com/DeqingSun/ch55xduino>`_