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

KBDSIZE::operator uint8_t() const {
  return (static_cast<uint8_t>(ROWSIZE) << 4) |
         (static_cast<uint8_t>(COLSIZE) << 0);
}

CLKEN::operator uint8_t() const {
  return (static_cast<uint8_t>(TIMEN) << 2) |
         (static_cast<uint8_t>(KBDEN) << 0);
}

}  // namespace reg
}  // namespace lm8330
}  // namespace kbd
