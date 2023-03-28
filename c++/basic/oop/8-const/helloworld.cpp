#include <iostream>
using namespace std;

int main() {
    // constant string is stored in read-only memory
    // so you can't change it
    // heap memory is read-write
    // stack memory is read-write
    // bss memory is read-only
    // stack -> <- heap | bss (uninitialized static data) | data (initialized static data) | text
    char * s0 = "hello world0";
    char s1[] = "hello world1";
    const char * s2 = "hello world2";

    int i = 0;
    int j;
    auto p = new int;

    cout << s1 << endl;

    s1[0] = 'H';

    cout << s1 << endl;

    cout << "[stack] s1  address: " << (void *)s1 << endl;
    cout << "[stack] i   address: " << (void *)&i << endl;
    cout << "[stack] j   address: " << (void *)&j << endl;
    cout << "[heap ] p   address: " << (void *)p << endl;
    cout << "[data ] s0  address: " << (void *)s0 << endl;
    cout << "[data ] s2  address: " << (void *)s2 << endl;
    cout << "[text ]main address: " << (void *)main << endl;

    return 0;
}