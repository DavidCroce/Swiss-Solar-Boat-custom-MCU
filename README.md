# Swiss-Solar-Boat-custom-MCU

# Programming the V2.2 Microcontroller

### Content

- [Setup](#setup)
- [Pin mapping](#pin-mapping)
- [Using the CAN bus](#using-the-can-bus)
- [Using the I2C interface](#using-the-i2c-interface)
- [Using the on-board SD card](#using-the-on-board-sd-card)

#### Setup

Instructions for setting up the V2.2 Microcontroller for programming.

### Pin mapping

Information about the pin mapping of the V2.2 Microcontroller.

#### Using the CAN bus

Instructions for using the CAN bus on the V2.2 Microcontroller.

#### Using the I2C interface

Instructions for using the I2C interface on the V2.2 Microcontroller.

#### Using the on-board SD card

Instructions for using the on-board SD card on the V2.2 Microcontroller.




---

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
