#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t or_bits(const integer_t &x, const integer_t &y)
    {
      if (mympz::is_zero(x))
        return y;
      if (mympz::is_zero(y))
        return x;

      integer_t z = bn_size(x) >= bn_size(y) ? y : x;
      integer_t t = bn_size(x) < bn_size(y) ? y : x;
      size_t n = bn_size(z);
      for (size_t i = 0; i < n; i++)
        z.number[i] |= t.number[i];
      return z;
    }
  }

} // namespace mynum