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

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (90u)
#define NUM_DIGITAL_PINS     (23u)
#define NUM_ANALOG_INPUTS    (10u)
#define NUM_ANALOG_OUTPUTS   (2u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Port define : Pin header for shield
#define PA02                 (50u) //A0
#define PA03                 (51u) // A5 // AREF
#define PB04                 (44u) //SWITCH_BUILTIN
#define PB05                 (45u) //LED_BUILTIN
#define PB06                 (46u) //A7
#define PB07                 (52u) //A8
#define PB08                 (53u) //A2
#define PB09                 (54u) //A3
#define PA04                 (55u) //A4
#define PA05                 (56u) //A1
#define PA12                 (57u) //SDA1
#define PA13                 (58u) //SCL1
#define PB03                 (59u)
#define PB02                 (60u)
#define PB01                 (61u) //A9
#define PB00                 (62u)
#define PB31                 (63u)
#define PB30                 (64u)
#define PA27                 (65u)
#define PB23                 (66u) //MOSI
#define PB22                 (67u) //MISO
#define PA19                 (68u)
#define PA18                 (69u)
#define PA17                 (70u) //SCL0 //SCK
#define PA16                 (71u) //SDA0

#define PB17                 (72u) //LED_RX_CAN0
#define PB16                 (73u) //LED_TX_CAN0
#define PB13                 (74u) //LED_RX_CAN1
#define PB12                 (75u) //LED_TX_CAN1

#define PA14                 (76u) //FAULT_CAN1
#define PA15                 (77u) //S_CAN1
#define PA20                 (78u) //FAULT_CAN0
#define PA21                 (79u) //S_CAN0

#define PA06                 (80u) //SD_CP
#define PA07                 (81u) //SD_WP
#define PA08                 (82u) //SD_CMD
#define PA09                 (83u) //SDDAT0
#define PA10                 (84u) //SD_DAT1
#define PA11                 (85u) //SD_DAT2
#define PB10                 (86u) //SD_DAT3
#define PB11                 (87u) //SD_CLK

// LED AND SWITCH
#define LED_BUILTIN          PB05
#define SWITCH_BUILTIN       PB04
#define LED_RX_CAN0          PB17
#define LED_TX_CAN0          PB16
#define LED_RX_CAN1          PB13
#define LED_TX_CAN1          PB12

/*
 * Analog pins
 */
 #define PIN_A0               (14ul) // alternative use of PA02
 #define PIN_A1               (PIN_A0 + 1) // alternative use of PA05
 #define PIN_A2               (PIN_A0 + 2) // alternative use of PAB08
 #define PIN_A3               (PIN_A0 + 3) // alternative use of PB09
 #define PIN_A4               (PIN_A0 + 4) // alternative use of PA04
 #define PIN_A5               (PIN_A0 + 5) // alternative use of PA03
 #define PIN_A6               (PIN_A0 + 6) // alternative use of PB00
 #define PIN_A7               (47u) // alternative use of PB06
 #define PIN_A8               (48u) // alternative use of PB07
 #define PIN_A9               (49u) // alternative use of
 static const uint8_t A0  = PIN_A0;
 static const uint8_t A1  = PIN_A1;
 static const uint8_t A2  = PIN_A2;
 static const uint8_t A3  = PIN_A3;
 static const uint8_t A4  = PIN_A4;
 static const uint8_t A5  = PIN_A5;
 static const uint8_t A6  = PIN_A6 ;
 static const uint8_t A7  = PIN_A7;
 static const uint8_t A8  = PIN_A8;
 static const uint8_t A9  = PIN_A9 ;

#define PIN_DAC0             (32u) //DAC0 alternative use of PA02
#define PIN_DAC1             (33u) //DAC1 alternative use of PA05
static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION		12

// AREF
#define PIN_ATN              (31ul) //aletrnative use of PA03
static const uint8_t ATN = PIN_ATN; //PA03
static const uint8_t AREF = PIN_ATN; // PA03

/*
 * Serial interfaces
 */

// Serial1
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (23u)
#define PIN_SPI_MOSI         (24u)
#define PIN_SPI_SCK          (25u)
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_3_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

static const uint8_t SS	  = 9 ;	// SERCOM1 last PAD is present on d9 but HW SS isn't used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (21u)
#define PIN_WIRE_SCL         (22u)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler
#define WIRE_IT_HANDLER_0    SERCOM2_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM2_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM2_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM2_3_Handler

static const uint8_t SDA1 = PIN_WIRE_SDA; //PA12
static const uint8_t SCL1 = PIN_WIRE_SCL; //PA13


// A FINALISER POUR AVOIR 2 I2C
static const uint8_t SDA0 = PA16; //PA16
static const uint8_t SCL0 = PA17; //PA17


/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (28ul)
#define PIN_USB_DM          (29ul)
#define PIN_USB_DP          (30ul)


/*
 * I2S Interfaces
 */
//#define I2S_INTERFACES_COUNT 1

//#define I2S_DEVICE          0
//#define I2S_CLOCK_GENERATOR 3

//#define PIN_I2S_SDO          (11u)
//#define PIN_I2S_SDI          (12u)
//#define PIN_I2S_SCK          PIN_SERIAL1_TX
//#define PIN_I2S_FS           (10u)
//#define PIN_I2S_MCK          PIN_SERIAL1_RX

// On-board QSPI Flash -> à modifier pour que ça marche avec une carte SD !
#define EXTERNAL_FLASH_DEVICES   GD25Q16C
#define EXTERNAL_FLASH_USE_QSPI

//QSPI Pins -> déjà été modifié dans .cpp
#define PIN_QSPI_SCK    (34u)
#define PIN_QSPI_CS     (35u)
#define PIN_QSPI_IO0    (36u)
#define PIN_QSPI_IO1    (37u)
#define PIN_QSPI_IO2    (38u)
#define PIN_QSPI_IO3    (39u)

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

/*
 * CAN
 */
 //CAN1
#define PIN_CAN_STANDBY (40) // voir si le code fonctionne sans
#define PIN_CAN_BOOSTEN (41) // voir si le code fonctionne sans
#define PIN_CAN_TX      (42)
#define PIN_CAN_RX      (43)

//CAN0
#define PIN_CAN1_TX     (88) //(12)
#define PIN_CAN1_RX     (89) //(13)


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
