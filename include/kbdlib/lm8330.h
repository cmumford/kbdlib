/**
 * @section license License
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#pragma once

#include <cstdint>

namespace kbd {
namespace lm8330 {

// The datasheet says the address is 0x88, but this is not a valid I2C address
// (> 127). I believe it meant that once shifted left one bit the value
// should be 0x88 = 0b10001000. Shifted right once is 0x44 = 0b01000100.
constexpr uint8_t kSlaveAddress = 0x44;  // I2C address of LM8330 IC.

// clang-format off
// See datasheet pg. 43.
enum class RegNum : uint8_t {
  KBDSETTLE  = 0x01, // Keypad settle time.
  KBDBOUNCE  = 0x02, // Debounce time.
  KBDSIZE    = 0x03, // Set keypad size.
  KBDDEDCFG0 = 0x04, // Dedicated key 0.
  KBDDEDCFG1 = 0x05, // Dedicated key 1.
  KBDRIS     = 0x06, // Keyboard raw interrupt status.
  KBDMIS     = 0x07, // Keypad masked interrupt status.
  KBDIC      = 0x08, // Keypad interrupt clear.
  KBDMSK     = 0x09, // Keypad interrupt mask.
  KBDCODE0   = 0x0B, // Keyboard code 0.
  KBDCODE1   = 0x0C, // Keyboard code 1.
  KBDCODE2   = 0x0D, // Keyboard code 2.
  KBDCODE3   = 0x0E, // Keyboard code 3.
  EVTCODE    = 0x10, // Key Event code.
  TIMCFG0    = 0x60, // PWM timer 0 configuration.
  PWMCFG0    = 0x61, // PWM timer 0 configuration control.
  TIMCFG1    = 0x68, // PWM timer 1 configuration.
  PWMCFG1    = 0x69, // PWM timer 1 configuration control.
  TIMCFG2    = 0x70, // PWM timer 2 configuration.
  PWMCFG2    = 0x71, // PWM timer 2 configuration control.
  TIMSWRES   = 0x78, // PWM timer software Reset.
  TIMRIS     = 0x7A, // PWM timer interrupt status.
  TIMMIS     = 0x7B, // PWM timer masked interrupt status.
  TIMIC      = 0x7C, // PWM timer interrupt clear.
  PWMWP      = 0x7D, // PWM timer pattern Pointer.
  PWMCFG     = 0x7E, // PWM script.
  I2CSA      = 0x80, // I2C-Compatible ACCESS.bus 10-Bit & 7-bit slave address.
  MFGCODE    = 0x80, // Manufacturer code.
  SWREV      = 0x81, // Software revision.
  RSTCTRL    = 0x82, // System reset.
  RSTINTCLR  = 0x84, // Clear NO Init/Power-On interrupt.
  CLKMODE    = 0x88, // Clock mode.
  CLKEN      = 0x8A, // Clock enable.
  AUTOSLP    = 0x8B, // Auto-sleep enable.
  AUTOSLPTIL = 0x8C, // Auto-sleep time (low)
  AUTOSLPTIH = 0x8D, // Auto-sheep time (high)
  IRQST      = 0x91, // Interrupt global interrupt status.
  IOCFG      = 0xA7, // Input/Output pin mapping configuration.
  IOPC0      = 0xAA, // Pull resistor configuration 0.
  IOPC1      = 0xAC, // Pull resistor configuration 1.
  IOPC2      = 0xAE, // Pull resistor configuration 2.
  GPIODATA0  = 0xC0, // GPIO data 0.
  GPIODATA1  = 0xC2, // GPIO data 1.
  GPIODATA2  = 0xC4, // GPIO data 2.
  GPIODIR0   = 0xC6, // GPIO port direction 0.
  GPIODIR1   = 0xC7, // GPIO port direction 1.
  GPIODIR2   = 0xC8, // GPIO port direction 2.
  GPIOIS0    = 0xC9, // Interrupt sense configuration 0.
  GPIOIS1    = 0xCA, // Interrupt sense configuration 1.
  GPIOIS2    = 0xCB, // Interrupt sense configuration 2.
  GPIOIBE0   = 0xCC, // GPIO interrupt edge configuration 0.
  GPIOIBE1   = 0xCD, // GPIO interrupt edge configuration 1.
  GPIOIBE2   = 0xCE, // GPIO interrupt edge configuration 2.
  GPIOIEV0   = 0xCF, // GPIO interrupt edge select 0.
  GPIOIEV1   = 0xD0, // GPIO interrupt edge select 1.
  GPIOIEV2   = 0xD1, // GPIO interrupt edge select 2.
  GPIOIE0    = 0xD2, // GPIO interrupt enable 0.
  GPIOIE1    = 0xD3, // GPIO interrupt enable 1.
  GPIOIE2    = 0xD4, // GPIO interrupt enable 2.
  GPIORIS0   = 0xD6, // Raw interrupt status 0.
  GPIORIS1   = 0xD7, // Raw interrupt status 1.
  GPIORIS2   = 0xD8, // Raw interrupt status 2.
  GPIOMIS0   = 0xD9, // Masked interrupt status 0.
  GPIOMIS1   = 0xDA, // Masked interrupt status 1.
  GPIOMIS2   = 0xDB, // Masked interrupt status 2.
  GPIOIC0    = 0xDC, // GPIO clear interrupt 0.
  GPIOIC1    = 0xDD, // GPIO clear interrupt 1.
  GPIOIC2    = 0xDE, // GPIO clear interrupt 2.
  GPIOOME0   = 0xE0, // GPIO open drain mode enable 0.
  GPIOOMS0   = 0xE1, // GPIO open drain mode select 0.
  GPIOOME1   = 0xE2, // GPIO open drain mode enable 1.
  GPIOOMS1   = 0xE3, // GPIO open drain mode select 1.
  GPIOOME2   = 0xE4, // GPIO open drain mode enable 2.
  GPIOOMS2   = 0xE5, // GPIO open drain mode select 2.
  GPIOWAKE0  = 0xE9, // GPIO wake-up 0.
  GPIOWAKE1  = 0xEA, // GPIO wake-up 1.
  GPIOWAKE2  = 0xEB, // GPIO wake-up 2.
};
// clang-format on

namespace reg {

struct IOCFG {
  uint8_t Reserved1 : 3;  // Reserved - set to zero.
  uint8_t GPIOSEL : 1;    // KPY11 config. 1 = IRQN enabled.
  uint8_t Reserved2 : 1;  // Reserved - set to zero.
  uint8_t BALLCFG : 3;    // Select column to configure.

  operator uint8_t() const;
};

/**
 * Defines the physical keyboard matrix size.
 */
struct KBDSIZE {
  uint8_t ROWSIZE : 4;  // Number of rows in the keyboard matrix.
  uint8_t COLSIZE : 4;  // Number of columns in the keyboard matrix.

  operator uint8_t() const;
};

/**
 * Clock enable.
 *
 * Controls the clock to different functional units. It is used to enable
 * the functional blocks globally and independently.
 */
struct CLKEN {
  uint8_t Reserved1 : 5;  // Reserved - set to zero.
  uint8_t TIMEN : 1;      // PWM timer 0, 1, 2 clock enable.
  uint8_t Reserved2 : 1;  // Reserved - set to zero.
  uint8_t KBDEN : 1;      // Keyboard clock enabled (enables/disables key scan).

  operator uint8_t() const;
};

/**
 * Keypad interrupt mask.
 *
 * Configures masking of keyboard interrupts. Masked interrupts do not
 * trigger an event on the Interrupt output.
 *
 * In case the interrupt processes registers KBDCODE[3:0], MSKELINT and
 * MSKEINT should be set to '1'. When the Event FIFO is processed,
 * MSKLINT and MSKSINT should be set. For keyboard polling operations,
 * all bits should be set and the polling operation consists of reading
 * out the IRQST.
 */
struct KBDMSK {
  uint8_t Reserved : 4;  // Reserved.
  uint8_t MSKELINT : 1;  // Keyboard event lost interrupt RELINT is masked.
  uint8_t MSKEINT : 1;   // keyboard event interrupt REVINT is masked,
  uint8_t MSKLINT : 1;   // keyboard lost interrupt RKLINT is masked.
  uint8_t MSKSINT : 1;   // keyboard status interrupt RSINT is masked.

  KBDMSK& operator=(uint8_t);
  operator uint8_t() const;
};

/**
 * Keypad interrupt clear.
 *
 * Setting these bits clears Keypad active Interrupts.
 */
struct KBDIC {
  uint8_t SFOFF : 1;     // Switches off scanning of special function (SF) keys.
  uint8_t Reserved : 5;  // Keyboard event lost interrupt RELINT is masked.
  uint8_t EVTIC : 1;  // Clear EVTCODE FIFO and corresponding interrupts REVTINT
                      // and RELINT.
  uint8_t KBDIC : 1;  // Clear RSINT and RKLINT interrupt bits.

  operator uint8_t() const;
};

/**
 * Interrupt global interrupt status.
 *
 * Returns the interrupt status from various on-chip function blocks. If any of
 * the bits is set and an IRQN line is configured, the IRQN line is asserted
 * active.
 */
struct IRQST {
  uint8_t PORIRQ : 1;    // Supply failure on VCC. 0: no failure.
  uint8_t KBDIRQ : 1;    // Kbd interrupt (further key selection in kbd module).
  uint8_t Reserved : 2;  // Unused.
  uint8_t TIM2IRQ : 1;   // Timer2 expiry (CDIRQ or CYCIRQ). 1: active.
  uint8_t TIM1IRQ : 1;   // Timer1 expiry (CDIRQ or CYCIRQ). 1: active.
  uint8_t TIM0IRQ : 1;   // Timer0 expiry (CDIRQ or CYCIRQ). 1: active.
  uint8_t GPIOIRQ : 1;   // GPIO interrupt (further selection in GPIO module).

  IRQST(uint8_t value);
  operator uint8_t() const;
};

/**
 * Key event code.
 *
 * With this register a FIFO buffer is addressed storing up to 15
 * consecutive events. Reading the value 0x7F from this address means
 * that the FIFO buffer is empty.
 *
 * @note Auto increment is disabled on this register. Multi-byte read
 *       will always read from the same address.
 */
struct EVTCODE {
  uint8_t RELEASE : 1;  // Indicates a key press or a key release event.
  uint8_t KEYROW : 3;   // Row index of key that is pressed or released
  uint8_t KEYCOL : 4;  // Column index of detected key that is pressed (0 to 11,
                       // 12 for special function key or and 13 & 14 for
                       // dedicated key) or released.

  operator uint8_t() const;
};

/**
 * Keyboard KBDCODE[0:3].
 *
 * Holds the row and column information of the first detected key.
 */
struct KBDCODE {
  uint8_t MULTIKEY : 1;  // If this bit is 1 another key is available in
                         // KBDCODE1 register.
  uint8_t KEYROW : 3;    // ROW index of detected key (0 to 7).
  uint8_t KEYCOL : 4;    // Column index of detected (0 to 11, 12 for special
                         // function key and 13 & 14 for dedicated KPY key).

  operator uint8_t() const;
};

/**
 * Built-in pull up/down resistor configuration.
 */
enum class Pull : uint8_t {
  Disabled = 0,  // Neither pull-up or down.
  Down = 1,      // Enable internal pull-down resistor.
  Up = 2,        // Enable internal pull-up resistor.
  Upp = 3,       // Enable internal pull-up resistor.
};

/**
 * Pull resistor configuration Register 1.
 *
 * Resistor enable for KPY* ball:
 *
 * 0b00: No pull resistor at ball.
 * 0b01: Pulldown resistor programmed.
 * 0b1x: Pullup resistor programmed.
 */
struct IOPC1 {
  Pull KPY7PR : 2;
  Pull KPY6PR : 2;
  Pull KPY5PR : 2;
  Pull KPY4PR : 2;
  Pull KPY3PR : 2;
  Pull KPY2PR : 2;
  Pull KPY1PR : 2;
  Pull KPY0PR : 2;

  operator uint16_t() const;
};

/**
 * Dedicated key register.
 *
 * Defines if a key is used as a standard keyboard/GPIO pin or whether it is
 * used as dedicated key input.
 *
 * Bit=0: The dedicated key function applies.
 * Bit=1: No dedicated key function is selected. The standard GPIO
 *        functionality applies according to register IOCFG or
 *        defined keyboard matrix.
 */
struct KBDDEDCFG {
  uint16_t KPX7 : 1;
  uint16_t KPX6 : 1;
  uint16_t KPX5 : 1;
  uint16_t KPX4 : 1;
  uint16_t KPX3 : 1;
  uint16_t KPX2 : 1;
  uint16_t KPY11 : 1;
  uint16_t KPY10 : 1;
  uint16_t KPY9 : 1;
  uint16_t KPY8 : 1;
  uint16_t KPY7 : 1;
  uint16_t KPY6 : 1;
  uint16_t KPY5 : 1;
  uint16_t KPY4 : 1;
  uint16_t KPY3 : 1;
  uint16_t KPY2 : 1;

  operator uint16_t() const;
};

/**
 * Keyboard interrupt status (both KBDRIS and KBDMIS).
 *
 * Returns the status of stored keyboard interrupts.
 */
struct KBDIS {
  uint8_t Reserved : 4;
  uint8_t ELINT : 1;   // Event lost interrupt.
  uint8_t EVTINT : 1;  // Keyboard event interrupt.
  uint8_t KLINT : 1;   // Key lost interrupt indicates a lost key-code.
  uint8_t SINT : 1;    // Scan interrupt.

  KBDIS(uint8_t value);
  operator uint8_t() const;
};

}  // namespace reg
}  // namespace lm8330
}  // namespace kbd