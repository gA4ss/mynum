#ifndef MYNUM_NUMBER_INTEGER_H_
#define MYNUM_NUMBER_INTEGER_H_

#include <mynum/number/number.h>

namespace mynum {
namespace number {

class Integer : public Number {
public:
  Integer() { __set_class(kIntegerType); }
  Integer(const char* number, int base=10) { 
    assign(number, base);
    real_park_ = core::integer(real_park_);
    __set_class(kIntegerType); 
  }
  Integer(std::string& number, int base=10) { 
    assign(number.c_str(), base);
    real_park_ = core::integer(real_park_);
    __set_class(kIntegerType); 
  }
  Integer(const core::Numeric& real_park) { 
    assign(real_park);
    real_park_ = core::integer(real_park_);
    __set_class(kIntegerType);
  }
  Integer(Number* number) { 
    assign(*number);
    real_park_ = core::integer(real_park_);
    __set_class(kIntegerType);
  }
  Integer(const Number& number) { 
    assign(number);
    real_park_ = core::integer(real_park_);
    __set_class(kIntegerType); 
  }
  virtual ~Integer() {}
};
typedef std::shared_ptr<Integer> mynum_integer_t;

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_INTEGER_H_