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



.. figure:: _static/duino/jtag_avr.png
  :align: center
  :width: 60%

  Pinout diagram for CH552 Programmer




.. list-table:: Pinout
   :widths: 33 33 33
   :header-rows: 1

   * - PIN
     - GPIO
     - I/O
   * - **MOSI**
     - 1.5
     - MOSI, PWM1
   * - **MISO**
     - 1.6
     - MISO, RXD1
   * - **CS**
     - 3.3
     - PWM1, TXD0
   * - **SCK**
     - 1.7
     - SCK, TXD1



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



.. only:: latex

   .. raw:: latex

      \clearpage
      \onecolumn
      \blanknotepage
      \twocolumn
