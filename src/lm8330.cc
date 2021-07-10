/**
 * @section license License
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#include <kbdlib/lm8330.h>

namespace kbd {
namespace lm8330 {
namespace reg {

static_assert(sizeof(IOCFG) == sizeof(uint8_t));
static_assert(sizeof(IOPC1) == sizeof(uint16_t));
static_assert(sizeof(KBDDEDCFG) == sizeof(uint16_t));

KBDSIZE::operator uint8_t() const {
  return (static_cast<uint8_t>(ROWSIZE) << 4) |
         (static_cast<uint8_t>(COLSIZE) << 0);
}

CLKEN::operator uint8_t() const {
  return (static_cast<uint8_t>(TIMEN) << 2) |
         (static_cast<uint8_t>(KBDEN) << 0);
}

IRQST::IRQST(uint8_t value)
    : PORIRQ((value & 0b10000000) >> 7),
      KBDIRQ((value & 0b01000000) >> 6),
      Reserved(0),
      TIM2IRQ((value & 0b00001000) >> 3),
      TIM1IRQ((value & 0b00000100) >> 2),
      TIM0IRQ((value & 0b00000010) >> 1),
      GPIOIRQ((value & 0b00000001) >> 0) {}

KBDIS::KBDIS(uint8_t value)
    : Reserved(0),
      ELINT((value & 0b00001000) >> 3),
      EVTINT((value & 0b00000100) >> 2),
      KLINT((value & 0b00000010) >> 1),
      SINT((value & 0b00000001) >> 0) {}

KBDMSK& KBDMSK::operator=(uint8_t value) {
  Reserved = 0;
  MSKELINT = (value & 0b00001000) >> 3;
  MSKEINT = (value & 0b00000100) >> 2;
  MSKLINT = (value & 0b00000010) >> 1;
  MSKSINT = (value & 0b00000001) >> 0;
  return *this;
}

KBDMSK::operator uint8_t() const {
  return (static_cast<uint8_t>(MSKELINT) << 3) |
         (static_cast<uint8_t>(MSKEINT) << 2) |
         (static_cast<uint8_t>(MSKLINT) << 1) |
         (static_cast<uint8_t>(MSKSINT) << 0);
}

KBDIC::operator uint8_t() const {
  return (static_cast<uint8_t>(SFOFF) << 7) |
         (static_cast<uint8_t>(EVTIC) << 1) |
         (static_cast<uint8_t>(KBDIC) << 0);
}

KBDCODE::KBDCODE(uint8_t value)
    : MULTIKEY((value & 0b10000000) >> 7),
      KEYROW((value & 0b01110000) >> 4),
      KEYCOL((value & 0b00001111) >> 0) {}

EVTCODE::EVTCODE(uint8_t value)
    : RELEASE((value & 0b10000000) >> 7),
      KEYROW((value & 0b01110000) >> 4),
      KEYCOL((value & 0b00001111) >> 0) {}

}  // namespace reg
}  // namespace lm8330
}  // namespace kbd
