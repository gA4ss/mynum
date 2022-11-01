#include <string>
#include <fstream>
#include <iostream>

#include <mynum/integer.h>
#include <mynum/float.h>
#include <mynum/convert.h>

using namespace mynum;

const int kNumber = 200;

int main(void) {
  std::ofstream ccfile("./constant_bernoulli_numbers.cc", std::ios::out);
  ccfile << "#include <mynum/float.h>" << std::endl << std::endl;
  ccfile << "namespace mynum {" << std::endl << std::endl;
  ccfile << "const uinteger_t kBernoulliNumbers = 200;" << std::endl;
  ccfile << "std::vector<Float> __bernoulli_numbers = {" << std::endl;

  Float a, b;
  std::string o;
  fraction_vector_t bs = bernoulli_numbers(kNumber);
  std::pair<Integer, Integer> res;
  for (int i = 1; i <= kNumber; i++) {
    a = convert_integer_to_float(bs.first[i-1]);
    b = convert_integer_to_float(bs.second[i-1]);
    o = (a / b).str();
    std::cout << "( " << a.str() << ", " << b.str() << " )" << " : " << o << std::endl;
    ccfile << "\t" << "\"" << o << "\"";
    if (i != kNumber) ccfile << "," << std::endl;
    else ccfile << std::endl;
  }

  ccfile << "};" << std::endl << std::endl;
  ccfile << "} // namespace mynum" << std::endl;
  ccfile.close();
  return 0;
}