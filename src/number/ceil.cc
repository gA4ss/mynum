#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  number_t ceil(const number_t &x)
  {
    int type = x.type();
    number_t _x;
    if (type == kNumTypeInteger)
    {
      _x.set_int_value(std::ceil(x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      _x.set_flt_value(std::ceil(x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      _x = x;
    }
    else if (type == kNumTypeMpf)
    {
      _x.set_mpf_value(f::ceil(x.num_mpf));
    }
    else if (type == kNumTypeFraction)
    {
      _x = x;
    }
    return _x;
  }
} // namespace mynum