/* Multiply-add
 * Returns x*y+z.
 *
 * The function computes the result without losing precision in any intermediate result.
 *
 * The following macro constants may be defined in an implementation to signal that this function generally provides an efficiency improvement over performing the arithmetic operations in x*y+z (such as when a hardware multiply-add instruction is used):
 */
#include <mynum/math.h>

namespace mynum {
namespace math {

Float fma(const Float& x, const Float& y, const Float& z) {
  return (x * y) + z;
}

Float fmaf(const Float& x, const Float& y, const Float& z) {
  return fma(x, y, z);
}

Float fmal(const Float& x, const Float& y, const Float& z) {
  return fma(x, y, z);
}

} // namespace math
} // namespace mynum
