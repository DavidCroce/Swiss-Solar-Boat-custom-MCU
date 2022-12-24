# Swiss-Solar-Boat-custom-MCU

# Programming the V2.2 Microcontroller

# Programming the V2.2 Microcontroller

## Content

- [Setup](#setup)
- [Pin mapping](#pin-mapping)
- [Using the CAN bus](#using-the-can-bus)
- [Using the I2C interface](#using-the-i2c-interface)
- [Using the on-board SD card](#using-the-on-board-sd-card)
## Setup

Instructions on setting up the V2.2 Microcontroller for programming.

## Pin mapping



| Pin on Shield  | Arduino Pin Name    | Function               |
|----------------|---------------------|------------------------|
| SERIAL1_RX     | PIN_SERIAL1_RX      | RX for Serial1         |
| SERIAL1_TX     | PIN_SERIAL1_TX      | TX for Serial1         |
| ADC0_0         | PIN0_ADC0           | Analog Pin 0 on ADC0   |
| ADC0_1         | PIN1_ADC0           | Analog Pin 1 on ADC0   |
| ADC0_2         | PIN2_ADC0           | Analog Pin 2 on ADC0   |
| ADC0_3         | PIN3_ADC0           | Analog Pin 3 on ADC0   |
|                | PA04                | Digital Pin with PWM   |
| ADC0_4         | PIN4_ADC0           | Analog Pin 4 on ADC0   |
|                | PB01                | Digital Pin with PWM   |
|                | PB02                | Digital Pin with PWM   |
|                | PB03                | Digital Pin with PWM   |
| ADC1_0         | PIN0_ADC1           | Analog Pin 0 on ADC1   |
|                | PB05                | Digital Pin with PWM   |
| ADC1_1         | PIN1_ADC1           | Analog Pin 1 on ADC1   |
| ADC1_2         | PIN2_ADC1           | Analog Pin 2 on ADC1   |
| ADC1_3         | PIN3_ADC1           | Analog Pin 3 on ADC1   |
|                | PB08                | Digital Pin with PWM   |
|                | PB09                | Digital Pin with PWM   |
| SDA0           | SDA0                | I2C SDA Pin 0          |
| SCL0           | SCL0                | I2C SCL Pin 0          |
| SDA1           | SDA1                | I2C SDA Pin 1          |
|                | PA12                | Digital Pin with PWM   |
| SCL1           | SCL1                | I2C SCL Pin 1          |
|                | PA13                | Digital Pin with PWM   |
| MISO           | PIN_SPI_MISO        | SPI MISO Pin           |
| MOSI           | PIN_SPI_MOSI        | SPI MOSI Pin           |
| SCK            | PIN_SPI_SCK         | SPI SCK Pin            |
|                | PA17                | Digital Pin with PWM   |
| USB_HOST_ENABLE | USB_HOST_ENABLE    | Not used               |
| USB_DM          | USB_DM             | USB DM Pin             |
| USB_DP          | USB_DP             | USB DP Pin             |
| AREF            | AREF               | AREF Pin               |
| DAC0            | DAC0               | DAC0 Pin               |
| DAC1            | DAC1               | DAC1 Pin               |
| ENUM_QSPI_SCK   | ENUM_QSPI_SCK      | QSPI SCK Pin           |
| ENUM_CS         | ENUM_CS            | QSPI CS Pin            |
| IO0             | IO0                | QSPI IO0 Pin           |
| IO1             | IO1                | QSPI IO1 Pin           |
| IO2             | IO2                | QSPI IO2 Pin           |
| IO3             | IO3                | QSPI IO3 Pin           |
| CAN0_TX         | PIN_CAN0_TX        | TX for CAN0 controller  |
|                 | PA22               | Digital Pin with PWM  |
| CAN0_RX         | PIN_CAN0_RX        | RX for CAN0 controller  |
|                 | PA23               | Digital Pin with PWM  |
| CAN1_TX         | PIN_CAN1_TX        | TX for CAN1 controller  |
| CAN1_RX         | PIN_CAN1_RX        | RX for CAN1 controller  |
|                 | PA15               | Digital Pin with PWM  |
| PA02            | PA02               | Digital Pin       |
|                 |                    | also DAC0         |
| PA03            | PA03               | Digital Pin       |
|                 |                    | also AREF         |
| PA04            | PA04               | Digital Pin with PWM |
| PA05            | PA05               | Digital Pin with PWM |
|                 |                    | also DAC1         |
| PA12            | PA12               | Digital Pin with PWM |
|                 |                    | also SDA1         |
| PA13            | PA13               | Digital Pin with PWM |
|                 |                    | also SCL1         |
| PA16            | PA16               | Digital Pin with PWM |
|                 |                    | also SDA0         |
| PA17            | PA17               | Digital Pin with PWM




Regenerate response

Information about the pin mapping of the V2.2 Microcontroller.

## Using the CAN bus

Instructions for using the CAN bus on the V2.2 Microcontroller.

## Using the I2C interface

Instructions for using the I2C interface on the V2.2 Microcontroller.

## Using the on-board SD card

Instructions for using the on-board SD card on the V2.2 Microcontroller.---

# `int CANSAME5x::_parsePacket()`

Parses a received packet of data from the hardware module.

## Parameters

None.

## Return value

- If a packet was successfully parsed: the data length code (`DLC`) of the received message.
- If no packet was available: 0.

## Description

This function is a member function of the `CANSAME5x` class and is used to parse a packet of data received by the hardware module. 

If a packet is available, the function extracts the identifier, data length code, and data payload of the message, and stores them in the corresponding member variables of the `CANSAME5x` object. The function also updates a hardware register to indicate that the message has been processed.

<details>
<summary><h3>Example</h3></summary>

```cpp
CANSAME5x can;
int dlc = can._parsePacket();
if (dlc > 0) {
  // Packet was successfully parsed
} else {
  // No packet was available
}
```
</details>
