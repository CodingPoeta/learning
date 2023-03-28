#include <iostream>
using namespace std;

// Two functions of 'static' keyword:
// 1. hidden
// 2. persistent
class A {
public:
    A() {
        a = 0;
    }
    void set(int x) {
        // you can access 'static' member by 'this' pointer
        this->a = x;
    }
    // static function can only access 'static' member
    static void print() {
        cout << "a = " << a << endl;
    }
    static int b;

private:
    // hidden is supported by 'private' keyword
    // persistent is supported by 'static' keyword
    static int a; // declaration
};

int A::a = 0; // definition
int A::b = 0;

int main () {
    A a;
    a.set(10);
    a.print();

    cout << a.b << endl;
    cout << A::b << endl;
    A::print();
    return 0;
}
