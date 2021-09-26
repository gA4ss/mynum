#ifndef MYNUM_EXCEPTION_H_
#define MYNUM_EXCEPTION_H_

#include <ctype.h>

#include <my/my_exception.h>

namespace mynum {

#define unknown_mynum_exception() { throw my::MyException("<mynum> Unknown MyNumber", __FILE__, __LINE__, __FUNCTION__, "%s", ""); }
#define divisor_is_zero_exception(format, ...) { throw my::MyException("<mynum> Divisor is Zero", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define operand_type_is_invalid_exception(format, ...) { throw my::MyException("<mynum> Operand Type is Invalid", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define operand_value_is_invalid_exception(format, ...) { throw my::MyException("<mynum> Operand Value is Invalid", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define operation_is_not_implement_exception(format, ...) { throw my::MyException("<mynum> Operation is not Implement", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define xxx_can_not_convert_to_yyy_exception(xxx, yyy) { throw my::MyException("<mynum> Type Convert", __FILE__, __LINE__, __FUNCTION__, "%s -> %s", (xxx), (yyy)); }

} // namespace mynum

#endif // MYNUM_EXCEPTION_H_
