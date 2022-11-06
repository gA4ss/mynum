#include <mynum/mynum.h>

namespace mynum
{
  namespace f
  {
    extern std::vector<float_t> __bernoulli_numbers;

    float_t csch(const float_t &x, const float_t &epsilon, size_t precision)
    {
      //
      // 保证 0< |x| < pi
      //
      const float_t const_pi = mympf::create(M_PI);
      if ((is_zero(x)) || (mympf::ucmp(x, const_pi) > 0) ||
          (diff_eps(const_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "0 < |x| < PI, x = %s", mympf::print_string(x).c_str());
      }

      const float_t const_0 = mympf::create(0);
      const float_t const_1 = mympf::create(1);
      size_t i = 1, j = __bernoulli_numbers.size();
      float_t y = mympf::div(const_1, x), p;
      float_t numerator, denominator, item, exponent = const_0, sign = mympf::create("-1");
      float_t n = const_1, k = mympf::create("-1"),
              l = mympf::create(2), o = const_1, b;
      do
      {
        p = y;
        exponent = mympf::sub(mympf::mul(n, l), o); //  2n-1
        if (i < j)
        {
          b = __bernoulli_numbers[i];
        }
        else
        {
          // 超过表大小，则重新计算。
          mynum_over_bernoulli_numbers_table_exception(
              "index \'%lu\' over the bernoulli table.", i);
        }
        item = mympf::sub(pow(l, exponent, epsilon, precision), o);
        numerator = mympf::mul(l, item);
        numerator = mympf::mul(numerator, b);
        denominator = factorial(mympf::add(exponent, o));
        item = mympf::div(numerator, denominator);
        item = mympf::mul(item, pow(x, exponent, epsilon, precision));
        sign = pow(k, n, epsilon, precision);
        item = mympf::mul(item, sign);
        y = mympf::add(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
      return check_result_on_precision(y, precision);
    }
  }
} // namespace mynum