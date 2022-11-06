#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

TEST(Float, Error) {
  mympf::float_t x = mympf::create(2, 0);
  std::cout << "erf(" << mympf::print_string(x) << ") = " 
            <<  mympf::print_string(f::erf(x)) << std::endl;
  std::cout << "erfc(" << mympf::print_string(x) << ") = " 
            << mympf::print_string(f::erfc(x)) << std::endl;
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}