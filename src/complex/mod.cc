#include <mynum/complex.h>

namespace mynum
{
  complex_t mod(const complex_t &x, const complex_t &y)
  {
    return complex_t(mod(x.real_park, y.real_park), mod(x.imaginary_part, y.imaginary_part));
  }
} // namespace mynum