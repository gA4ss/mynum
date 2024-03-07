#include <mynum/complex.h>

namespace mynum
{
  complex_t mul(const complex_t &x, const complex_t &y)
  {
    return complex_t(mul(x.real_park, y.real_park), mul(x.imaginary_part, y.imaginary_part));
  }
} // namespace mynum