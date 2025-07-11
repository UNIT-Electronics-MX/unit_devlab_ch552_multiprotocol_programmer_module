Using OpenOCD
=============

To program your microcontroller using OpenOCD, use the following command:

.. code-block:: bash

    openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg \
            -c "init" -c "reset init" \
            -c "flash write_image erase blink.bin 0x10000000" \
            -c "reset run" -c "shutdown"

Supported Microcontrollers
--------------------------

This guide supports the following microcontrollers:

.. list-table::
    :widths: 20 80
    :header-rows: 1

    * - Microcontroller
      - Description
    * - RP2040
      - Low-cost microcontroller with a dual-core ARM Cortex-M0+ processor.
    * - STM32F103C8T6
      - Budget-friendly microcontroller with an ARM Cortex-M3 processor.
    * - STM32F411
      - Cost-effective microcontroller with an ARM Cortex-M4 processor.


Selecting Your Microcontroller Target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Each microcontroller requires a specific configuration file. This file is a script that instructs OpenOCD on how to communicate with the microcontroller. The configuration file is tailored to the microcontroller and the debugger interface.

.. list-table::
    :widths: 30 70
    :header-rows: 1

    * - Microcontroller
      - Configuration File
    * - RP2040
      - ``rp2040.cfg``
    * - STM32F103C8T6
      - ``stm32f103c8t6.cfg``
    * - STM32F411
      - ``stm32f411.cfg``

 
PyOCD
=====

PyOCD is a command-line tool for interacting with ARM Cortex-M microcontrollers. It supports flashing, erasing, debugging, and low-level memory access using CMSIS-DAP, DAPLink, ST-Link, and other probes.

Basic Syntax
------------

.. code-block:: bash

    pyocd <command> [OPTIONS]

You can specify the target using ``-t <target>`` or through a configuration file using ``--config <file.yaml>``.

Configuration File
------------------

Use a YAML configuration file to define global options:

.. code-block:: yaml

    # Misc/pyocd.yaml
    target_override: py32f003x6
    frequency: 1000000
    log_level: info

To load this config:

.. code-block:: bash

    pyocd erase --config ./Misc/pyocd.yaml

Commands
--------

erase
^^^^^

Erase flash memory of the target device.

.. code-block:: bash

    pyocd erase -t py32f003x6 [OPTIONS]

Options:

- ``--chip``: Erase the entire flash memory.
- ``--sector <ADDR>``: Erase a single sector by address.
- ``--config <file.yaml>``: Load configuration from YAML file.

Example:

.. code-block:: bash

    pyocd erase -t py32f003x6 --chip --config ./Misc/pyocd.yaml

flash
^^^^^

Flash a binary, hex, or ELF file to the target.

.. code-block:: bash

    pyocd flash <file> -t py32f003x6 [OPTIONS]

Options:

- ``--base-address <addr>``: Override the base address (for .bin files).
- ``--verify``: Verify flash contents after writing.
- ``--erase=chip|sector|auto``: Select erase mode.
- ``--format bin|hex|elf``: Force file format.
- ``--config <file.yaml>``: Load YAML config.

Example:

.. code-block:: bash

    pyocd flash firmware.hex -t py32f003x6 --erase=chip --verify

gdbserver
^^^^^^^^^

Start a GDB server for remote debugging.

.. code-block:: bash

    pyocd gdbserver -t py32f003x6 [OPTIONS]

Options:

- ``--port <number>``: GDB server port.
- ``--telnet-port <number>``: Telnet monitor port.
- ``--persist``: Keep the server alive after GDB disconnects.
- ``--config <file.yaml>``: Load YAML config.

reset
^^^^^

Reset the target microcontroller.

.. code-block:: bash

    pyocd reset -t py32f003x6 [OPTIONS]

Options:

- ``--halt``: Halt the CPU after reset.
- ``--config <file.yaml>``: Load YAML config.

list
^^^^

List connected debug probes and supported targets.

.. code-block:: bash

    pyocd list

read / write
^^^^^^^^^^^^

Read and write memory directly.

.. code-block:: bash

    pyocd read32 0x08000000 4
    pyocd write32 0x20000000 0x12345678

CMSIS-Pack Targets
------------------

To add custom target support (e.g., ``py32f003x6``), use:

.. code-block:: bash

    pyocd pack install py32f003x6

Or add a local `.pdsc` file:

.. code-block:: bash

    pyocd pack add ./path/to/PY32F003.pdsc

Example Workflow
----------------

.. code-block:: bash

    pyocd list
    pyocd erase -t py32f003x6 --chip
    pyocd flash build/main.hex -t py32f003x6 --verify
    pyocd gdbserver -t py32f003x6
    pyocd reset -t py32f003x6 --halt

References
----------

- `https://pyocd.io/ <https://pyocd.io/>`_
- `https://github.com/pyocd/pyocd <https://github.com/pyocd/pyocd>`_

Command Help
------------

.. code-block:: bash

    pyocd --help
    pyocd flash --help
    pyocd erase --help
