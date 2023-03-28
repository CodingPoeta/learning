#include <iostream>
using namespace std;

// overhead for a function call

// inline function
// compiler will replace the function call with the function body
// it's better in header file

// tradeoff: code size vs. performance
// compare to macro: macro is not type safe
// recursive function cannot be inline
inline int f(int a, int b) {
    return a + b;
}

// inline inside class:
// any function defined inside a class declaration is inline by default
class A {
public:
    A(): a(0) { cout << "A::A()" << endl;}
    ~A() { cout << "A::~A()" << endl;}
    void print() { cout << "A::print()" << endl; }
    void print(int i);
protected:
    void setA(int a) { this->a = a; }
private:
    int a;
};

inline void A::print(int i) {
    cout << "A::a = " << a << ", i = " << i << endl;
    print();
}

int main() {
    int a = 1;
    int b = 2;
    int c = f(a, b);
    cout << c << endl;

    A a1;
    a1.print(66);
    a1.print();
    return 0;
}
