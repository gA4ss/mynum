#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  int sgn(const real_t &x)
  {
    int type = x.type(), s = 0;
    if (type == kRealTypeInteger)
    {
      s = x.num_integer < 0 ? 1 : 0;
    }
    else if (type == kRealTypeFloat)
    {
      s = x.num_float < 0.0 ? 1 : 0;
    }
    else if (type == kRealTypeMpz)
    {
      s = z::sgn(x.num_mpz);
    }
    else if (type == kRealTypeMpf)
    {
      s = f::sgn(x.num_mpf);
    }
    else if (type == kRealTypeFraction)
    {
      s = f::sgn(x.num_fraction);
    }
    return s;
  }
} // namespace mynum
