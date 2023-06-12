#include <mynum/mynum.h>

namespace mynum
{
  bool is_zero(const number_t &x)
  {
    bool y = false;
    int type = x.type();
    if (type == kNumTypeInteger)
    {
      y = (x.num_integer == 0);
    }
    else if (type == kNumTypeFloat)
    {
      y = (x.num_float <= kEpsilon);
    }
    else if (type == kNumTypeMpz)
    {
      y = mympz::is_zero(x.num_mpz);
    }
    else if (type == kNumTypeMpf)
    {
      y = f::is_zero(x.num_mpf);
    }
    else if (type == kNumTypeFraction)
    {
      y = mympz::is_zero(x.num_fraction.first);
    }
    return y;
  }
} // namespace mynum