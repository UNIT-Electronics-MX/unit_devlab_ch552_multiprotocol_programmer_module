AVR: Compile and Upload Code
=============================

Toolchain Overview
------------------

To compile and upload code to an AVR microcontroller, you'll need the **AVR-GCC** toolchain. This includes essential components such as the compiler, assembler, linker, and utilities like ``avr-objcopy``.

Installation
------------

You can download and install the AVR-GCC toolchain from the official Microchip website:

.. tabs::

    .. tab:: Windows

        Download the installer from the Microchip website and follow the installation instructions.

        - `AVR-GCC Compiler for Microchip Studio <https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers>`_

    .. tab:: Linux

        You can install the AVR-GCC toolchain using your package manager. For example, on Ubuntu:

        .. code-block:: console

            sudo apt-get install avr-gcc avr-binutils avr-libc

    .. tab:: macOS

        You can use Homebrew to install the AVR-GCC toolchain:

        .. code-block:: console

            brew tap osx-cross/avr
            brew install avr-gcc


Ensure the toolchain is added to your system’s ``PATH`` environment variable for global access.

Example: Compiling a Blink Program
-----------------------------------

This example demonstrates how to compile a basic blink program for two common AVR microcontrollers:

* **ATtiny88**
* **ATmega328P**

.. code-block:: bash

             +-----------------+
    PC6 (RST)| 1  ATmega328 28 | PC5 (A5)
    PD0 (RX) | 2            27 | PC4 (A4)
    PD1 (TX) | 3            26 | PC3 (A3)
         PD2 | 4            25 | PC2 (A2)
    PD3 (PWM)| 5            24 | PC1 (A1)
         PD4 | 6            23 | PC0 (A0)
        VCC  | 7            22 | GND
        GND  | 8            21 | AREF
         PB6 | 9            20 | AVCC
         PB7 |10            19 | PB5 (D13)
    PD5 (D5) |11            18 | PB4 (D12)
    PD6 (D6) |12            17 | PB3 (D11/PWM)
    PD7 (D7) |13            16 | PB2 (D10/PWM)
    PB0 (D8) |14            15 | PB1 (D9/PWM)
             +-----------------+


The program toggles an LED connected to **pin PB0** every second.

Source File 
~~~~~~~~~~~~

.. code-block:: c

    #define F_CPU 16000000UL
    #include <avr/io.h>
    #include <util/delay.h>

    int main(void) {
        DDRB |= (1 << PB0); // Set PB0 as output
        while (1) {
            PORTB ^= (1 << PB0); // Toggle PB0
            _delay_ms(1000);
        }
    }

Compilation Commands
~~~~~~~~~~~~~~~~~~~~

Use the following commands to compile and generate the HEX file:

.. code-block:: c

    # For ATtiny88
    avr-gcc -mmcu=attiny88 -Os -o blink.elf blink.c
    avr-objcopy -O ihex blink.elf blink.hex

    # For ATmega328P
    avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o blink.elf blink.c
    avr-objcopy -O ihex blink.elf blink.hex

Explanation of flags:

* ``-mmcu=`` specifies the target microcontroller.
* ``-Os`` enables size optimization.
* ``-DF_CPU`` sets the clock frequency used for timing functions.

Uploading with AVRDUDE
-----------------------

Once the ``.hex`` file is generated, you can upload it to the AVR microcontroller using **AVRDUDE**.

Installation AVRDUDE Linux 
----------------------------

You can install AVRDUDE on Linux using your package manager. For example, on Ubuntu:

.. code-block:: bash

    sudo apt-get install avrdude


Upload Command
~~~~~~~~~~~~~~~

.. code-block:: c

    avrdude -p m328p -c usbasp -U flash:w:blink.hex


Explanation:

* ``-p m328p`` specifies the target device (ATmega328P).
* ``-c usbasp`` sets the programmer to the CH552 USB Multi-Protocol Programmer.
* ``-U flash:w:blink.hex`` uploads the hex file to flash memory.

Replace ``m328p`` with the appropriate identifier for your specific AVR device (e.g., ``t88`` for ATtiny88). A full list of supported devices is available in the `AVRDUDE user manual <http://www.nongnu.org/avrdude/user-manual/avrdude.html#Device-Options>`_.



.. raw:: html

    <div style="text-align: center;">
        <button class="btn btn-primary" style="margin: 10px; padding: 5px 10px; background-color: #007bff; border: none; border-radius: 4px; cursor: pointer;" onclick="window.open('./_static/duino/programador2.png', '_blank')">View Options</button>
      <img src="./_static/duino/programador2.png" alt="AVR Programmer" style="width: 100%;">
      <p>ATMEGA328P Microcontroller</p>
    </div>