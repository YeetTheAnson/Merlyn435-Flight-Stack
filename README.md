# Merlyn435 Flight Stack

## Introduction
This is my custom Merlyn435 Flight Stack! This project was made as a successor to my previous Merlyn411 flight controller due to several limitations. It lacked in its processing power and free UART ports. Its mounting pattern was also unconventional at 25mm, making its mounting incompatible with any ESCs on the market. By upgrading to the AT32F435@288MHz, the new Merlyn435 easily handles 8k8 PID loop and advanced autonomous flights with 3 spare UART ports.

The Merlyn435 also upgrades the IMU from the MPU6500 to the LSM6DSK320X, which provides significantly better vibration noise rejection at $3.8\ \mathrm{mdps}/\sqrt{\mathrm{Hz}}$ compared to $10\ \mathrm{mdps}/\sqrt{\mathrm{Hz}}$. This results in cooler motors and more stable flights with fewer gyro filters, preventing issues such as mid throttle oscillation and flyaways.

The Merlyn435 flight controller is designed for a wide battery voltage ranging from 2 to 6 cells. This flight controller can also be mounted in various sizes of drones from 2" to as big as it can get.

It is a 3 in 1 flight controller which offers features such as an integrated 2.4GHz ExpressLRS receiver and an OSD to overlay telemetry directly in the video feed. Furthermore, it has 16MB of flash memory for blackbox logging to assist in flight tuning.

The MerlynESC is a 4 in 1 ESC which runs on Bluejay firmware and also operates from 2 to 6s battery voltages. Its maximum continuous current is 40A per motor and peaks up to 55A for a maximum duration of 10 seconds.

![image](assets/Merlyn435.png)
![image](assets/MerlynESC.png)
![image](assets/20mm.png)
![image](assets/ESCSpecs.png)
![image](assets/Comparison.png)

| Feature | Merlyn435 | Merlyn411 |
|---|---|---|
| **MCU** | AT32F435CGU7 @ 288MHz | STM32F411CEU6 @ 100MHz |
| **MCU Flash Size** | 1024kB | 512kB |
| **UART Interfaces** | 5 Hardware UART (2 internal, 3 free) | 2 Hardware UART + 1 SoftSerial (1 internal, 1 softserial, 1 free) |
| **IMU** | LSM6DSK320X (SPI) | MPU6500 (SPI) |
| **Barometer** | BMP388 (I2C) | None |
| **OSD** | AT7456E (SPI) | AT7456E (SPI) |
| **Blackbox Flash** | 16MB (SPI) | 16MB (SPI) |
| **Integrated Receiver** | Serial ExpressLRS 2.4GHz  | Serial ExpressLRS 2.4GHz |
| **Mounting Size** | M2 20x20mm | M2 25.5x25.5mm |
| **BEC** | 5V 2A @ 1.1MHz Synchronous | 5V 2A @ 150kHz Asynchronous |
| **ESC Connection** | 8 pin JST-SH (Betaflight standard) | Direct solder pads |


## Hardware Specifications

### Merlyn435
* **MCU:** AT32F435CGU7
* **IMU:** LSM6DSK320X @ SPI1
* **Barometer:** BMP388 @ 0x76
* **OSD:** AT7456E @ SPI2
* **Blackbox:** W25Q128JV 16MB Flash @ SPI2
* **Receiver:** Serial ExpressLRS (ESP8285 + SX1281) @ UART2
* **Voltage range:** 2-6s LiPo / Li-ion / LiHV
* **Power Supply:** LMR51420YDDCR buck converter + SPX3819M5-L-3-3 LDO
* **Mounting:** M2 20x20mm

### MerlynESC
* **MCU:** EFM8BB21F16G
* **MOSFET:** JMSL0302AU
* **Gate Driver:** EG6288
* **Max Current:** 145A Peak / 40A Continuous @ 1.2mΩ
* **Voltage range:** 2-6s LiPo / Li-ion / LiHV
* **Power Supply:** HT75C0-1 12V LDO + HT7533-1 3.3V LDO
* **Mounting:** M2 20x20mm


## Pinout
<img src="assets/HeadersF.png" width="300">
<img src="assets/HeadersB.png" width="300">


| Header | Pin name | AT32 Pin | Description |
|---|---|---|---|
| **ESC** | `(1)BAT+` | - | Battery Positive Input from ESC |
| | `(2)GND` | - | Ground |
| | `(3)NC` | - | No Connection |
| | `(4)CURR` | PA1 | Current Sense Input |
| | `(5)M1` | PB6 | Motor 1 Signal Output |
| | `(6)M2` | PB7 | Motor 2 Signal Output |
| | `(7)M3` | PB0 | Motor 3 Signal Output |
| | `(8)M4` | PB1 | Motor 4 Signal Output |
| **GPS** | `C` | PH2 | I2C SCL (Internal BMP388 & External Magnetometer) |
| | `D` | PH3 | I2C SDA (Internal BMP388 & External Magnetometer) |
| | `T` | PB4 | UART7 TX |
| | `R` | PB3 | UART7 RX |
| | `G` | - | Ground |
| | `5` | - | 5V Power Output |
| **URT5** | `T` | PB9 | UART5 TX |
| | `R` | PB8 | UART5 RX |
| | `G` | - | Ground |
| | `5` | - | 5V Power Output |
| **CAM** | `I` | - | Analog Video Input |
| | `G` | - | Ground |
| | `5` | - | 5V Power Output |
| **URT3** | `5` | - | 5V Power Output |
| | `G` | - | Ground |
| | `R` | PB11 | UART3 RX |
| | `T` | PB10 | UART3 TX |
| **VTX** | `T` | PA9 | UART1 TX (IRC Tramp / SmartAudio) |
| | `O` | - | Analog Video Output (OSD Overlay) |
| | `G` | - | Ground |
| | `B+` | - | Battery Output for VTX |
| **BZ** | `-` | PC15 | Beeper MOSFET  Pin |
| | `+` | - | 5V Power Output |
| **POWER** | `3` | - | 3.3V Power Input/Output |
| | G | - | Ground |
| | `5` | - | 5V Power Input/Output |
| **Test Points** | `RX` | PA2 | UART2 TX (ExpressLRS RX) |
| | `TX` | PA3 | UART2 RX (ExpressLRS TX) |
| | `D` | PA13 | SWDIO (Debug & Flash) |
| | `C` | PA14 | SWCLK (Debug & Flash) |
| | `R` | NRST | NRST (Debug & Flash) |
| | `B` | BOOT0 | BOOT0 (Debug & Flash) |
| **Jumpers** | `BOOT` | ESP8285 GPIO0 | Bridge to enter ExpressLRS bootloader mode |
| | `RST` | ESP8285 CHIP_EN | Bridge to disable internal ExpressLRS receiver |

----

## Hardware Overview

### Merlyn435
![image](assets/Merlyn435Schematic.png)
<img src="assets/FCL1.png" width="300">
<img src="assets/FCL2.png" width="300">
<img src="assets/FCL3.png" width="300">
<img src="assets/FCL4.png" width="300">

### MerlynESC
![image](assets/MerlynESCSchematic.png)
<img src="assets/ESCL1.png" width="300">
<img src="assets/ESCL2.png" width="300">
<img src="assets/ESCL3.png" width="300">
<img src="assets/ESCL4.png" width="300">
<img src="assets/ESCL5.png" width="300">
<img src="assets/ESCL6.png" width="300">

----

## Flight Controller Firmware
Because the Merlyn435 is a custom hardware layout with no existing Betaflight targets, you must compile Betaflight using the custom target definitions in [/firmware/source/betaflight](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/tree/main/firmware/source/betaflight) or use the pre compiled firmware of your preferred Betaflight version in [/firmware/binaries](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/tree/main/firmware/binaries)

> [!IMPORTANT]
> The LSM6DSK320X was officially added in **v2026.6**. The same **Betaflight** configuration can be used to compile your binary for both **2025.12** and **2026.6** without any issues. However, **2025.12 does not support or detect the LSM6DSK320X**, so the **LSM6DSK320X** IMU will only function when running **2026.6 or later**.

### How to build the firmware (Betaflight)
1. Clone the [betaflight repository](https://github.com/betaflight/betaflight) using any UNIX terminal (use MSYS2 MINGW64 on Windows) and enter the directory
2. Enter `make configs` (install any required GCC toolchain if asked)
3. Create a directory in betaflight/src/config/configs named `MERLYN435` and paste [config.h](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/tree/main/firmware/source/betaflight/config.h) in the new directory
  - For v2026.6 and later, create a directory in configs named "ANSN" before creating the `MERLYN435` directory inside "ANSN"
4. Enter `make MERLYN435` and the `.hex` file should appear in `betaflight/obj`

### How to build the firmware (iNav)
1. Clone the [iNav repository](https://github.com/iNavFlight/inav) using any UNIX terminal (Building iNav is not supported on Windows) and enter the directory
2. Switch to the latest iNav stable release. E.g. `git checkout 9.1.0`
3. Create two directories. One named `build` in the root directory and another named `MERLYN435` in /src/main/target
4. Copy `CMakeLists.txt`, `target.c` and `target.h` into the `MERLYN435` directory from [/firmware/source/inav](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/tree/main/firmware/source/inav)
5. Enter the `build` directory
6. Enter `cmake ..` (install any required GCC toolchain if asked)
7. Enter `make MERLYN435` and the `.hex` file should appear in `/build`

### Flight Controller Flashing
1. **Via USB DFU Mode (Recommended):** Short the SWD `B` test point to 3.3v and plug in the USB C cable. Open [Betaflight Configurator](https://app.betaflight.com) (applicable for iNav), select your compiled local `.hex` file, and click Flash Firmware.
2. **Via SWD:** If the bootloader is corrupted, connect an ST Link programmer to the `B`, `D` and `C` test points (`R` is optional) and flash the compiled binary with STM32CubeProgrammer.

## ExpressLRS Flashing
The internal ESP8285 ExpressLRS receiver is wired to the AT32 via UART2. It uses the **BETAFPV 2.4GHz Lite RX** firmware target. The firmware binaries can be obtained from the ELRS [site](https://expresslrs.github.io/web-flasher/) or from this repository in [/firmware/binaries](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/blob/main/firmware/binaries/(ExpressLRS)MERLYN435_v4.10_FCC.bin). There are two way to flash the receiver:

### Method 1: Betaflight Passthrough
Note that Betaflight must be installed and configured before passthrough works.
1. Bridge the BOOT pad
<img src="assets/BootBridge.png" width="300">

2. Connect the FC via USB
3. Open the ExpressLRS Configurator [web flasher](https://expresslrs.github.io/web-flasher/) or app
4. Select `Receiver`
5. Select your preferred firmware version and the `BETAFPV 2.4GHz Lite RX` target and press next
6. [OPTIONAL] Enter your bind phrase
7. Select the Betaflight Passthrough flashing method, press next and follow the steps

### Method 2: Manual Flashing
<img src="assets/FTDIWiring.png" width="400">

If the ESP8285 is bricked or passthrough fails, you can flash it directly using an FTDI adapter or another ESP8285/ESP8286/ESP32 or even an Arduino. Bridge `R` to `GND` as well as the BOOT jumper and connect the FTDI TX to RX and FTDI RX to TX


## ESC Flashing
<img src="assets/C2Prog.png" width="550">

The MerlynESC is a 4 in 1 ESC that runs Bluejay firmware target `A`, MCU type `H`, `30`x20.4ns deadtime and `48`KHz PWM frequency. The firmware files can be found in [/firmware/binaries](https://github.com/YeetTheAnson/Merlyn435-Flight-Stack/blob/main/firmware/binaries/(Bluejay)A_H_30_48_v0.21.0.hex) or the official Bluejay repository. You can flash the EFM8BB21 chips using the C2 programming pads with a makeshift arduino programmer.

-----

## Drone Assembly

![image](assets/WiringDiagram.png)

While this project is mainly focused on the Merlyn435 + MerlynESC flight stack, I also designed a high performance 3 inch freestyle FPV drone. If you want to recreate the full build, below is the component breakdown:

### Component List
*   **Frame:** RATE S30 Pro carbon fiber frame
*   **Motors:** RATE 1505 4300KV
*   **Propellers:** HQProp 3x3x3
*   **Camera:** Caddx Ratel 2 analog camera
*   **VTX:** Cyclone 1W analog video transmitter
*   **GPS:** RATE M10 GPS module
*   **Battery:** GNB 4S 850mAh 120C LiHV

### Why 3D Printing the Frame is Not Recommended
I advise against 3D printing your frame. On my previous build, a 100 percent infill PETG frame shattered from a very light fall. More importantly, 3D printed frames flex and resonate which causes excessive gyro noise and leads to deteriorated flight performance. 

<img src="assets/shattered.jpg" width="400">

https://github.com/user-attachments/assets/90db9ad2-082e-437a-b4b3-71ebe933a74a

----

## Bill of Material

Note: The prices in USD are converted as of 22 August 2026 and may fluctuate. Promo codes will be applied before checkout to bring the costs down. And yes, the costs of separate components are cheaper than JLCPCB assembly.

| Category | Item Name | Description | Link | Vendor | Quantity | Total Price (USD) |
|---|---|---|---|---|---:|---:|
| Flight Controller | TAXM8M4RDBCCT2T | 8 MHz crystal | [link](https://www.lcsc.com/product-detail/C400090.html) | LCSC | 5 | 0.73 |
| Flight Controller | 7D027000I01 | 27 MHz crystal | [link](https://www.lcsc.com/product-detail/C648950.html) | LCSC | 5 | 0.47 |
| Flight Controller | XL7EL89CMI-111YLC-26M | 26 MHz crystal | [link](https://www.lcsc.com/product-detail/C19272774.html) | LCSC | 5 | 0.44 |
| Flight Controller | XC21M4-52.000-F10NNHPL | 52 MHz crystal | [link](https://www.lcsc.com/product-detail/C3034316.html) | LCSC | 5 | 0.68 |
| Flight Controller | TYPE-C 16P QTWT | USB C Connector SMT | [link](https://www.lcsc.com/product-detail/C5187472.html) | LCSC | 5 | 0.43 |
| Flight Controller | LMR51420YDDCR | Buck converter | [link](https://www.lcsc.com/product-detail/C5383002.html) | LCSC | 2 | 1.96 |
| Flight Controller | AT7456E | Video overlay OSD | [link](https://www.lcsc.com/product-detail/C82351.html) | LCSC | 2 | 7.49 |
| Flight Controller | SPX3819M5-L-3-3/TR | 3.3v LDO regulator | [link](https://www.lcsc.com/product-detail/C9055.html) | LCSC | 10 | 2.19 |
| Flight Controller | APH0420T4R7M | 4.7uH inductor | [link](https://www.lcsc.com/product-detail/C5349668.html) | LCSC | 5 | 0.45 |
| Flight Controller | USBLC6-2SC6 | USB ESD protection | [link](https://www.lcsc.com/product-detail/C7519.html) | LCSC | 5 | 0.92 |
| Flight Controller | BWU.FL-IPEX1 | U.FL connector | [link](https://www.lcsc.com/product-detail/C5137195.html) | LCSC | 10 | 0.42 |
| Flight Controller | 0402WGF1202TCE | 12k 0402 resistor | [link](https://www.lcsc.com/product-detail/C25752.html) | LCSC | 100 | 0.69 |
| Flight Controller | 0402WGF1501TCE | 1.5k 0402 resistor | [link](https://www.lcsc.com/product-detail/C25867.html) | LCSC | 100 | 0.50 |
| Flight Controller+ESC | CL10A106MA8NRNC | 10uF 0603 capacitor | [link](https://www.lcsc.com/product-detail/C96446.html) | LCSC | 20 | 1.60 |
| Flight Controller | 1206B475K500NT | 4.7uF 1206 capacitor | [link](https://www.lcsc.com/product-detail/C29823.html) | LCSC | 10 | 2.72 |
| Flight Controller | W25Q128JVSIQ | 16MB flash chip | [link](https://www.lcsc.com/product-detail/C97521.html) | LCSC | 2 | 5.22 |
| Flight Controller | HC-1.0-8PWT | JST SH 8p connector | [link](https://www.lcsc.com/product-detail/C2845367.html) | LCSC | 5 | 0.67 |
| Flight Controller | LSM6DSK320XTR | LSM6 series IMU | [link](https://www.lcsc.com/product-detail/C53025794.html) | LCSC | 1 | 9.18 |
| Flight Controller | PCB | PCB | - | JLCPCB | 1 | 7.00 |
| Flight Controller | Partial PCB Assembly | Partial PCB Assembly | - | JLCPCB | 1 | 47.91 |
| ESC | GRM21BR61H106KE43L | 10uF 0805 capacitor | [link](https://www.lcsc.com/product-detail/C440198.html) | LCSC | 5 | 1.25 |
| ESC | CL31A106KBHNNNE | 10uF 1206 capacitor | [link](https://www.lcsc.com/product-detail/C13585.html) | LCSC | 20 | 5.63 |
| ESC | CL05B104KB54PNC | 0.1uF 0402 capacitor | [link](https://www.lcsc.com/product-detail/C307331.html) | LCSC | 100 | 0.93 |
| ESC | CL05A105KA5NQNC | 1uF 0402 capacitor | [link](https://www.lcsc.com/product-detail/C52923.html) | LCSC | 50 | 0.61 |
| ESC | 1SS400CMT2R | SOD923 diode | [link](https://www.lcsc.com/product-detail/C510311.html) | LCSC | 40 | 1.02 |
| ESC | JMSL0302AU | N channel MOSFET | [link](https://www.lcsc.com/product-detail/C2890409.html) | LCSC | 50 | 11.46 |
| ESC | 0402WGF1002TCE | 10k 0402 resistor | [link](https://www.lcsc.com/product-detail/C25744.html) | LCSC | 100 | 0.19 |
| ESC | 0402WGF4701TCE | 4.7k 0402 resistor | [link](https://www.lcsc.com/product-detail/C25900.html) | LCSC | 100 | 0.50 |
| ESC | 0402WGF1001TCE | 1k 0402 resistor | [link](https://www.lcsc.com/product-detail/C11702.html) | LCSC | 100 | 0.67 |
| ESC | 0402WGF100JTCE | 10R 0402 resistor | [link](https://www.lcsc.com/product-detail/C25077.html) | LCSC | 100 | 0.58 |
| ESC | HoYLR2512E-3W-0.5mR-1% | 0.5mR 2512 shunt resistor | [link](https://www.lcsc.com/product-detail/C5375456.html) | LCSC | 10 | 0.60 |
| ESC | 0402WGF3902TCE | 39k 0402 resistor | [link](https://www.lcsc.com/product-detail/C25783.html) | LCSC | 100 | 0.69 |
| ESC | HT75C0-1 | 12v LDO regulator | [link](https://www.lcsc.com/product-detail/C64551.html) | LCSC | 5 | 0.99 |
| ESC | HT7533-1 | 3.3v LDO regulator | [link](https://www.lcsc.com/product-detail/C14289.html) | LCSC | 5 | 0.71 |
| ESC | EFM8BB21F16G-C-QFN20R | ESC MCU | [link](https://www.lcsc.com/product-detail/C80713.html) | LCSC | 8 | 10.01 |
| ESC | EG6288 | Gate driver | [link](https://www.lcsc.com/product-detail/C55058511.html) | LCSC | 10 | 3.06 |
| ESC | INA139NA/3K | Current sensor | [link](https://www.lcsc.com/product-detail/C129947.html) | LCSC | 2 | 1.12 |
| ESC | PCB | PCB | - | JLCPCB | 1 | 2.00 |
| Flight Controller + ESC | Shipping | EPOST shipping | - | JLCPCB | 1 | 6.49 |
| Flight Controller + ESC | Shipping | LCSC | - | LCSC | 1 | 4.92 |
| Drone Parts | RATE 1505 4300kv motor | Motors | [link](https://click.world.taobao.com/_b.RcEIyQ) | TaoBao | 4 | 28.75 |
| Drone Parts | RATE S30 Pro frame | Carbon fiber frame | [link](https://click.world.taobao.com/_b.6cEImS) | TaoBao | 1 | 23.06 |
| Drone Parts | RATE analog antenna | Right hand circular polarized 5.8GHz antenna | [link](https://click.world.taobao.com/_b.ecEImU) | TaoBao | 1 | 5.80 |
| Drone Parts | RATE 90mm ELRS antenna | Linear polarized dipole 2.4GHz antenna | [link](https://click.world.taobao.com/_b.3cEIO4) | TaoBao | 1 | 0.95 |
| Drone Parts | RATE beeper/buzzer | Active piezo buzzer | [link](https://click.world.taobao.com/_b.VcEIzD) | TaoBao | 1 | 0.64 |
| Drone Parts | HQPROP T3x3x3 | 2 Pairs 3 inch propeller | [link](https://click.world.taobao.com/_b.0cEJ5z) | TaoBao | 1 | 1.88 |
| Drone Parts | RATE XT30 + Cable | Connector and cable | [link](https://click.world.taobao.com/_b.acEJqe) | TaoBao | 1 | 0.64 |
| Drone Parts | RATE Rubber Grommets | 10pcs soft mounting rubber grommet | [link](https://click.world.taobao.com/_b.KcEIzp) | TaoBao | 1 | 0.48 |
| Drone Parts | RATE M10 GPS | Nano size gps module with battery | [link](https://click.world.taobao.com/_b.tcEIm7) | TaoBao | 1 | 8.80 |
| Drone Parts | 470uF low ESR capacitor | Capacitor for MOSFET protection | [link](https://click.world.taobao.com/_b.ecEuQ7) | TaoBao | 1 | 0.42 |
| Drone Parts | Cyclone 1W VTX | 5.8GHz analog video transmitter | [link](https://click.world.taobao.com/_b.zcEIzr) | TaoBao | 1 | 14.00 |
| Drone Parts | TaoBao Tax | Fees | - | TaoBao | 1 | 10.05 |
| Drone Parts | TaoBao Shipping | Shipping | - | TaoBao | 1 | 4.05 |
| Drone Parts | CADDX Ratel 2 + Tax | 19mm Analog camera | [link](https://www.aliexpress.com/item/1005009304280288.html) | AliExpress | 1 | 28.64 |
| Drone Parts | AliExpress Shipping | Shipping | - | AliExpress | 1 | 0.99 |
| Drone Parts | GNB LiHV 4S 850mAh | 4S LiHV battery | [link](https://shopee.com.my/Gaoneng-GNB-15.2HV-850mAh-120C-4S-Lipo-Battery-with-XT30-Plug-GNB850-120-4S-i.92575144.18545880487) | Shopee | 1 | 20.10 |

- **Flight Controller Total:** \$91.67
- **ESC Total:** \$42.02
- **Shipping Total:** \$26.50
- **Drone Parts Total:** \$134.16 
### **Grand Total:** \$294.35
