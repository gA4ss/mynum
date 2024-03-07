#include <mynum/complex.h>

namespace mynum
{
  complex_t div(const complex_t &x, const complex_t &y)
  {
    return complex_t(div(x.real_park, y.real_park), div(x.imaginary_part, y.imaginary_part));
  }
} // namespace mynum