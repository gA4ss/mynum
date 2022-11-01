#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
  std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
  std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
  std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
  std::cout << "sizeof(size_t) = " << sizeof(size_t) << std::endl;

  unsigned long u = 0xAAAAAAAA, v = 0xAAAAAAAA;
  unsigned long o = u * v;
  std::cout << "u * v = " << std::hex << o << std::endl;
  return 0;
}