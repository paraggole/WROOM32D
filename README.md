# ESP32-WROOM-32 PCB Design: Compact and Efficient ESP32-based PCB with USB-C Power & LiPo Charging  

## Overview  
This PCB design integrates **ESP32-WROOM-32, AMS1117-3.3V, CH340G USB-to-UART, MPU6050 (Accelerometer/Gyro), and a TP4056 LiPo charging module** to create a compact, functional, and manufacturable solution. The design ensures efficient **power management, seamless USB-C/LiPo switching, and debugging capabilities** for ease of use.  

## Features  
- **ESP32-WROOM-32 microcontroller** with Wi-Fi and Bluetooth capabilities.  
- **USB-C interface** for both power and data (UART flashing via CH340G).  
- **Automatic power switching** between USB-C and LiPo battery using **AO3401A P-MOSFET**.  
- **TP4056 LiPo charger** for safe battery charging when USB is connected.  
- **AMS1117-3.3V regulator** for stable ESP32 power supply.  
- **MPU6050 sensor (I2C interface)** for motion sensing.  
- **Auto-programming circuit** for ESP32 flashing (CH340G + DTR/RTS circuit).  
- **Test points** for power monitoring, UART debugging, and I2C signals.  
- **Reverse polarity and overcurrent protection** for safe operation.  

## Role of Each Component  

### 1. ESP32-WROOM-32 (Main Microcontroller)  
The ESP32-WROOM-32 is the heart of this PCB. It provides:  
- **Wi-Fi & Bluetooth connectivity** for IoT applications.  
- **Multiple GPIOs** for sensors and peripherals.  
- **UART interface** for programming and debugging.  
- **Low-power modes** for energy efficiency.  

### 2. AMS1117-3.3V (Voltage Regulator)  
The AMS1117-3.3V LDO (Low Dropout Regulator) is used to regulate voltage:  
- Converts **USB 5V or LiPo 4.2V max** to **3.3V** required by ESP32.  
- Provides **stable power** under varying loads.  
- Requires **proper heat dissipation** (vias included).  

### 3. CH340G (USB-to-UART Bridge)  
The CH340G facilitates serial communication between the **ESP32 and a PC**:  
- Converts **USB-C signals** into UART signals for programming/debugging.  
- Handles **DTR/RTS auto-reset circuit**, enabling **flashing without button presses**.  

### 4. TP4056 (LiPo Charging Module)  
The TP4056 ensures **safe charging of a single LiPo cell**:  
- Charges LiPo battery from **USB-C power**.  
- **Built-in overcharge & overcurrent protection**.  
- **Charge/Standby status indicator (LED output)**.  

### 5. AO3401A (P-Channel MOSFET for Power Switching)  
The AO3401A acts as an **automatic power switch**:  
- **When USB is connected** → ESP32 runs on **USB power** + LiPo **charges**.  
- **When USB is disconnected** → ESP32 runs on **LiPo battery**.  
- **Schottky diode + MOSFET** prevent reverse current flow.  

### 6. MPU6050 (Accelerometer + Gyroscope)  
The MPU6050 is an **I2C-based sensor** used for motion sensing:  
- Measures **acceleration & angular velocity**.  
- Used for **gesture recognition, stabilization, and IMU applications**.  

### 7. Passive Components (Resistors, Capacitors, Test Points)  
- **Decoupling capacitors (10µF, 100nF)** near AMS1117 and ESP32 for **stability**.  
- **Pull-up resistors (10kΩ, 100kΩ)** for MOSFET gate control.  
- **Test points** for easy **voltage and signal monitoring**.  

## Schematic Overview  
The schematic includes:  
- **ESP32-WROOM-32** (Main microcontroller).  
- **CH340G USB-to-UART bridge** (for programming).  
- **TP4056 LiPo charger** (Handles battery charging from USB-C).  
- **AO3401A P-MOSFET for power switching** (Automatically selects USB/LiPo).  
- **AMS1117-3.3V regulator** (Supplies ESP32 from USB or battery).  
- **MPU6050 accelerometer/gyro** (I2C interface).  
- **Auto-program circuit** (DTR/RTS control for ESP32 flashing).  

## Power Management & Switching  
- **USB-C 5V Power**: Powers ESP32 & charges the LiPo battery.  
- **LiPo Battery (3.7V-4.2V)**: Supplies power when USB is **not** connected.  
- **Automatic Switching**:  
  - If **USB is connected**, ESP32 runs on **USB power**, and LiPo **charges**.  
  - If **USB is disconnected**, ESP32 runs on **battery power**.  
  - **AO3401A MOSFET + Schottky diode** ensure smooth transition.  

## UART & Programming Circuit  
- **CH340G USB-to-UART** allows ESP32 programming over USB-C.  
- **DTR/RTS auto-program circuit** (with **2N7002 transistors** for level shifting).  
- **TX/RX test points included** for debugging.  

## PCB Layout Considerations  
- **2-layer PCB with optimal trace routing**.  
- **Power and ground planes properly separated** to minimize noise.  
- **Wide traces for high-current paths (AMS1117, TP4056, LiPo connections).**  
- **Decoupling capacitors (10µF & 100nF) placed near AMS1117 and ESP32 for stability.**  
- **Test points added for TX, RX, I2C, and power signals for debugging.**  
- **vias included under AMS1117 and TP4056 for heat dissipation.**  

## Getting Started  

### 1. Setting Up the Board  
1. **Connect USB-C cable** to power the board and enable UART.  
2. **If no USB is connected**, ensure **LiPo battery is attached**.  
3. **Use a serial monitor** (115200 baud) to check ESP32 boot logs.  

### 2. Flashing the ESP32  
- **Automatic flashing via CH340G** (No need to press BOOT/RESET manually).  
- **Use ESP-IDF or Arduino IDE** with correct ESP32-WROOM-32 settings.  

### 3. Debugging Tips  
- Check **TX/RX test points** for serial communication issues.  
- Measure **test points** to verify correct power switching.  
- If programming fails, check **DTR/RTS signal** from CH340G.  

## Support & Contributions  
Found a bug or have improvements? Open an **Issue** or a **Pull Request** on GitHub.  

Contact: [Your Email]  

Designed for ESP32 projects.  
