#include <mynum/bignum.h>

namespace mynum {

bignum_t mul(const bignum_t& a, const bignum_t& b) {
  if (a.empty() || b.empty()) {
    bignum_t c = {0};
    return c;
  }
  bignum_t x, y, z;
  size_t m = 0, n = 0;

  // 保证 m >= n
  if (a.size() >= b.size()) {
    x = a; m = a.size();
    y = b; n = b.size();
  } else if (a.size() < b.size()) {
    y = a; n = a.size();
    x = b; m = b.size();
  }
  z.resize(m+n);

  unit_t q = 0, t = 0;
  for (size_t j = 0; j < n; j++) {
    q = 0;
    for (size_t i = 0; i < m; i++) {
      t = x[i] * y[j] + z[i+j] + q;
      z[i+j] = t % 10;
      q = t / 10;
    }
    z[j+m] = q;
  }
  return z;
}

} // namespace mynum