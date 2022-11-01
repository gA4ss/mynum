#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/float.h>

using namespace mynum;

TEST(Float, Logarithmic) {
  Float x = "4", y;
  y = ln(x);
  // std::cout << "ln(4) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "1.386294361119891") < "0.0001") << "y = " << y.str();
  
  x = "5";
  y = ln(x);
  // std::cout << "ln(5) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "1.609437912434100") < "0.0001") << "y = " << y.str();

  x = "0.6";
  y = ln(x);
  // std::cout << "ln(0.6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "-0.510826") < "0.0001") << "y = " << y.str();

  x = "0.4";
  y = ln(x);
  // std::cout << "ln(0.4) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "-0.916291") < "0.0001") << "y = " << y.str();

  x = "5";
  y = log10(x);
  // std::cout << "ln(5) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.69897000") < "0.0001") << "y = " << y.str();

  x = "0.6";
  y = log10(x);
  // std::cout << "ln(0.6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "-0.221849") < "0.0001") << "y = " << y.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}