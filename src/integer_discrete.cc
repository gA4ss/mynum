#include <mynum/integer.h>
#include <cstring>

namespace mynum {

Integer or_bits(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return Integer();
  if (is_zero(num1)) return num2; 
  if (is_zero(num2)) return num1;
  if (is_infinite(num1) || is_infinite(num2))
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");

  Integer a = num1, b = num2;
  bignum_t integer_park_3, decimal_park_3;
  same_digits(a, b);
  bignum_t integer_park_1 = a.integer_park(), decimal_park_1 = a.decimal_park();
  bignum_t integer_park_2 = b.integer_park(), decimal_park_2 = b.decimal_park();
  size_t n = integer_park_1.size();
  for (size_t i = 0; i < n; i++) {
    integer_park_3.push_front(integer_park_1[i] | integer_park_2[i]);
  }

  n = decimal_park_1.size();
  for (size_t i = 0; i < n; i++) {
    decimal_park_3.push_front(decimal_park_1[i] | decimal_park_2[i]);
  }
  Integer c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() | b.sign());
  return c;
}

Integer and_bits(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return Integer();
  if (is_infinite(num1) || is_infinite(num2)) 
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");
  if (is_zero(num1) || is_zero(num2)) return Integer("0");

  Integer a = num1, b = num2;
  bignum_t integer_park_3, decimal_park_3;
  same_digits(a, b);
  bignum_t integer_park_1 = a.integer_park(), decimal_park_1 = a.decimal_park();
  bignum_t integer_park_2 = b.integer_park(), decimal_park_2 = b.decimal_park();
  size_t n = integer_park_1.size();
  for (size_t i = 0; i < n; i++) {
    integer_park_3.push_front(integer_park_1[i] & integer_park_2[i]);
  }

  n = decimal_park_1.size();
  for (size_t i = 0; i < n; i++) {
    decimal_park_3.push_front(decimal_park_1[i] & decimal_park_2[i]);
  }

  Integer c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() & b.sign());
  return c;
}

Integer xor_bits(const Integer& num1, const Integer& num2) {
  if (is_nan(num1) || is_nan(num2)) return Integer();
  if (is_infinite(num1) || is_infinite(num2)) 
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");

  Integer a = num1, b = num2;
  bignum_t integer_park_3, decimal_park_3;
  same_digits(a, b);
  bignum_t integer_park_1 = a.integer_park(), decimal_park_1 = a.decimal_park();
  bignum_t integer_park_2 = b.integer_park(), decimal_park_2 = b.decimal_park();
  size_t n = integer_park_1.size();
  for (size_t i = 0; i < n; i++) {
    integer_park_3.push_front(integer_park_1[i] ^ integer_park_2[i]);
  }

  n = decimal_park_1.size();
  for (size_t i = 0; i < n; i++) {
    decimal_park_3.push_front(decimal_park_1[i] ^ decimal_park_2[i]);
  }
  Integer c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() ^ b.sign());
  return c;
}

Integer not_bits(const Integer& num1) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_zero(num1)) return Integer("1");
  if (is_one(abs(num1))) return Integer("0");

  Integer res = num1;
  bignum_t integer_park = res.integer_park(), decimal_park = res.decimal_park();
  size_t n = integer_park.size();
  for (size_t i = 0; i < n; i++) {
    integer_park[i] = ~integer_park[i];
  }
  n = decimal_park.size();
  for (size_t i = 0; i < n; i++) {
    decimal_park[i] = ~decimal_park[i];
  }

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  if (res.sign() == kPositive) res.__set_sign(kNegative);
  else res.__set_sign(kPositive);
  return res;
}

/* 将num1下取整后进行运算。 */
Integer lshift_bits(const Integer& num1, const Integer& bits) {
  if (is_nan(num1)) return Integer();
  if (is_nan(bits)) operand_value_is_invalid_exception("%s", "bits is nan");
  if (is_infinite(num1) || is_infinite(bits))
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");
  if (is_float(num1) || is_float(bits))
    operand_type_is_invalid_exception("%s", "num1 or bits is float");
  if (is_zero(num1)) return Integer("0");

  Integer res = floor(num1), one("1"), two("2");
  Integer i("0");
  while(lt(i, bits)) {
    res = mul(res, two);
    i = add(i, one);
  }
  return res;
}

/* 将num1下取整后进行运算。 */
Integer rshift_bits(const Integer& num1, const Integer& bits) {
  if (is_nan(num1)) return Integer();
  if (is_nan(bits)) operand_value_is_invalid_exception("%s", "bits is nan");
  if (is_infinite(num1) || is_infinite(bits))
    operand_value_is_invalid_exception("%s", "num1 or bits is infinite");
  if (is_float(num1) || is_float(bits))
    operand_type_is_invalid_exception("%s", "num1 or bits is float");
  if (is_zero(num1)) return Integer("0");

  Integer res = floor(num1), one("1"), two("2");
  Integer i("0");
  while(lt(i, bits)) {
    res = quo(res, two);
    i = add(i, one);
  }
  return res;
}

} // namespace mynum