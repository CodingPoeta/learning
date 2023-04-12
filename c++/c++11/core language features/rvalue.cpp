#include <iostream>

#ifndef TYPE
  #define TYPE int
#endif

struct Integer {
  Integer(int i) : i_(i) {}
  Integer(const Integer &i) : i_(i.i_) { std::cout << "copy" << std::endl; }
  Integer(Integer &&i) : i_(i.i_) { std::cout << "move" << std::endl; }
  int i_;
};

void PrintV(TYPE &t) { std::cout << "lvalue" << std::endl; }

void PrintV(TYPE &&t) { std::cout << "rvalue" << std::endl; }

template <typename T>
void Test(T &&t) {
  std::cout << "----------------- " << &t << std::endl;
  PrintV(t);
  // PrintV(static_cast<T&&>(t));
  PrintV(std::forward<T>(t));
  PrintV(std::move(t));
}

int main() {
  Test(1);  // lvalue rvalue rvalue
  TYPE a = 1;
  std::cout << &a << std::endl;
  Test(a);                            // lvalue lvalue rvalue
  Test(std::forward<TYPE>(a));     // lvalue rvalue rvalue
  Test(std::forward<TYPE &>(a));   // lvalue lvalue rvalue
  Test(std::forward<TYPE &&>(a));  // lvalue rvalue rvalue
  return 0;
}