#include <mynum/number/complex.h>

namespace mynum {
namespace number {

Complex conjugate(const Complex& num1) {
  Complex res = num1;
  -res.imaginary_park_;
  return res;
}

} // namespace number
} // namespace mynum