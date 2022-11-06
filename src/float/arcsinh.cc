#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    // https://www.itl.nist.gov/div898/software/dataplot/refman2/ch7/arcsinh.pdf

    float_t arcsinh(const float_t &x, const float_t &epsilon, size_t precision)
    {
      const float_t const_1 = mympf::create(1);
      const float_t const_2 = mympf::create(2);
      float_t y = mympf::add(pow(x, const_2, epsilon, precision), const_1);
      y = ln(mympf::add(x, sqrt(y, epsilon, precision)), epsilon, precision);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum