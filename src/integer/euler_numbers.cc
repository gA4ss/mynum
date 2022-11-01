#include <mynum/integer.h>

namespace mynum {

int_array_t euler_numbers(my::uinteger_t m) {
  if (m == 0) {
    operand_value_is_invalid_exception(
      "m should greater than 0, m = %ul", m
    );
  }
  if (m % 2 != 0)
    m++;

  int_array_t es = int_array_t(m+1, "0");
  int_array_t buf = int_array_t(2*m+1, "0");
  buf[0] = "1";
  es[0] = "1";

  // for (uinteger_t j = 1; j <= m; j += 2)
  //  es[j] = "0";

  Integer sum = "0", binom = "1", item;
  for (my::uinteger_t n = 1; n <= m; n++) {
    sum = "0";
    binom = "1";
    for (my::uinteger_t r = 0; r < n; r++) {
      item = buf[2*r];
      item *= binom;
      sum += item;

      binom *= std::to_string((2*n-2*r-1)*(n-r)).c_str();
      binom /= std::to_string((r+1)*(2*r+1)).c_str();
    }
    buf[2*n] = -sum;
    es[n] = -sum;
  }
  return es;
}

} // namespae mynum