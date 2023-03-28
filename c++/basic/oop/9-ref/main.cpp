#include <iostream>
using namespace std;

int* f(int* x) {
    (*x)++;
    return x;
}

int& g(int& x) {
    x++;
    return x;
}

int x = 0;

int& h() {
    int q;
    // return q; // error
    return x;
}

int main() {
    char c;
    char* p = &c;
    char& r = c; // reference / alias
    // reference is a kind of const pointer
    // int& *p; // error
    // int* &p; reference to pointer is OK

    int a = 1;
    f(&a); // Ugly but explicit
    g(a);  // Clean but implicit (you don't know if g() will modify a at first glance)
    // h() returns a reference to x which is a left value
    h() = 2;

    return 0;
}