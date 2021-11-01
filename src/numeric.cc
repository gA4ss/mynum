#include <mynum/numeric.h>
#include <cstring>

namespace mynum {

Numeric::Numeric() { zero(); }

Numeric::Numeric(const char* number, int base) {
  zero();
  __create_from_string(number, base);
}

Numeric::Numeric(std::string& number, int base) {
  zero();
  __create_from_string(number.c_str(), base);
}

Numeric::Numeric(Numeric* number) {
  assign(*number);
}

Numeric::Numeric(const Numeric& number) {
  assign(number);
}

Numeric::~Numeric() {}

void Numeric::assign(const Numeric& n) {
  sign_ = n.sign();
  integer_park_ = n.integer_park();
  decimal_park_ = n.decimal_park();
  infinite_ = n.infinite();
}

void Numeric::zero() {
  sign_ = kPositive;
  infinite_ = false;

  integer_park_.clear();
  decimal_park_.clear();
  integer_park_.push_back(0);
}

void Numeric::one(bool sign) {
  sign_ = sign;
  infinite_ = false;

  integer_park_.clear();
  decimal_park_.clear();
  integer_park_.push_back(1);
}

void Numeric::nan(bool sign) {
  sign_ = static_cast<int>(sign);
  infinite_ = false;
  integer_park_.clear();
  decimal_park_.clear();
}

void Numeric::none() {
  nan(false);
}

std::string Numeric::str() const {
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

  for (int i = integer_park_.size()-1; i >= 0; i--) {
    char c = static_cast<char>(integer_park_[i] + kZeroCode);
    ret.push_back(c);
  }

  if (!decimal_park_.empty()) {
    ret.push_back('.');
    integer_t precision = static_cast<integer_t>(decimal_park_.size());
    for (integer_t i = precision-1; i >= 0; i--) {
      char c = static_cast<char>(decimal_park_[i] + kZeroCode);
      ret.push_back(c);
    }
  }

  return ret;
}

void Numeric::set_sign(bool negative=false) {
  sign_ = (negative == true) ? kNegative : kPositive;
}

void Numeric::set_infinite(int sign) {
  sign_ = static_cast<int>(sign);
  infinite_ = true;
}

void Numeric::set_integer_park_zero() {
  integer_park_.clear();
  integer_park_.push_back(0);
}

void Numeric::set_decimal_park_zero() {
  decimal_park_.clear();
  decimal_park_.push_back(0);
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

void Numeric::__create_from_string(const char* number, int base) {
  my_assert(number, "%s", "number ptr is null.");
  __invalid_base(base);             // FIXME: 目前只支持10进制构造。
  __check_number_format(number);    // 检查number字符串的格式。

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

  //
  // 这里分为两部分处理,整数部分与小数部分
  //
  std::string integer_str = "", decimal_str = "";
  uinteger_t precision = 0;
  std::size_t found = number_str.find('.');
  if (found != std::string::npos) {
    integer_str = number_str.substr(0, found);
    decimal_str = number_str.substr(found + 1);
    precision = decimal_str.size();
  } else {
    integer_str = number_str;
    precision = 0;
  }

  if (integer_str.empty()) integer_str = "0";

  integer_park_ = string_to_bignum(integer_str.c_str(), true);
  if (precision) decimal_park_ = string_to_bignum(decimal_str.c_str(), false);
}

/* 对比无穷，考虑符号。
 * 返回值:
 * 1 : num1 > num2
 * 0 : num1 == num2
 * -1 : num1 < num2
 * -2 : num1 与 num2 关系不确定
 */
int Numeric::__cmp_infinite(const Numeric& num1, const Numeric& num2) {
  if (is_infinite(num1) && is_infinite(num2)) {
    if (num1.sign() == num2.sign()) return 0;
    else if (num1.sign() > num2.sign()) return 1;
    return -1;
  } else if (is_infinite(num1) && !is_infinite(num2)) {
    if (num1.sign() == kNegative) return -1;
    return 1;
  } else if (!is_infinite(num1) && is_infinite(num2)) {
    if (num2.sign() == kNegative) return 1;
    return -1;
  }
  return -2;
}

int Numeric::__add_infinite(const Numeric& num1, const Numeric& num2) {
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

int Numeric::__sub_infinite(const Numeric& num1, const Numeric& num2) {
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

int Numeric::__mul_infinite(const Numeric& num1, const Numeric& num2) {
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
int Numeric::__div_infinite(const Numeric& num1, const Numeric& num2) {
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

int Numeric::__mod_infinite(const Numeric& num1, const Numeric& num2) {
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

Numeric Numeric::__infinite_operation_result(int inf) {
  Numeric res;
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

/* 此函数只对比值的情况，不考虑符号情况。*/
static int __cmp(const Numeric& num1, const Numeric& num2) {
  int res = cmp(num1.integer_park(), num2.integer_park());
  if (res != 0) return res;
  // 整数相等，则比对小数。
  if (!num1.decimal_park().empty() && !num2.decimal_park().empty())
    res = cmp(num1.decimal_park(), num2.decimal_park(), true);
  return res;
}

bool equ(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return true;

  int c = __cmp_infinite(num1, num2);
  if (c == 0) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  c = __cmp(num1, num2);
  if (num1.sign() == num2.sign() && c == 0)
    return true;
  return false;
}

bool gt(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return false;

  int c = __cmp_infinite(num1, num2);
  if (c == 1) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  if (num1.sign() > num2.sign())
    return true;
  else if (num1.sign() < num2.sign())
    return false;

  //
  // 这里表示同号
  //
  my_assert(num1.sign() == num2.sign(), "\'%d\' != \'%d\'", num1.sign(), num2.sign());
  c = __cmp(num1, num2);
  if (c == 0) {
    return false;
  } else if (c == 1) {
    if (num1.sign() == kNegative)
      return false;
  } else if (c == -1) {
    if (num1.sign() == kPositive)
      return false;
  }
  return true;
}

bool lt(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (is_zero(num1) && is_zero(num2)) return false;

  int c = __cmp_infinite(num1, num2);
  if (c == -1) return true;
  if (c != -2) return false;

  my_assert(c == -2, "c = %d", c);
  if (num1.sign() > num2.sign())
    return false;
  else if (num1.sign() < num2.sign())
    return true;

  //
  // 这里表示同号
  //
  my_assert(num1.sign() == num2.sign(), "\'%d\' != \'%d\'", num1.sign(), num2.sign());
  c = __cmp(num1, num2);
  if (c == 0) {
    return false;
  } else if (c == 1) {
    if (num1.sign() == kNegative)
      return true;
  } else if (c == -1) {
    if (num1.sign() == kPositive)
      return true;
  }
  return false;
}

bool ge(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return gt(num1, num2) || equ(num1, num2);
}

bool le(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  return lt(num1, num2) || equ(num1, num2);
}

bool is_zero(const Numeric& num1) {
  if (is_infinite(num1)) return false;

  bignum_t integer_park = num1.integer_park();
  bignum_t decimal_park = num1.decimal_park();
  // 两个队列没有值就是0。
  if (integer_park.empty() && decimal_park.empty())
    return true;
  
  for (size_t i = 0; i < integer_park.size(); i++) {
    if (integer_park[i] != 0)
      return false;
  }

  if (num1.precision()) {
    for (size_t i = 0; i < decimal_park.size(); i++)
      if (decimal_park[i] != 0)
        return false;
  }

  return true;
}

bool is_one(const Numeric& num1) {
  bignum_t x = string_to_bignum("1");
  bool integer_cmp = (cmp(num1.integer_park(), x) == 0);
  if (num1.precision() == 0)
    return integer_cmp;

  x = string_to_bignum("0");
  return integer_cmp && (cmp(num1.decimal_park(), x) == 0);
}

bool is_nan(const Numeric& num1) {
  if (num1.infinite()) return false;
  if (num1.integer_park().size() == 0 && \
      num1.decimal_park().size() == 0)
    return true;
  return false;
}

bool is_infinite(const Numeric& num1) {
  return num1.infinite();
}

bool is_none(const Numeric& num1) {
  if ((is_nan(num1)) && (num1.sign() == kNegative))
    return true;
  return false;
}

bool is_integer(const Numeric& num1) {
  if (num1.precision() == 0) return true;

  if (num1.precision()) {
    bignum_t decimal_park = num1.decimal_park();
    for (size_t i = 0; i < decimal_park.size(); i++)
      if (decimal_park[i] != 0)
        return false;
  }
  return true;
}

bool is_float(const Numeric& num1) {
  if (num1.precision() == 0) return false;

  bignum_t decimal_park = num1.decimal_park();
  for (size_t i = 0; i < decimal_park.size(); i++)
    if (decimal_park[i] != 0)
      return true;
  return false;
}

void copy(Numeric& to, const Numeric& from) {
  to.set_sign(from.sign());
  to.set_integer_park(from.integer_park());
  to.set_decimal_park(from.decimal_park());
  to.set_infinite(from.infinite());
}

void same_digits(Numeric& num1, Numeric& num2) {
  bignum_t integer_park_1 = num1.integer_park(), decimal_park_1 = num1.decimal_park();
  bignum_t integer_park_2 = num2.integer_park(), decimal_park_2 = num2.decimal_park();
  bignum_t x, y;

  if (integer_park_1.size() > integer_park_2.size()) {
    size_t n = integer_park_1.size() - integer_park_2.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_2.push_back(0);
    }
    num2.set_integer_park(integer_park_2);
  } else if (integer_park_1.size() < integer_park_2.size()) {
    size_t n = integer_park_2.size() - integer_park_1.size();
    for (size_t i = 0; i < n; i++) {
      integer_park_1.push_back(0);
    }
    num1.set_integer_park(integer_park_1);
  }

  if (decimal_park_1.size() > decimal_park_2.size()) {
    size_t n = decimal_park_1.size() - decimal_park_2.size();
    for (size_t i = 0; i < n; i++) {
      decimal_park_2.push_front(0);
    }
    num2.set_decimal_park(decimal_park_2);
  } else if (decimal_park_1.size() < decimal_park_2.size()) {
    size_t n = decimal_park_2.size() - decimal_park_1.size();
    for (size_t i = 0; i < n; i++) {
      decimal_park_1.push_front(0);
    }
    num1.set_decimal_park(decimal_park_1);
  }
}

} // namespace mynum