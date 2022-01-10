#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/float.h>
#include <mynum/math.h>

using namespace mynum;

TEST(Float, Error) {
  for (Float x = 0.00; x < 0.2; x += 0.01) {
    std::cout << "erf(" << x << ") = " << erf(x) << "\t";
    std::cout << "erfc(" << x << ") = " << erfc(x) << std::endl;
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}