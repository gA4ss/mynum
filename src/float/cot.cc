#include <mynum/mynum.h>

namespace mynum
{

  namespace f
  {

#if defined(ITER_IN_TH)
    extern std::vector<float_t> __bernoulli_numbers;
#endif

    float_t cot(const float_t &x, size_t precision)
    {
      const float_t const_pi = mympf::create(kPI);
      const float_t epsilon = epsilon_from_precision(precision);
      if ((is_zero(x)) || (mympf::ucmp(x, const_pi) > 0) || (diff_eps(const_pi, x, epsilon)))
      {
        mynum_operand_value_is_invalid_exception(
            "0 < x < PI, x = %s", mympf::print_string(x).c_str());
      }

      float_t y;
#if defined(ITER_IN_TH)
      //
      // 保证 0< |x| < pi
      //
      const float_t const_1 = mympf::create(1);
      size_t i = 0, j = __bernoulli_numbers.size();
      float_t numerator, denominator, exponent, item;
      float_t n = const_1, b, p;
      const float_t const_2 = mympf::create(2);
      y = const_1;
      do
      {
        p = y;
        if (i == 0)
        {
          y = mympf::div(y, x);
          ++i;
          continue;
        }
        exponent = mympf::mul(n, const_2);
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
        numerator = pow(const_2, exponent, precision);
        numerator = mympf::mul(numerator, b);
        denominator = factorial(exponent);
        item = div(numerator, denominator);
        exponent = mympf::sub(exponent, const_1);
        item = mympf::mul(item, pow(x, exponent, precision));
        y = mympf::sub(y, item);
        n = mympf::add(n, const_1);
        ++i;
      } while (!diff_eps(y, p, epsilon));
#else
      y = mympf::div(cos(x, precision), sin(x, precision));
#endif
      return check_result_on_precision(y, precision);
    }
  }

} // namespace mynum