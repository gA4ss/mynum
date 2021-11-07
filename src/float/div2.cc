#include <mynum/float.h>
#include <mynum/float/__infinity.h>

namespace mynum {

// /* 这里认定num1是数字而num2是无穷。 */
// static Float __mod_infinite_operation(const Float& num1, const Float& num2) {
//   my_assert(is_infinite(num2), "%s", "num2 is not infinite.");

//   Float res;
//   if (is_zero(num1)) {
//     res.zero();
//   } else if (!is_infinite(num1)) {
//     if (num1.sign() == num2.sign()) {
//       res = num1;
//     } else {
//       res = num2;
//     }
//   }
//   return res;
// }

void div2(const Float& num1, const Float& num2, Float& quo, Float& rem) {
  return;
}

} // namespace mynum