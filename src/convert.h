#ifndef MYNUM_CONVERT_H_
#define MYNUM_CONVERT_H_

#include <mynum/integer.h>
#include <mynum/float.h>

namespace mynum {

Float convert_integer_to_float(const Integer& i);
Integer convert_float_to_integer(const Float& f);

} // namespace mynum

#endif // MYNUM_CONVERT_H_