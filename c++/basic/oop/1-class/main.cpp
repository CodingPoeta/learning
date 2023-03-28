#include "TicketMachine.h"

int main() {
    {
        TicketMachine machine;
        machine.showPrompt();
        machine.insertMoney(20);
        machine.printTicket();
        machine.showBalance();
        machine.showTotal();
    }

    {
        TicketMachine machine2(5, 40, 3);
        machine2.showPrompt();
        machine2.insertMoney(20);
        machine2.printTicket();
        machine2.showBalance();
        machine2.showTotal();
    }

    return 0;
}
