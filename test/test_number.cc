#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>
#include <mynum/wrapper.h>

using namespace mynum;

TEST(Float, Number)
{
  number_t n("1/2");
  std::cout << n.value() << std::endl;

  n = number_t(1231.0);
  std::cout << n.type() << " " << n.value() << std::endl;

  n = number_t(3.1415926);
  std::cout << n.type() << " " << n.value() << std::endl;

  n = number_t("-5/2");
  std::cout << n.type() << " " << n.value() << std::endl;

  n = number_t("32143781439713589483247637186471648932174839265843917489332132112123123131321321");
  std::cout << n.type() << " " << n.value() << std::endl;

  // std::cout << LDBL_MAX << " " << LDBL_MIN << std::endl;
  // std::cout << std::to_string(LDBL_MAX) << std::endl;

  n = number_t("1.618");
  std::cout << n.type() << " " << n.value() << std::endl;

  n = number_t("32143781439713589483247637186471648932174839265843917489332132112.3213432784568236574832647832164783216478321");
  std::cout << n.type() << " " << n.value() << std::endl;

  n = 1983;
  n += 3;
  std::cout << n << std::endl;

  n = 1983;
  n *= 1210;
  std::cout << n << std::endl;

  n = 1983;
  n /= 6;
  std::cout << n << std::endl;
}

TEST(Float, Number2)
{
  // std::cout << std::to_string(LDBL_MIN) << std::endl;
  // std::cout << std::to_string(LDBL_MAX) << std::endl;
}

TEST(Float, IO)
{
  number_t n("321434214");
  std::cout << n << std::endl;
  n = number_t(1983);
  std::cout << n << std::endl;
  // std::cin >> n;
  // std::cout << n << std::endl;

  number_t x = n;
  std::cout << x << std::endl;
  x = "321321";
  std::cout << x << std::endl;
}

TEST(Float, Cast)
{
  number_t n;
  n = static_cast<number_t>(1983);
  std::cout << n << std::endl;
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}