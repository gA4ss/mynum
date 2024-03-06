#include <mynum/real.h>

namespace mynum
{
  bool is_zero(const real_t &x)
  {
    bool y = false;
    int type = x.type();
    if (type == kRealTypeInteger)
    {
      y = (x.num_integer == 0);
    }
    else if (type == kRealTypeFloat)
    {
      y = (x.num_float <= kEpsilon);
    }
    else if (type == kRealTypeMpz)
    {
      y = mympz::is_zero(x.num_mpz);
    }
    else if (type == kRealTypeMpf)
    {
      y = f::is_zero(x.num_mpf);
    }
    else if (type == kRealTypeFraction)
    {
      y = mympz::is_zero(x.num_fraction.first);
    }
    return y;
  }
} // namespace mynum