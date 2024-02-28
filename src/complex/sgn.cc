#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  int sgn(const number_t &x)
  {
    int type = x.type(), s = 0;
    if (type == kNumTypeInteger)
    {
      s = x.num_integer < 0 ? 1 : 0;
    }
    else if (type == kNumTypeFloat)
    {
      s = x.num_float < 0.0 ? 1 : 0;
    }
    else if (type == kNumTypeMpz)
    {
      s = z::sgn(x.num_mpz);
    }
    else if (type == kNumTypeMpf)
    {
      s = f::sgn(x.num_mpf);
    }
    else if (type == kNumTypeFraction)
    {
      s = f::sgn(x.num_fraction);
    }
    return s;
  }
} // namespace mynum
