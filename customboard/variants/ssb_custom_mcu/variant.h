/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_FEATHER_M4_
#define _VARIANT_FEATHER_M4_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


enum Pinsymbol {

  // SERCOM/UART (Serial1) / Also used by CAN_LED RX/TX

  PIN_SERIAL1_RX = 0,      // PB17
  PIN_SERIAL1_TX,          // PB16

  // Analog pins 
  // ----------- ADC0 ------------

  PIN0_ADC0, // PA02
  PIN1_ADC0, // PA03
  PIN2_ADC0, // PA05
  PIN3_ADC0, // PA04 (has PWM)
  PIN4_ADC0, // PB00
  PIN5_ADC0, // PB01 (has PWM)
  PIN6_ADC0, // PB02 (has PWM)
  PIN7_ADC0, // PB03 (has PWM)
  
  //  ----------- ADC1 ------------
 
  PIN0_ADC1, // PB04 (SWITCH on SHIELD)
  PIN1_ADC1, // PB05 (LED_G on SHIELD)
  PIN2_ADC1, // PB06
  PIN3_ADC1, // PB07
  PIN4_ADC1, // PB08 (has PWM)
  PIN5_ADC1, // PB09 (has PWM)

  //  ----------- I2C pins (SDA,SCL) ----------------

  SDA0, // PA16
  SCL0, // PA17
  SDA1, // PA12
  SCL1, // PA13

  // SPI pins (MISO,MOSI,SCK)
  // ----------------------

  PIN_SPI_MISO, // PB22
  PIN_SPI_MOSI, // PB23
  PIN_SPI_SCK,  // PA17 (also SCL0 should be changed)

  // --------- USB -----------

  USB_HOST_ENABLE,  // Not used
  USB_DM,           
  USB_DP,

  // 31 (AREF)

  AREF,             // PA03

  // --------- DAC -----------

  DAC0,             // PA02
  DAC1,             // PA05

  // ------- QSPI (SCK, CS, IO0, IO1, IO2, IO3) ---------

  ENUM_QSPI_SCK,
  ENUM_CS,
  IO0,
  IO1,
  IO2,
  IO3,

  // --------- CAN0 (TX, RX) ----------

  PIN_CAN0_TX,  // PA22 (CAN0_TX on SHIELD)
  PIN_CAN0_RX,  // PA23 (CAN0_RX on SHIELD)

  // --------- CAN1 (TX, RX) ----------

  PIN_CAN1_TX,  // PB14 (CAN1_TX on SHIELD)
  PIN_CAN1_RX,  // PA15 (CAN1_RX on SHIELD)

  // --------- Digital pins -----------

  // PORTA

  PA02, // also DAC0
  PA03, // also AREF
  PA04, // (has PWM)
  PA05, // also DAC1 (has PWM)
  PA12, // also SDA1 (has PWM)
  PA13, // also SCL1 (has PWM)
  PA16, // also SDA0 (has PWM)
  PA17, // also SCL0 (has PWM)
  PA18, // (has PWM)
  PA19, // (has PWM)
  PA22, // also CAN0_TX (has PWM)
  PA23, // also CAN0_RX (has PWM)
  PA27,

  PB00,
  PB01,
  PB02,
  PB03,
  PB04,
  PB05,
  PB06,
  PB07,
  PB08,
  PB09,
  PB14,
  PB15,
  PB22,
  PB23,
  PB30,
  PB31,


  PINS_COUNT
};
/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Not really used
// Number of pins defined in PinDescription array
#define NUM_DIGITAL_PINS     (23u)
#define NUM_ANALOG_INPUTS    (6u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

// additional symbol definitions used by arduino core

#define PIN_DAC0             DAC0     // PA02
#define PIN_DAC1             DAC1     // PA05

#define ADC_RESOLUTION		12
static const uint8_t  A0 = PIN0_ADC0;

// Other pins
#define PIN_ATN              (AREF)
static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */

#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */

#define SPI_INTERFACES_COUNT 1

#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_3_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

static const uint8_t SS	  = 9 ;	// SERCOM1 last PAD is present on d9 but HW SS isn't used. Set here only for reference.

/*
 * Wire Interfaces
 */

#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (SDA0)
#define PIN_WIRE_SCL         (SCL0)
#define PERIPH_WIRE          sercom1
#define WIRE_IT_HANDLER      SERCOM1_Handler
#define WIRE_IT_HANDLER_0    SERCOM1_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM1_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM1_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM1_3_Handler

#define PIN_WIRE1_SDA         (SDA1)
#define PIN_WIRE1_SCL         (SCL1)
#define PERIPH_WIRE1          sercom2
#define WIRE1_IT_HANDLER      SERCOM2_Handler
#define WIRE1_IT_HANDLER_0    SERCOM2_0_Handler
#define WIRE1_IT_HANDLER_1    SERCOM2_1_Handler
#define WIRE1_IT_HANDLER_2    SERCOM2_2_Handler
#define WIRE1_IT_HANDLER_3    SERCOM2_3_Handler

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (USB_HOST_ENABLE)
#define PIN_USB_DM          (USB_DM)
#define PIN_USB_DP          (USB_DP)

/*
 * I2S Interfaces
 
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE 0
#define I2S_CLOCK_GENERATOR 3

#define PIN_I2S_SDO (11u)
#define PIN_I2S_SDI (12u)
#define PIN_I2S_SCK PIN_SERIAL1_TX
#define PIN_I2S_FS (10u)
#define PIN_I2S_MCK PIN_SERIAL1_RX
*/
// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES   GD25Q16C
#define EXTERNAL_FLASH_USE_QSPI

//QSPI Pins
#define PIN_QSPI_SCK    (ENUM_QSPI_SCK)
#define PIN_QSPI_CS     (ENUM_CS)
#define PIN_QSPI_IO0    (IO0)
#define PIN_QSPI_IO1    (IO1)
#define PIN_QSPI_IO2    (IO2)
#define PIN_QSPI_IO3    (IO3)

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

/*
 * CAN
 */
//#define PIN_CAN_STANDBY (40)
//#define PIN_CAN_BOOSTEN (41)
#define PIN_CAN_TX      (PIN_CAN0_RX)
#define PIN_CAN_RX      (PIN_CAN0_RX)


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_FEATHER_M4_ */

