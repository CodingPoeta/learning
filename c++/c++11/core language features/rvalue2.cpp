#include <iostream>

class A {
 public:
  A(int size) : size_(size) { data_ = new int[size]; }
  A() {}
  A(const A& a) : size_(a.size_) {
    data_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
      data_[i] = a.data_[i];
    }
    std::cout << "copy " << std::endl;
  }
  A(A&& a) {
    this->data_ = a.data_;
    a.data_ = nullptr;
    std::cout << "move " << std::endl;
  }
  ~A() { delete[] data_; }
  int* data_;
  int size_;
};
int main() {
  A a(10);
  A b = a;
  A c = std::move(a);  // 调用移动构造函数
  std::cout << "a " << a.data_ << std::endl;
  std::cout << "b " << b.data_ << std::endl;
  std::cout << "c " << c.data_ << std::endl;
  return 0;
}
