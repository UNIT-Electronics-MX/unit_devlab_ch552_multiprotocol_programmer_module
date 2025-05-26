Terms, Acknowledgments, and Licenses
====================================

Terms and Conditions
--------------------

By using, modifying, or distributing the documentation, firmware, or hardware designs included in this repository, you agree to the following terms:

- All materials are provided **"as-is"**, without warranty of any kind.
- The authors and contributors shall not be held responsible for **any damages**, data loss, or legal issues arising from the use of these materials.
- Usage is intended for **educational, development, prototyping**, and other lawful purposes.
- When redistributing or reusing any part of this project, you must **retain attribution** and comply with the corresponding license terms of each component.

Acknowledgments and Contributors
--------------------------------

This project builds upon the work of several open-source developers and projects:

CMSIS-DAP (DAPLink Firmware for CH552)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Stefan Wagner**  
  Project: `CH552-DAPLink <https://github.com/wagiminator/CH552-DAPLink>`_  
  License: Creative Commons BY-SA 3.0  
  Description: CMSIS-DAP firmware and hardware design

- **Ralph Doncaster**  
  Source: `nerdralph/ch554_sdcc <https://github.com/nerdralph/ch554_sdcc>`_  
  Description: Original CMSIS-DAP firmware implementation for CH554 (SDCC)

- **Deqing Sun**  
  Source: `CH55xduino <https://github.com/DeqingSun/ch55xduino>`_  
  Description: CH552/CH554 Arduino-compatible toolchain

USB-Blaster Firmware (CH552G)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- **Vladimir Duan**  
  Project: `CH55x-USB-Blaster <https://github.com/VladimirDuan/CH55x-USB-Blaster>`_  
  License: MIT  
  Description: USB-Blaster JTAG emulation for CH55x

- **Blinkinlabs**  
  SDK Source: `ch554_sdcc <https://github.com/Blinkinlabs/ch554_sdcc>`_  
  Description: SDK for CH552/CH554 (SDCC)

- **Doug Brown**  
  Blog: `Fixing a Knockoff Altera USB Blaster <https://www.downtowndougbrown.com/2024/06/fixing-a-knockoff-altera-usb-blaster-that-never-worked/>`_  
  Description: Insights into compatibility and firmware flashing

Hardware License
----------------

All hardware designs (schematics, layouts, and design files) in this repository are released under the **MIT License**, allowing unrestricted use, modification, and distribution, provided the original license and attribution are retained.

Resources and References
------------------------

.. list-table:: Source URLs
   :header-rows: 1

   * - Project / Tool
     - Source URL
   * - CH552 DAPLink
     - `https://github.com/wagiminator/CH552-DAPLink <https://github.com/wagiminator/CH552-DAPLink>`_
   * - picoDAP
     - `https://github.com/wagiminator/CH552-picoDAP <https://github.com/wagiminator/CH552-picoDAP>`_
   * - CH55xDuino
     - `https://github.com/DeqingSun/ch55xduino <https://github.com/DeqingSun/ch55xduino>`_
   * - CMSIS-DAP Handbook
     - `https://os.mbed.com/handbook/CMSIS-DAP <https://os.mbed.com/handbook/CMSIS-DAP>`_
   * - CH55x USB-Blaster
     - `https://github.com/VladimirDuan/CH55x-USB-Blaster <https://github.com/VladimirDuan/CH55x-USB-Blaster>`_
   * - SDCC Compiler
     - `https://sdcc.sourceforge.net/ <https://sdcc.sourceforge.net/>`_
   * - CH554 SDK
     - `https://github.com/Blinkinlabs/ch554_sdcc <https://github.com/Blinkinlabs/ch554_sdcc>`_

Licenses
--------

Documentation & Visual Content
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This user guide and its visual content are licensed under:

**Creative Commons Attribution-ShareAlike 3.0 Unported License**

.. image:: https://i.creativecommons.org/l/by-sa/3.0/88x31.png
   :target: http://creativecommons.org/licenses/by-sa/3.0/
   :alt: Creative Commons License

Firmware Projects
~~~~~~~~~~~~~~~~~

- **CH552-DAPLink**: Creative Commons BY-SA 3.0 — © Stefan Wagner
- **CH55x-USB-Blaster**: MIT License — © Vladimir Duan
- **CH55x SDK / Tools**: MIT License — © Blinkinlabs

Hardware Repository
~~~~~~~~~~~~~~~~~~~

- All PCB designs and schematics are released under the **MIT License**.

.. note::

   If you distribute this product with third-party firmware (e.g., CMSIS-DAP), you are responsible for ensuring license compliance. Only firmware developed by Unit Electronics and released under the MIT license is supported for commercial redistribution.


Preloaded USB-Serial Firmware
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This product may include preloaded firmware based on the project by **Kongou Hikari**:  
"USB to Serial Converter firmware for CH552T".  
Original source: *[https://github.com/diodep/ch55x_dualserial/tree/master]*  
License: MIT

Under the terms of the MIT License, users are free to modify or replace the firmware. Unit Electronics provides this firmware for convenience only and does not offer performance guarantees.  
