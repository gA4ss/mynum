#include <iostream>
#include <cmath>
#include <cfloat>

int main(int argc, char* argv[])
{
  std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;
  // long double x = -2.2165681500327987;
  long double a = FLT_MAX;
  std::cout << a << std::endl;
  long double x = -2.216568;
  std::cout << "sin(" << x << ") = " << std::sin(x) << std::endl;
  return 0;
}