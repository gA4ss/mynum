#include <mynum/float.h>

namespace mynum {

Float sqrt(const Float& num1, const char* epsilon) {
  if (num1.sign() == kNegative) {
    operand_value_is_invalid_exception(
      "%s", "operand must be positive."
    );
  }
  if (is_zero(num1)) return Float("0");
  else if (is_one(num1)) return Float("1");

  Float pre = "0", cur = "1", t = "2", e = epsilon, tt;
  while (abs(cur - pre) > e) {
    pre = cur;
    tt = num1 / cur;
    // std::cout << "tt = num1 / cur : " << tt.str() << std::endl;
    tt += cur;
    // std::cout << "tt += cur : " << tt.str() << std::endl;
    cur = tt / t;
    // std::cout << "cur = tt / 2 : " << cur.str() << std::endl << std::endl;
    // cur = (cur + num1 / cur) / t;
  }
  return cur;
}

} // namespace mynum