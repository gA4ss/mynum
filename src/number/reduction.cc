#include <mynum/mynum.h>

namespace mynum
{
  number_t reduction(const number_t &x)
  {
    if (x.type() == kNumTypeFraction)
    {
      number_t y;
      y.set_frac_value(f::reduction(x.num_fraction));
      return y;
    }
    return x;
  }
} // namespace mynum
