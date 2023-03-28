#include <iostream>
using namespace std;

class X
{
public:
    X()
    {
        cout << "X constructor called." << endl;
    }

    ~X()
    {
        cout << "X destructor called." << endl;
    }
};

void func1(int i = 0)
{
    cout << "func1 called." << endl;
    if (i < 10)
    {
        goto j1;
    }
    X x1;
j1:
    switch (i)
    {
    case 1:
        // X x2;
        break;
    case 2:
        // X x3;
        break;
    default:
        break;
    }
}

int main()
{
    func1();
    return 0;
}
