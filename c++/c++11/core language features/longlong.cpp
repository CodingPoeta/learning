#include <iostream>
#include <limits>

struct X {
  short x1 : 8;
  int x2 : 24;
  long long x3 : 32;
};

int main() {
  X x;
  x.x1 = 0x7f;
  x.x2 = 0x7fffff;
  x.x3 = 0x7fff;
  std::cout << x.x1 << std::endl;
  std::cout << x.x2 << std::endl;
  std::cout << x.x3 << std::endl;
  std::cout << sizeof(x) << std::endl;
  std::cout << std::numeric_limits<long long>::max() << std::endl;

  return 0;
}