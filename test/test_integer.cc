#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

TEST(Integer, Shift) {
  integer_t m, n;

  m = mympz::create(4);
  n = z::lshift_bits(m, 5);
  EXPECT_TRUE(mympz::print_string(n) == "128");

  n = z::rshift_bits(m, 5);
  EXPECT_TRUE(mympz::print_string(n) == "0");

  m = mympz::create(1000);
  n = z::rshift_bits(m, 100);
  EXPECT_TRUE(mympz::print_string(n) == "0");
}

TEST(Integer, Logic) {
  integer_t m, n;

  m = mympz::create("1231323142143232432");
  n = mympz::create("32135424");
  m = z::and_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "19548416");

  m = mympz::create("978967937698547549832743917498314");
  n = mympz::create("413431432546543643431435425443214");
  m = z::and_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "329594107819806939974316052196746");

  m = mympz::create("1231323142143232432");
  n = mympz::create("32135424");
  m = z::or_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "1231323142155819440");

  m = mympz::create("978967937698547549832743917498314");
  n = mympz::create("413431432546543643431435425443214");
  m = z::or_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "1062805262425284253289863290744782");

  m = mympz::create("1231323142143232432");
  n = mympz::create("32135424");
  m = z::xor_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "1231323142136271024");

  m = mympz::create("978967937698547549832743917498314");
  n = mympz::create("413431432546543643431435425443214");
  m = z::xor_bits(m, n);
  EXPECT_TRUE(mympz::print_string(m) == "733211154605477313315547238548036");

  n = mympz::create("32135424");
  m = z::not_bits(n);
  n = z::xor_bits(m, n);
  n = z::not_bits(n);
  // std::cout << "n = " << mympz::print_string(n);
  EXPECT_TRUE(mympz::print_string(n) == "0");

  n = mympz::create("413431432546543643431435425443214");
  m = z::not_bits(n);
  n = z::xor_bits(m, n);
  n = z::not_bits(n);
  // std::cout << "n = " << mympz::print_string(n);
  EXPECT_TRUE(mympz::print_string(n) == "0");
}

TEST(Integer, Euclid) {
  integer_t m, n, z, k;
  std::pair<integer_t, integer_t> st;

  m = mympz::create(10);
  n = mympz::create(20);
  z = mympz::gcd(m, n);
  EXPECT_TRUE(mympz::print_string(z) == "10") << "z = " << mympz::print_string(z);

  st = z::extended_euclidean(m, n);
  k = mympz::add(mympz::mul(st.first, m), mympz::mul(st.second, n));
  EXPECT_TRUE(mympz::cmp(k, z) == 0);

  m = mympz::create(10);
  n = mympz::create(20);
  z = z::lcm(m, n);
  EXPECT_TRUE(mympz::print_string(z) == "20");

  m = mympz::create(100);
  n = mympz::create(25);
  z = mympz::gcd(m, n);
  EXPECT_TRUE(mympz::print_string(z) == "25");

  st = z::extended_euclidean(m, n);
  k = mympz::add(mympz::mul(st.first, m), mympz::mul(st.second, n));
  EXPECT_TRUE(mympz::cmp(k, z) == 0);

  m = mympz::create(14532);
  n = mympz::create(451);
  z = z::gcd(m, n);
  st = z::extended_euclidean(m, n);
  k = mympz::add(mympz::mul(st.first, m), mympz::mul(st.second, n));
  EXPECT_TRUE(mympz::cmp(k, z) == 0);

  m = mympz::create("4314732164817431865844730754725493874983174932");
  n = mympz::create("3214343243214313213233213");
  z = z::gcd(m, n);
  st = z::extended_euclidean(m, n);
  k = mympz::add(mympz::mul(st.first, m), mympz::mul(st.second, n));
  EXPECT_TRUE(mympz::cmp(k, z) == 0);


  m = mympz::create(5);
  n = mympz::create(15);
  z = z::gcd(m, n);
  st = z::extended_euclidean(m, n);
  k = mympz::add(mympz::mul(st.first, m), mympz::mul(st.second, n));
  EXPECT_TRUE(mympz::cmp(k, z) == 0) << "z = " << mympz::print_string(z) << " "
                                     << "k = " << mympz::print_string(k);
}

TEST(Integer, Factorial) {
  integer_t m, n;

  m = mympz::create(5);
  n = z::factorial(m);
  EXPECT_TRUE(mympz::print_string(n) == "120");

  m = mympz::create(15);
  n = z::factorial(m);
  EXPECT_TRUE(mympz::print_string(n) == "1307674368000");

  m = mympz::create(25);
  n = z::factorial(m);
  EXPECT_TRUE(mympz::print_string(n) == "15511210043330985984000000");
}

TEST(Integer, Pow) {
  integer_t m, n, e;

  m = mympz::create(5);
  e = mympz::create(3);
  n = z::pow(m, e);
  EXPECT_TRUE(mympz::print_string(n) == "125");

  m = mympz::create(2);
  e = mympz::create(8);
  n = z::pow(m, e);
  EXPECT_TRUE(mympz::print_string(n) == "256");

  m = mympz::create(2);
  e = mympz::create(64);
  n = z::pow(m, e);
  EXPECT_TRUE(mympz::print_string(n) == "18446744073709551616");

  m = mympz::create(2);
  e = mympz::create(128);
  n = z::pow(m, e);
  EXPECT_TRUE(mympz::print_string(n) == "340282366920938463463374607431768211456");
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}