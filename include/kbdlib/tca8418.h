/**
 * @section license License
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#pragma once

#include <cstdint>

namespace kbd {
namespace tca8418 {

// clang-format off
enum class RegNum : uint8_t {
  Reserved       = 0x00,
  CFG            = 0x01,
  INT_STAT       = 0x02,
  KEY_LCK_EC     = 0x03,
  KEY_EVENT_A    = 0x04,
  KEY_EVENT_B    = 0x05,
  KEY_EVENT_C    = 0x06,
  KEY_EVENT_D    = 0x07,
  KEY_EVENT_E    = 0x08,
  KEY_EVENT_F    = 0x09,
  KEY_EVENT_G    = 0x0A,
  KEY_EVENT_H    = 0x0B,
  KEY_EVENT_I    = 0x0C,
  KEY_EVENT_J    = 0x0D,
  KP_LCK_TIMER   = 0x0E,
  UNLOCK1        = 0x0F,
  UNLOCK2        = 0x10,
  GPIO_INT_STAT1 = 0x11,
  GPIO_INT_STAT2 = 0x12,
  GPIO_INT_STAT3 = 0x13,
  GPIO_DAT_STAT1 = 0x14,
  GPIO_DAT_STAT2 = 0x15,
  GPIO_DAT_STAT3 = 0x16,
  GPIO_DAT_OUT1  = 0x17,
  GPIO_DAT_OUT2  = 0x18,
  GPIO_DAT_OUT3  = 0x19,
  GPIO_INT_EN1   = 0x1A,
  GPIO_INT_EN2   = 0x1B,
  GPIO_INT_EN3   = 0x1C,
  KP_GPIO1       = 0x1D,
  KP_GPIO2       = 0x1E,
  KP_GPIO3       = 0x1F,
  GPI_EM1        = 0x20,
  GPI_EM2        = 0x21,
  GPI_EM3        = 0x22,
  GPIO_DIR1      = 0x23,
  GPIO_DIR2      = 0x24,
  GPIO_DIR3      = 0x25,
  GPIO_INT_LVL1  = 0x26,
  GPIO_INT_LVL2  = 0x27,
  GPIO_INT_LVL3  = 0x28,
  DEBOUNCE_DIS1  = 0x29,
  DEBOUNCE_DIS2  = 0x2A,
  DEBOUNCE_DIS3  = 0x2B,
  GPIO_PULL1     = 0x2C,
  GPIO_PULL2     = 0x2D,
  GPIO_PULL3     = 0x2E,
};
// clang-format on

namespace Register {

struct CFG {
  uint8_t KE_IEN : 1;        // Key events interrupt enable to host processor.
  uint8_t GPI_IEN : 1;       // GPI interrupt enable to host processor.
  uint8_t K_LCK_IEN : 1;     // Keypad lock interrupt enable.
  uint8_t OVR_FLOW_IEN : 1;  // Overflow interrupt enable.
  uint8_t INT_CFG : 1;       // Interrupt configuration.
  uint8_t OVR_FLOW_M : 1;    // Overflow mode.
  uint8_t GPI_E_CFG : 1;     // GPI event mode configuration.
  uint8_t AI : 1;            // Auto-increment for read and write operations.
};

struct INT_STAT {
  uint8_t K_INT : 1;         // Key events interrupt status.
  uint8_t GPI_INT : 1;       // GPI interrupt status.
  uint8_t K_LCK_INT : 1;     // Keypad lock interrupt status.
  uint8_t OVR_FLOW_INT : 1;  // Overflow interrupt status.
  uint8_t CAD_INT : 1;       // CTRL-ALT-DEL key sequence status.
  uint8_t Reserved : 3;      // Always zero.
};

struct KEY_LCK_EC {
  uint8_t KEC : 4;       // How many key events are in the FIFO.
  uint8_t LCK1 : 1;      // Keypad lock status.
  uint8_t LCK2 : 1;      // Keypad lock status.
  uint8_t K_LCK_EN : 1;  // Key lock enable.
  uint8_t Reserved : 1;  // Always 0.
};

struct KEY_EVENT_A {
  uint8_t key_code;
};

// Used for GPIO_INT_STAT1, GPIO_DAT_STAT1, GPIO_DAT_OUT1,
// and GPIO_INT_EN1.
struct GPIO_INT_STAT1 {
  uint8_t R0 : 1;
  uint8_t R1 : 1;
  uint8_t R2 : 1;
  uint8_t R3 : 1;
  uint8_t R4 : 1;
  uint8_t R5 : 1;
  uint8_t R6 : 1;
  uint8_t R7 : 1;
};

/**
 * Used for:
 *
 * * GPIO_INT_STAT2
 * * GPIO_DAT_STAT2
 * * GPIO_DAT_OUT2
 * * GPIO_INT_EN2
 */
struct GPIO_INT_STAT2 {
  uint8_t C0 : 1;
  uint8_t C1 : 1;
  uint8_t C2 : 1;
  uint8_t C3 : 1;
  uint8_t C4 : 1;
  uint8_t C5 : 1;
  uint8_t C6 : 1;
  uint8_t C7 : 1;
};

// Used for GPIO_INT_STAT3, GPIO_DAT_STAT3, GPIO_DAT_OUT3,
// and GPIO_INT_EN3.
struct GPIO_INT_STAT3 {
  uint8_t C8 : 1;
  uint8_t C9 : 1;
  uint8_t Unused : 6;
};

}  // namespace Register
}  // namespace tca8414
}  // namespace kbd