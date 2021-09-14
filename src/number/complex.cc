#include <mynum/number/complex.h>

namespace mynum {
namespace number {

std::string Complex::str() const { 
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

bool equ(const Complex& num1, const Complex& num2) {
  return ((num1.real_park_ == num2.real_park_) && (num1.imaginary_park_ == num2.imaginary_park_));
}

bool gt(const Complex& num1, const Complex& num2) {
  operand_type_is_invalid_exception("num1 is %s", "Complex");
  return false;
}

bool lt(const Complex& num1, const Complex& num2) {
  operand_type_is_invalid_exception("num1 is %s", "Complex");
  return false;
}

bool ge(const Complex& num1, const Complex& num2) {
  operand_type_is_invalid_exception("num1 is %s", "Complex");
  return false;
}

bool le(const Complex& num1, const Complex& num2) {
  operand_type_is_invalid_exception("num1 is %s", "Complex");
  return false;
}

bool is_zero(const Complex& num1) {
  return (is_zero(num1.real_park_) && is_zero(num1.imaginary_park_));
}

bool is_one(const Complex& num1) {
  return (is_one(num1.real_park_) && is_zero(num1.imaginary_park_));
}

bool is_nan(const Complex& num1) {
  return (is_nan(num1.real_park_) || is_nan(num1.imaginary_park_));
}

bool is_infinite(const Complex& num1) {
  operand_type_is_invalid_exception("%s", "num1 is infinite");
  return false;
}

bool is_none(const Complex& num1) {
  return (is_none(num1.real_park_) || is_none(num1.imaginary_park_));
}

bool is_integer(const Complex& num1) {
  return (is_integer(num1.real_park_) || is_zero(num1.imaginary_park_));
}

bool is_float(const Complex& num1) {
  return (is_float(num1.real_park_) || is_zero(num1.imaginary_park_));
}

bool is_odd(const Complex& num1) {
  return (is_odd(num1.real_park_) && is_odd(num1.imaginary_park_));
}

bool is_even(const Complex& num1) {
  return (is_even(num1.real_park_) && is_even(num1.imaginary_park_));
}

Complex add(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = num1.real_park_ + num2.real_park_;
  res.imaginary_park_ = num1.imaginary_park_ + num2.imaginary_park_;
  return res;
}

Complex sub(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = num1.real_park_ - num2.real_park_;
  res.imaginary_park_ = num1.imaginary_park_ - num2.imaginary_park_;
  return res;
}

Complex mul(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = (num1.real_park_ * num2.real_park_) - (num1.imaginary_park_ * num2.imaginary_park_);
  res.imaginary_park_ = (num1.real_park_ * num2.imaginary_park_) + (num1.imaginary_park_ * num2.real_park_);
  return res;
}

Complex div(const Complex& num1, const Complex& num2) {
  Numeric a,b,c,d;
  a = num1.real_park_;
  b = num1.imaginary_park_;
  c = num2.real_park_;
  d = num2.imaginary_park_;

  Numeric real, imaginary;
  real = div((a * c + b * d), (c*c + d*d));
  imaginary = div((b * c - a * d), (c*c + d*d));
  return Complex(real, imaginary);
}

Complex quo(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "quo");
  return Complex("0");
}

Complex rem(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "rem");
  return Complex("0");
}

Complex mod(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "mod");
  return Complex("0");
}

Complex or_bits(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = or_bits(num1.real_park_, num2.real_park_);
  res.imaginary_park_ = or_bits(num1.imaginary_park_, num2.imaginary_park_);
  return res;
}

Complex and_bits(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = and_bits(num1.real_park_, num2.real_park_);
  res.imaginary_park_ = and_bits(num1.imaginary_park_, num2.imaginary_park_);
  return res;
}

Complex xor_bits(const Complex& num1, const Complex& num2) {
  Complex res;
  res.real_park_ = xor_bits(num1.real_park_, num2.real_park_);
  res.imaginary_park_ = xor_bits(num1.imaginary_park_, num2.imaginary_park_);
  return res;
}

Complex not_bits(const Complex& num1) {
  Complex res;
  res.real_park_ = not_bits(num1.real_park_);
  res.imaginary_park_ = not_bits(num1.imaginary_park_);
  return res;
}

Complex lshift_bits(const Complex& num1, const Complex& bits) {
  Complex res;
  res.real_park_ = lshift_bits(num1.real_park_, bits.real_park_);
  res.imaginary_park_ = lshift_bits(num1.imaginary_park_, bits.imaginary_park_);
  return res;
}

Complex rshift_bits(const Complex& num1, const Complex& bits) {
  Complex res;
  res.real_park_ = rshift_bits(num1.real_park_, bits.real_park_);
  res.imaginary_park_ = rshift_bits(num1.imaginary_park_, bits.imaginary_park_);
  return res;
}

Complex abs(const Complex& num1) {
  Complex res;
  res.real_park_ = abs(num1.real_park_);
  res.imaginary_park_ = abs(num1.imaginary_park_);
  return res;
}

Complex floor(const Complex& num1) {
  Complex res;
  res.real_park_ = floor(num1.real_park_);
  res.imaginary_park_ = floor(num1.imaginary_park_);
  return res;
}

Complex ceil(const Complex& num1) {
  Complex res;
  res.real_park_ = ceil(num1.real_park_);
  res.imaginary_park_ = ceil(num1.imaginary_park_);
  return res;
}

Complex round(const Complex& num1, uinteger_t precision) {
  Complex res;
  res.real_park_ = round(num1.real_park_, precision);
  res.imaginary_park_ = round(num1.imaginary_park_, precision);
  return res;
}

Complex integer(const Complex& num1) {
  Complex res;
  res.real_park_ = integer(num1.real_park_);
  res.imaginary_park_ = integer(num1.imaginary_park_);
  return res;
}

Complex decimal(const Complex& num1) {
  Complex res;
  res.real_park_ = decimal(num1.real_park_);
  res.imaginary_park_ = decimal(num1.imaginary_park_);
  return res;
}

Complex pow(const Complex& num1, const Complex& exp) {
  operation_is_not_implement_exception("%s", "pow");
  return Complex("0");
}

Complex rooting(const Complex& num1, const Complex& exp) {
  operation_is_not_implement_exception("%s", "rooting");
  return Complex("0");
}

Complex log(const Complex& base, const Complex& log) {
  operation_is_not_implement_exception("%s", "log");
  return Complex("0");
}

Complex log2(const Complex& n) {
  operation_is_not_implement_exception("%s", "log2");
  return Complex("0");
}

Complex log10(const Complex& n) {
  operation_is_not_implement_exception("%s", "log10");
  return Complex("0");
}

Complex ln(const Complex& n) {
  operation_is_not_implement_exception("%s", "ln");
  return Complex("0");
}

Complex factorial(const Complex& num1) {
  operation_is_not_implement_exception("%s", "factorial");
  return Complex("0");
}

std::pair<Complex, Complex> extended_euclidean(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "extended_euclidean");
  return {Complex("0"), Complex("0")};
}

Complex gcd(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "gcd");
  return Complex("0");
}

Complex lcm(const Complex& num1, const Complex& num2) {
  operation_is_not_implement_exception("%s", "lcm");
  return Complex("0");
}

//
// 三角函数
//
Complex sin(const Complex& x) {
  operation_is_not_implement_exception("%s", "sin");
  return Complex("0");
}

Complex cos(const Complex& x) {
  operation_is_not_implement_exception("%s", "cos");
  return Complex("0");
}

Complex tan(const Complex& x) {
  operation_is_not_implement_exception("%s", "tan");
  return Complex("0");
}

Complex csc(const Complex& x) {
  operation_is_not_implement_exception("%s", "csc");
  return Complex("0");
}

Complex sec(const Complex& x) {
  operation_is_not_implement_exception("%s", "sec");
  return Complex("0");
}

Complex cot(const Complex& x) {
  operation_is_not_implement_exception("%s", "cot");
  return Complex("0");
}


//
// 反三角函数
//
Complex arcsin(const Complex& x) {
  operation_is_not_implement_exception("%s", "arcsin");
  return Complex("0");
}

Complex arccos(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccos");
  return Complex("0");
}

Complex arctan(const Complex& x) {
  operation_is_not_implement_exception("%s", "arctan");
  return Complex("0");
}

Complex arccsc(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccsc");
  return Complex("0");
}

Complex arcsec(const Complex& x) {
  operation_is_not_implement_exception("%s", "arcsec");
  return Complex("0");
}

Complex arccot(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccot");
  return Complex("0");
}


//
// 双曲函数
//
Complex sinh(const Complex& x) {
  operation_is_not_implement_exception("%s", "sinh");
  return Complex("0");
}

Complex cosh(const Complex& x) {
  operation_is_not_implement_exception("%s", "cosh");
  return Complex("0");
}

Complex tanh(const Complex& x) {
  operation_is_not_implement_exception("%s", "tanh");
  return Complex("0");
}

Complex csch(const Complex& x) {
  operation_is_not_implement_exception("%s", "csch");
  return Complex("0");
}

Complex sech(const Complex& x) {
  operation_is_not_implement_exception("%s", "sech");
  return Complex("0");
}

Complex coth(const Complex& x) {
  operation_is_not_implement_exception("%s", "coth");
  return Complex("0");
}


//
// 反双曲函数
//
Complex arcsinh(const Complex& x) {
  operation_is_not_implement_exception("%s", "arcsinh");
  return Complex("0");
}

Complex arccosh(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccosh");
  return Complex("0");
}

Complex arctanh(const Complex& x) {
  operation_is_not_implement_exception("%s", "arctanh");
  return Complex("0");
}

Complex arccsch(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccsch");
  return Complex("0");
}

Complex arcsech(const Complex& x) {
  operation_is_not_implement_exception("%s", "arcsech");
  return Complex("0");
}

Complex arccoth(const Complex& x) {
  operation_is_not_implement_exception("%s", "arccoth");
  return Complex("0");
}

//
// 功能函数
//
void copy(Complex& to, const Complex& from) {
  to.real_park_ = from.real_park();
  to.imaginary_park_ = from.imaginary_park();
}

//
// 友元重载运算符
//

// 双目算术运算符
Complex operator+(const Complex& num1, const Complex& num2) {
  return add(num1, num2);
}

Complex operator-(const Complex& num1, const Complex& num2) {
  return sub(num1, num2);
}

Complex operator*(const Complex& num1, const Complex& num2) {
  return mul(num1, num2);
}

Complex operator/(const Complex& num1, const Complex& num2) {
  return div(num1, num2);
}

Complex operator%(const Complex& num1, const Complex& num2) {
  return mod(num1, num2);
}

Complex operator+(const Complex& num1, const char* num2) {
  return add(num1, Complex(num2));
}

Complex operator-(const Complex& num1, const char* num2) {
  return sub(num1, Complex(num2));
}

Complex operator*(const Complex& num1, const char* num2) {
  return mul(num1, Complex(num2));
}

Complex operator/(const Complex& num1, const char* num2) {
  return div(num1, Complex(num2));
}

Complex operator%(const Complex& num1, const char* num2) {
  return mod(num1, Complex(num2));
}

Complex operator+(const char* num1, const Complex& num2) {
  return add(Complex(num1), num2);
}

Complex operator-(const char* num1, const Complex& num2) {
  return sub(Complex(num1), num2);
}

Complex operator*(const char* num1, const Complex& num2) {
  return mul(Complex(num1), num2);
}

Complex operator/(const char* num1, const Complex& num2) {
  return div(Complex(num1), num2);
}

Complex operator%(const char* num1, const Complex& num2) {
  return mod(Complex(num1), num2);
}

// 关系运算符
bool operator==(const Complex& num1, const Complex& num2) {
  return equ(num1, num2);
}

bool operator!=(const Complex& num1, const Complex& num2) {
  return !equ(num1, num2);
}

bool operator<(const Complex& num1, const Complex& num2) {
  return lt(num1, num2);
}

bool operator>(const Complex& num1, const Complex& num2) {
  return gt(num1, num2);
}

bool operator<=(const Complex& num1, const Complex& num2) {
  return le(num1, num2);
}

bool operator>=(const Complex& num1, const Complex& num2) {
  return ge(num1, num2);
}

bool operator==(const Complex& num1, const char* num2) {
  return equ(num1, Complex(num2));
}

bool operator!=(const Complex& num1, const char* num2) {
  return !equ(num1, Complex(num2));
}

bool operator<(const Complex& num1, const char* num2) {
  return lt(num1, Complex(num2));
}

bool operator>(const Complex& num1, const char* num2) {
  return gt(num1, Complex(num2));
}

bool operator<=(const Complex& num1, const char* num2) {
  return le(num1, Complex(num2));
}

bool operator>=(const Complex& num1, const char* num2) {
  return ge(num1, Complex(num2));
}

bool operator==(const char* num1, const Complex& num2) {
  return equ(Complex(num1), num2);
}

bool operator!=(const char* num1, const Complex& num2) {
  return !equ(Complex(num1), num2);
}

bool operator<(const char* num1, const Complex& num2) {
  return lt(Complex(num1), num2);
}

bool operator>(const char* num1, const Complex& num2) {
  return gt(Complex(num1), num2);
}

bool operator<=(const char* num1, const Complex& num2) {
  return le(Complex(num1), num2);
}

bool operator>=(const char* num1, const Complex& num2) {
  return ge(Complex(num1), num2);
}

// 逻辑运算符
bool operator||(const Complex& num1, const Complex& num2) {
  return (!is_zero(num1) || !is_zero(num2));
}

bool operator&&(const Complex& num1, const Complex& num2) {
  return (!is_zero(num1) && !is_zero(num2));
}

bool operator!(const Complex& num1) {
  return is_zero(num1);
}

bool operator||(const Complex& num1, const char* num2) {
  return (!is_zero(num1) || !is_zero(Complex(num2)));
}

bool operator&&(const Complex& num1, const char* num2) {
  return (!is_zero(num1) && !is_zero(Complex(num2)));
}

bool operator||(const char* num1, const Complex& num2) {
  return (!is_zero(Complex(num1)) || !is_zero(num2));
}

bool operator&&(const char* num1, const Complex& num2) {
  return (!is_zero(Complex(num1)) && !is_zero(num2));
}

// 位运算符
Complex operator~(const Complex& num1) {
  return not_bits(num1);
}

Complex operator|(const Complex& num1, const Complex& num2) {
  return or_bits(num1, num2);
}

Complex operator&(const Complex& num1, const Complex& num2) {
  return and_bits(num1, num2);
}

Complex operator^(const Complex& num1, const Complex& num2) {
  return xor_bits(num1, num2);
}

Complex operator<<(const Complex& num1, const Complex& bits) {
  return lshift_bits(num1, bits);
}

Complex operator>>(const Complex& num1, const Complex& bits) {
  return rshift_bits(num1, bits);
}

Complex operator|(const Complex& num1, const char* num2) {
  return or_bits(num1, Complex(num2));
}

Complex operator&(const Complex& num1, const char* num2) {
  return and_bits(num1, Complex(num2));
}

Complex operator^(const Complex& num1, const char* num2) {
  return xor_bits(num1, Complex(num2));
}

Complex operator<<(const Complex& num1, const char* bits) {
  return lshift_bits(num1, Complex(bits));
}

Complex operator>>(const Complex& num1, const char* bits) {
  return rshift_bits(num1, Complex(bits));
}

Complex operator|(const char* num1, const Complex& num2) {
  return or_bits(Complex(num1), num2);
}

Complex operator&(const char* num1, const Complex& num2) {
  return and_bits(Complex(num1), num2);
}

Complex operator^(const char* num1, const Complex& num2) {
  return xor_bits(Complex(num1), num2);
}

Complex operator<<(const char* num1, const Complex& bits) {
  return lshift_bits(Complex(num1), bits);
}

Complex operator>>(const char* num1, const Complex& bits) {
  return rshift_bits(Complex(num1), bits);
}

Complex conjugate(const Complex& num1) {
  Complex res = num1;
  -res.imaginary_park_;
  return res;
}

char Complex::operator[](uinteger_t i) {
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

void Complex::__create_from_string(const char* n, int base) {
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
    } else {
      std::string real_str = "";
      if (plus_pos == 0)
        real_str = s;
      else
        real_str = s.substr(0, plus_pos);
      real_park_ = real_str.c_str();
      imaginary_park_.zero();
    }
  } else {
    std::string::size_type i_pos = s.find("i");
    if (i_pos != s.npos) {
      std::string imaginary_str = s.substr(0, i_pos);
      real_park_.zero();
      imaginary_park_ = imaginary_str.c_str();
    } else {
      real_park_ = s.c_str();
      imaginary_park_.zero();
    }
  }
}

} // namespace number
} // namespace mynum