AVR: Getting Started
====================

Introduction to AVR Microcontrollers
--------------------------------------
AVR (Advanced Virtual RISC) is a family of microcontrollers originally developed by Atmel, now part of Microchip Technology. Renowned for their simplicity, low power consumption, and ease of use, AVR microcontrollers are widely adopted in embedded systems, including Arduino boards and other DIY electronics projects.

The AVR family spans a variety of models with differing specifications—such as flash memory capacity, I/O pin count, and integrated peripherals. Common examples include the **ATmega** series (e.g., ``ATmega328P``, ``ATmega2560``) and the **ATtiny** series (e.g., ``ATtiny85``, ``ATtiny2313``).

Architecture Overview
---------------------
AVR microcontrollers are based on a **modified Harvard architecture**, which separates instruction and data memory. This design allows for simultaneous access and contributes to faster instruction execution and efficient memory usage.

Developers typically write code for AVR devices using **AVR Assembly** or higher-level languages like **C/C++**, supported by environments such as **Atmel Studio** or the **Arduino IDE**.

Programming with the CH552 Multi-Protocol Programmer
------------------------------------------------------


.. raw:: html

   <div style="text-align: center;">
     <img src="./_static/hardware/swdio_avr.png" alt="ISP Pinout" style="width: 50%;">
     <p>ISP Pinout</p>
   </div>


The **CH552 USB Multi-Protocol Programmer** provides robust support for AVR microcontrollers via the **In-System Programming (ISP)** interface. This method enables direct programming of the target microcontroller’s **flash memory** and **EEPROM** without removing it from the circuit.

.. raw:: html

   <div style="text-align: center;">
     <img src="./_static/docs/iscp.png" alt="AVR Programmer" style="width: 50%;">
     <p>AVR Programmer Pinout</p>
   </div>

Key Advantages:
~~~~~~~~~~~~~~~
* **Non-intrusive**: Program the MCU without desoldering or removing it from the board.
* **Efficient workflow**: Ideal for development, testing, and field updates.
* **Wide compatibility**: Supports common AVR chips used in educational and commercial projects.

Supported Operations:
~~~~~~~~~~~~~~~~~~~~~
* Flash memory writing
* EEPROM access
* Fuse and lock bit configuration
* Signature verification

Getting Started
---------------
To program AVR microcontrollers using the CH552 programmer:

#. Connect the ISP header to the target board (MISO, MOSI, SCK, RESET, VCC, GND).
#. Use compatible software such as ``avrdude`` or the Arduino IDE with custom programmer settings.
#. Ensure proper voltage levels (typically 5V or 3.3V depending on the target device).
#. Run the programming command to flash the firmware or configure the device.

.. code-block:: console

    avrdude -p m328p -c ch552 -U flash:w:firmware.hex

.. only:: latex

   .. raw:: latex

      \clearpage
      \onecolumn
      \blanknotepage
      \twocolumn
