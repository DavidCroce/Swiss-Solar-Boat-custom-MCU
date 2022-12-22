# Swiss-Solar-Boat-custom-MCU

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

## Example
<details>
```cpp
CANSAME5x can;
int dlc = can._parsePacket();
if (dlc > 0) {
  // Packet was successfully parsed
} else {
  // No packet was available
}```
</details>
