#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {
    extern std::vector<float_t> __euler_numbers;

    float_t sec(const float_t &x, size_t precision)
    {
      //
      // 保证 |x| < pi/2
      //
      const float_t epsilon = epsilon_from_precision(precision);
      const float_t const_half_pi = mympf::create(kPI_2);
      if ((mympf::ucmp(x, const_half_pi) > 0) || (diff_eps(const_half_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "|x| < PI/2, x = %s", mympf::print_string(x).c_str());
      }

      const float_t const_1 = mympf::create(1);
      size_t i = 1, j = __euler_numbers.size();
      float_t y = const_1, n = const_1, p, e;
      float_t numerator, denominator, exponent, item;
      const float_t const_2 = mympf::create(2);
      do
      {
        p = y;
        exponent = mympf::mul(n, const_2);
        if (i < j)
        {
          e = __euler_numbers[i];
        }
        else
        {
          mynum_over_euler_numbers_table_exception(
              "index \'%lu\' over the euler table.", i);
        }
        numerator = abs(e);
        denominator = factorial(exponent);
        item = mympf::div(numerator, denominator);
        item = mympf::mul(item, pow(x, exponent, precision));
        y = mympf::add(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum