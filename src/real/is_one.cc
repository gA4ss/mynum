#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  bool is_one(const real_t &x)
  {
    bool y = false;
    int type = x.type();
    if (type == kRealTypeInteger)
    {
      y = (x.num_integer == 1);
    }
    else if (type == kRealTypeFloat)
    {
      y = (std::abs(x.num_float - 1.0) <= kEpsilon);
    }
    else if (type == kRealTypeMpz)
    {
      y = mympz::is_one(x.num_mpz);
    }
    else if (type == kRealTypeMpf)
    {
      y = f::is_one(x.num_mpf);
    }
    else if (type == kRealTypeFraction)
    {
      y = (mympz::cmp(x.num_fraction.first, x.num_fraction.second) == 0);
    }
    return y;
  }
} // namespace mynum