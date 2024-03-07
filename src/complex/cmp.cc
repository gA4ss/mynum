#include <mynum/complex.h>
#include <cmath>

namespace mynum
{
  int cmp(const complex_t &x, const complex_t &y)
  {
    if (abs(x) < abs(y))
      return -1;
    else if (abs(x) > abs(y))
      return 1;
    return 0;
  }
} // namespace mynum