#include <string>
#include <fstream>
#include <iostream>

#include <mynum/integer.h>
#include <mynum/float.h>
#include <mynum/convert.h>

using namespace mynum;

const int kNumber = 200;

int main(void) {
  std::ofstream ccfile("./constant_euler_numbers.cc", std::ios::out);
  ccfile << "#include <mynum/float.h>" << std::endl << std::endl;
  ccfile << "namespace mynum {" << std::endl << std::endl;
  ccfile << "const uinteger_t kEulerNumbers = " << std::to_string(kNumber) << ";" << std::endl;
  ccfile << "std::vector<Float> __euler_numbers = {" << std::endl;

  Float a;
  int_array_t ia = euler_numbers(kNumber);
  for (int i = 0; i < kNumber; i++) {
    a = convert_integer_to_float(ia[i]);
    std::cout << a.str() << std::endl;
    ccfile << "\t" << "\"" << a.str() << "\"";
    if (i != (kNumber-1)) ccfile << "," << std::endl;
    else ccfile << std::endl;
  }

  ccfile << "};" << std::endl << std::endl;
  ccfile << "} // namespace mynum" << std::endl;
  ccfile.close();
  return 0;
}