#include <iostream>

namespace ns {
namespace v1 {
void foo() { std::cout << "ns::v1::foo" << std::endl; }
inline namespace [[deprecated]] sub {}  // namespace sub
}  // namespace v1
inline namespace v2 {
void foo() { std::cout << "ns::v2::foo" << std::endl; }
}  // namespace v2
}  // namespace ns

namespace ns::v1::inline sub {
void foo2() { std::cout << "ns::v1::sub::foo2" << std::endl; }
}  // namespace ns::v1::inline sub

int main() {
  ns::v1::foo();
  ns::foo();
  ns::v2::foo();
  ns::v1::foo2();
  ns::v1::sub::foo2();
  return 0;
}
