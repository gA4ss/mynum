#include <mynum/mynum.h>
#include <cmath>

namespace mynum
{
  number_t pow(const number_t &a, const number_t &x, size_t precision)
  {
    std::pair<number_t, number_t> ax = same_type(a, x);
    number_t _a = ax.first, _x = ax.second;

    number_t y;
    int type = _a.type();
    if (type == kNumTypeInteger)
    {
      y.set_int_value(std::pow(_a.num_integer, _x.num_integer));
    }
    else if (type == kNumTypeFloat)
    {
      y.set_flt_value(std::pow(_a.num_float, _x.num_float));
    }
    else if (type == kNumTypeMpz)
    {
      float_t fa = mympf::create(_a.num_mpz, 0);
      float_t fx = mympf::create(_x.num_mpz, 0);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    else if (type == kNumTypeMpf)
    {
      y.set_mpf_value(f::pow(_a.num_mpf, _x.num_mpf, precision));
    }
    else if (type == kNumTypeFraction)
    {
      float_t fa = f::to_float(_a.num_fraction);
      float_t fx = f::to_float(_x.num_fraction);
      y.set_mpf_value(f::pow(fa, fx, precision));
    }
    return y;
  }
} // namespace mynum