#include <mynum/float.h>
namespace mynum {

static bignum_t __effective_digit(const Float& num1, my::uinteger_t precision, unit_t& v) {
  bignum_t new_decimal_park;
  if (precision >= num1.precision()) {
    v = 0;
    return new_decimal_park;
  }

  bignum_t decimal_park = num1.decimal_park();
  size_t diff = decimal_park.size() - precision;
  new_decimal_park.insert(new_decimal_park.end(), decimal_park.begin()+diff, 
                                                  decimal_park.end());
  bignum_t::iterator iter = (decimal_park.end() - precision);
  v = *(iter-1);
  if (new_decimal_park.empty()) new_decimal_park.push_back(0);
  return new_decimal_park;
}

static bool __mantissa_is_5(const Float& num1) {
  bignum_t decimal_park = num1.decimal_park();
  if ((decimal_park.size() == 1) && (decimal_park[0] == 5))
    return true;

  //
  // 首位为5，其余位为0。
  //
  if (*(decimal_park.end()-1) == 5) {
    size_t length = decimal_park.size();
    for (size_t i = length-1; i > 0; i++) {
      if (decimal_park[i] != 0) return false;
    }
    return true;
  }

  return false;
}

static bool __is_odd(const Float& num1) {
  // if (!is_integer(num1)) operand_type_is_invalid_exception("%s", "num1 is not integer.");
  unit_t x = *(num1.integer_park().begin());
  if (x%2 == 0) return false;
  return true;
}

/* 当尾数为5，而尾数后面的数字均为0时，应看尾数“5”的前一位：若前一位数字此时为奇数，
 * 就应向前进一位；若前一位数字此时为偶数，则应将尾数舍去。数字“0”在此时应被视为偶数。
 */
Float round(const Float& num1, my::uinteger_t significant_digits) {
  if (is_nan(num1)) return Float();
  if (is_zero(num1)) return Float("0");
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_integer(num1)) return num1;
  if (significant_digits >= num1.precision()) return num1;

  if (__mantissa_is_5(num1)) {
    if (__is_odd(integer(num1))) {
      if (num1.sign() == kPositive)
        return integer(num1 + "1");
      else
        return integer(num1 + "-1");
    }
    // 偶数舍去尾数
    return integer(num1);
  }

  unit_t v = 0;
  bignum_t effective_park = __effective_digit(num1, significant_digits, v);
  Float res = num1;
  res.set_decimal_park(effective_park);

  if (v >= 5) {
    bignum_t plus;
    plus.resize(significant_digits-1);
    plus.push_front(1);
    Float tmp("0");
    tmp.set_decimal_park(plus);
    res += tmp;
  }

  return res;
}

} // namespace mynum