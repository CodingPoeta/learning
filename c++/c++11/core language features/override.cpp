#include <iostream>

struct Base {
  virtual void doSomething(int i) const
  {
    std::cout << "This is from Base with " << i << std::endl;
  }
private:
  virtual int dontChangeMe() const = 0;
};

struct Derived: Base {
  void doSomething(int i) const override
  {
    std::cout << "This is from Derived with " << i << std::endl;
  }
private:
  int dontChangeMe() const final  { return 419; }
};

struct Derived2: Derived {
private:
  // int dontChangeMe() const override { return 61; }
};

void letDoSomething(Base &base) {
  base.doSomething(419);
}

int main() {
  Derived d;
  letDoSomething(d); // 输出结果： "This is from Base with 419"
}
