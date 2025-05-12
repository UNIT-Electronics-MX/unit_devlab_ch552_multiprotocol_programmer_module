# Hardware Design Files

<a href=""><img src="resources/Schematics_icon.jpg?raw=false" width="500px"><br/> Schematics</a>

# Pinout

<a href=""><img src="resources/blaster_pinout.jpg" width="500px"><br/> Pinout</a>

| Interface        | Description                                              | Signals / Pins                        | Typical Use                                        |
|------------------|----------------------------------------------------------|---------------------------------------|----------------------------------------------------|
| **JTAG**         | Standard boundary-scan and debug interface               | TCK, TMS, TDI, TDO, nTRST             | Full chip programming, in-circuit test, debug      |
| **SPI**          | High-speed serial peripheral interface                   | MOSI, MISO, SCK, CS                   | Flash memory programming, peripheral data exchange |
| **SWD**          | ARM’s two-wire serial debug and programming interface    | SWCLK, SWDIO                          | Cortex-M programming & step-through debugging      |
| **JST Header**   | Compact connector for power + single-wire debug signals  | SWC (SWCLK), SWD (SWDIO), VCC, GND    | Quick-connect to target board for SWD and power    |

---

## GPIO Pins

> **Protocol SPI**

| PIN            | GPIO  | I/O |
|----------------|-------|-----|
| **MOSI**       | 1.5   | I/O |
| **MISO**       | 1.6   | I/O |
| **SCK**        | 1.7   | I/O |
| **CS**         | 1.4   | I/O |

> **Protocol JTAG**

| PIN            | GPIO  | I/O |
|----------------|-------|-----|
| **TCK**        | 1.7   | I/O |
| **TMS**        | 3.2   | I/O |
| **TDI**        | 1.5   | I/O |
| **TDO**        | 1.6   | I/O |

> **Protocol SWD**

| PIN            | GPIO  | I/O |
|----------------|-------|-----|
| **SWCLK**      | 1.7   | I/O |
| **SWDIO**      | 1.6   | I/O |





# Board Topology
