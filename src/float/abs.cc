#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t abs(const float_t &x)
    {
      float_t y = x;
      y.set_neg(0);
      return y;
    }
  }

} // namespace mynum