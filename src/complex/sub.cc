#include <mynum/complex.h>

namespace mynum
{
  complex_t sub(const complex_t &x, const complex_t &y)
  {
    return complex_t(sub(x.real_park, y.real_park), sub(x.imaginary_part, y.imaginary_part));
  }
} // namespace mynum