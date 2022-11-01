#include <mynum/convert.h>

namespace mynum {

Float convert_integer_to_float(const Integer& i) {
  Float res;
  res.set_integer_park(i.integer_park());
  res.set_decimal_park_zero();
  res.set_sign(i.sign());
  res.set_infinite(i.infinite());
  return res;
}

Integer convert_float_to_integer(const Float& f) {
  Integer res;
  res.set_integer_park(f.integer_park());
  res.set_sign(f.sign());
  res.set_infinite(f.infinite());
  return res;
}

} // namespace mynum