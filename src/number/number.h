#ifndef MYNUM_NUMBER_NUMBER_H_
#define MYNUM_NUMBER_NUMBER_H_

#include <mynum/common.h>
#include <mynum/core/numeric.h>

namespace mynum {
namespace number {

enum {
  kComplexType = 0,
  kRealType = 1,
  kIntegerType = 2
};

class Number {
public:
  Number() : class_id_(kComplexType), class_name_("complex") { zero(); }

  Number(const core::Numeric& real_park) : Number() { assign(real_park, false); }
  Number(const core::Numeric& real_park, const core::Numeric& imaginary_park) : Number() { 
    assign(real_park, imaginary_park);
  }

  Number(Number* number) { assign(*number); }
  Number(const Number& number) { assign(number); }

  Number(const char* number, int base=10) { assign(number, base); }
  Number(std::string& number, int base=10) { assign(number.c_str(), base); }

  virtual ~Number() {}

  virtual std::string str() const;

  virtual int class_id() const { return class_id_; }
  virtual std::string class_name() const { return class_name_; }

  virtual core::Numeric real_park() const;
  virtual core::Numeric imaginary_park() const;

  virtual void assign(const core::Numeric& real_park, bool it=false) {
    if (it) {
      real_park_ = core::integer(real_park);
      class_id_ = kIntegerType; class_name_ = "integer";
    } else {
      real_park_ = real_park;
      class_id_ = kRealType; class_name_ = "real";
    }
    imaginary_park_.zero();
  }

  virtual void assign(const core::Numeric& real_park, const core::Numeric& imaginary_park) {
    real_park_ = real_park; imaginary_park_ = imaginary_park;
    class_id_ = kComplexType; class_name_ = "complex";
  }

  virtual void assign(const char* number, int base=10) {
    __create_from_string(number, base);
  }

  virtual void assign(const Number& number) {
    real_park_ = number.real_park(); imaginary_park_ = number.imaginary_park();
    class_id_ = number.class_id(); class_name_ = number.class_name();
  }

  virtual void zero() { real_park_.zero(); imaginary_park_.zero(); }
  virtual void one(int sign) { real_park_.one(sign); imaginary_park_.zero(); }
  virtual void infinite(int sign);
  virtual void nan() { real_park_.nan(kPositive); imaginary_park_.nan(kPositive); }
  virtual void none() { real_park_.none(); imaginary_park_.none(); }

  //////////////////////////////
  // operation function
  //////////////////////////////
  Number& operator+();
  Number& operator-();

  Number& operator++();
  Number operator++(int);
  Number& operator--();
  Number operator--(int);

  virtual void operator=(const Number& num2);
  virtual void operator=(const char* num2);
  virtual void operator+=(const Number& num2);
  virtual void operator+=(const char* num2);
  virtual void operator-=(const Number& num2);
  virtual void operator-=(const char* num2);
  virtual void operator*=(const Number& num2);
  virtual void operator*=(const char* num2);
  virtual void operator/=(const Number& num2);
  virtual void operator/=(const char* num2);
  virtual void operator%=(const Number& num2);
  virtual void operator%=(const char* num2);
  virtual void operator&=(const Number& num2);
  virtual void operator&=(const char* num2);
  virtual void operator|=(const Number& num2);
  virtual void operator|=(const char* num2);
  virtual void operator^=(const Number& num2);
  virtual void operator^=(const char* num2);
  virtual void operator<<=(const Number& bits);
  virtual void operator>>=(const Number& bits);
  virtual char operator[](uinteger_t i);

protected:
  void __create_from_string(const char* n, int base);
  void __set_real_park(const core::Numeric& real_park) { real_park_ = real_park; }
  void __set_real_park_zero() { real_park_.zero(); }
  void __set_imaginary_park(const core::Numeric& imaginary_park) { imaginary_park_ = imaginary_park; }
  void __set_imaginary_park_zero() { imaginary_park_.zero(); }
  void __set_class(int cls);

protected:
  core::Numeric real_park_;
  core::Numeric imaginary_park_;

  int class_id_;
  std::string class_name_;
};

typedef std::shared_ptr<Number> mynum_number_t;
typedef std::vector<mynum_number_t> mynum_numbers_t;

bool equ(const Number& num1, const Number& num2);
bool gt(const Number& num1, const Number& num2);
bool lt(const Number& num1, const Number& num2);
bool ge(const Number& num1, const Number& num2);
bool le(const Number& num1, const Number& num2);

bool is_zero(const Number& num1);
bool is_one(const Number& num1);
bool is_nan(const Number& num1);
bool is_infinite(const Number& num1);
bool is_none(const Number& num1);
bool is_integer(const Number& num1);
bool is_float(const Number& num1);
bool is_odd(const Number& num1);
bool is_even(const Number& num1);

Number add(const Number& num1, const Number& num2);
Number sub(const Number& num1, const Number& num2);
Number mul(const Number& num1, const Number& num2);
Number div(const Number& num1, const Number& num2);
Number quo(const Number& num1, const Number& num2);
Number rem(const Number& num1, const Number& num2);
Number mod(const Number& num1, const Number& num2);
Number or_bits(const Number& num1, const Number& num2);
Number and_bits(const Number& num1, const Number& num2);
Number xor_bits(const Number& num1, const Number& num2);
Number not_bits(const Number& num1);
Number lshift_bits(const Number& num1, const Number& bits);
Number rshift_bits(const Number& num1, const Number& bits);
Number abs(const Number& num1);
Number floor(const Number& num1);
Number ceil(const Number& num1);
Number round(const Number& num1, uinteger_t precision);
Number integer(const Number& num1);
Number decimal(const Number& num1);
Number pow(const Number& num1, const Number& exp);
Number rooting(const Number& num1, const Number& exp);
Number log(const Number& base, const Number& log);
Number log2(const Number& n);
Number log10(const Number& n);
Number ln(const Number& n);
Number factorial(const Number& num1);
std::pair<Number, Number> extended_euclidean(const Number& num1, const Number& num2);
Number gcd(const Number& num1, const Number& num2);
Number lcm(const Number& num1, const Number& num2);

Number sin(const Number& x);
Number cos(const Number& x);
Number tan(const Number& x);
Number csc(const Number& x);
Number sec(const Number& x);
Number cot(const Number& x);

Number arcsin(const Number& x);
Number arccos(const Number& x);
Number arctan(const Number& x);
Number arccsc(const Number& x);
Number arcsec(const Number& x);
Number arccot(const Number& x);

Number sinh(const Number& x);
Number cosh(const Number& x);
Number tanh(const Number& x);
Number csch(const Number& x);
Number sech(const Number& x);
Number coth(const Number& x);

Number arcsinh(const Number& x);
Number arccosh(const Number& x);
Number arctanh(const Number& x);
Number arccsch(const Number& x);
Number arcsech(const Number& x);
Number arccoth(const Number& x);

Number& copy(Number& to, const Number& from);

//////////////////////////////
// operation function
//////////////////////////////
Number operator+(const Number& num1, const Number& num2);
Number operator-(const Number& num1, const Number& num2);
Number operator*(const Number& num1, const Number& num2);
Number operator/(const Number& num1, const Number& num2);
Number operator%(const Number& num1, const Number& num2);

Number operator+(const Number& num1, const char* num2);
Number operator-(const Number& num1, const char* num2);
Number operator*(const Number& num1, const char* num2);
Number operator/(const Number& num1, const char* num2);
Number operator%(const Number& num1, const char* num2);

Number operator+(const char* num1, const Number& num2);
Number operator-(const char* num1, const Number& num2);
Number operator*(const char* num1, const Number& num2);
Number operator/(const char* num1, const Number& num2);
Number operator%(const char* num1, const Number& num2);

bool operator==(const Number& num1, const Number& num2);
bool operator!=(const Number& num1, const Number& num2);
bool operator<(const Number& num1, const Number& num2);
bool operator>(const Number& num1, const Number& num2);
bool operator<=(const Number& num1, const Number& num2);
bool operator>=(const Number& num1, const Number& num2);

bool operator==(const Number& num1, const char* num2);
bool operator!=(const Number& num1, const char* num2);
bool operator<(const Number& num1, const char* num2);
bool operator>(const Number& num1, const char* num2);
bool operator<=(const Number& num1, const char* num2);
bool operator>=(const Number& num1, const char* num2);

bool operator==(const char* num1, const Number& num2);
bool operator!=(const char* num1, const Number& num2);
bool operator<(const char* num1, const Number& num2);
bool operator>(const char* num1, const Number& num2);
bool operator<=(const char* num1, const Number& num2);
bool operator>=(const char* num1, const Number& num2);

bool operator||(const Number& num1, const Number& num2);
bool operator&&(const Number& num1, const Number& num2);
bool operator!(const Number& num1);

bool operator||(const Number& num1, const char* num2);
bool operator&&(const Number& num1, const char* num2);

bool operator||(const char* num1, const Number& num2);
bool operator&&(const char* num1, const Number& num2);

Number operator~(const Number& num1);
Number operator|(const Number& num1, const Number& num2);
Number operator&(const Number& num1, const Number& num2);
Number operator^(const Number& num1, const Number& num2);
Number operator<<(const Number& num1, const Number& bits);
Number operator>>(const Number& num1, const Number& bits);

Number operator|(const Number& num1, const char* num2);
Number operator&(const Number& num1, const char* num2);
Number operator^(const Number& num1, const char* num2);
Number operator<<(const Number& num1, const char* bits);
Number operator>>(const Number& num1, const char* bits);

Number operator|(const char* num1, const Number& num2);
Number operator&(const char* num1, const Number& num2);
Number operator^(const char* num1, const Number& num2);
Number operator<<(const char* num1, const Number& bits);
Number operator>>(const char* num1, const Number& bits);

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_NUMBER_H_