#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  number_t floor(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::floor(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::floor(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x = x;
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::floor(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x = x;
    }
    return _x;
  }
} // namespace mynum