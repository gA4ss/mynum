#include <mynum/complex.h>

namespace mynum
{
  complex_t add(const complex_t &x, const complex_t &y)
  {
    return complex_t(add(x.re(), y.re()), add(x.im(), y.im()));
  }
} // namespace mynum