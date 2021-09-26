#ifndef MYNUM_NUMBER_REAL_H_
#define MYNUM_NUMBER_REAL_H_

#include <mynum/number/number.h>

namespace mynum {
namespace number {

class Real : public Number {
public:
  Real() { __set_class(kRealType); }
  Real(const char* number, int base=10) { assign(number, base); __set_class(kRealType); }
  Real(std::string& number, int base=10) { assign(number.c_str(), base); __set_class(kRealType); }
  Real(const core::Numeric& real_park) { assign(real_park); __set_class(kRealType); }
  Real(Number* number) { assign(*number); __set_class(kRealType); }
  Real(const Number& number) { assign(number); __set_class(kRealType); }
  virtual ~Real() {}
};
typedef std::shared_ptr<Real> mynum_real_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_REAL_H_