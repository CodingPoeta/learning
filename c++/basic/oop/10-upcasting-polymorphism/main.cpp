#include <iostream>
using namespace std;

class A {
public:
    int a;
    A() : a(0) {}
    A(int a) : a(a) {}
    A(const A& a) : a(a.a) {cout << "Copy constructor" << endl;}
    A& operator=(const A& a) {
        this->a = a.a;
        cout << "Copy assignment" << endl;
        return *this;
    }
    A(A&& a) : a(a.a) {cout << "Move constructor" << endl;}
    A& operator=(A&& a) {
        this->a = a.a;
        cout << "Move assignment" << endl;
        return *this;
    }
    // void print() { cout << a << endl;}
    virtual void print() { cout << a << endl;}
};

class B: public A {
    int b;
    int c;
public:
    B() : A(), b(0), c(-1) {}
    B(int a) : A(a), b(0), c(-1) {}
    B(int a, int b) : A(a), b(b), c(-1) {}
    void print() {
        cout << a << " " << b << " " << c << endl;
    }
};

class C: private A {
};

int main() {
    A a1(1);
    A a2 = a1; // Copy constructor
    int* p1 = (int*)&a1;
    A a3 = std::move(a1); // Move constructor
    A a4;
    a4 = a1; // Copy assignment
    a4 = std::move(a1); // Move assignment

    B b1(1);
    // B b2 = b1; // error
    // B b3 = move(b1); // error    
    // B b4;
    // b4 = b1; // error
    // b4 = move(b1); // error

    // C c0(); // warning: empty parentheses interpreted as a function declaration
    C c0{};
    // C c1(1);
    // C c2 = c1; // error
    // C c3 = move(c1); // error
    // C c4;
    // c4 = c1; // error
    // c4 = move(c1); // error

    cout << a1.a << " " << b1.a << endl;
    cout << sizeof(a1) << " " << sizeof(b1) << endl;
    cout << "------------------------" << endl;

    int *p = (int*)&a3;
    cout << "A: " << &a3.a << " "<< p << endl;
    // *p = 20;

    cout << *p << " " << *(p+1) << " " << *(p+2)  << " " << *(p+3) << " " << *(p+4) << " " << *(p+5) << endl;
    cout << "------------------------" << endl;

    p = (int*)&b1;
    cout << "B: " << &b1.a << " "<< p << endl;
    cout << *p << " " << *(p+1) << " " << *(p+2)  << " " << *(p+3) << " " << *(p+4) << " " << *(p+5) << endl;
    b1.print();

    cout << "------------------------" << endl;
    A& bAsA = b1;
    bAsA.print(); // polymorphism

    p = (int*)&bAsA;
    cout << &bAsA.a << " "<< p << endl;
    cout << *p << " " << *(p+1) << " " << *(p+2)  << " " << *(p+3) << " " << *(p+4) << " " << *(p+5) << endl;

    cout << "-----------m32-----------" << endl;
    cout << "vtbl[0]: " << *(*(int**)p + 0 ) << endl;
    cout << "vtbl[1]: " << *(*(int**)p + 1 ) << endl;

    return 0;
}
