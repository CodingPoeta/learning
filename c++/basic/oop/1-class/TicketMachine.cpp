#include "TicketMachine.h"
#include <iostream>

using namespace std;

TicketMachine::TicketMachine() {
    cout << "TicketMachine constructor called." << endl;
    price = 10;
    balance = 0;
    total = 0;
}

TicketMachine::TicketMachine(int price, int balance, int total) {
    cout << "TicketMachine constructor called. price, balance, total: " << price << balance << total << endl;
    this->price = price;
    this->balance = balance;
    this->total = total;
}

TicketMachine::~TicketMachine() {
    cout << "TicketMachine destructor called." << endl;
}

void TicketMachine::showPrompt() {
    cout << "Welcome to the ticket machine!" << endl;
    cout << "The price of a ticket is " << price << " cents." << endl;
}

void TicketMachine::insertMoney(int amount) {
    balance += amount;
}

void TicketMachine::printTicket() {
    if (balance >= price) {
        cout << "Here is your ticket." << endl;
        balance = balance - price;
        total = total + price;
    } else {
        cout << "You must insert at least " << (price - balance) << " cents." << endl;
    }
}

void TicketMachine::showBalance() {
    cout << "The balance of your account is " << balance << " cents." << endl;
}

void TicketMachine::showTotal() {
    cout << "The total amount of money collected by this machine is " << total << " cents." << endl;
}
