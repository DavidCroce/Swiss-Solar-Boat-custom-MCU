# **Disclaimer!!!** this document is a WIP so the example code and function descriptions might be incomplete or plain wrong!

# `Index`

- [`int CANSAME5x::begin(long baudrate)`](#int-cansame5xbeginlong-baudrate)
- [`void CANSAME5x::end()`](#void-cansame5xend)
- [`int CANSAME5x::beginPacket(int id, int dlc = -1, bool rtr = false)`](#int-cansame5xbeginpacketint-id-int-dlc---1-bool-rtr--false)
- [`size_t CANSAME5x::write(uint8_t byte)`](#size_t-cansame5xwriteuint8_t-byte)
- [`size_t CANSAME5x::write(const uint8_t *buffer, size_t size)`](#size_t-cansame5xwriteconst-uint8_t-buffer-size_t-size)
- [`int CANSAME5x::endPacket()`](#endPacket)
- [`int CANSAME5x::parsePacket()`](#int-cansame5xparsepacket)
- [`void CANSAME5x::onReceive(void (*callback)(int))`](#void-cansame5xonreceivevoid-callbackint)
- [`void CANSAME5x::handleInterrupt()`](#void-cansame5xhandleinterrupt)
- [`int CANSAME5x::filter(int id, int mask)`](#int-cansame5xfilterint-id-int-mask)
- [`int CANSAME5x::filterExtended(long id, long mask)`](#int-cansame5xfilterextendedlong-id-long-mask)
- [`int CANSAME5x::observe()`](#int-cansame5xobserve)
- [`int CANSAME5x::loopback()`](#int-cansame5xloopback)
- [`int CANSAME5x::sleep()`](#int-cansame5xsleep)
- [`int CANSAME5x::wakeup()`](#int-cansame5xwakeup)
- [`int CANSAME5x::available()`](#int-cansame5xavailable)
- [`int CANSAME5x::read()`](#int-cansame5xread)
- [`int CANSAME5x::peek()`](#int-cansame5xpeek)
- [`void CANSAME5x::flush()`](#void-cansame5xflush)


## `int CANSAME5x::begin(long baudrate)`

This function initializes the CAN functionality of the microcontroller. It configures the transmit and receive buffers, sets up the acceptance filter, and enables the CAN controller.

## Parameters
- `baudrate`: The communication speed of the CAN bus, specified in bits per second.

## Return value
- Returns 1 if the initialization was successful, or 0 if it failed.

<details> <summary>Example usage</summary>

```cpp
CANSAME5x can0;

if (can0.begin(500000)) {
  // CAN initialization successful
} else {
  // CAN initialization failed
}
```

</details>
<br>
<br>

## `void CANSAME5x::end()` 

This function disables the CAN functionality of the microcontroller and resets the transmit and receive buffers. It also disables the CAN controller and clears the CAN interrupt.

## Parameters
- None.

## Return value
- None.
<br>
<br>

## `int CANSAME5x::beginPacket(int id, int dlc = -1, bool rtr = false)`

Starts a new packet with the specified identifier, data length, and remote transmission request flag.

## Parameters

- `id`: The identifier of the packet. This must be an integer between 0 and 0x7FF.
- `dlc`: The data length of the packet, in bytes. This must be an integer between 0 and 8. If this parameter is not specified, the default value is -1, which means that the data length will be determined by the write() function.
- `rtr`: The remote transmission request flag. If this flag is set to true, the packet will be a remote transmission request packet. Otherwise, it will be a data packet. The default value is false.

## Return value

1 if the packet was successfully started, 0 otherwise.

## Description

This function is used to start a new packet with the specified identifier, data length, and remote transmission request flag. It sets the internal state variables of the object and clears the data buffer.

## Example
```cpp
CANControllerClass can;
can.beginPacket(0x123, 8, true);
```

## `size_t CANSAME5x::write(uint8_t byte)`

Writes a single byte to the current packet being transmitted.

## Parameters

- `byte`: the byte to be written to the packet.

## Return value

The number of bytes written, which is always 1 if the packet has been begun, 0 otherwise.

## Description

This function is used to write a single byte to the current packet being transmitted over the CAN bus. It is a wrapper for the write(const uint8_t *buffer, size_t size) function, which is used to write a block of data to the packet.

## Example
```cpp
CANControllerClass can;
can.beginPacket(0x123);
can.write(0x01);
can.write(0x02);
can.endPacket();
```




## `size_t CANSAME5x::write(const uint8_t *buffer, size_t size)`

Appends data to the current packet being transmitted.

## Parameters

- `buffer`: A pointer to the buffer containing the data to be appended to the packet.
- `size`: The number of bytes of data to be appended to the packet.

## Return value

The number of bytes of data that were actually appended to the packet. This may be less than the `size` parameter if there is not enough space in the packet buffer to fit the entire data.

## Description

This function is used to append data to the current packet being transmitted by the CAN controller. It copies the data from the `buffer` parameter into the internal packet buffer, up to the specified number of bytes or until the packet buffer is full, whichever comes first.

## Example

```cpp
CANSAME5x can;
can.beginPacket(0x123);
uint8_t data[5] = {1, 2, 3, 4, 5};
can.write(data, 5);
can.endPacket();
```



## `int CANSAME5x::endPacket()`

This function finalizes the construction of a CAN message and sends it over the CAN bus. It waits for the transmit buffer to become available, copies the message data and metadata into the buffer, and initiates the transmission of the message.

## Parameters
None.

## Return value
- Returns 1 if the transmission was successful, or 0 if it failed.

<details> 
<summary>Example usage</summary>

```cpp
CANSAME5x can0;

can0.begin(10000);

// Build up packet data with beginTransmission() and write() function
can0.beginTransmission(0x1);
can0.write(0xFF);

if (can0.endPacket()) {
  // Packet transmitted successfully
} else {
  // Packet transmission failed
}
```

</details>
<br>
<br>


## `int CANSAME5x::parsePacket()`

Parses a received packet of data from the hardware module, with additional functionality for error recovery and debugging.

## Parameters

None.

## Return value

- If a packet was successfully parsed: the data length code (`DLC`) of the received message.
- If no packet was available: 0.

## Description

This function is used to parse a packet of data received by the CAN controller. The different parts of the packet can then be accessed using `CANSAME5x`'s getter functions such as ```read(), packetId(), packetDlc()...```

## Example
<details>
<summary>Show example</summary>

```cpp
int dlc = can.parsePacket();
if (dlc > 0) {
  // Packet was successfully parsed
} else {
  // No packet was available
}
```

</details>
<br>
<br>

## `void CANSAME5x::onReceive(void (*callback)(int))`

Sets a callback function to be called when a message is received on the CAN bus.

## Parameters

- `callback`: A function pointer to the callback function. The function should take a single `int` parameter, which will be the identifier of the received message.

## Return value

None.

## Description

This function is a member function of the `CANSAME5x` class and is used to set a callback function that will be called whenever a message is received on the CAN bus. The function is passed a function pointer to the callback function as an argument.

The callback function should take a single `int` parameter, which will be the identifier of the received message.

If a callback function is provided, the function will also enable hardware interrupts for the CAN bus. If no callback function is provided (i.e. `callback` is `nullptr`), the function will disable hardware interrupts for the CAN bus.

## Example
<details>
<summary>Show example</summary>

```cpp
#include <CANSAME5x.h>

void messageReceived(int id) {
  // Handle received message with identifier `id`
}

int main() {
  CANSAME5x can;
  can.onReceive(messageReceived);
  return 0;
}
```
</details>
<br>
<br>

## `void CANSAME5x::handleInterrupt()`

Handles a hardware interrupt for the CAN bus.

## Parameters

None.

## Return value

None.

## Description

This function is a member function of the `CANSAME5x` class and is used to handle a hardware interrupt for the CAN bus. When a hardware interrupt is received, the function checks the cause of the interrupt and processes it accordingly.

In particular, if the interrupt is due to a received message, the function calls the `parsePacket` function to extract the message and pass it to the callback function that was previously set using the `onReceive` function.

## Example
<details>
<summary>Show example</summary>

```cpp
#include <CANSAME5x.h>

void messageReceived(int id) {
  // Handle received message with identifier `id`
}

int main() {
  CANSAME5x can;
  can.onReceive(messageReceived);

  while (true) {
    if (can.handleInterrupt()) {
      // Interrupt was handled
    } else {
      // No interrupt was pending
    }
  }

  return 0;
}
```
</details>
<br>
<br>


## `int CANSAME5x::filter(int id, int mask)`

Sets up a filter for standard (11-bit) CAN messages.

## Parameters

- `id`: the identifier of the message to be accepted or rejected by the filter.
- `mask`: the mask to be applied to the identifier. A bit value of 1 indicates that the corresponding bit in the identifier should be ignored, while a bit value of 0 indicates that the corresponding bit in the identifier must match the corresponding bit in the filter.

## Return value

Always returns 1.

## Description

This function is a member function of the `CANSAME5x` class and is used to configure a hardware filter for the CAN bus. The filter determines which messages are accepted or rejected by the hardware, based on their identifiers and the mask applied to the identifiers.

In this particular implementation, the filter is configured to accept standard messages with identifiers matching the specified `id` and `mask`, and to reject all extended messages.

## Example
<details>
<summary>Show example</summary>

```cpp
#include <CANSAME5x.h>

int main() {
  CANSAME5x can;
  can.filter(0x123, 0x7FF);

  while (true) {
    // Only messages with identifiers between 0x123 and 0x123 + 0x7FF will be received by the CAN bus
  }

  return 0;
}
```
</details>
<br>
<br>

## `int CANSAME5x::filterExtended(long id, long mask)`

Sets up a filter for extended (29-bit) CAN messages.

## Parameters

- `id`: The identifier of the message to filter for.
- `mask`:  A bitmask used to match against the id parameter. A bit is considered a match if it is set to 1 in both the id and mask parameters.

## Return value

Always returns 1.

## Description

This function is a member function of the CANSAME5x class and is used to configure a hardware filter for extended (29-bit) CAN messages. When a filter is set up, the hardware module will only receive and process messages with a matching identifier.

The `id` and `mask` parameters are used to specify the identifier and mask values for the filter. The identifier value is a 29-bit integer that represents the unique identifier of the message to filter for. The mask value is a bitmask that is applied to the identifier value. A bit is considered a match if it is set to 1 in both the id and mask parameters.

By default, this function rejects all standard (11-bit) CAN messages.

<details>
<summary>Example</summary>

```cpp
CANSAME5x can;
can.filterExtended(0x12345678, 0x1FFFFFFF); // Filter for extended messages with identifier 0x12345678
```
</details>
<br>
<br>


## `int CANSAME5x::observe()`

Puts the CAN controller into "observer" mode, which allows it to receive messages without transmitting any.

## Parameters

None.

## Return value

1.

## Description

This function is a member function of the CANSAME5x class and is used to enable the "observe" mode for the CAN Controller. In this mode, the hardware module functions as a passive listener on the bus and does not transmit any messages.

<details>
<summary>## Example</summary>

```cpp
CANSAME5x can;
can.observe();
```
</details>
<br>
<br>

## `int CANSAME5x::loopback()`

Enables loopback mode for testing on the hardware module.

## Parameters

None.

## Return value

1 if the operation was successful, 0 otherwise.

## Description

This function is a member function of the `CANSAME5x` class and is used to enable loopback mode on the hardware module. 

In loopback mode, transmitted messages are looped back and can be received by the same device that transmitted them. This is useful for testing the device's transmit and receive capabilities without actually transmitting messages over the CAN bus.

## Example
<details>
<summary>Example</summary>

```cpp
CANSAME5x can;
int result = can.loopback();
if (result == 1) {
  // Loopback mode was successfully enabled
} else {
  // An error occurred while enabling loopback mode
}
```
</details>
<br>
<br>


## `int CANSAME5x::sleep()`

Puts the CAN controller in sleep mode.

## Parameters

None.

## Return value

1

## Description

This function is a member function of the `CANSAME5x` class and is used to put the CAN controller in sleep mode. It sets the sleep request bit in the `CCCR` register and waits for the sleep acknowledge bit in the `CCCR` register to be set. It then disables the clock for the CAN controller.

## Example
<details>
<summary>Example</summary>

```cpp
CANSAME5x can;
can.sleep();
```
</details>
<br>
<br>


## `int CANSAME5x::wakeup()`

Enables the CAN controller clock.

## Parameters

None.

## Return value

1 if the clock was successfully enabled, 0 otherwise.

## Description

This function is used to enable the clock for the CAN controller. It sets the clock gating control register for the appropriate CAN controller and waits for the `INIT` bit in the CCCR register to be cleared.

## Example
<details>
<summary>Example</summary>

```cpp
CANSAME5x can;
can.wakeup();
```
</details>


## `int CANSAME5x::available()`

Checks if data is available to be read from the CAN controller.

## Parameters

None.

## Return value

The number of bytes available to be read.

## Description

This function is used to check if data is available to be read from the CAN controller. It does not actually read any data, it just returns the number of bytes that can be read.

## Example

```cpp
CANSAME5x can;
if (can.available()) {
  // Data is available to be read
}
```


## `int CANSAME5x::read()`

Reads a byte from the data payload of the received packet.

## Parameters

None.

## Return value

- If data is available: the next byte from the data payload of the received packet.
- If no data is available: -1.

## Description

This function is used to read data from the data payload of a received packet. It returns the next byte from the payload and increments an internal index. If the end of the payload has been reached, the function returns -1.

## Example

```cpp
CANSAME5x can;
int data = can.read();
if (data >= 0) {
  // Data was successfully read
} else {
  // No data was available
}
```


## `int CANSAME5x::peek()`

Returns the next byte in the received packet without removing it from the buffer.

## Parameters

None.

## Return value

The next byte in the received packet, or -1 if no data is available.

## Description

This function is used to retrieve the next byte in the received packet without removing it from the receive buffer. It is useful for previewing the data in a packet before deciding whether to read it or discard it.

## Example

```cpp
CANSAME5x can;
int nextByte = can.peek();
if (nextByte >= 0) {
  // There is data available to be read
} else {
  // No data is available
}
```


## `void CANSAME5x::flush()`

Clears the receive buffer.

## Parameters

None.

## Return value

None.

## Description

This function is used to clear the receive buffer for the CAN controller. It discards any data currently in the buffer and resets the read index to the beginning of the buffer.

## Example

```cpp
CANSAME5x can;
can.flush();
```
