#include <mynum/complex.h>

namespace mynum
{
  real_t length(const complex_t &x)
  {
    return sqrt(add(mul(x.re(), x.re()), mul(x.im(), x.im())));
  }
} // namespace mynum