#include <mynum/float.h>
#include <mynum/convert.h>

namespace mynum {

std::pair<Integer, Integer> fraction(const Float& x) {
  if (is_nan(x)) operand_value_is_invalid_exception("%s", "x is nan");
  if (is_infinite(x)) operand_value_is_invalid_exception("%s", "x is infinite");
  if (is_one(x)) return {Integer("1"), Integer("1")};
  if (is_zero(x)) return {Integer("0"), Integer("1")};
  if (is_integer(x)) return {convert_float_to_integer(x), Integer("1")};

  //
  // 这里保证了，x的尾数部分不为0。
  //
  Integer numerator = Integer(x.decimal_park());
  bignum_t den;
  size_t i = x.decimal_park().size();
  while (i--) den.push_back(0);
  den.push_back(1);
  Integer denominator = Integer(den);
  Integer g = gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;

  Integer y = Integer(x.integer_park());
  numerator += (y * denominator);
  numerator.set_sign(x.sign());
  // Float _numerator = Float(numerator.integer_park());
  // _numerator.set_sign(x.sign());
  // return {_numerator, Float(denominator.integer_park())};
  return {numerator, denominator};
}

} // namespace mynum