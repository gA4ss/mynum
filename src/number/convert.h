#ifndef MYNUM_NUMBER_CONVERT_H_
#define MYNUM_NUMBER_CONVERT_H_

#include <mynum/number/number.h>
#include <mynum/number/complex.h>
#include <mynum/number/real.h>
#include <mynum/number/integer.h>

namespace mynum {
namespace number {

mynum_complex_t convert_to_complex(const mynum_number_t& object);
mynum_real_t convert_to_real(const mynum_number_t& object);
mynum_integer_t convert_to_integer(const mynum_number_t& object);

bool is_complex(const mynum_number_t& object);
bool is_real(const mynum_number_t& object);
bool is_integer(const mynum_number_t& object);

Complex* convert_to_complex_ptr(Number* object);
Real* convert_to_real_ptr(Number* object);
Integer* convert_to_integer_ptr(Number* object);

bool is_complex_ptr(Number* object);
bool is_real_ptr(Number* object);
bool is_integer_ptr(Number* object);

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_CONVERT_H_