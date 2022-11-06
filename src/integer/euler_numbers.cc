#include <mynum/mynum.h>

namespace mynum
{
  namespace z
  {
    int_array_t euler_numbers(size_t m)
    {
      if (m == 0)
      {
        mynum_operand_value_is_invalid_exception(
            "m should greater than 0, m = %ul", m);
      }
      if (m % 2 != 0)
        m++;

      const integer_t const_0 = mympz::create(0);
      const integer_t const_1 = mympz::create(1);
      const integer_t const_2 = mympz::create(2);
      const integer_t const_4 = mympz::create(4);

      int_array_t es = int_array_t(m + 1, const_0);
      int_array_t buf = int_array_t(2 * m + 1, const_0);
      buf[0] = const_1;
      es[0] = const_1;

      integer_t sum = const_0, binom = const_1, item;
      for (size_t n = 1; n <= m; n++)
      {
        sum = const_0;
        binom = const_1;
        for (size_t r = 0; r < n; r++)
        {
          item = buf[2 * r];
          item = mympz::mul(item, binom);
          sum = mympz::add(sum, item);

          binom = mympz::mul(binom,
                             mympz::create(std::to_string((2 * n - 2 * r - 1) * (n - r))));
          binom = mympz::idiv(binom,
                              mympz::create(std::to_string((r + 1) * (2 * r + 1))));
        }
        sum.neg = !!!(sum.neg);
        buf[2 * n] = sum;
        sum.neg = !!!(sum.neg);
        es[n] = sum;
      }
      return es;
    }
  }

} // namespae mynum