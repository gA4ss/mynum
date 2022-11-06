#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t not_bits(const integer_t &x)
    {
      if (mympz::is_zero(x))
        return mympz::create(1);
      if (mympz::is_one(abs(x)))
        return mympz::create(0);

      integer_t y = x;
      size_t n = bn_size(y);
      for (size_t i = 0; i < n; i++)
        y.number[i] = ~(y.number[i]);
      return y;
    }
  }

} // namespace mynum