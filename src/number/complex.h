#ifndef MYNUM_NUMBER_COMPLEX_H_
#define MYNUM_NUMBER_COMPLEX_H_

#include <mynum/number/number.h>

namespace mynum {
namespace number {

class Complex : public Number {
public:
  Complex() { __set_class(kComplexType); }
  Complex(const char* number, int base=10) { assign(number, base); __set_class(kComplexType); }
  Complex(std::string& number, int base=10) { assign(number.c_str(), base); __set_class(kComplexType); }
  Complex(const core::Numeric& real_park) { assign(real_park); __set_class(kComplexType); }
  Complex(const core::Numeric& real_park, const core::Numeric& imaginary_park) { assign(real_park, imaginary_park); }
  Complex(Number* number) { assign(*number);  __set_class(kComplexType); }
  Complex(const Number& number) { assign(number); __set_class(kComplexType); }
  virtual ~Complex() {}

  friend Complex conjugate(const Complex& num1);
};
typedef std::shared_ptr<Complex> mynum_complex_t;

Complex conjugate(const Complex& num1);

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_COMPLEX_H_