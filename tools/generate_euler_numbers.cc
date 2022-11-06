#include <string>
#include <fstream>
#include <iostream>

#include <mynum/mynum.h>

using namespace mynum;

const int kNumber = 200;

int main(void)
{
  std::ofstream ccfile("./constant_euler_numbers.cc", std::ios::out);
  ccfile << "#include <mynum/mynum.h>" << std::endl
         << std::endl;
  ccfile << "namespace mynum {" << std::endl
         << std::endl;
  ccfile << "namespace f {" << std::endl
         << std::endl;
  ccfile << "const size_t kEulerNumbers = " << std::to_string(kNumber) << ";" << std::endl;
  ccfile << "std::vector<float_t> __euler_numbers = {" << std::endl;

  mynum::float_t a;
  int_array_t ia = z::euler_numbers(kNumber);
  for (int i = 0; i < kNumber; i++)
  {
    a.number = ia[i];
    std::cout << mympf::print_string(a) << std::endl;
    ccfile << "\t"
           << "mympf::create(\"" << mympf::print_string(a) << "\")";
    if (i != (kNumber - 1))
      ccfile << "," << std::endl;
    else
      ccfile << std::endl;
  }

  ccfile << "};" << std::endl
         << std::endl;
  ccfile << "} // namespace f" << std::endl;
  ccfile << "} // namespace mynum" << std::endl;
  ccfile.close();
  return 0;
}