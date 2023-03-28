#include <iostream>

template <class T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 111, b = 222;
    swap(a, b);
    std::cout << a << "  " << b << std::endl;

    double c = 1.1, d = 2.2;
    swap(c, d);
    std::cout << c << "  " << d << std::endl;

    float e = 3.3, f = 4.4;
    swap<float>(e, f);
    std::cout << e << "  " << f << std::endl;

    return 0;
}

// overloading rules:
// 1. Check first for unique function match
// 2. Then check for unique template match
// 3. Then check for function match with implicit type conversion
