#include <mynum/core/numeric.h>

#include <cstring>

namespace mynum {
namespace core {

static const unit_t kZeroCode = 48;

/* 整数部分消减 true, 小数部分消减 false。
 * 保留最后一个0。
 * 在内部除法中__div中不能使用缩减，因为
 * 最末尾的0是为了占位。
 */
static void __shrink_zero(bignum_t& a, bool reverse=false) {
  if (a.empty()) return;
  if ((a.size() == 1) && (a[0] == 0)) return;
  
  if (reverse) {
    int l = static_cast<int>(a.size());
    for (int i = l-1; i > 0; i--) {
      if (a[i] == 0) {
        a.pop_back();
      } else {
        break;
      }
    }
  } else {
    int l = static_cast<int>(a.size());
    for (int i = 0; i < l; i++) {
      if (a[i] == 0) {
        a.pop_front();
      } else {
        break;
      }
    }
  }
}

config_t Numeric::config_ = { 128 };

Numeric::Numeric() { nan(); }

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

void Numeric::nan(bool sign) {
  sign_ = static_cast<int>(sign);
  infinite_ = false;
  integer_park_.clear();
  decimal_park_.clear();
}

void Numeric::none() {
  nan(false);
}

void Numeric::zero() {
  sign_ = kPositive;
  infinite_ = false;

  integer_park_.clear();
  decimal_park_.clear();
  integer_park_.push_back(0);
}

void Numeric::infinite(bool sign) {
  nan();
  sign_ = static_cast<int>(sign);
  infinite_ = true;
}

void Numeric::one(bool sign) {
  sign_ = sign;
  infinite_ = false;

  integer_park_.clear();
  decimal_park_.clear();
  integer_park_.push_back(1);
}

void Numeric::assign(const Numeric& number) {
  sign_ = number.sign();
  integer_park_ = number.integer_park();
  decimal_park_ = number.decimal_park();
  infinite_ = number.infinite();
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

static void __invalid_base(int base) {
  if (base != 10 && base != 2 && base != 8 && base != 16) {
    invalid_arguments_exception("base = %d", base);
  }
}

static bool __check_number_format(const char* number) {
  return true;
}

void Numeric::__create_from_string(const char* number, int base) {
  my_assert(number, "%s", "number ptr is null.");
  __invalid_base(base);   // FIXME: 目前只支持10进制构造。

  // 检查number字符串的格式
  if (!__check_number_format(number)) {
    invalid_arguments_exception("number = %s", number);
  }

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
  if (number_str[0] == '-') {
    sign_ = kNegative;
    number_str.erase(0, 1);
  } else if (number_str[0] == '+') {
    sign_ = kPositive;
    number_str.erase(0, 1);
  } else {
    sign_ = kPositive;
  }

  // nan
  if (number_str == "nan") {
    nan();
    return;
  }

  // inf
  if (number_str == "inf") {
    infinite(sign_);
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

  integer_park_.clear();
  decimal_park_.clear();
  length = integer_str.size();
  for (size_t i = 0; i < length; i++) {
    unit_t j = static_cast<unit_t>(integer_str[i]) - kZeroCode;
    integer_park_.push_front(j);
  }

  if (precision) {
    length = decimal_str.size();
    for (size_t i = 0; i < length; i++) {
      unit_t j = static_cast<unit_t>(decimal_str[i]) - kZeroCode;
      decimal_park_.push_front(j);
    }
  }

  __shrink_zero(integer_park_, true);
  __shrink_zero(decimal_park_, false);
}

void Numeric::__set_integer_park_zero() {
  integer_park_.clear();
  integer_park_.push_back(0);
}

void Numeric::__set_decimal_park_zero() {
  decimal_park_.clear();
  decimal_park_.push_back(0);
}

static int __cmp(const bignum_t& a, const bignum_t& b, bool is_float=false) {
  int res = 0, l = 0;
  bignum_t _a = a, _b = b;
  if (_a.size() > _b.size()) {
    l = static_cast<int>(_a.size() - _b.size());
    for (int i = 0; i < l; i++) {
      if (is_float) _b.push_front(0);
      else _b.push_back(0);
    }
  } else if (_a.size() < _b.size()) {
    l = static_cast<int>(_b.size() - _a.size());
    for (int i = 0; i < l; i++) {
      if (is_float) _a.push_front(0);
      else _a.push_back(0);
    }
  }

  my_assert(_a.size() == _b.size(), "(_a.size() = %d, _b.size() = %d) is not equal.", _a.size(), _b.size());
  l = static_cast<int>(_a.size());
  for (int i = l-1; i >= 0; i--) {
    if (_a[i] > _b[i]) {
      res = 1;
      break;
    } else if (_a[i] < _b[i]) {
      res = -1;
      break;
    }
  }
  return res;
}

/* 此函数只对比值的情况，不考虑符号情况。*/
static int __cmp(const Numeric& num1, const Numeric& num2) {
  int res = __cmp(num1.integer_park(), num2.integer_park());
  if (res != 0) return res;
  // 整数相等，则比对小数。
  res = __cmp(num1.decimal_park(), num2.decimal_park(), true);
  return res;
}

/* 对比无穷，考虑符号。
 * 返回值:
 * 1 : num1 > num2
 * 0 : num1 == num2
 * -1 : num1 < num2
 * -2 : num1 与 num2 关系不确定
 */
static int __cmp_infinite(const Numeric& num1, const Numeric& num2) {
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
  Numeric o("1");
  return equ(num1, o);
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

bool is_odd(const Numeric& num1) {
  if (!is_integer(num1)) operand_type_is_invalid_exception("%s", "num1 is not integer.");
  unit_t x = *(num1.integer_park().begin());
  if (x%2 == 0) return false;
  return true;
}

bool is_even(const Numeric& num1) {
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

static int __add_infinite(const Numeric& num1, const Numeric& num2) {
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

static int __sub_infinite(const Numeric& num1, const Numeric& num2) {
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

static int __mul_infinite(const Numeric& num1, const Numeric& num2) {
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
static int __div_infinite(const Numeric& num1, const Numeric& num2) {
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

static int __mod_infinite(const Numeric& num1, const Numeric& num2) {
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

static Numeric __infinite_operation_result(int inf) {
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

// ----------------------------------------------------------------------

static bignum_t __add_integer_park(const bignum_t& a, const bignum_t& b, bool o) {
  bignum_t x, y, z;
  if (a.empty() && !b.empty()) {
    x.push_back(0);
    y = b;
  } else if (!a.empty() && b.empty()) {
    x = a;
    y.push_back(0);
  } else if (a.empty() && b.empty()) {
    x.push_back(0);
    y.push_back(0);
  } else {
    x = a;
    y = b;
  }

  if (x.size() > y.size()) {
    y.resize(x.size());
  } else if (x.size() < y.size()) {
    x.resize(y.size());
  }

  unit_t c = 0, r = static_cast<uint8_t>(o);
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    c = x[i] + y[i] + r;
    if (c >= 10) {
      c = c - 10;
      r = 1;
    } else {
      r = 0;
    }
    z.push_back(c);
  }
  // 如果存在进位则保存
  if (r) z.push_back(r);
  __shrink_zero(z, true);
  return z;
}

static bignum_t __add_decimal_park(const bignum_t& a, const bignum_t& b, bool* o) {
  my_assert(o, "%s", "o is nullptr.");
  *o = false;
  if (a.empty() && !b.empty()) {
    return b;
  } else if (!a.empty() && b.empty()) {
    return a;
  } else if (a.empty() && b.empty()) {
    bignum_t c = {0};
    return c;
  }
  bignum_t x = a, y = b, z;

  if (x.size() > y.size()) {
    size_t l = x.size() - y.size();
    for (size_t i = 0; i < l; i++) {
      y.push_front(0);
    }
  } else if (x.size() < y.size()) {
    size_t l = y.size() - x.size();
    for (size_t i = 0; i < l; i++) {
      x.push_front(0);
    }
  }

  unit_t r = 0, c = 0;
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    c = x[i] + y[i] + r;
    if (c >= 10) {
      c = c - 10;
      r = 1;
    } else {
      r = 0;
    }
    z.push_back(c);
  }
  *o = static_cast<bool>(r);    // 设置是否进位
  __shrink_zero(z, false);
  return z;
}

Numeric add(const Numeric& num1, const Numeric& num2) {
  Numeric res;
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
      Numeric _num2(num2);
      res = sub(num1, -_num2);
    } else {
      Numeric _num1(num1);
      res = sub(num2, -_num1);
    }
  }
  return res;
}

static bignum_t __sub_decimal_park(const bignum_t& a, const bignum_t& b, bool* t=nullptr) {
  my_assert(t, "%s", "t is nullptr.");
  bignum_t x, y, z;
  if (t) *t = false;
  if (a.empty() && !b.empty()) {
    x.push_back(0);
    y = b;
  } else if (!a.empty() && b.empty()) {
    x = a;
    y.push_back(0);
  } else if (a.empty() && b.empty()) {
    bignum_t c = {0};
    return c;
  } else {
    x = a;
    y = b;
  }

  if (x.size() > y.size()) {
    size_t l = x.size() - y.size();
    for (size_t i = 0; i < l; i++) {
      y.push_front(0);
    }
  } else if (x.size() < y.size()) {
    size_t l = y.size() - x.size();
    for (size_t i = 0; i < l; i++) {
      x.push_front(0);
    }
  }

  unit_t r = 0, c = 0;
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    if (x[i] - r >= y[i]) {
      c = x[i] - y[i] - r;
      r = 0;
    } else {
      c = x[i] + 10 - y[i];
      r = 1; 
    }
    z.push_back(c);
  }
  if (t) *t = static_cast<bool>(r);    // 设置是否借位
  __shrink_zero(z, false);
  return z;
}

/* 这里已经保证了a的数值肯定大于b的数值 */
static bignum_t __sub_integer_park(bignum_t& a, bignum_t& b, bool t=false) {
  bignum_t x, y, z;
  if (a.empty() && !b.empty()) {
    x.push_back(0);
    y = b;
  } else if (!a.empty() && b.empty()) {
    x = a;
    y.push_back(0);
  } else if (a.empty() && b.empty()) {
    x.push_back(0);
    y.push_back(0);
  } else {
    x = a;
    y = b;
  }

  if (x.size() > y.size()) {
    y.resize(x.size());
  } else if (x.size() < y.size()) {
    x.resize(y.size());
  }

  unit_t r = static_cast<unit_t>(t), c = 0;
  size_t l = x.size();
  for (size_t i = 0; i < l; i++) {
    if (x[i] - r >= y[i]) {
      c = x[i] - y[i] - r;
      r = 0;
    } else {
      c = x[i] + 10 - y[i] - r;
      r = 1;
    }
    z.push_back(c);
  }
  if (r != 0) {
    r = 1;
  }
  my_assert(r == 0, "%s", "borrow must be 0.");
  __shrink_zero(z, true);
  return z;
}

Numeric sub(const Numeric& num1, const Numeric& num2) {
  Numeric res;
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

static bignum_t __mul(const bignum_t& a, const bignum_t& b) {
  if (a.empty() || b.empty()) {
    bignum_t c = {0};
    return c;
  }
  bignum_t x, y, z;
  size_t m = 0, n = 0;

  // 保证 m >= n
  if (a.size() >= b.size()) {
    x = a; m = a.size();
    y = b; n = b.size();
  } else if (a.size() < b.size()) {
    y = a; n = a.size();
    x = b; m = b.size();
  }
  z.resize(m+n);

  unit_t q = 0, t = 0;
  for (size_t j = 0; j < n; j++) {
    q = 0;
    for (size_t i = 0; i < m; i++) {
      t = x[i] * y[j] + z[i+j] + q;
      z[i+j] = t % 10;
      q = t / 10;
    }
    z[j+m] = q;
  }

  __shrink_zero(z, true);
  return z;
}

/* 提取整数与小数部分合成一个大数，然后两个大数相乘最后
 * 结果取两个大数精度相加。
 * FIXME: 使用 Karatsuba 算法改写增加速度。
 */
Numeric mul(const Numeric& num1, const Numeric& num2) {
  Numeric res;
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
  uinteger_t precision = num1.precision() + num2.precision();
  //size_t digit = product.size() - precision;
  decimal_park.insert(decimal_park.end(), product.begin(), product.begin()+precision);
  integer_park.insert(integer_park.end(), product.begin()+precision, product.end());

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  res.__set_sign(sign);

  return res;
}

/*
 * a1表示a的首项系数，以此类推。B为某个进制。
 * 1.当a,b的位数一致，a1 >= b1，a > b。
 *  1-1 : a1 = b1 ---> q = 1.
 *  1-2 : a1 > b1 ---> q1 = floor(a_1/b_1), q2 = max(floor( (a1*B+a2-B+1) / (b1*B+b2)) ), 1)
 *        q1 <= q <= q2
 * 2.当a的位数比b大一位，a1 <= b1，a > b, a < b*B(仅差一位)。
 *  2-1 : q1 = min(floor( (a1*B+a2) / b1 ), B-1)
 *        q <= q1
 * 证明见《计算机代数》【陈玉福，张智勇】 25-26页。
 */
static std::pair<unit_t, unit_t> __get_quotient_range(const bignum_t& a, const bignum_t& b) {
  const unit_t B = 10;
  unit_t a1 = *(a.end()-1), b1 = *(b.end()-1);
  unit_t a2 = 0, b2 = 0;

  if (a.size() >= 2) a2 = *(a.end()-2);
  if (b.size() >= 2) b2 = *(b.end()-2);

  if (a.size() == b.size()) {
    //
    // 第一种情况
    //
    if (a1 == b1)
      return std::make_pair(1, 1);
    else { // 这里一定是 a1 > b1
      my_assert(a1 > b1, "a1(%d) < b1(%d)", a1, b1);
      unit_t q1 = a1 / b1, q2 = std::max((a1*B+a2-B+1)/(b1*B+b2), 1);
      return q1 < q2 ? std::make_pair(q1, q2) : std::make_pair(q2, q1);
    }
  } else {
    //
    // 第二种情况
    //
    unit_t q = std::min((a1*B+a2)/b1, B-1);
    return std::make_pair(1, q);
  }
  my_assert(false, "%s", "never go here!");
  return std::make_pair(0, 0);
}

/* 不考虑符号，这里保证b不为0。 */
static bignum_t __div(const bignum_t& a, const bignum_t& b, 
                      uinteger_t max_quotient_borrow, 
                      uinteger_t* m=nullptr) {
  //const bignum_t ten = {0, 1};    // 表示10
  bignum_t x = a, y = b;

  if (__cmp(x, y) == 0) {
    return {1};
  }

  bignum_t quotient, product, dividend = x, divisor = y, remainder = {0};
  uinteger_t dividend_remainder_digits = dividend.size(), multiple = 0; // 这里扩大了多少倍，返回结果缩小多少倍。

  //
  // 这里对被除数与除数做一些初始化工作
  //
  int cmp = __cmp(dividend, divisor);
  if (cmp == -1) {
    while (__cmp(dividend, divisor) == -1) {
      dividend.push_front(0); // dividend = __mul(dividend, ten);
      quotient.push_front(0);
      ++multiple;
    }
    dividend_remainder_digits = 0;
  } else { // cmp == 1
    //
    // 从末尾取a与b相同的位数 : a_n, b_n
    // 如果 a_n < b_n, 则取a_{n+1}
    //
    size_t n = divisor.size();
    dividend_remainder_digits -= n;
    dividend = bignum_t(x.begin()+dividend_remainder_digits, x.end());
    if (__cmp(dividend, divisor) == -1) {
      // 如果小于这里dividend必比divisor多一位。
      --dividend_remainder_digits;
      dividend = bignum_t(x.begin()+dividend_remainder_digits, x.end());
    }
  }

  // 第一次运行必须保证被除数大于除数。
  while (true) {
    // 尝试获取商的范围。
    std::pair<unit_t, unit_t> quo_range = __get_quotient_range(dividend, divisor);
    unit_t q = 0;
    for (q = quo_range.first; q <= quo_range.second; q++) {
      product = __mul(divisor, {q});
      //
      // product 必然小于等于 dividend
      //
      remainder = __sub_integer_park(dividend, product, false);
      int c = __cmp(divisor, remainder);
      if ((c == -1) || (c == 0)) {
        continue;
      } else {
        quotient.push_front(q);
        break;
      }
    }

    //
    // 算法结束条件： 1，2需要同时满足。3是单独满足即可。
    // 1.检查余数如果为0。
    // 2.被除数没有多余的位。
    // 3.商的精度足够了。
    //
    if ((__cmp(remainder, {0}) == 0) && (dividend_remainder_digits == 0))
      break;
    if (max_quotient_borrow != kNumericUnitMax) {
      if (multiple >= max_quotient_borrow) {
        break;
      }
    }

    //
    // 更新被除数
    //
    dividend = remainder;
    if (dividend_remainder_digits == 0) {
      //
      // 这里其实有个隐含条件就是余数不为0。因为到达这里余数肯定不为零。
      // 上面的退出条件已经判断了。 
      // my_assert(__cmp(remainder, {0}) != 0, "%s", "remainder is zero!");
      //
      while (__cmp(dividend, divisor) == -1) {
        dividend.push_front(0); // dividend = __mul(dividend, ten);
        quotient.push_front(0);
        ++multiple;
      }
      //
      // 这里不存在借用被除数的位。所以
      // 商的0要比被除数少一个
      //
      quotient.pop_front();
    } else {
      if (__cmp(dividend, {0}) == 0) dividend.clear();  // 余数为零。
      while ((__cmp(dividend, divisor) == -1) && (dividend_remainder_digits != 0)) {
        dividend.insert(dividend.end(), 
                        x.begin()+dividend_remainder_digits-1, 
                        x.begin()+dividend_remainder_digits);
        --dividend_remainder_digits;
      }

      // 如果被除数剩余全部是0。
      if (__cmp(dividend, {0}) == 0) {
        quotient.insert(quotient.begin(), dividend.begin(), dividend.end());
        break;
      }

      //
      // 如果进入循环说明 dividend_remainder_digits == 0，
      // 这时候如果dividend仍然小于divisor则进行借位。
      // 因为这边是正常补位所以不进行弹出了。
      //
      while (__cmp(dividend, divisor) == -1) {
        dividend.push_front(0); // dividend = __mul(dividend, ten);
        quotient.push_front(0);
        ++multiple;
      }
    }
  }/* end while */

  if(m) *m = multiple;
  return quotient;
}

Numeric div(const Numeric& num1, const Numeric& num2) {
  Numeric res;
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

  uinteger_t multiple = 0;
  bignum_t quotient = __div(bignum1, bignum2, Numeric::config_.max_quotient_borrow, &multiple);

  //
  // 分割整数与小数部分
  //
  bignum_t integer_park, decimal_park;
  uinteger_t precision = 0;
  if (num1.precision() > num2.precision()) {
    precision = num1.precision() - num2.precision() + multiple;
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  } else if (num1.precision() < num2.precision()) {
    precision = num2.precision() - num1.precision();
    integer_park.insert(integer_park.end(), quotient.end()-precision-1, quotient.end());
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.end()-precision-1);
  } else {
    precision = multiple;
    decimal_park.insert(decimal_park.end(), quotient.begin(), quotient.begin()+precision);
    integer_park.insert(integer_park.end(), quotient.begin()+precision, quotient.end());
  }

  __shrink_zero(decimal_park, false);
  __shrink_zero(integer_park, true);

  int sign = kPositive;
  if (num1.sign() == num2.sign()) sign = kPositive;
  else sign = kNegative;

  res.__set_integer_park(integer_park);
  res.__set_decimal_park(decimal_park);
  res.__set_sign(sign);

  return res;
}

/* 这里认定num1是数字而num2是无穷。 */
static Numeric __mod_infinite_operation(const Numeric& num1, const Numeric& num2) {
  my_assert(is_infinite(num2), "%s", "num2 is not infinite.");

  Numeric res;
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
void idiv(const Numeric& num1, const Numeric& num2, Numeric& quo, Numeric& rem) {
  if (is_zero(num2)) divisor_is_zero_exception("num2 = %s", num2.str().c_str());
  if (is_nan(num1) || is_nan(num2)) {
    quo = Numeric("nan"); rem = Numeric("nan");
    return;
  }
  if (is_zero(num1)) { 
    quo = Numeric("0"); rem = Numeric("0"); 
    return; 
  }
  if (is_one(abs(num2))) {
    quo = floor(num1);
    if (num2.sign() != num1.sign()) quo.__set_sign(kNegative);
    rem = Numeric("0");
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
    if (num1.sign() == num2.sign()) quo = Numeric("1");
    else quo = Numeric("-1");
    rem = Numeric("0");
    return;
  } else if (lt(abs(num1), abs(num2))) {
    if (num1.sign() == num2.sign()) {
      quo = Numeric("0");
      if (num1.sign() == kPositive) rem = floor(num1);
      else rem = ceil(num1);
      return;
    } else {
      quo = Numeric("-1");
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

Numeric quo(const Numeric& num1, const Numeric& num2) {
  Numeric q, r;
  idiv(num1, num2, q, r);
  return q;
}

Numeric rem(const Numeric& num1, const Numeric& num2) {
  return mod(num1, num2);
}

Numeric mod(const Numeric& num1, const Numeric& num2) {
  Numeric q, r;
  idiv(num1, num2, q, r);
  return r;
}

Numeric or_bits(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return Numeric();
  if (is_zero(num1)) return num2; 
  if (is_zero(num2)) return num1;
  if (is_infinite(num1) || is_infinite(num2))
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");

  Numeric a = num1, b = num2;
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
  Numeric c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() | b.sign());
  return c;
}

Numeric and_bits(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return Numeric();
  if (is_infinite(num1) || is_infinite(num2)) 
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");
  if (is_zero(num1) || is_zero(num2)) return Numeric("0");

  Numeric a = num1, b = num2;
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

  Numeric c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() & b.sign());
  return c;
}

Numeric xor_bits(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return Numeric();
  if (is_infinite(num1) || is_infinite(num2)) 
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");

  Numeric a = num1, b = num2;
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
  Numeric c;
  c.__set_integer_park(integer_park_3);
  c.__set_decimal_park(decimal_park_3);
  c.__set_sign(a.sign() ^ b.sign());
  return c;
}

Numeric not_bits(const Numeric& num1) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_zero(num1)) return Numeric("1");
  if (is_one(abs(num1))) return Numeric("0");

  Numeric res = num1;
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
Numeric lshift_bits(const Numeric& num1, const Numeric& bits) {
  if (is_nan(num1)) return Numeric();
  if (is_nan(bits)) operand_value_is_invalid_exception("%s", "bits is nan");
  if (is_infinite(num1) || is_infinite(bits))
    operand_value_is_invalid_exception("%s", "num1 or num2 is infinite");
  if (is_float(num1) || is_float(bits))
    operand_type_is_invalid_exception("%s", "num1 or bits is float");
  if (is_zero(num1)) return Numeric("0");

  Numeric res = floor(num1), one("1"), two("2");
  Numeric i("0");
  while(lt(i, bits)) {
    res = mul(res, two);
    i = add(i, one);
  }
  return res;
}

/* 将num1下取整后进行运算。 */
Numeric rshift_bits(const Numeric& num1, const Numeric& bits) {
  if (is_nan(num1)) return Numeric();
  if (is_nan(bits)) operand_value_is_invalid_exception("%s", "bits is nan");
  if (is_infinite(num1) || is_infinite(bits))
    operand_value_is_invalid_exception("%s", "num1 or bits is infinite");
  if (is_float(num1) || is_float(bits))
    operand_type_is_invalid_exception("%s", "num1 or bits is float");
  if (is_zero(num1)) return Numeric("0");

  Numeric res = floor(num1), one("1"), two("2");
  Numeric i("0");
  while(lt(i, bits)) {
    res = quo(res, two);
    i = add(i, one);
  }
  return res;
}

Numeric abs(const Numeric& num1) {
  Numeric res(num1);
  res.__set_sign(kPositive);
  return res;
}

Numeric floor(const Numeric& num1) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) return Numeric("inf");
  if (is_integer(num1)) return num1;

  Numeric res = num1;
  res.__set_decimal_park_zero();
  if (num1.sign() == kNegative) {
    res.__set_sign(true);
    res = add(res, Numeric("1"));
    res.__set_sign(kNegative);
  }
  return res;
}

Numeric ceil(const Numeric& num1) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) return Numeric("inf");
  if (is_integer(num1)) return num1;
  
  Numeric res = num1;
  res.__set_decimal_park_zero();
  if (num1.sign() == kPositive) {
    res = add(res, Numeric("1"));
  }
  return res;
}

static bignum_t __effective_digit(const Numeric& num1, uinteger_t precision, unit_t& v) {
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
  return new_decimal_park;
}

static bool __mantissa_is_5(const Numeric& num1) {
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

/* 当尾数为5，而尾数后面的数字均为0时，应看尾数“5”的前一位：若前一位数字此时为奇数，
 * 就应向前进一位；若前一位数字此时为偶数，则应将尾数舍去。数字“0”在此时应被视为偶数。
 */
Numeric round(const Numeric& num1, uinteger_t precision) {
  if (is_nan(num1)) return Numeric();
  if (is_zero(num1)) return Numeric("0");
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");
  if (is_integer(num1)) return num1;
  if (precision >= num1.precision()) return num1;

  if (__mantissa_is_5(num1)) {
    if (is_odd(integer(num1))) {
      if (num1.sign() == kPositive)
        return integer(num1 + "1");
      else
        return integer(num1 + "-1");
    }
    // 偶数舍去尾数
    return integer(num1);
  }

  unit_t v = 0;
  bignum_t effective_park = __effective_digit(num1, precision, v);
  Numeric res = num1;
  res.__set_decimal_park(effective_park);

  if (v >= 5) {
    bignum_t plus;
    plus.resize(precision-1);
    plus.push_front(1);
    Numeric tmp("0");
    tmp.__set_decimal_park(plus);
    res += tmp;
  }

  return res;
}

Numeric integer(const Numeric& num1) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Numeric res = num1;
  res.__set_decimal_park_zero();
  return res;
}

Numeric decimal(const Numeric& num1) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Numeric res = num1;
  res.__set_integer_park_zero();
  return res;
}

Numeric pow(const Numeric& num1, const Numeric& exp) {
  if (is_nan(num1)) return Numeric();
  if (is_infinite(num1)) operand_value_is_invalid_exception("%s", "num1 is infinite");

  Numeric res = "1", i = "0", j = integer(exp);
  while (i < j) {
    res *= num1;
    ++i;
  }
  return res;
}

Numeric rooting(const Numeric& num1, const Numeric& exp) {
  operation_is_not_implement_exception("%s", "rooting");
  Numeric res;
  return res;
}

Numeric log(const Numeric& base, const Numeric& log) {
  operation_is_not_implement_exception("%s", "log");
  Numeric res;
  return res;
}

Numeric log2(const Numeric& n) {
  operation_is_not_implement_exception("%s", "log2");
  Numeric res;
  return res;
}

Numeric log10(const Numeric& n) {
  operation_is_not_implement_exception("%s", "log10");
  Numeric res;
  return res;
}

Numeric ln(const Numeric& n) {
  operation_is_not_implement_exception("%s", "ln");
  Numeric res;
  return res;
}

Numeric factorial(const Numeric& num1) {
  if (num1.sign() == kNegative) operand_value_is_invalid_exception("%s", "num1 is negative");
  if (is_zero(num1) || is_one(num1)) return Numeric("1");
  Numeric a = integer(num1), b = "1";
  while (a != "1") {
    b *= a;
    --a;
  }
  return b;
}

/*
 * Extern Euclid(gcd(a,b) = sa+tb)
 */
std::pair<Numeric, Numeric> extended_euclidean(const Numeric& num1, const Numeric& num2) {
  Numeric q, a = integer(num1), b = integer(num2);
  std::vector<Numeric> r(3, {"0"});
  std::vector<Numeric> s(3, {"0"});
  std::vector<Numeric> t(3, {"0"});
  
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
Numeric gcd(const Numeric& num1, const Numeric& num2) {
  Numeric a,b,r,q;
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

Numeric lcm(const Numeric& num1, const Numeric& num2) {
  Numeric res, g;
  g = gcd(num1, num2);
  res = mul(integer(num1), integer(num2));
  res = res / g;
  return res;
}

int sgn(const Numeric& num1) {
  if (is_zero(num1)) return 0;
  if (num1.sign() == kNegative) return -1;
  return 1;
}

Numeric sin(const Numeric& x) {
  operation_is_not_implement_exception("%s", "sin");
  Numeric res;
  return res;
}

Numeric cos(const Numeric& x) {
  operation_is_not_implement_exception("%s", "cos");
  Numeric res;
  return res;
}

Numeric tan(const Numeric& x) {
  operation_is_not_implement_exception("%s", "tan");
  Numeric res;
  return res;
}

Numeric csc(const Numeric& x) {
  operation_is_not_implement_exception("%s", "csc");
  Numeric res;
  return res;
}

Numeric sec(const Numeric& x) {
  operation_is_not_implement_exception("%s", "sec");
  Numeric res;
  return res;
}

Numeric cot(const Numeric& x) {
  operation_is_not_implement_exception("%s", "cot");
  Numeric res;
  return res;
}

Numeric arcsin(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arcsin");
  Numeric res;
  return res;
}

Numeric arccos(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccos");
  Numeric res;
  return res;
}

Numeric arctan(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arctan");
  Numeric res;
  return res;
}

Numeric arccsc(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccsc");
  Numeric res;
  return res;
}

Numeric arcsec(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arcsec");
  Numeric res;
  return res;
}

Numeric arccot(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccot");
  Numeric res;
  return res;
}

Numeric sinh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "sinh");
  Numeric res;
  return res;
}

Numeric cosh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "cosh");
  Numeric res;
  return res;
}

Numeric tanh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "tanh");
  Numeric res;
  return res;
}

Numeric csch(const Numeric& x) {
  operation_is_not_implement_exception("%s", "csch");
  Numeric res;
  return res;
}

Numeric sech(const Numeric& x) {
  operation_is_not_implement_exception("%s", "sech");
  Numeric res;
  return res;
}

Numeric coth(const Numeric& x) {
  operation_is_not_implement_exception("%s", "coth");
  Numeric res;
  return res;
}

Numeric arcsinh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arcsinh");
  Numeric res;
  return res;
}

Numeric arccosh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccosh");
  Numeric res;
  return res;
}

Numeric arctanh(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arctanh");
  Numeric res;
  return res;
}

Numeric arccsch(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccsch");
  Numeric res;
  return res;
}

Numeric arcsech(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arcsech");
  Numeric res;
  return res;
}

Numeric arccoth(const Numeric& x) {
  operation_is_not_implement_exception("%s", "arccoth");
  Numeric res;
  return res;
}

void copy(Numeric& to, const Numeric& from) {
  to.__set_sign(from.sign());
  to.__set_integer_park(from.integer_park());
  to.__set_decimal_park(from.decimal_park());
  to.__set_infinite(from.infinite());
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

// --------------------------------------------------------------------------------

Numeric operator+(const Numeric& num1, const Numeric& num2) {
  return add(num1, num2);
}

Numeric operator-(const Numeric& num1, const Numeric& num2) {
  return sub(num1, num2);
}

Numeric operator*(const Numeric& num1, const Numeric& num2) {
  return mul(num1, num2);
}

Numeric operator/(const Numeric& num1, const Numeric& num2) {
  return quo(num1, num2);
}

Numeric operator%(const Numeric& num1, const Numeric& num2) {
  return mod(num1, num2);
}

Numeric operator+(const Numeric& num1, const char* num2) {
  return add(num1, Numeric(num2));
}

Numeric operator-(const Numeric& num1, const char* num2) {
  return sub(num1, Numeric(num2));
}

Numeric operator*(const Numeric& num1, const char* num2) {
  return mul(num1, Numeric(num2));
}

Numeric operator/(const Numeric& num1, const char* num2) {
  return quo(num1, Numeric(num2));
}

Numeric operator%(const Numeric& num1, const char* num2) {
  return mod(num1, Numeric(num2));
}

Numeric operator+(const char* num1, const Numeric& num2) {
  return add(Numeric(num1), num2);
}

Numeric operator-(const char* num1, const Numeric& num2) {
  return sub(Numeric(num1), num2);
}

Numeric operator*(const char* num1, const Numeric& num2) {
  return mul(Numeric(num1), num2);
}

Numeric operator/(const char* num1, const Numeric& num2) {
  return quo(Numeric(num1), num2);
}

Numeric operator%(const char* num1, const Numeric& num2) {
  return mod(Numeric(num1), num2);
}

bool operator==(const Numeric& num1, const Numeric& num2) {
  return equ(num1, num2);
}

bool operator!=(const Numeric& num1, const Numeric& num2) {
  return !equ(num1, num2);
}

bool operator<(const Numeric& num1, const Numeric& num2) {
  return lt(num1, num2);
}

bool operator>(const Numeric& num1, const Numeric& num2) {
  return gt(num1, num2);
}

bool operator<=(const Numeric& num1, const Numeric& num2) {
  return le(num1, num2);
}

bool operator>=(const Numeric& num1, const Numeric& num2) {
  return ge(num1, num2);
}

bool operator==(const Numeric& num1, const char* num2) {
  return equ(num1, Numeric(num2));
}

bool operator!=(const Numeric& num1, const char* num2) {
  return !equ(num1, Numeric(num2));
}

bool operator<(const Numeric& num1, const char* num2) {
  return lt(num1, Numeric(num2));
}

bool operator>(const Numeric& num1, const char* num2) {
  return gt(num1, Numeric(num2));
}

bool operator<=(const Numeric& num1, const char* num2) {
  return le(num1, Numeric(num2));
}

bool operator>=(const Numeric& num1, const char* num2) {
  return ge(num1, Numeric(num2));
}

bool operator==(const char* num1, const Numeric& num2) {
  return equ(Numeric(num1), num2);
}

bool operator!=(const char* num1, const Numeric& num2) {
  return !equ(Numeric(num1), num2);
}

bool operator<(const char* num1, const Numeric& num2) {
  return lt(Numeric(num1), num2);
}

bool operator>(const char* num1, const Numeric& num2) {
  return gt(Numeric(num1), num2);
}

bool operator<=(const char* num1, const Numeric& num2) {
  return le(Numeric(num1), num2);
}

bool operator>=(const char* num1, const Numeric& num2) {
  return ge(Numeric(num1), num2);
}

bool operator||(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const Numeric& num1, const Numeric& num2) {
  if (is_nan(num1) || is_nan(num2)) return false;
  if (!is_zero(num1) && !is_zero(num2)) return true;
  return false;
}

bool operator||(const Numeric& num1, const char* num2) {
  Numeric num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) || !is_zero(num2_)) return true;
  return false;
}

bool operator&&(const Numeric& num1, const char* num2) {
  Numeric num2_(num2);
  if (is_nan(num1) || is_nan(num2_)) return false;
  if (!is_zero(num1) && !is_zero(num2_)) return true;
  return false;
}

bool operator||(const char* num1, const Numeric& num2) {
  Numeric num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) || !is_zero(num2)) return true;
  return false;
}

bool operator&&(const char* num1, const Numeric& num2) {
  Numeric num1_(num1);
  if (is_nan(num1_) || is_nan(num2)) return false;
  if (!is_zero(num1_) && !is_zero(num2)) return true;
  return false;
}

bool operator!(const Numeric& num1) {
  if (is_nan(num1)) return false;
  return is_zero(num1);
}

Numeric operator~(const Numeric& num1) {
  return not_bits(num1);
}

Numeric operator|(const Numeric& num1, const Numeric& num2) {
  return or_bits(num1, num2);
}

Numeric operator&(const Numeric& num1, const Numeric& num2) {
  return and_bits(num1, num2);
}

Numeric operator^(const Numeric& num1, const Numeric& num2) {
  return xor_bits(num1, num2);
}

Numeric operator<<(const Numeric& num1, const Numeric& bits) {
  return lshift_bits(num1, bits);
}

Numeric operator>>(const Numeric& num1, const Numeric& bits) {
  return rshift_bits(num1, bits);
}

Numeric operator|(const Numeric& num1, const char* num2) {
  return or_bits(num1, Numeric(num2));
}

Numeric operator&(const Numeric& num1, const char* num2) {
  return and_bits(num1, Numeric(num2));
}

Numeric operator^(const Numeric& num1, const char* num2) {
  return xor_bits(num1, Numeric(num2));
}

Numeric operator<<(const Numeric& num1, const char* bits) {
  return lshift_bits(num1, Numeric(bits));
}

Numeric operator>>(const Numeric& num1, const char* bits) {
  return rshift_bits(num1, Numeric(bits));
}

Numeric operator|(const char* num1, const Numeric& num2) {
  return or_bits(Numeric(num1), num2);
}

Numeric operator&(const char* num1, const Numeric& num2) {
  return and_bits(Numeric(num1), num2);
}

Numeric operator^(const char* num1, const Numeric& num2) {
  return xor_bits(Numeric(num1), num2);
}

Numeric operator<<(const char* num1, const Numeric& bits) {
  return lshift_bits(Numeric(num1), bits);
}

Numeric operator>>(const char* num1, const Numeric& bits) {
  return rshift_bits(Numeric(num1), bits);
}

// ----------------------------------------------------------------------
Numeric& Numeric::operator+() {
  return *this;
}

Numeric& Numeric::operator-() {
  if (sign_ == kNegative) sign_ = kPositive;
  else sign_ = kNegative;
  return *this;
}

Numeric& Numeric::operator++() {
  *this = add(*this, Numeric("1"));
  return *this;
}

Numeric Numeric::operator++(int) {
  Numeric res;
  copy(res, *this);
  *this = add(*this, Numeric("1"));
  return res;
}

Numeric& Numeric::operator--() {
  *this = sub(*this, Numeric("1"));
  return *this;
}

Numeric Numeric::operator--(int) {
  Numeric res;
  copy(res, *this);
  *this = sub(*this, Numeric("1"));
  return res;
}

void Numeric::operator=(const Numeric& num2) {
  assign(num2);
}

void Numeric::operator=(const char* num2) {
  assign(Numeric(num2));
}

void Numeric::operator+=(const Numeric& num2) {
  *this = add(*this, num2);
}

void Numeric::operator+=(const char* num2) {
  *this = add(*this, Numeric(num2));
}

void Numeric::operator-=(const Numeric& num2) {
  *this = sub(*this, num2);
}

void Numeric::operator-=(const char* num2) {
  *this = sub(*this, Numeric(num2));
}

void Numeric::operator*=(const Numeric& num2) {
  *this = mul(*this, num2);
}

void Numeric::operator*=(const char* num2) {
  *this = mul(*this, Numeric(num2));
}

void Numeric::operator/=(const Numeric& num2) {
  *this = div(*this, num2);
}

void Numeric::operator/=(const char* num2) {
  *this = div(*this, Numeric(num2));
}

void Numeric::operator%=(const Numeric& num2) {
  *this = mod(*this, num2);
}

void Numeric::operator%=(const char* num2) {
  *this = mod(*this, Numeric(num2));
}

void Numeric::operator&=(const Numeric& num2) {
  *this = and_bits(*this, num2);
}

void Numeric::operator&=(const char* num2) {
  *this = and_bits(*this, Numeric(num2));
}

void Numeric::operator|=(const Numeric& num2) {
  *this = or_bits(*this, num2);
}

void Numeric::operator|=(const char* num2) {
  *this = or_bits(*this, Numeric(num2));
}

void Numeric::operator^=(const Numeric& num2) {
  *this = xor_bits(*this, num2);
}

void Numeric::operator^=(const char* num2) {
  *this = xor_bits(*this, Numeric(num2));
}

void Numeric::operator<<=(const Numeric& bits) {
  *this = lshift_bits(*this, bits);
}

void Numeric::operator>>=(const Numeric& bits) {
  *this = rshift_bits(*this, bits);
}

char Numeric::operator[](uinteger_t i) {
  std::string res = str();
  if (i >= res.size()) out_of_range_exception("i = %d", i);
  return res[i];
}

} // namespace core
} // namespace mynum