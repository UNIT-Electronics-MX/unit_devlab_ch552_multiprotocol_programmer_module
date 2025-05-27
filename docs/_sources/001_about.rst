General Information
===================

The **CH552 USB Multi-Protocol Programmer** is a compact and versatile development tool designed for high-precision embedded system applications. It supports a broad range of protocols and device architectures, including **AVR**, **ARM (CMSIS-DAP)**, and **CPLD (MAX II)**. Its USB connectivity enables direct interfacing with standard development environments, enabling:

- In-system programming (ISP)
- Step-through debugging
- Boundary-scan testing (JTAG)
- Flash memory operations

Compatible with popular platforms such as **STM32**, **RP2040**, and **PY32**, this programmer integrates configurable GPIO lines, multi-protocol headers, and streamlined power delivery—making it ideal for rapid prototyping and field diagnostics.

Supported Architectures
-----------------------

* **AVR** — via ISP (SPI configuration)
* **ARM Cortex-M** — via CMSIS-DAP and SWD

  - **RP2040** 
  - **PY32**
  - **STM32** 

* **CPLD/FPGA (MAX II)** — via JTAG


All protocols are exposed via labeled headers or JST connectors, allowing fast, solderless prototyping.


This device connects to a host system via USB and allows the user to program and debug various microcontrollers and programmable logic devices.

Supported Interfaces
--------------------

- **JTAG**, for full-chip debugging and boundary scan
- **SWD**, for ARM Cortex-M series
- **SPI**, for flash and peripheral programming
- **UART**, for serial bootloaders and communication
- **GPIO**, for bit-banging or peripheral testing

.. list-table:: Interface and Signal Overview
   :widths: 20 30 25 25
   :header-rows: 1

   * - Interface
     - Description
     - Signals / Pins
     - Typical Use
   * - **JTAG**
     - Standard boundary-scan and debug interface
     - TCK, TMS, TDI, TDO, nTRST
     - Full chip programming, in-circuit test, debug
   * - **SPI**
     - High-speed serial peripheral interface
     - MOSI, MISO, SCK, CS
     - Flash memory programming, peripheral data exchange
   * - **SWD**
     - ARM’s two-wire serial debug and programming interface
     - SWCLK, SWDIO
     - Cortex-M programming and step-through debugging
   * - **JST Header**
     - Compact connector for power and single-wire debug signals
     - SWC (SWCLK), SWD (SWDIO), VCC, GND
     - Quick-connect to target board for SWD and power



Sections GPIO Pin Distribution
------------------------------

The CH552 USB Multi-Protocol Programmer features a set of GPIO pins that can be configured for various protocols, including JTAG, SWD, and ISP. These GPIOs are mapped to specific functions in the firmware, allowing users to adapt the programmer for different applications.


The GPIO pin distribution is defined within the CH552 firmware, supporting flexible assignment for various protocols. The firmware configures the specific mapping of GPIOs to protocols, such as SPI, JTAG, or SWD, based on the loaded configuration. Users can alter the pin distribution by modifying the firmware source code to suit their application requirements.

Protocol ISP – In-System Programming
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compatible with **AVR** microcontrollers, this protocol allows programming and debugging via the SPI interface. The programmer can be used to flash firmware directly into the target device's memory.

.. only:: html

   .. figure:: _static/hardware/swdio_avr.png
      :align: center
      :width: 60%

      Pinout diagram for CH552 Programmer

.. only:: latex

   .. raw:: latex

      \begin{center}
      \includegraphics[width=\linewidth,keepaspectratio]{swdio_avr.png}
      \end{center}


.. list-table:: Pinout
   :widths: 33 33 33
   :header-rows: 1

   * - PIN
     - GPIO
     - I/O
   * - **MOSI**
     - 1.5
     - I/O
   * - **MISO**
     - 1.6
     - I/O
   * - **CS**
     - 3.0
     - I/O
   * - **SCK**
     - 1.7
     - I/O


Protocol JTAG
-------------

Compatible with **CPLD** and **FPGA** devices, this protocol allows programming and debugging via the JTAG interface. The programmer can be used to flash firmware directly into the target device's memory.


.. only:: html

   .. figure:: _static/hardware/jtag.png
      :align: center
      :width: 60%

      Pinout diagram for CH552 Programmer

.. only:: latex

   .. raw:: latex

      \begin{figure}[H]
      \centering
      \includegraphics[width=\linewidth,keepaspectratio]{jtag.png}
      \caption{Pinout diagram for CH552 Programmer (JTAG interface)}
      \end{figure}

.. list-table:: Pinout
   :widths: 33 33 33
   :header-rows: 1

   * - PIN
     - GPIO
     - I/O
   * - **TCK**
     - 1.7
     - I/O
   * - **TMS**
     - 3.2
     - I/O
   * - **TDI**
     - 1.5
     - I/O
   * - **TDO**
     - 1.6
     - I/O

.. list-table:: Pinout NC - Not Connected
   :widths: 33 33 33
   :header-rows: 1

   * - PIN
     - GPIO
     - I/O
   * - **NC 6**
     - 3.4
     - I/O
   * - **NC 7**
     - 3.3
     - I/O
   * - **NC 8**
     - 1.4
     - I/O


Protocol SWD
------------

Compatible with **ARM Cortex-M** microcontrollers, this protocol allows programming and debugging via the SWD interface. The programmer can be used to flash firmware directly into the target device's memory.



.. only:: html

   .. figure:: _static/hardware/swdio_jst.png
      :align: center
      :width: 60%

      SWD Pinout

.. only:: latex

   .. raw:: latex

      \begin{figure}[H]
      \centering
      \includegraphics[width=\linewidth,keepaspectratio]{swdio_jst.png}
      \caption{SWD Pinout(JTAG interface)}
      \end{figure}



.. list-table:: Pinout
   :widths: 33 33 33
   :header-rows: 1

   * - PIN
     - GPIO
     - I/O
   * - **SWCLK**
     - 1.7
     - I/O
   * - **SWDIO**
     - 1.6
     - I/O


.. note::
   GPIO numbers refer to the CH552 internal ports. Ensure correct firmware pin mapping before connecting external devices.

.. only:: html

   .. figure:: _static/programmer_pinout.jpg
      :align: center
      :width: 60%

      Pinout diagram for CH552 Programmer

.. only:: latex

   .. raw:: latex

      \clearpage
      \thispagestyle{empty}
      \onecolumn
      \begin{center}
      \includegraphics[width=\textwidth,height=\paperheight,keepaspectratio]{programmer_pinout.jpg}
      \end{center}
      \twocolumn


.. only:: html

    .. rubric:: Schematic Diagram

    .. raw:: html

      <div style="text-align: center;">
      <button style="background-color: rgb(226, 142, 15); color: white; border: none; padding: 10px 20px;"
      onclick="window.open('./_static/hardware/Schematics_CH552_USB_Multi-Protocol_Programmer_V1.pdf', '_blank')">
      Download Schematics (PDF)
      </button>
      </div>
      <br>
      <iframe src="./_static/hardware/Schematics_CH552_USB_Multi-Protocol_Programmer_V1.pdf" style="width:100%; height:500px;" frameborder="0"></iframe>

.. only:: latex

   .. raw:: latex

      \clearpage
      \chapter*{Appendix A: Schematics}
      \addcontentsline{toc}{chapter}{Appendix A: Schematics}
      \includepdf[pages=-,landscape=true]{Schematics_CH552_USB_Multi-Protocol_Programmer_V1.pdf}
    

