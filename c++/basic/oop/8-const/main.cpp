#include <iostream>
using namespace std;

const int bufSize = 512;
// compiler won't let you change the value of exConst
extern const int exConst;

class Date {
private:
    int month;
    int day;
public:
    Date(int m, int d): month(m), day(d) {}
    // const member function
    // can't change the value of any data member
    // this pointer is const pointer
    int getMonth() const {
            // month = 1; // error: assignment of member 'Date::month' in read-only object
            cout << "Date::getMonth(const Date* this)" << endl;
            return month; 
        }
    int getDay() const { cout << "Date::getDay(const Date* this)" << endl; return day; }
    int getDay() { cout << "Date::getDay(Date* this)" << endl; return day; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
};

int main() {
    const int i = 0;
    // i = 1; // error: assignment of read-only variable 'i'
    int j = 0;
    const int *p = &i; // pointer to const int
    // *p = 1; // error: assignment of read-only location '* p'
    p = &j; // ok
    int * const p2 = &j; // const pointer to int
    *p2 = 1; // ok
    // p2 = &i; // error: assignment of read-only variable 'p2'
    const int * const p3 = &i; // const pointer to const int
    // *p3 = 1; // error: assignment of read-only location '* p3'
    // p3 = &j; // error: assignment of read-only variable 'p3'

    // const object
    const Date d(1, 1);
    // d.setMonth(2); // error: assignment of member 'Date::month' in read-only object
    cout << d.getDay() << endl;

    Date d2(1, 1);
    cout << d2.getDay() << endl;
    cout << d2.getMonth() << endl;
    
    return 0;
}
