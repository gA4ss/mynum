#include <mynum/complex.h>

namespace mynum
{
  complex_t mul(const complex_t &x, const complex_t &y)
  {
    return complex_t(mul(x.re(), y.re()), mul(x.im(), y.im()));
  }
} // namespace mynum