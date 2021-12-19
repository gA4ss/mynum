#include <mynum/float.h>
namespace mynum {

Float erfc(const Float& x, const char* epsilon) {
  return 1 - erf(x, epsilon);
}

} // namespace mynum