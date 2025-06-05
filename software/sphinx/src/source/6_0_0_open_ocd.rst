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

.. code-block:: bash

    pyocd erase -t py32f003x6 --chip --config ./Misc/pyocd.yaml
