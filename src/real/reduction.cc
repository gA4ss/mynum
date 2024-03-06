#include <mynum/real.h>

namespace mynum
{
  real_t reduction(const real_t &x)
  {
    if (x.type() == kRealTypeFraction)
    {
      real_t y;
      y.set_frac_value(f::reduction(x.num_fraction));
      return y;
    }
    return x;
  }
} // namespace mynum
