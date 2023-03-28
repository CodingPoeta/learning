#include <iostream>
#include <stdio.h>
using namespace std;

class Base {
public:
	virtual void a() { cout << "Base a()" << endl; }
	virtual void b() { cout << "Base b()" << endl; }
	virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
	virtual void b() { cout << "Derive b()" << endl; }
};

int main()
{
	cout << "-----------Base------------" << endl;
	Base* q = new Base;
	auto tmp1 = (void**)q;
	auto vptr1 = (void**)(*tmp1);
    
    cout << "vptr1: " << vptr1 << endl;
    cout << "main: " << (void*)(main) << endl;

	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr1[i]);
		((void(*) ()) vptr1[i])();
	}

	Derive* p = new Derive;
	auto tmp = (void**)p;
	auto vptr = (void**)(*tmp);
	cout << "---------Derive------------" << endl;
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr[i]);
		((void(*) ()) vptr[i])();
	}
	return 0;
}
