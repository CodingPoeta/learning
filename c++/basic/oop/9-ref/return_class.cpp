#include <iostream>
using namespace std;

int cnt=0;

class A {
public:
    int i;
    A() : i(0) { cout << ++cnt << "A()" << endl; }
    A(int i) : i(i+1) { cout << ++cnt << "A(" << i << ")->" << this->i << endl; };
    ~A() { cout << --cnt << "~A(" << i << ")" << endl; }
};

A copy(A a) {
    return a;
}

A f(int i) {
    A a(i);
    return a;
}

int g() {
    int i=10;
    return i;
}

int main() {
    A a, b = f(1);
    cout << b.i << endl;
    f(2) = b;
    b.i = 20;

    A c = 3;
    // A c = A(3);
    // A c = {3};
    A d = b;
    copy(A{4});
    // g() = 20;
    cout << "----------------" << endl;
    return 0;
}
