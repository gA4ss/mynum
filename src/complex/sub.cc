#include <mynum/complex.h>

namespace mynum
{
  complex_t sub(const complex_t &x, const complex_t &y)
  {
    return complex_t(sub(x.re(), y.re()), sub(x.im(), y.im()));
  }
} // namespace mynum