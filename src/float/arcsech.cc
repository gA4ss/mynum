#include <mynum/float.h>
namespace mynum {

Float arcsech(const Float& x, const char* epsilon) {
  // 0 < x <= 1
  if ((x <= "0") || (x > "1")) {
    operand_value_is_invalid_exception(
      "0 < x <= 1, x = %s", x.str().c_str()
    );
  }
  Float y = add(sqrt(sub("1", pow(x, "2")), epsilon), "1");
  return ln(div(y, x), epsilon);
}

} // namespace mynum