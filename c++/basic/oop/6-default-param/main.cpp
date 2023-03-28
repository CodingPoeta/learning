#include <iostream>
using namespace std;

// default parameter must be the last parameter
// compiler will use the default value if the corresponding argument is omitted
// default parameter must be a constant expression
// not implemented at runtime
// not a good practice to use default parameter
int add(int a = 0, int b = 0, int c = 0) {
    return a + b + c;
}

int main () {
    cout << add() << endl;
    cout << add(1) << endl;
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    return 0;
}
