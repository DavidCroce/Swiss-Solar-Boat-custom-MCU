# Programming the V2.2 Microcontroller

## Content

- [Setup](#setup)
- [Pin mapping](#pin-mapping)
- [Using the CAN module](#using-the-can-module)
- [Using the I2C interface](#using-the-i2c-interface)
- [Using the on-board SD card](#using-the-on-board-sd-card)
- [Other Information](#other-information)

## Setup

1. **Install** Arduino IDE on your device
2. Go into Arduino IDE's **Settings** and in the **Additional boards manager URLs** field, add the following url:
```
https://raw.githubusercontent.com/JohnTomasTaylor/Swiss-Solar-Boat-custom-MCU/main/package_SSB_index.json
```
3. Go into **Board Manager** (should be under Tools -> Boards -> Board Manager) and install the **Swiss Solar Boat Custom MCU Boards** Package
4. **Install** the platformio extension for VSCode 
5. You should now be able to choose the SSB custom board in your projects, either by choosing it when creating a new project or by going into the **platformio.ini** file and changing the board field to **SSB Custom MCU**

## Pin mapping

The microcontroller v2.2 has multiple pins that can be used for different purposes. These purposes are represented by the different names that each pin can be referred to in Arduino code. For example, the pin PA05 can be referred to as PA05 to use it as a digital pin, DAC0 to use it as the DAC0's output, or PIN2_ADC0 to use it as an input to the ADC of the microcontroller. If you are unsure of a pin's purpose while programming, you can hover over the pin in VSCode to see a tooltip with its function and aliases.

| Pin on Shield | Arduino Pin Name | Function |
| ------------- | ---------------- | -------- |
| PB17          | PIN_SERIAL1_RX   |          |
| PB16          | PIN_SERIAL1_TX   |          |
| PA02          | PIN0_ADC0        |          |
|               | DAC0             |          |
|               | PA02             |          |
| PA03          | PIN1_ADC0        |          |
|               | AREF             |          |
|               | PA03             |          |
| PA05          | PIN2_ADC0        |          |
|               | DAC1             |          |
|               | PA05             |          |
| PA04          | PIN3_ADC0        |          |
|               | PA04             |          |
| PB00          | PIN4_ADC0        |          |
|               | PB00             |          |
| PB01          | PIN5_ADC0        |          |
|               | PB01             |          |
| PB02          | PIN6_ADC0        |          |
|               | PB02             |          |
| PB03          | PIN7_ADC0        |          |
|               | PB03             |          |
| PB04          | PIN0_ADC1        |          |
|               | PB04             |          |
| PB05          | PIN1_ADC1        |          |
|               | PB05             |          |
| PB06          | PIN2_ADC1        |          |
|               | PB06             |          |
| PB07          | PIN3_ADC1        |          |
|               | PB07             |          |
| PB08          | PIN4_ADC1        |          |
|               | PB08             |          |
| PB09          | PIN5_ADC1        |          |
|               | PB09             |          |
| PA16          | SDA0             |          |
|               | PA16             |          |
| PA17          | SCL0             |          |
|               | SCK              |          |
|               | PA17             |          |
| PA12          | SDA1             |          |
|               | PA12             |          |
| PA13          | SCL1             |          |
|               | PA13             |          |
| PB22          | MISO             |          |
|               | PB22             |          |
| PB23          | MOSI             |          |
|               | PB23             |          |
| PA00          | USB_HOST_ENABLE  |          |
| PA24          | USB_DM           |          |
| PA27          | USB_DP           |          |
|               | PA27             |          |
| PB11          | ENUM_QSPI_SCK    |          |
| PA08          | ENUM_CS          |          |
| PA09          | IO0              |          |
| PA10          | IO1              |          |
| PA11          | IO2              |          |
| PB10          | IO3              |          |
| PA22          | PIN_CAN0_TX      |          |
|               | PA22             |          |
| PA23          | PIN_CAN0_RX      |          |
|               | PA23             |          |
| PB14          | PIN_CAN1_TX      |          |
|               | PB14             |          |
| PB15          | PIN_CAN1_RX      |          |
|               | PB15             |          |
| PA18          | PA18             |          |
| PA19          | PA19             |          |
| PB30          | PB30             |          |
| PB31          | PB31             |          |


## Using the CAN module

The arduino package for the microcontroller 2.2 uses a CAN library named CANSAME5x. For more information you can browse its [documentation](CANSAME5x-Documentation.md).

### Examples
#### Initializing the can module and sending data over the can bus

```cpp
#include <Arduino.h>
#include <CANSAME5x>

CANSAME5x can0 = CANSAME5x(PIN_CAN0_TX, PIN_CAN0_RX);
// for can1:
// CANSAME5x can1 = CANSAME5x(PIN_CAN1_TX, PIN_CAN1_RX);

void setup()
{
    //initialize can module with a baudrate of 10000
    can0.begin(10000)
}

void loop() {
    // begin a standard packet with an ID of 0x1 and data of 0x0332
    can0.beginPacket(0x1);
    can0.write(0x32);
    can0.write(0X03);
    can0.endPacket();
}
```


## Using the I2C interface

The microcontroller is equipped with two I2C buses, to use them you have to import the arduino library **Wire.h**. Each I2C bus is represented by a class instance in the code, **Wire** is the instance for SDA0/SCL0 while **Wire1** is the one for SDA1/SCL1. For more information check out the [Arduino documentation](https://www.arduino.cc/reference/en/language/functions/communication/wire/)

## Using the on-board SD card

Instructions for using the on-board SD card on the V2.2 Microcontroller.

## Other Information

If you need more information about how the package was made or about the same51, you might find it in the [miscellanious information](#Miscellanious-Information.md) page
