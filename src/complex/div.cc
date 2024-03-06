#include <mynum/complex.h>

namespace mynum
{
  complex_t div(const complex_t &x, const complex_t &y)
  {
    return complex_t(div(x.re(), y.re()), div(x.im(), y.im()));
  }
} // namespace mynum