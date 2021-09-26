#include <mynum/number/number.h>

namespace mynum {
namespace number {

std::string Number::str() const {
  if (class_id_ == kRealType) return real_park_.str();
  else if (class_id_ == kIntegerType) return integer(real_park_).str();

  std::string res = "";
  if (is_zero(real_park_) && is_zero(imaginary_park_)) {
    res = "0";
    return res;
  }
  
  if (!is_zero(real_park_))
    res += real_park_.str();

  if (!is_zero(imaginary_park_)) {
    if (!is_zero(real_park_))
      res += "+";
    res += (imaginary_park_.str() + "i");
  }
  return res;
}

core::Numeric Number::real_park() const {
  if (class_id_ == kIntegerType)
    return core::integer(real_park_);
  return real_park_;
}

core::Numeric Number::imaginary_park() const {
  if ((class_id_ == kIntegerType) || (class_id_ == kRealType)) return core::Numeric("0");
  return imaginary_park_;
}

/* 虚数实际上是没有无穷的，这里直接也不抛出异常了。为了计算不受影响。 */
void Number::infinite(int sign) {
  // if (class_id_ == kComplexType)
  //   operand_type_is_invalid_exception("%s", "infinite");
  real_park_.infinite(sign);
}

Number& Number::operator+() {
  if (class_id_ == kComplexType) +imaginary_park_;
  +real_park_;
  return *this; 
}

Number& Number::operator-() {
  if (class_id_ == kComplexType) -imaginary_park_;
  -real_park_;
  return *this;
}

Number& Number::operator++() { 
  if (class_id_ == kComplexType) ++imaginary_park_;
  ++real_park_;
  return *this; 
}

Number Number::operator++(int) {
  Number t = *this;
  if (class_id_ == kComplexType) imaginary_park_++;
  real_park_++;
  return t; 
}

Number& Number::operator--() {
  if (class_id_ == kComplexType) --imaginary_park_;
  --real_park_;
  return *this;
}

Number Number::operator--(int) {
  Number t = *this;
  if (class_id_ == kComplexType) imaginary_park_--;
  real_park_--;
  return t;
}

void Number::operator=(const Number& num2) { assign(num2); }
void Number::operator=(const char* num2) { assign(Number(num2)); }
void Number::operator+=(const Number& num2) { *this = add(*this, num2); }
void Number::operator+=(const char* num2) { *this += Number(num2); }
void Number::operator-=(const Number& num2) { *this = sub(*this, num2); }
void Number::operator-=(const char* num2) { *this -= Number(num2); }
void Number::operator*=(const Number& num2) { *this = mul(*this, num2); }
void Number::operator*=(const char* num2) { *this *= Number(num2); }
void Number::operator/=(const Number& num2) { *this = div(*this, num2); }
void Number::operator/=(const char* num2) { *this /= Number(num2); }
void Number::operator%=(const Number& num2) { *this = mod(*this, num2); }
void Number::operator%=(const char* num2) { *this %= Number(num2); }
void Number::operator&=(const Number& num2) { *this = and_bits(*this, num2); }
void Number::operator&=(const char* num2) { *this &= Number(num2); }
void Number::operator|=(const Number& num2) { *this = or_bits(*this, num2); }
void Number::operator|=(const char* num2) { *this |= Number(num2); }
void Number::operator^=(const Number& num2) { *this = xor_bits(*this, num2); }
void Number::operator^=(const char* num2) { *this ^= Number(num2);  }
void Number::operator<<=(const Number& bits) { *this = lshift_bits(*this, bits); }
void Number::operator>>=(const Number& bits) { *this = rshift_bits(*this, bits); }
char Number::operator[](uinteger_t i) {
  std::string res = str();
  if (i >= res.size()) out_of_range_exception("i = %d", i);
  return res[i];
}

static std::string::size_type __sign_pos(const std::string& s) {
  std::string::size_type position = s.rfind("+");
  if (position != s.npos) {
    return position;
  }

  position = s.rfind("-");
  if (position != s.npos) {
    return position;
  }

  return s.npos;
}

void Number::__create_from_string(const char* n, int base) {
  //
  // 1.存在'+'或者'-'字符
  //  1-1.存在'i'字符         分割
  //  1-2 不存在'i'字符       仅实部
  // 2 不存在'+'或者'-'字符
  //  2-1 存在'i'字符         仅虚部
  //  2-2 不存在'i'字符       仅实部
  //
  std::string s(n);
  std::string::size_type plus_pos = __sign_pos(s);
  if (plus_pos != s.npos) {
    std::string::size_type i_pos = s.find("i");
    if (i_pos != s.npos) {
      std::string real_str = s.substr(0, plus_pos);
      size_t len = i_pos - plus_pos;
      std::string imaginary_str = s.substr(plus_pos, len);
      real_park_ = real_str.c_str();
      imaginary_park_ = imaginary_str.c_str();
      class_id_ = kComplexType;
      class_name_ = "complex";
    } else {
      std::string real_str = "";
      if (plus_pos == 0)
        real_str = s;
      else
        real_str = s.substr(0, plus_pos);
      real_park_ = real_str.c_str();
      imaginary_park_.zero();

      if (is_integer(real_park_)) {
        class_id_ = kIntegerType;
        class_name_ = "integer";
      } else {
        class_id_ = kRealType;
        class_name_ = "real";
      }
    }
  } else {
    std::string::size_type i_pos = s.find("i");
    if (i_pos != s.npos) {
      std::string imaginary_str = s.substr(0, i_pos);
      real_park_.zero();
      imaginary_park_ = imaginary_str.c_str();
      class_id_ = kComplexType;
      class_name_ = "complex";
    } else {
      real_park_ = s.c_str();
      imaginary_park_.zero();

      if (is_integer(real_park_)) {
        class_id_ = kIntegerType;
        class_name_ = "integer";
      } else {
        class_id_ = kRealType;
        class_name_ = "real";
      }
    }
  }/* end else */
}

void Number::__set_class(int cls) {
  class_id_ = cls;
  if (cls == kIntegerType) {
    class_name_ = "integer";
  } else if (cls == kRealType) {
    class_name_ = "real";
  } else {
    class_name_ = "complex";
  }
}

bool equ(const Number& num1, const Number& num2) {
  return ((num1.real_park() == num2.real_park()) && 
          (num1.imaginary_park() == num2.imaginary_park()));
}

/* 如果是虚数与实数比较，则只对比实部分。 */
bool gt(const Number& num1, const Number& num2) {
  return (num1.real_park() > num2.real_park());
}

/* 如果是虚数与实数比较，则只对比实部分。 */
bool lt(const Number& num1, const Number& num2) {
  return (num1.real_park() < num2.real_park());
}

/* 如果是虚数与实数比较，则只对比实部分。 */
bool ge(const Number& num1, const Number& num2) {
  return (num1.real_park() >= num2.real_park());
}

/* 如果是虚数与实数比较，则只对比实部分。 */
bool le(const Number& num1, const Number& num2) {
  return (num1.real_park() <= num2.real_park());
}

bool is_zero(const Number& num1) {
  return (core::is_zero(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

bool is_one(const Number& num1) {
  return (core::is_one(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

bool is_nan(const Number& num1) {
  return (core::is_nan(num1.real_park()) || 
          core::is_nan(num1.imaginary_park()));
}

bool is_infinite(const Number& num1) {
  if (num1.class_id() == kComplexType)
    operand_type_is_invalid_exception("num1 is %s", num1.class_name().c_str());
  return core::is_infinite(num1.real_park());
}

bool is_none(const Number& num1) {
  return (core::is_none(num1.real_park()) || 
          core::is_none(num1.imaginary_park()));
}

bool is_integer(const Number& num1) {
  return (core::is_integer(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

bool is_float(const Number& num1) {
  return (core::is_float(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

bool is_odd(const Number& num1) {
  return (core::is_odd(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

bool is_even(const Number& num1) {
  return (core::is_even(num1.real_park()) && 
          core::is_zero(num1.imaginary_park()));
}

static int __detection_number_type(const Number& num1, const Number& num2) {
  if ((num1.class_id() == kComplexType) || (num2.class_id() == kComplexType))
    return kComplexType;
  else if ((num1.class_id() == kRealType) || (num2.class_id() == kRealType))
    return kRealType;
  return kIntegerType;
}

Number add(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      num1.real_park() + num2.real_park(),
      num1.imaginary_park() + num2.imaginary_park()
    );
  } else {
    res.assign(
      num1.real_park() + num2.real_park(),
      t == kIntegerType
    );
  }
  return res;
}

Number sub(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      num1.real_park() - num2.real_park(),
      num1.imaginary_park() - num2.imaginary_park()
    );
  } else {
    res.assign(
      num1.real_park() - num2.real_park(),
      t == kIntegerType
    );
  }
  return res;
}

Number mul(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      (num1.real_park() * num2.real_park()) - (num1.imaginary_park() * num2.imaginary_park()),
      (num1.real_park() * num2.imaginary_park()) + (num1.imaginary_park() * num2.real_park())
    );
  } else {
    res.assign(
      num1.real_park() * num2.real_park(),
      t == kIntegerType
    );
  }
  return res;
}

Number div(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    core::Numeric a,b,c,d;
    a = num1.real_park();
    b = num1.imaginary_park();
    c = num2.real_park();
    d = num2.imaginary_park();

    core::Numeric real, imaginary;
    real = core::div((a * c + b * d), (c * c + d * d));
    imaginary = core::div((b * c - a * d), (c * c + d * d));
    res.assign(
      real, 
      imaginary
    );
  } else {
    res.assign(
      core::div(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number quo(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    core::Numeric a,b,c,d;
    a = num1.real_park();
    b = num1.imaginary_park();
    c = num2.real_park();
    d = num2.imaginary_park();

    core::Numeric real, imaginary;
    real = core::quo((a * c + b * d), (c * c + d * d));
    imaginary = core::quo((b * c - a * d), (c * c + d * d));
    res.assign(
      real, 
      imaginary
    );
  } else {
    res.assign(
      core::quo(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number rem(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    core::Numeric a,b,c,d;
    a = num1.real_park();
    b = num1.imaginary_park();
    c = num2.real_park();
    d = num2.imaginary_park();

    core::Numeric real, imaginary;
    real = core::rem((a * c + b * d), (c * c + d * d));
    imaginary = core::rem((b * c - a * d), (c * c + d * d));
    res.assign(real, imaginary);
  } else {
    res.assign(
      core::rem(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number mod(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    core::Numeric a,b,c,d;
    a = num1.real_park();
    b = num1.imaginary_park();
    c = num2.real_park();
    d = num2.imaginary_park();

    core::Numeric real, imaginary;
    real = core::mod((a * c + b * d), (c * c + d * d));
    imaginary = core::mod((b * c - a * d), (c * c + d * d));
    res.assign(real, imaginary);
  } else {
    res.assign(
      core::mod(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number or_bits(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      core::or_bits(num1.real_park(), num2.real_park()),
      core::or_bits(num1.imaginary_park(), num2.imaginary_park())
    );
  } else {
    res.assign(
      core::or_bits(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number and_bits(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      core::and_bits(num1.real_park(), num2.real_park()),
      core::and_bits(num1.imaginary_park(), num2.imaginary_park())
    );
  } else {
    res.assign(
      core::and_bits(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number xor_bits(const Number& num1, const Number& num2) {
  Number res;
  int t = __detection_number_type(num1, num2);
  if (t == kComplexType) {
    res.assign(
      core::xor_bits(num1.real_park(), num2.real_park()),
      core::xor_bits(num1.imaginary_park(), num2.imaginary_park())
    );
  } else {
    res.assign(
      core::xor_bits(num1.real_park(), num2.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number not_bits(const Number& num1) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::not_bits(num1.real_park()),
      core::not_bits(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::not_bits(num1.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里必须为整数。*/
Number lshift_bits(const Number& num1, const Number& bits) {
  Number res;
  if ((num1.class_id() != kIntegerType) || (bits.class_id() != kIntegerType))
    operand_type_is_invalid_exception("%s", "num1 or bits is not integer");

  res.assign(
    core::lshift_bits(num1.real_park(), bits.real_park()),
    true
  );
  return res;
}

/* 这里必须为整数。*/
Number rshift_bits(const Number& num1, const Number& bits) {
  Number res;
  if ((num1.class_id() != kIntegerType) || (bits.class_id() != kIntegerType))
    operand_type_is_invalid_exception("%s", "num1 or bits is not integer");

  res.assign(
    core::rshift_bits(num1.real_park(), bits.real_park()),
    true
  );
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number abs(const Number& num1) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::abs(num1.real_park()),
      core::abs(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::abs(num1.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number floor(const Number& num1) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::floor(num1.real_park()),
      core::floor(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::floor(num1.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number ceil(const Number& num1) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::ceil(num1.real_park()),
      core::ceil(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::ceil(num1.real_park()),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。*/
Number round(const Number& num1, uinteger_t precision) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::round(num1.real_park(), precision),
      core::round(num1.imaginary_park(), precision)
    );
  } else {
    res.assign(
      core::round(num1.real_park(), precision),
      t == kIntegerType
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。
 * 如果非序数，一律返回整形。
 */
Number integer(const Number& num1) {
  Number res;
  if (num1.class_id() == kComplexType) {
    res.assign(
      core::integer(num1.real_park()),
      core::integer(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::integer(num1.real_park()),
      true
    );
  }
  return res;
}

/* 这里如果是虚数，是自己定义的运算，不合数理。
 * 如果不是虚数一律返回实数。
 */
Number decimal(const Number& num1) {
  Number res;
  int t = num1.class_id();
  if (t == kComplexType) {
    res.assign(
      core::decimal(num1.real_park()),
      core::decimal(num1.imaginary_park())
    );
  } else {
    res.assign(
      core::decimal(num1.real_park()),
      false
    );
  }
  return res;
}

/* 指数不能是虚数，只能是实数或者整数。
 * 如果底数是虚数则指数必须是整数。
 * 如果底数是实数，指数是实数则会转到开方运行。
 */
Number pow(const Number& num1, const Number& exp) {
  Number res;
  if (exp.class_id() == kComplexType) {
    operand_type_is_invalid_exception("exp is %s", exp.class_name().c_str());
  }

  if (num1.class_id() == kComplexType) {
    // 指数必须是整数
    if (!core::is_integer(exp.real_park())) {
      operand_type_is_invalid_exception("exp is not %s", "Integer");
    }

    Number i = exp - "1";
    while (i != "0") {
      res = res * res;
      --i;
    }
  } else {
    //
    // FIXME : 这里指数应该分为两部分，整数部分与小数部分来运算。
    //
    if (!core::is_integer(exp.real_park())) {
      res = rooting(num1, exp);
    } else {
      // 指数必须是整数
      res.assign(
        core::pow(num1.real_park(), exp.real_park()),
        num1.class_id() == kIntegerType
      );
    }
  }
  return res;
}

/* 虚数没有开放运算，结果必为实数。 */
Number rooting(const Number& num1, const Number& exp) {
  Number res;
  if (exp.class_id() == kComplexType) {
    operand_type_is_invalid_exception("exp is %s", exp.class_name().c_str());
  }

  if (num1.class_id() == kComplexType) {
    operation_is_not_implement_exception("operand is %s", num1.class_name().c_str());
  } else {
    res.assign(
      core::rooting(num1.real_park(), exp.real_park()),
      false
    );
  }
  return res;
}

/* 虚数没有对数运算，结果必为实数。 */
Number log(const Number& base, const Number& log) {
  Number res;
  if ((base.class_id() == kComplexType) || (log.class_id() == kComplexType))
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "log");
  res.assign(
    core::log(base.real_park(), log.real_park()),
    false
  );
  return res;
}

/* 虚数没有对数运算，结果必为实数。 */
Number log2(const Number& n) {
  Number res;
  if (n.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "log2");
  res.assign(
    core::log2(n.real_park()),
    false
  );
  return res;
}

/* 虚数没有对数运算，结果必为实数。 */
Number log10(const Number& n) {
  Number res;
  if (n.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "log10");
  res.assign(
    core::log10(n.real_park()),
    false
  );
  return res;
}

/* 虚数没有对数运算，结果必为实数。 */
Number ln(const Number& n) {
  Number res;
  if (n.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "ln");
  res.assign(
    core::ln(n.real_park()),
    false
  );
  return res;
}

/* 虚数没有对数运算，结果必为整数。 */
Number factorial(const Number& num1) {
  Number res;
  if (num1.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "factorial");
  res.assign(
    core::factorial(num1.real_park()),
    true
  );
  return res;
}

/* 虚数没有扩展欧几里德运算，结果必为整数。 */
std::pair<Number, Number> extended_euclidean(const Number& num1, const Number& num2) {
  if ((num1.class_id() == kComplexType) || (num2.class_id() == kComplexType))
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", 
                                         "extended euclidean");
  
  std::pair<core::Numeric, core::Numeric> st = 
    core::extended_euclidean(num1.real_park(), num2.real_park());
  std::pair<Number, Number> res;
  res.first.assign(st.first, true);
  res.second.assign(st.second, true);
  return res;
}

/* 虚数没有最大公约数运算，结果必为整数。 */
Number gcd(const Number& num1, const Number& num2) {
  Number res;
  if ((num1.class_id() == kComplexType) || (num2.class_id() == kComplexType))
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "gcd");
  
  res.assign(
    core::gcd(num1.real_park(), num2.real_park()),
    true
  );
  return res;
}

/* 虚数没有最小公倍数运算，结果必为整数。 */
Number lcm(const Number& num1, const Number& num2) {
  Number res;
  if ((num1.class_id() == kComplexType) || (num2.class_id() == kComplexType))
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "gcd");
  
  res.assign(
    core::lcm(num1.real_park(), num2.real_park()),
    true
  );
  return res;
}

/* 虚数没有最小公倍数运算，结果必为整数。 */
Number sin(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "sin");
  res.assign(
    core::sin(x.real_park()),
    false
  );
  return res;
}

/* 虚数没有最小公倍数运算，结果必为整数。 */
Number cos(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "cos");
  res.assign(
    core::cos(x.real_park()),
    false
  );
  return res;
}

Number tan(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "tan");
  res.assign(
    core::tan(x.real_park()),
    false
  );
  return res;
}

Number csc(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "csc");
  res.assign(
    core::csc(x.real_park()),
    false
  );
  return res;
}

Number sec(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "sec");
  res.assign(
    core::sec(x.real_park()),
    false
  );
  return res;
}

Number cot(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "cot");
  res.assign(
    core::cot(x.real_park()),
    false
  );
  return res;
}

Number arcsin(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arcsin");
  res.assign(
    core::arcsin(x.real_park()),
    false
  );
  return res;
}

Number arccos(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccos");
  res.assign(
    core::arccos(x.real_park()),
    false
  );
  return res;
}

Number arctan(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arctan");
  res.assign(
    core::arctan(x.real_park()),
    false
  );
  return res;
}

Number arccsc(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccsc");
  res.assign(
    core::arccsc(x.real_park()),
    false
  );
  return res;
}

Number arcsec(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arcsec");
  res.assign(
    core::arcsec(x.real_park()),
    false
  );
  return res;
}

Number arccot(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccot");
  res.assign(
    core::arccot(x.real_park()),
    false
  );
  return res;
}

Number sinh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "sinh");
  res.assign(
    core::sinh(x.real_park()),
    false
  );
  return res;
}

Number cosh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "cosh");
  res.assign(
    core::cosh(x.real_park()),
    false
  );
  return res;
}

Number tanh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "tanh");
  res.assign(
    core::tanh(x.real_park()),
    false
  );
  return res;
}

Number csch(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "csch");
  res.assign(
    core::csch(x.real_park()),
    false
  );
  return res;
}

Number sech(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "sech");
  res.assign(
    core::sech(x.real_park()),
    false
  );
  return res;
}

Number coth(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "coth");
  res.assign(
    core::coth(x.real_park()),
    false
  );
  return res;
}

Number arcsinh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arcsinh");
  res.assign(
    core::arcsinh(x.real_park()),
    false
  );
  return res;
}

Number arccosh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccosh");
  res.assign(
    core::arccosh(x.real_park()),
    false
  );
  return res;
}

Number arctanh(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arctanh");
  res.assign(
    core::arctanh(x.real_park()),
    false
  );
  return res;
}

Number arccsch(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccsch");
  res.assign(
    core::arccsch(x.real_park()),
    false
  );
  return res;
}

Number arcsech(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arcsech");
  res.assign(
    core::arcsech(x.real_park()),
    false
  );
  return res;
}

Number arccoth(const Number& x) {
  Number res;
  if (x.class_id() == kComplexType)
    operation_is_not_implement_exception("operand is \"complex\", %s not implement", "arccoth");
  res.assign(
    core::arccoth(x.real_park()),
    false
  );
  return res;
}

Number& copy(Number& to, const Number& from) {
  if (to.class_id() == kComplexType) {
    to.assign(
      from.real_park(),
      from.imaginary_park()
    );
  } else if (to.class_id() == kRealType) {
    to.assign(
      from.real_park(),
      false
    );
  } else { // if (to.class_id() == kIntegerType)
    to.assign(
      core::integer(from.real_park()),
      true
    );
  }
  return to;
}

// 双目算术运算符
Number operator+(const Number& num1, const Number& num2) {
  return add(num1, num2);
}

Number operator-(const Number& num1, const Number& num2) {
  return sub(num1, num2);
}

Number operator*(const Number& num1, const Number& num2) {
  return mul(num1, num2);
}

Number operator/(const Number& num1, const Number& num2) {
  return div(num1, num2);
}

Number operator%(const Number& num1, const Number& num2) {
  return mod(num1, num2);
}

Number operator+(const Number& num1, const char* num2) {
  return add(num1, Number(num2));
}

Number operator-(const Number& num1, const char* num2) {
  return sub(num1, Number(num2));
}

Number operator*(const Number& num1, const char* num2) {
  return mul(num1, Number(num2));
}

Number operator/(const Number& num1, const char* num2) {
  return div(num1, Number(num2));
}

Number operator%(const Number& num1, const char* num2) {
  return mod(num1, Number(num2));
}

Number operator+(const char* num1, const Number& num2) {
  return add(Number(num1), num2);
}

Number operator-(const char* num1, const Number& num2) {
  return sub(Number(num1), num2);
}

Number operator*(const char* num1, const Number& num2) {
  return mul(Number(num1), num2);
}

Number operator/(const char* num1, const Number& num2) {
  return div(Number(num1), num2);
}

Number operator%(const char* num1, const Number& num2) {
  return mod(Number(num1), num2);
}

bool operator==(const Number& num1, const Number& num2) {
  return equ(num1, num2);
}

bool operator!=(const Number& num1, const Number& num2) {
  return !equ(num1, num2);
}

bool operator<(const Number& num1, const Number& num2) {
  return lt(num1, num2);
}

bool operator>(const Number& num1, const Number& num2) {
  return gt(num1, num2);
}

bool operator<=(const Number& num1, const Number& num2) {
  return le(num1, num2);
}

bool operator>=(const Number& num1, const Number& num2) {
  return ge(num1, num2);
}

bool operator==(const Number& num1, const char* num2) {
  return equ(num1, Number(num2));
}

bool operator!=(const Number& num1, const char* num2) {
  return !equ(num1, Number(num2));
}

bool operator<(const Number& num1, const char* num2) {
  return lt(num1, Number(num2));
}

bool operator>(const Number& num1, const char* num2) {
  return gt(num1, Number(num2));
}

bool operator<=(const Number& num1, const char* num2) {
  return le(num1, Number(num2));
}

bool operator>=(const Number& num1, const char* num2) {
  return ge(num1, Number(num2));
}

bool operator==(const char* num1, const Number& num2) {
  return equ(Number(num1), num2);
}

bool operator!=(const char* num1, const Number& num2) {
  return !equ(Number(num1), num2);
}

bool operator<(const char* num1, const Number& num2) {
  return lt(Number(num1), num2);
}

bool operator>(const char* num1, const Number& num2) {
  return gt(Number(num1), num2);
}

bool operator<=(const char* num1, const Number& num2) {
  return le(Number(num1), num2);
}

bool operator>=(const char* num1, const Number& num2) {
  return ge(Number(num1), num2);
}

bool operator||(const Number& num1, const Number& num2) {
  return (!is_zero(num1) || !is_zero(num2));
}

bool operator&&(const Number& num1, const Number& num2) {
  return (!is_zero(num1) && !is_zero(num2));
}

bool operator!(const Number& num1) {
  return is_zero(num1);
}

bool operator||(const Number& num1, const char* num2) {
  return (!is_zero(num1) || !is_zero(Number(num2)));
}

bool operator&&(const Number& num1, const char* num2) {
  return (!is_zero(num1) && !is_zero(Number(num2)));
}

bool operator||(const char* num1, const Number& num2) {
  return (!is_zero(Number(num1)) || !is_zero(num2));
}

bool operator&&(const char* num1, const Number& num2) {
  return (!is_zero(Number(num1)) && !is_zero(num2));
}

Number operator~(const Number& num1) {
  return not_bits(num1);
}

Number operator|(const Number& num1, const Number& num2) {
  return or_bits(num1, num2);
}

Number operator&(const Number& num1, const Number& num2) {
  return and_bits(num1, num2);
}

Number operator^(const Number& num1, const Number& num2) {
  return xor_bits(num1, num2);
}

Number operator<<(const Number& num1, const Number& bits) {
  return lshift_bits(num1, bits);
}

Number operator>>(const Number& num1, const Number& bits) {
  return rshift_bits(num1, bits);
}

Number operator|(const Number& num1, const char* num2) {
  return or_bits(num1, Number(num2));
}

Number operator&(const Number& num1, const char* num2) {
  return and_bits(num1, Number(num2));
}

Number operator^(const Number& num1, const char* num2) {
  return xor_bits(num1, Number(num2));
}

Number operator<<(const Number& num1, const char* bits) {
  return lshift_bits(num1, Number(bits));
}

Number operator>>(const Number& num1, const char* bits) {
  return rshift_bits(num1, Number(bits));
}

Number operator|(const char* num1, const Number& num2) {
  return or_bits(Number(num1), num2);
}

Number operator&(const char* num1, const Number& num2) {
  return and_bits(Number(num1), num2);
}

Number operator^(const char* num1, const Number& num2) {
  return xor_bits(Number(num1), num2);
}

Number operator<<(const char* num1, const Number& bits) {
  return lshift_bits(Number(num1), bits);
}

Number operator>>(const char* num1, const Number& bits) {
  return rshift_bits(Number(num1), bits);
}

} // namespace number
} // namespace mynum