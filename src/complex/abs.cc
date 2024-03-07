#include <mynum/complex.h>

namespace mynum
{
  real_t abs(const complex_t &x)
  {
    return sqrt(add(mul(x.real_park, x.real_park), mul(x.imaginary_part, x.imaginary_part)));
  }
} // namespace mynum