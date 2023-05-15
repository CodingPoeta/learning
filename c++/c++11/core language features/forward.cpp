#include <iostream>
#include <string>

template<typename T>
void show_type(T t) {
  std::cout << typeid(t).name() << std::endl;
}

void show_ref(std::string &s) {
  std::cout << "lvalue ref" << std::endl;
}

void show_ref(std::string &&s) {
  std::cout << "rvalue ref" << std::endl;
}

template<typename T>
void perfect_forwarding(T &&t) {
  // show_type(static_cast<T &&>(t));
  show_type(std::forward<T>(t));
  show_ref(std::forward<T>(t));
}

std::string get() { return "hello"; }

int main(){
  std::string ss = "hello1";
  perfect_forwarding(ss);
  perfect_forwarding(get());
  perfect_forwarding(std::move(ss));
  return 0;
}
