#ifndef MYNUM_EXCEPTION_H_
#define MYNUM_EXCEPTION_H_

namespace mynum
{
#define mynum_exception(format, ...)                                              \
  {                                                                               \
    throw my::MyException("<mynum>",                                              \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

#define mynum_operand_value_is_invalid_exception(format, ...)                     \
  {                                                                               \
    throw my::MyException("<mynum> operand value is invalid",                     \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

#define mynum_over_bernoulli_numbers_table_exception(format, ...)                 \
  {                                                                               \
    throw my::MyException("<mynum> over bernoulli numbers table size",            \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

#define mynum_over_euler_numbers_table_exception(format, ...)                     \
  {                                                                               \
    throw my::MyException("<mynum> over euler numbers table size",                \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

#define unknown_mynum_exception()                                                                   \
  {                                                                                                 \
    throw my::MyException("<mynum> Unknown Exception", __FILE__, __LINE__, __FUNCTION__, "%s", ""); \
  }
} // namespace mynum

#endif // MYNUM_EXCEPTION_H_