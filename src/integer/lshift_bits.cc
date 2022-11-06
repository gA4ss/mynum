#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t lshift_bits(const integer_t &x, size_t n)
    {
      if (mympz::is_zero(x))
        return mympz::create(0);

      return mympz::lshift(x, n);
    }
  }
} // namespace mynum