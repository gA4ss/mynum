#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    float_t exp(const float_t &x, const float_t &epsilon, size_t precision)
    {
      // mynum_dbgprint_fmt("exp(%s, %s).\n",
      //                    mympf::print_string(x).c_str(),
      //                    mympf::print_string(epsilon).c_str());
      precision_on_epsilon(precision, epsilon);
      float_t y = x, n = mympf::create(2), p;
      const float_t const_1 = mympf::create(1);
      do
      {
        p = y;
        // mynum_dbgprint_fmt("f::pow(x, n, epsilon) = %s.\n",
        //                    mympf::print_string(f::pow(x, n, epsilon)).c_str());
        // mynum_dbgprint_fmt("factorial(n) = %s.\n",
        //                    mympf::print_string(factorial(n)).c_str());
        // mynum_dbgprint_fmt("div(f::pow(x, n, epsilon), factorial(n)) = %s.\n",
        //                    mympf::print_string(mympf::div(f::pow(x, n, epsilon), factorial(n))).c_str());
        // mynum_dbgprint_fmt("y' = %s.\n",
        //                    mympf::print_string(y).c_str());
        y = mympf::add(y, mympf::div(f::pow(x, n, epsilon, precision), factorial(n)));
        // mynum_dbgprint_fmt("y = %s.\n",
        //                    mympf::print_string(y).c_str());
        n = mympf::add(n, const_1);
      } while (!diff_eps(y, p, epsilon));
      y = mympf::add(y, const_1);
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum