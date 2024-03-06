#include <mynum/real.h>
#include <cmath>

namespace mynum
{
  real_t round(const real_t &x)
  {
    int type = x.type();
    real_t _x;
    if (type == kRealTypeInteger)
    {
      _x.set_int_value(std::round(x.num_integer));
    }
    else if (type == kRealTypeFloat)
    {
      _x.set_flt_value(std::round(x.num_float));
    }
    else if (type == kRealTypeMpz)
    {
      _x = x;
    }
    else if (type == kRealTypeMpf)
    {
      _x.set_mpf_value(f::round(x.num_mpf));
    }
    else if (type == kRealTypeFraction)
    {
      _x = x;
    }
    return _x;
  }
} // namespace mynum