#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    float_t erfc(const float_t &x, const float_t &epsilon, size_t precision)
    {
      float_t y = mympf::sub(mympf::create(1), erf(x, epsilon, precision));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum