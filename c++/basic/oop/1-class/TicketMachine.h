// #pragma once

#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H

class TicketMachine {
public:
    TicketMachine();
    TicketMachine(int price, int balance, int total);
    virtual ~TicketMachine();
    void showPrompt();
    void insertMoney(int money);
    void printTicket();
    void showBalance();
    void showTotal();

private:
    int price;
    int balance;
    int total;

protected:

};

#endif /* TICKETMACHINE_H */
