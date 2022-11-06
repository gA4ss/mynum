#include <mynum/mynum.h>

namespace mynum
{

  namespace z
  {

    #define _do(r2, r0, q, r1) r2 = mympz::sub(r0, mympz::mul(q, r1))
    /*
     * Extern Euclid(gcd(a,b) = sa+tb)
     */
    std::pair<integer_t, integer_t> extended_euclidean(const integer_t &x, const integer_t &y)
    {
      //
      // 这里只能为正数
      //

      const integer_t const_0 = mympz::create(0);
      const integer_t const_1 = mympz::create(1);

      integer_t q, a = x, b = y;
      a.neg = 0, b.neg = 0;
      std::vector<integer_t> r(3, {const_0});
      std::vector<integer_t> s(3, {const_0});
      std::vector<integer_t> t(3, {const_0});

      if (mympz::ucmp(a, b) >= 0)
      {
        r[0] = abs(a);
        s[0] = const_1;
        t[0] = const_0;
        r[1] = abs(b);
        s[1] = const_0;
        t[1] = const_1;
      }
      else
      {
        r[0] = abs(b);
        s[0] = const_0;
        t[0] = const_1;
        r[1] = abs(a);
        s[1] = const_1;
        t[1] = const_0;
      }

      while (mympz::ucmp(r[1], const_0))
      {
        q = mympz::idiv(r[0], r[1]);
        _do(r[2], r[0], q, r[1]);
        _do(s[2], s[0], q, s[1]);
        _do(t[2], t[0], q, t[1]);

        r[0] = r[1];
        s[0] = s[1];
        t[0] = t[1];

        r[1] = r[2];
        s[1] = s[2];
        t[1] = t[2];
      }

      if (mympz::cmp(a, const_0) < 0)
        s[0].neg = !!!(s[0].neg);
      if (mympz::cmp(b, const_0) < 0)
        t[0].neg = !!!(t[0].neg);
      return {s[0], t[0]};
    }
  }
} // namespace mynum