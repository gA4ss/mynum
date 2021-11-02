#include <mynum/integer.h>
#include <cstring>

namespace mynum {

Integer::Integer() { zero(); }

Integer::Integer(const bignum_t& number) {
  integer_park_ = number;
}

Integer::~Integer() {}

std::string Integer::str() const {
  std::string ret="";

  if (is_nan(*this)) {
    ret = "nan";
    return ret;
  }

  if (sign_ == kNegative)
    ret.push_back('-');

  // inf
  if (infinite_) {
    ret += "inf";
    return ret;
  }

  ret = bignum_to_string(integer_park_);
  return ret;
}

static void __invalid_base(int base) {
  if (base != 10 && base != 2 && base != 8 && base != 16) {
    invalid_arguments_exception("base = %d", base);
  }
}

static bool __check_number_format(const char* number) {
  // 暂时无实现
  return true;
}

void Integer::__create_from_string(const char* number, int base) {
  my_assert(number, "%s", "number ptr is null.");
  __invalid_base(base);   // FIXME: 目前只支持10进制构造。
  __check_number_format(number));

  //
  // FIXME: 这里存在溢出风险。
  // strcpy,strcmp
  //

  if (strlen(number) == 0) {
    zero();
    return;
  }

  std::string number_str = number;
  size_t length = number_str.size();

  // 首先判断符号
  sign_ = kPositive;
  if (number_str[0] == '-') {
    sign_ = kNegative;
    number_str.erase(0, 1);
  } else if (number_str[0] == '+') {
    number_str.erase(0, 1);
  }

  // nan
  if (number_str == "nan") {
    nan();
    return;
  }

  // inf
  if (number_str == "inf") {
    set_infinite(sign_);
    return;
  }

  integer_park_ = string_to_bignum(number_str.c_str(), true);
}

bool is_odd(const Integer& num1) {
  if (!is_integer(num1)) operand_type_is_invalid_exception("%s", "num1 is not integer.");
  unit_t x = *(num1.integer_park().begin());
  if (x%2 == 0) return false;
  return true;
}

bool is_even(const Integer& num1) {
  if (!is_integer(num1)) operand_type_is_invalid_exception("%s", "num1 is not integer.");
  unit_t x = *(num1.integer_park().begin());
  if (x%2 != 0) return false;
  return true;
}

// ----------------------------------------------------------------------
//                             无穷相关的运算
// ----------------------------------------------------------------------

enum {
  kOperandInfNegInfinity = 0,
  kOperandInfPosInfinity = 1,
  kOperandInfZero = 2,
  kOperandInfOne = 3,
  kOperandInfNegOne = 4,
  kOperandInfNan = 5,
  kOperandInfIndeterminacy = 6
};

static int __add_infinite(const Integer& num1, const Integer& num2) {
  int res = kOperandInfIndeterminacy;
  if (is_infinite(num1) && !is_infinite(num2)) {
    res = num1.sign();
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = num2.sign();
  } else if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2.sign()) {
      if (num1.sign() == kNegative) 
        res = kOperandInfNegInfinity;
      else 
        res = kOperandInfPosInfinity;
    } else {
      res = kOperandInfNan;
    }
  } else {  // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

static int __sub_infinite(const Integer& num1, const Integer& num2) {
  int res = kOperandInfIndeterminacy;
  int num2_sign = num2.sign() == kPositive ? kNegative : kPositive;
  if (is_infinite(num1) && !is_infinite(num2)) {
    res = num1.sign();
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = num2_sign;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2_sign) {
      if (num1.sign() == kNegative)
        res = kOperandInfNegInfinity;
      else 
        res = kOperandInfPosInfinity;
    } else {
      res = kOperandInfNan;
    }
  } else { // (!is_infinite(num1) && !is_infinite(num2))
    res = kOperandInfIndeterminacy;
  }
  return res;
}

static int __mul_infinite(const Integer& num1, const Integer& num2) {
  int sign = num1.sign() * num2.sign();
  if ((num1.sign() == kNegative) && (num2.sign() == kNegative))
    sign = kPositive;

  int res = kOperandInfIndeterminacy;
  if (is_zero(num1) && is_infinite(num2)) {
    res = kOperandInfNan;
  } else if (is_infinite(num1) && is_zero(num2)) {
    res = kOperandInfNan;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = sign;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = sign;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() != num2.sign())
      res = kOperandInfNegInfinity;
    else
      res = kOperandInfPosInfinity;
  } else { // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

/* 这里保证除数不为0 */
static int __div_infinite(const Integer& num1, const Integer& num2) {
  int sign = num1.sign() * num2.sign();
  if ((num1.sign() == kNegative) && (num2.sign() == kNegative))
    sign = kPositive;

  int res = kOperandInfIndeterminacy;
  if (is_zero(num2)) {
    divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  } else if (is_zero(num1)) {
    res = kOperandInfZero;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = sign;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfZero;
  } else if (is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfNan;
  } else { // !is_infinite(num1) && !is_infinite(num2)
    res = kOperandInfIndeterminacy;
  }
  return res;
}

static int __mod_infinite(const Integer& num1, const Integer& num2) {
  int res = kOperandInfIndeterminacy;
  if (is_zero(num2)) {
    divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  } else if (is_zero(num1)) {
    res = kOperandInfZero;
  } else if (!is_infinite(num1) && !is_infinite(num2)) {
    res = kOperandInfIndeterminacy;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    res = kOperandInfNan;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    res = kOperandInfIndeterminacy;
  } else { // is_infinite(num1) && is_infinite(num2)
    res = kOperandInfNan;
  }
  return res;
}

static Integer __infinite_operation_result(int inf) {
  Integer res;
  if (inf == kOperandInfNegInfinity) {
    res.infinite(false);
  } else if (inf == kOperandInfPosInfinity) {
    res.infinite(true);
  } else if (inf == kOperandInfZero) {
    res.zero();
  } else if (inf == kOperandInfOne) {
    res.one(true);
  } else if (inf == kOperandInfNegOne) {
    res.one(false);
  } else if (inf == kOperandInfNan) {
    res.nan();
  } else if (inf == kOperandInfIndeterminacy) {
    res.none();
  } else {
    invalid_arguments_exception("inf = %d", inf);
  }
  return res;
}

Integer add(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num1)) return num2;
  if (is_zero(num2)) return num1;

  int inf = __add_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  // num1与num2同号
  if (num1.sign() == num2.sign()) {
    bool o = false;
    bignum_t decimal_park_1 = num1.decimal_park(), decimal_park_2 = num2.decimal_park();
    bignum_t decimal_park = __add_decimal_park(decimal_park_1, decimal_park_2, &o);
    bignum_t integer_park_1 = num1.integer_park(), integer_park_2 = num2.integer_park();
    bignum_t integer_park = __add_integer_park(integer_park_1, integer_park_2, o);
    res.__set_integer_park(integer_park);
    res.__set_decimal_park(decimal_park);
    res.__set_sign(num1.sign());
  } else { // 异号
    if (num1.sign() > num2.sign()) {
      Integer _num2(num2);
      res = sub(num1, -_num2);
    } else {
      Integer _num1(num1);
      res = sub(num2, -_num1);
    }
  }
  return res;
}

Integer sub(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num1)) { res = num2; res.__set_sign(kNegative); return res; }
  if (is_zero(num2)) return num1;
  
  int inf = __sub_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t decimal_park_1 = num1.decimal_park(), decimal_park_2 = num2.decimal_park();
  bignum_t decimal_park;
  bignum_t integer_park_1 = num1.integer_park(), integer_park_2 = num2.integer_park();
  bignum_t integer_park;
  int sign = kPositive;
  bool t = false;

  int cmp = __cmp(num1, num2);
  if ((num1.sign() == kPositive) && (num2.sign() == kPositive)) {
    // a - b
    if ((cmp == 1) || (cmp == 0)) {
      // a >= b
      decimal_park = __sub_decimal_park(decimal_park_1, decimal_park_2, &t);
      integer_park = __sub_integer_park(integer_park_1, integer_park_2, t);
      sign = kPositive;
    } else {
      // a < b
      decimal_park = __sub_decimal_park(decimal_park_2, decimal_park_1, &t);
      integer_park = __sub_integer_park(integer_park_2, integer_park_1, t);
      sign = kNegative;
    }
  } else if ((num1.sign() == kPositive) && (num2.sign() == kNegative)) {
    // a - (-b)
    decimal_park = __add_decimal_park(decimal_park_1, decimal_park_2, &t);
    integer_park = __add_integer_park(integer_park_1, integer_park_2, t);
    sign = kPositive;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kPositive)) {
    // -a - b
    decimal_park = __add_decimal_park(decimal_park_1, decimal_park_2, &t);
    integer_park = __add_integer_park(integer_park_1, integer_park_2, t);
    sign = kNegative;
  } else if ((num1.sign() == kNegative) && (num2.sign() == kNegative)) {
    // -a - (-b)
    if (cmp == 1) {
      // a > b
      decimal_park = __sub_decimal_park(decimal_park_1, decimal_park_2, &t);
      integer_park = __sub_integer_park(integer_park_1, integer_park_2, t);
      sign = kNegative;
    } else { // cmp == -1 || cmp == 0
      // a <= b
      decimal_park = __sub_decimal_park(decimal_park_2, decimal_park_1, &t);
      integer_park = __sub_integer_park(integer_park_2, integer_park_1, t);
      sign = kPositive;
    }
  }/* end if */

  res.__set_sign(sign);
  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  return res;
}

/* 提取整数与小数部分合成一个大数，然后两个大数相乘最后
 * 结果取两个大数精度相加。
 * FIXME: 使用 Karatsuba 算法改写增加速度。
 */
Integer mul(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if ((is_zero(num1) || is_zero(num2)) && (!is_infinite(num1) && !is_infinite(num2))) {
    res.zero();
    return res;
  }
  if (is_one(num1)) return num2;
  if (is_one(num2)) return num1;

  int inf = __mul_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park(), decimal_park_1 = num1.decimal_park();
  bignum_t integer_park_2 = num2.integer_park(), decimal_park_2 = num2.decimal_park();
  bignum_t bignum1, bignum2;

  bignum1.insert(bignum1.end(), decimal_park_1.begin(), decimal_park_1.end());
  bignum1.insert(bignum1.end(), integer_park_1.begin(), integer_park_1.end());
  bignum2.insert(bignum2.end(), decimal_park_2.begin(), decimal_park_2.end());
  bignum2.insert(bignum2.end(), integer_park_2.begin(), integer_park_2.end());
  bignum_t product = __mul(bignum1, bignum2);

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  bignum_t integer_park, decimal_park;
  uinteger_t precision = num1.precision() + num2.precision(), fill_zero = 0;
  // 扩大几倍缩小几倍
  if (precision > product.size()) {
    fill_zero = precision - product.size();
    while (fill_zero--) product.push_back(0);
  }
  decimal_park.insert(decimal_park.end(), product.begin(), product.begin()+precision);
  integer_park.insert(integer_park.end(), product.begin()+precision, product.end());
  if (integer_park.empty()) integer_park.push_back(0);
  else if (integer_park.back() == 0) __shrink_zero(integer_park, true);
  if (decimal_park.front() == 0) __shrink_zero(decimal_park, false);

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  res.__set_sign(sign);

  return res;
}

Integer div(const Integer& num1, const Integer& num2) {
  Integer res;
  if (is_nan(num1) || is_nan(num2)) return res;
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_zero(num1)) { res.zero(); return res; }
  if (is_one(num2)) return num1;

  int inf = __div_infinite(num1, num2);
  res = __infinite_operation_result(inf);
  if (!is_none(res))
    return res;

  bignum_t integer_park_1 = num1.integer_park(), decimal_park_1 = num1.decimal_park();
  bignum_t integer_park_2 = num2.integer_park(), decimal_park_2 = num2.decimal_park();
  bignum_t bignum1, bignum2;

  bignum1.insert(bignum1.end(), decimal_park_1.begin(), decimal_park_1.end());
  bignum1.insert(bignum1.end(), integer_park_1.begin(), integer_park_1.end());

  bignum2.insert(bignum2.end(), decimal_park_2.begin(), decimal_park_2.end());
  bignum2.insert(bignum2.end(), integer_park_2.begin(), integer_park_2.end());

  // __div除法，前边不能存在0。
  __shrink_zero(bignum1, true); __shrink_zero(bignum2, true);

  //
  // 真正的运算，这里将小数部分也当作整数运算。完后一并
  // 计算精度。
  //
  uinteger_t multiple = 0;
  bignum_t quotient = __div(bignum1, bignum2, Integer::config_.max_quotient_borrow, &multiple);
  
  //
  // 分割整数部分与小数部分
  //
  bignum_t integer_park, decimal_park;
  uinteger_t precision = 0, fill_zero = 0;
  if (num1.precision() > num2.precision()) {
    precision = num1.precision() - num2.precision() + multiple;
    if (precision > quotient.size()) {
      fill_zero = precision - quotient.size();
      while (fill_zero--) quotient.push_back(0);
    }
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  } else if (num1.precision() < num2.precision()) {
    precision = multiple;
    fill_zero = num2.precision() - num1.precision();
    while (fill_zero--) quotient.push_front(0);
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  } else {
    precision = multiple;
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  }
  if (integer_park.empty()) integer_park.push_back(0);  // 保证整数部分最少是0
  __shrink_zero(decimal_park, false); // 删除小数末尾的0
  __shrink_zero(integer_park, true); // 删除整数末尾的0

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  res.__set_sign(sign);

  // return round(res, Integer::config_.precision);
  return res;
}

/* 这里认定num1是数字而num2是无穷。 */
static Integer __mod_infinite_operation(const Integer& num1, const Integer& num2) {
  my_assert(is_infinite(num2), "%s", "num2 is not infinite.");

  Integer res;
  if (is_zero(num1)) {
    res.zero();
  } else if (!is_infinite(num1)) {
    if (num1.sign() == num2.sign()) {
      res = num1;
    } else {
      res = num2;
    }
  }
  return res;
}

/* 余数在数学中的定义是始终大于等于0的。
 * 这里的整除运算都是在取floor后进行运算。
 */
void idiv(const Integer& num1, const Integer& num2, Integer& quo, Integer& rem) {
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_nan(num1) || is_nan(num2)) {
    quo = Integer("nan"); rem = Integer("nan");
    return;
  }
  if (is_zero(num1)) { 
    quo = Integer("0"); rem = Integer("0"); 
    return; 
  }
  if (is_one(abs(num2))) {
    quo = floor(num1);
    if (num2.sign() != num1.sign()) quo.__set_sign(kNegative);
    rem = Integer("0");
    return;
  }

  //
  // 处理与无穷的运算。
  //
  int div_inf = __div_infinite(num1, num2);
  int mod_inf = __mod_infinite(num1, num2);
  if ((div_inf != kOperandInfIndeterminacy) && (mod_inf != kOperandInfIndeterminacy)) {
    quo = __infinite_operation_result(div_inf);
    rem = __infinite_operation_result(mod_inf);
    return;
  } else if ((div_inf == kOperandInfZero) && (mod_inf == kOperandInfIndeterminacy)) {
    //
    // 出现商为0的情况，只有a/inf。但是模并不确定。
    //
    quo = __infinite_operation_result(div_inf);
    rem = __mod_infinite_operation(num1, num2);
    return;
  }

  my_assert((div_inf == kOperandInfIndeterminacy) && (mod_inf == kOperandInfIndeterminacy), \
            "%d != %d", div_inf, mod_inf);

  //
  // 这里是快速计算部分，将相等以及
  // 被除数小于除数的情况进行快速计算。
  //

  if (equ(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) quo = Integer("1");
    else quo = Integer("-1");
    rem = Integer("0");
    return;
  } else if (lt(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) {
      quo = Integer("0");
      if (num1.sign() == kPositive) rem = floor(num1);
      else rem = ceil(num1);
      return;
    } else {
      quo = Integer("-1");
      rem = sub(floor(abs(num2)), floor(abs(num1)));
      rem.__set_sign(num2.sign());
      return;
    }
  }

  //
  // 这里必然 abs(num1) > abs(num2)
  //
  quo = div(floor(num1), floor(num2));
  quo = floor(quo);
  rem = sub(floor(num1), mul(floor(num2), quo));
  return;
}

Integer quo(const Integer& num1, const Integer& num2) {
  Integer q, r;
  idiv(num1, num2, q, r);
  return q;
}

Integer rem(const Integer& num1, const Integer& num2) {
  return mod(num1, num2);
}

Integer mod(const Integer& num1, const Integer& num2) {
  Integer q, r;
  idiv(num1, num2, q, r);
  return r;
}

Integer abs(const Integer& num1) {
  Integer res(num1);
  res.__set_sign(kPositive);
  return res;
}

Integer pow(const Integer& num1, const Integer& exp) {
  if (is_nan(num1)) return Integer();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Integer res = "1", i = "0", j = integer(exp);
  while (i < j) {
    res *= num1;
    ++i;
  }
  return res;
}

Integer factorial(const Integer& num1) {
  if (num1.sign() == kNegative) operand_value_is_invalid_exception("%s", "num1 is negative");
  if (is_zero(num1) || is_one(num1)) return Integer("1");
  Integer a = integer(num1), b = "1";
  while (a != "1") {
    b *= a;
    --a;
  }
  return integer(b);
}

/*
 * Extern Euclid(gcd(a,b) = sa+tb)
 */
std::pair<Integer, Integer> extended_euclidean(const Integer& num1, const Integer& num2) {
  Integer q, a = integer(num1), b = integer(num2);
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

/*
 * Euclid(a = q_0b + r_0)
 */
Integer gcd(const Integer& num1, const Integer& num2) {
  Integer a,b,r,q;
  if (abs(integer(num1)) > abs(integer(num2))) {
    a = abs(integer(num1)); b = abs(integer(num2));
  } else if (abs(integer(num1)) < abs(integer(num2)))  {
    a = abs(integer(num2)); b = abs(integer(num1));
  } else {
    return abs(integer(num1));
  }

  while(true) {
    idiv(a, b, q, r);
    if (r == "0")
      break;
    a = b;
    b = r;
  };
  return b;
}

Integer lcm(const Integer& num1, const Integer& num2) {
  Integer res, g;
  g = gcd(num1, num2);
  res = mul(integer(num1), integer(num2));
  res = res / g;
  return res;
}

int sgn(const Integer& num1) {
  if (is_zero(num1)) return 0;
  if (num1.sign() == kNegative) return -1;
  return 1;
}

void copy(Integer& to, const Integer& from) {
  to.__set_sign(from.sign());
  to.__set_integer_park(from.integer_park());
  to.__set_decimal_park(from.decimal_park());
  to.__set_infinite(from.infinite());
}

void same_digits(Integer& num1, Integer& num2) {
  bignum_t integer_park_1 = num1.integer_park(), decimal_park_1 = num1.decimal_park();
  bignum_t integer_park_2 = num2.integer_park(), decimal_park_2 = num2.decimal_park();
  bignum_t x, y;

  if (integer_park_1.size() > integer_park_2.size()) {
    size_t n = integer_park_1.size() - integer_park_2.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_2.push_back(0);
    }
    num2.__set_integer_park(integer_park_2);
  } else if (integer_park_1.size() < integer_park_2.size()) {
    size_t n = integer_park_2.size() - integer_park_1.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_1.push_back(0);
    }
    num1.__set_integer_park(integer_park_1);
  }

  if (decimal_park_1.size() > decimal_park_2.size()) {
    size_t n = decimal_park_1.size() - decimal_park_2.size();
    for (size_t i = 0; i < n; i++) {
      decimal_park_2.push_front(0);
    }
    num2.__set_decimal_park(decimal_park_2);
  } else if (decimal_park_1.size() < decimal_park_2.size()) {
    size_t n = decimal_park_2.size() - decimal_park_1.size();
    for (size_t i = 0; i < n; i++) {
      decimal_park_1.push_front(0);
    }
    num1.__set_decimal_park(decimal_park_1);
  }
}

} // namespace mynum