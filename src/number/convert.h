#ifndef MYNUM_NUMBER_CONVERT_H_
#define MYNUM_NUMBER_CONVERT_H_

#include <mynum/number/number.h>
#include <mynum/number/complex.h>
#include <mynum/number/real.h>
#include <mynum/number/integer.h>

namespace mynum {
namespace number {

mynum_complex_t convert_to_complex(const mynum_number_t& object);
Complex* convert_to_complex(Number* object);
Complex convert_to_complex(Number& object);

mynum_real_t convert_to_real(const mynum_number_t& object);
Real* convert_to_real(Number* object);
Real convert_to_real(Number& object);

mynum_integer_t convert_to_integer(const mynum_number_t& object);
Integer* convert_to_integer(Number* object);
Integer convert_to_integer(Number& object);

bool is_complex(const mynum_number_t& object);
bool is_complex(Number* object);
bool is_complex(const Number& object);

bool is_real(const mynum_number_t& object);
bool is_real(Number* object);
bool is_real(const Number& object);

bool is_integer(const mynum_number_t& object);
bool is_integer(Number* object);
bool is_integer(const Number& object);



} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_CONVERT_H_