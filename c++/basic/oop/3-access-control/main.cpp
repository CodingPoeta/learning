#include <iostream>

using namespace std;

// class or struct difference
// class: default access control is private
// struct: default access control is public

struct X;

class A {
private:
    int a;
    int *p;
public:
    A(): p(NULL),a(0){
        cout << "A constructor called." << endl;
    }
    A(int _a): p(NULL),a(_a){
        cout << "A constructor called." << endl;
    }
    ~A() {
        if (p != NULL) {
            delete p;
        }
        cout << "A destructor called." << endl;
    }
    void setA(int a) {
        this->a = a;
    }
    void f() { p = new int; }
    void g(A* q) { cout << q->a << endl; }
    void peekX(X* x);
};

struct X {
private:
    int x;
public:
    void init();
    friend void g(X*, int);
    friend void A::peekX(X*);
    friend struct Z;
};

void X::init() {
    x = 0;
}

void g(X* x, int i) {
    x->x = i;
}

void A::peekX(X* x) {
    cout << x->x << endl;
}

struct Z {
private:
    int z;
};

int main () {
    A* p = new A[1];
    for (int i = 0; i < 1; i++) {
        p[i].setA(i);
    }
    delete[] p;
    return 0;
}
