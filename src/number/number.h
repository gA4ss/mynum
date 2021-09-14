#ifndef MYNUM_NUMBER_NUMBER_H_
#define MYNUM_NUMBER_NUMBER_H_

#include <memory>
#include <vector>

#include <mynum/core/common.h>
#include <mynum/core/numeric.h>

using namespace mynum::core;

namespace mynum {
namespace number {

class Number {
public:
  Number();
  virtual ~Number();
  virtual std::string str() const = 0;
  virtual std::string class_name() const = 0;
};

typedef std::shared_ptr<Number> mynum_number_t;
typedef std::vector<mynum_number_t> mynum_numbers_t;

template<typename T>
std::shared_ptr<Number> create_object() {
  //
  // FIXME : 校验传入模板类型
  //
  return std::make_shared<T>();
}

template<typename T>
std::shared_ptr<T> dyn_cast(std::shared_ptr<Number> ptr) {
  return std::dynamic_pointer_cast<T>(ptr);
}

// template<typename T>
// std::shared_ptr<
//   typename std::enable_if<!std::is_same<Number, T>::value)
//                           &&(std::is_base_of<Number, T>::value), T>::type>
// dyn_cast(std::shared_ptr<Number> ptr) {
//   return std::dynamic_pointer_cast<T>(ptr);
// }

} // namespace number
} // namespace mynum

#endif // MYNUM_NUMBER_NUMBER_H_