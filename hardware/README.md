# Hardware Design Files

<div align="center">

<a href="/hardware/unit_sch_V_0_0_1_ue0090_CH552_USB_Multi-Protocol-Programmer.pdf">
  <img src="resources/Schematics_icon.jpg?raw=false" width="300px">
  <br/> 
  Schematics
</a>

</div>

## Key Technical Specifications

<div align="center">

| Interface        | Description                                              | Signals / Pins                        | Typical Use                                        |
|:----------------:|:--------------------------------------------------------:|:-------------------------------------:|:--------------------------------------------------:|
| **JTAG**         | Standard boundary-scan and debug interface               | TCK, TMS, TDI, TDO, nTRST             | Full chip programming, in-circuit test, debug      |
| **AVR-ISP**          | High-speed serial peripheral interface                   | MOSI, MISO, SCK, CS                   |  Commonly used for programming AVR microcontrollers |
| **SWD**          | ARM's two-wire serial debug and programming interface    | SWCLK, SWDIO                          | Cortex-M programming & step-through debugging      |
| **JST Header**   | Compact connector for power + single-wire debug signals  | SWC (SWCLK), SWD (SWDIO), VCC, GND    | Quick-connect to target board for SWD and power    |

</div>

### Electrical characteristics when the microcontroller is powered with 5V

<div align="center">

| **Parameter** |                     **Description**                      | **Min** | **Typ** | **Max** | **Unit** |
|:-------------:|:--------------------------------------------------------:|:-------:|:-------:|:-------:|:--------:|
|      Vin      |           Input voltage to power on the module           |   3.7   |    -    |   5.5   |    V     |
|      Vil      |                 Input low level voltage                  |  -0.4   |    -    |   1.2   |    V     |
|      Vih      |                 Input high level voltage                 |   2.4   |    -    | Vin+0.4 |    V     |
|      Vol      |                 Low level output voltage                 |    -    |    -    |   0.4   |    V     |
|      Voh      |                High level output voltage                 | VCC-0.4 |    -    |    -    |    V     |
|    Icc24M*    |           Total supply current when Fsys=24MHz           |    8    |   11    |    -    |    mA    |
|     Icc6M     |           Total supply current when Fsys=6MHz            |    4    |    6    |    -    |    mA    |
|    Icc750K    |          Total supply current when Fsys=750KHz           |    2    |    3    |    -    |    mA    |
|      Iin      |       The input current without pull-down resistor       |   -5    |    0    |    5    |    uA    |
|     Idn5      |        The input current with pull-down resistor         |   -35   |   -70   |  -140   |    uA    |
|     Iup5      |         The input current with pull-up resistor          |   35    |   70    |   140   |    uA    |
|     IUP5X     | The input current with pull-up resistor from low to high |   250   |   400   |   600   |    uA    |
|     Vpot      |                 Power on reset threshold                 |   2.1   |   2.3   |   2.5   |    V     |

</div>

*24MHz Fsys only can be used when the microcontroller is working with 5V.

### Electrical characteristics when the microcontroller is powered with 3.3V

<div align="center">

| **Parameter** |                     **Description**                      | **Min** | **Typ** | **Max** | **Unit** |
|:-------------:|:--------------------------------------------------------:|:-------:|:-------:|:-------:|:--------:|
|      Vin      |           Input voltage to power on the module           |   2.8   |   3.3   |   3.6   |    V     |
|      Vil      |                 Input low level voltage                  |  -0.4   |    -    |   0.8   |    V     |
|      Vih      |                 Input high level voltage                 |   1.9   |    -    | Vin+0.4 |    V     |
|      Vol      |                 Low level output voltage                 |    -    |    -    |   0.4   |    V     |
|      Voh      |                High level output voltage                 | VCC-0.4 |    -    |    -    |    V     |
|    Icc12M*    |           Total supply current when Fsys=12MHz           |    3    |    5    |    -    |    mA    |
|     Icc6M     |           Total supply current when Fsys=6MHz            |    2    |    4    |    -    |    mA    |
|    Icc750K    |          Total supply current when Fsys=750KHz           |    1    |    2    |    -    |    mA    |
|      Iin      |       The input current without pull-down resistor       |   -5    |    0    |    5    |    uA    |
|     Idn5      |        The input current with pull-down resistor         |   -15   |   -30   |   -60   |    uA    |
|     Iup5      |         The input current with pull-up resistor          |   15    |   30    |   60    |    uA    |
|     IUP5X     | The input current with pull-up resistor from low to high |   100   |   170   |   250   |    uA    |
|     Vpot      |                 Power on reset threshold                 |   2.1   |   2.3   |   2.5   |    V     |

</div>

*Use the jumper bridge to select the microcontroller's operating voltage.

# Pinout

<div align="center">

<a href="unit_pinout_v_0_0_3_ue0090_multi_protocol_programmer_en.pdf">
  <img src="resources/unit_pinout_v_0_0_3_ue0090_multi_protocol_programmer_en.jpg" width="500px">
  <br/> 
  Pinout
</a>

</div>

---

## GPIO Pins


<div align="center">

### **Protocol SPI**

| PIN            | GPIO  | I/O |
|:--------------:|:-----:|:---:|
| **MISO**       | 1.6   | I/O |
| **MOSI**       | 1.5   | I/O |
| **SCK**        | 1.7   | I/O |
| **CS**         | 3.3   | I/O |

### **Protocol JTAG**

| PIN            | GPIO  | I/O |
|:--------------:|:-----:|:---:|
| **TCK**        | 1.7   | I/O |
| **TDO**        | 1.6   | I/O |
| **TMS**        | 3.2   | I/O |
| **TDI**        | 1.5   | I/O |

### **Protocol SWD**

| PIN            | GPIO  | I/O |
|:--------------:|:-----:|:---:|
| **SWCLK**      | 1.5   | I/O |
| **SWDIO**      | 1.6   | I/O |

</div>

### IDC-10 JST Header Pinout

<div align="center">


| PIN | GPIO | Signal | Description |
|:---:|:----:|:------:|:-----------|
| 1   | 1.7  | SWCLK  | SWD Clock / MOSI |
| 2   | -    | GND    | Ground |
| 3   | 1.6  | SWDIO  | SWD Data / MISO |
| 4   | -    | VCC    | Target Voltage Supply |
| 5   | 3.2  | Reset  | Reset (Optional) |
| 6   | 1.4  | CS     | Chip Select (Optional) |
| 7   | 3.1  | TXD    | TXD (Optional) |
| 8   | 3.0  | RXD    | RXD (Optional) |
| 9   | 1.5  | MOSI   | MOSI (Optional) |

</div >

# Board Topology

<div align="center">

<a href="#">
  <img src="./resources/unit_topology_V_0_0_1_ue0090_CH552_USB_Multi-Protocol-Programmer.png" width="900px">
  <br/>
  Topology
</a>


| Ref.  | Description                                                                 |
|:-----:|:---------------------------------------------------------------------------:|
| IC1   | CH552 Microcontroller                                                       |
| U1    | AP2112K 3.3V LDO Voltage Regulator                                          |
| PB1   | Boot Push Button                                                            |
| TP1   | Reset Test Point                                                            |
| TP2   | P3.1 Test Point                                                             |
| L1    | Built-In LED                                                                |
| L2    | Power On LED                                                                |
| SB1   | Solder bridge to enable VCC at JTAG                                         |
| SB2   | Solder bridge to enable VCC at JST                                          |
| J1    | USB Type-C Connector                                                        |
| J2    | Low-power I2C JST Connector                                                 |
| J3    | JTAG Connector                                                              |
| JP1   | Header for SWD or ICSP programming                                          |
| JP2   | Header to Select Operating Voltage Level                                    |

</div>

# Board Dimensions

<div align="center">

<a href="#">
  <img src="./resources/unit_dimension_V_0_0_1_ue0090_CH552_USB_Multi-Protocol-Programmer.png" width="500px">
  <br/>
  Dimensions
</a>
</div>

