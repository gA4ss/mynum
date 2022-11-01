#include <mynum/integer.h>

namespace mynum {

/*
 * Extern Euclid(gcd(a,b) = sa+tb)
 */
std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2) {
  Integer q, a = num1, b = num2;
  std::vector<Integer> r(3, {"0"});
  std::vector<Integer> s(3, {"0"});
  std::vector<Integer> t(3, {"0"});
  
  if (abs(a) >= abs(b)) {
    r[0] = abs(a);
    s[0] = "1";
    t[0] = "0";
    r[1] = abs(b);
    s[1] = "0";
    t[1] = "1";
  } else {
    r[0] = abs(b);
    s[0] = "0";
    t[0] = "1";
    r[1] = abs(a);
    s[1] = "1";
    t[1] = "0";
  }

  while (r[1] != "0") {
    q = quo(r[0], r[1]);
    r[2] = r[0] - q * r[1];
    s[2] = s[0] - q * s[1];
    t[2] = t[0] - q * t[1];

    r[0] = r[1];
    s[0] = s[1];
    t[0] = t[1];

    r[1] = r[2];
    s[1] = s[2];
    t[1] = t[2];
  }

  if (a < "0") -s[0];
  if (b < "0") -t[0];
  return {s[0], t[0]};
}

} // namespace mynum