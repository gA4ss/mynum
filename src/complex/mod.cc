#include <mynum/complex.h>

namespace mynum
{
  complex_t mod(const complex_t &x, const complex_t &y)
  {
    return complex_t(mod(x.re(), y.re()), mod(x.im(), y.im()));
  }
} // namespace mynum