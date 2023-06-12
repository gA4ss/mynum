#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  int cmp(const number_t &x, const number_t &y)
  {
    std::pair<number_t, number_t> xy = same_type(x, y);
    number_t _x = xy.first, _y = xy.second;
    int type = _x.type(), z = 0;
    if (type == kNumTypeInteger)
    {
      z = _x.num_integer == _y.num_integer ? 0 : 
          _x.num_integer < _y.num_integer ? -1 : 1;
    }
    else if (type == kNumTypeFloat)
    {
      z = std::abs(_x.num_float - _y.num_float) <= kEpsilon ? 0 : 
          _x.num_float < _y.num_float ? -1 : 1;
    }
    else if (type == kNumTypeMpz)
    {
      z = mympz::cmp(_x.num_mpz, _y.num_mpz);
    }
    else if (type == kNumTypeMpf)
    {
      z = mympf::cmp(_x.num_mpf, _y.num_mpf);
    }
    else if (type == kNumTypeFraction)
    {
      std::pair<fraction_t, fraction_t> k = 
        f::common_denominator(_x.num_fraction, _y.num_fraction);
      z = mympz::cmp(k.first.first, k.second.first);
    }
    return z;
  }
} // namespace mynum