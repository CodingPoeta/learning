#include <iostream>

struct X {
  X() = default;
  X(const X&) { std::cout << "copy" << std::endl; }
  X(X&&) { std::cout << "move" << std::endl; }
  ~X() { std::cout << "destructor" << std::endl; }
};
X f(X&& x) { return x; }
int main() { X x = f(X{}); }
