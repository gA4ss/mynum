#include <mynum/complex.h>

namespace mynum
{
  complex_t add(const complex_t &x, const complex_t &y)
  {
    return complex_t(add(x.real_park, y.real_park), add(x.imaginary_part, y.imaginary_part));
  }
} // namespace mynum