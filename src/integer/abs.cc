#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    integer_t abs(const integer_t &x)
    {
      integer_t y = x;
      y.neg = 0;
      return y;
    }
  } // namespace z
} // namespace mynum