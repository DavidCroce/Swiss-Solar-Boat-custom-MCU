# Miscellanious Information

This section contains information (links, tips) about arduino variants and the same51 microcontroller that were useful when creating the package. It might useful for someone looking to make changes to the package or just trying to understand weird quirks of the microcontroller.

## Content

- [Pins, Pads and Ports](#digital-ports)
    - [The Signals Multiplexing Table](#signal-multiplexing-table)
    - [Arduino Variants](#arduino-variants)
    - [Digital Pins](#digital-pins)
    - [PORT module](#port-module)
- [ADC](#ADC)
- [Sercom](#sercom)
    - [SPI](#spi)
    - [I2C](#i2c)
- [CAN](#can)
- [SD card](#sd-card)
- [PWM](#pwm)
- [Timers](#timers)

## Digital Ports

Information about ports

### Arduino Variants

To understand how the variant file is used by the arduino library Right-click -> Go to definition and Right-click -> Go to References might the single most useful features of Vscode. The following [link](https://www.instructables.com/Arduino-IDE-Creating-Custom-Boards/) is a good explanation on how to create an arduino package.

## ADC

Adding ADC0 or ADC1 pins to the variant file is pretty straightforward and looks like this. 
```
{ PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },
```
The only difference between the two ADC's is in the pin_attr field. For ADC0 the attribute is **PIN_ATTR_ANALOG** while for ADC1 it is named **PIN_ATTR_ANALOG_ALT**, this attribute is checked in the arduino analogRead() function.

If some analog pins always read the same value it might be due the arduino analogRead() function (if the package is up to date this shouldn't be the case). If the function starts with lines like #ifdef PIN_A6, etc remove them, they shouldn't be there.

## Sercom

When looking at the multiplexing table in the datasheet be sure to check out *6.2.6 SERCOM I2C Configuration* about IOSET's. It turns out that for a given SERCOM the different pads can only accessed by specific groups of pins. If two pins are connected to the right pads of the SERCOM, they might still not work together for this reason. But sometimes it [works](https://forums.adafruit.com/viewtopic.php?f=19&p=878131) so it might be worth a try.
Another important part of the datasheet is *1. Configuration Summary* which tells you what modules are present in the different atsamx5 models.


### SPI

### I2C

To set up multiple I2C in the Arduino variants, you need to change WIRE_INTERFACES_COUNT in variant.h and add the right defines for the new Wire object. It's probably clearer if you look at how WIRE_INTERFACES_COUNT is used in the Wire.cc module.

## CAN

Even though it doesn't seem to be clearly stated in the datasheet, the pins TX and RX should be set to OUTPUT and INPUT respectively. If Rx is set to OUTPUT the controller won't work correctly. The CANSAME5x library has been modified so that this is done in begin() function.

When debugging the can controller the CTRL and PSR register are especially interesting.

For the variants you just have to define a variant line for CAN0(1)_RX/TX, as long as the pin and port field are correct the other fields don't matter (in the example only PORTA and 22 matter)
```
{ PORTA, 22, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
```

## SD card

## PWM

## Timers

