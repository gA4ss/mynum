#include <mynum/float.h>
namespace mynum {

// https://www.itl.nist.gov/div898/software/dataplot/refman2/ch7/arcsinh.pdf

Float arcsinh(const Float& x, const char* epsilon) {
  Float y = add(pow(x, "2"), "1");
  return ln(add(x, sqrt(y)), epsilon);
}

} // namespace mynum