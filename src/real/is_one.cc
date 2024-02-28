#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  bool is_one(const real_t &x)
  {
    bool y = false;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y = (x.num_integer == 1);
    }
    else if (type == kNumTypeFloat)
    {
      y = (std::abs(x.num_float - 1.0) <= kEpsilon);
    }
    else if (type == kNumTypeMpz)
    {
      y = mympz::is_one(x.num_mpz);
    }
    else if (type == kNumTypeMpf)
    {
      y = f::is_one(x.num_mpf);
    }
    else if (type == kNumTypeFraction)
    {
      y = (mympz::cmp(x.num_fraction.first, x.num_fraction.second) == 0);
    }
    return y;
  }
} // namespace mynum