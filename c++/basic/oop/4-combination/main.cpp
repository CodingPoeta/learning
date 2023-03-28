#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age): name(name), age(age) {}
    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Currency {
private:
    int dollars;
    int cents;
public:
    Currency(int dollars, int cents): dollars(dollars), cents(cents) {}
    void print() {
        cout << "Dollars: " << dollars << ", Cents: " << cents << endl;
    }
};

class SavingsAccount {
private:
    Person owner;
    Currency balance;
public:
    SavingsAccount(Person owner, Currency balance): owner(owner), balance(balance) {}
    void print() {
        owner.print();
        balance.print();
    }
};

int main() {
    Person p("John", 20);
    Currency c(100, 50);
    SavingsAccount s(p, c);
    s.print();
    return 0;
}
