#include <string>
#include <fstream>
#include <iostream>

#include <mynum/mynum.h>

using namespace mynum;

const int kNumber = 200;

int main(void) {
  std::ofstream ccfile("./constant_bernoulli_numbers.cc", std::ios::out);
  ccfile << "#include <mynum/mynum.h>" << std::endl << std::endl;
  ccfile << "namespace mynum {" << std::endl << std::endl;
  ccfile << "namespace f {" << std::endl << std::endl;
  ccfile << "const size_t kBernoulliNumbers = 200;" << std::endl;
  ccfile << "std::vector<float_t> __bernoulli_numbers = {" << std::endl;

  mynum::float_t a, b;
  a.precision = 0;
  b.precision = 0;
  std::string o;
  fraction_vector_t bs = z::bernoulli_numbers(kNumber);
  std::pair<integer_t, integer_t> res;
  for (int i = 1; i <= kNumber; i++) {
    a.number.number = bs.first[i-1].number;
    b.number.number = bs.second[i-1].number;
    // a = convert_integer_to_float(bs.first[i-1]);
    // b = convert_integer_to_float(bs.second[i-1]);
    o = mympf::print_string(mympf::div(a, b));
    std::cout << "( " << mympf::print_string(a) << ", " << mympf::print_string(b) << " )" << " : " << o << std::endl;
    ccfile << "\t" << "mympf::create(\"" << o << "\")";
    if (i != kNumber) ccfile << "," << std::endl;
    else ccfile << std::endl;
  }

  ccfile << "};" << std::endl << std::endl;
  ccfile << "} // namespace f" << std::endl;
  ccfile << "} // namespace mynum" << std::endl;
  ccfile.close();
  return 0;
}