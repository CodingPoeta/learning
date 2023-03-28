#include <iostream>
using namespace std;

class A {
public:
    A(): a(0) { cout << "A::A()" << endl;}
    ~A() { cout << "A::~A()" << endl;}
    void print() { cout << "A::print()" << endl; }
    void print(int i) { cout << "A::a = " << a << ", i = " << i << endl; print(); }
protected:
    void setA(int a) { this->a = a; }
private:
    int a;
};

class B: public A {
public:
    B(): b(0) { cout << "B::B()" << endl;}
    ~B() { cout << "B::~B()" << endl;}
    void setB(int a, int b) { setA(a); this->b = b; }
    void print() { cout << "B::b = " << b << endl; }
private:
    int b;
}; 

int main () {
    B b;
    // b.setA(1); // error: ‘void A::setA(int)’ is protected
    b.setB(10, 2);
    b.print();
    
    // b.print(66); 
    // error: too many arguments to function call, expected 0, have 1; did you mean 'A::print'?
    // name hiding: B::print() hides A::print(int)
    // resolve: use scope resolution operator
    b.A::print(66);
    
    return 0;
}
