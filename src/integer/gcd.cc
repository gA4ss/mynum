#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    /*
     * Euclid(a = q_0b + r_0)
     */
    integer_t gcd(const integer_t &x, const integer_t &y)
    {
      return mympz::gcd(x, y);
    }
  }
} // namespace mynum