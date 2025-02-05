#include <iostream>
#include <string>
using namespace std;

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

int main() {
    Client c1(1, "Mohamed", "mohamed12", 20000);
    c1.Display();
    c1.deposit(500);
    c1.withdraw(1000);

    Client c2(2, "Ahmed", "Ahmed246", 1500);
    c1.transferTo(9500, c2);
    c1.Display();
    c2.Display();

    Employee e1(3, "Mahmoud", "Mahmoud135", 6000);
    e1.Display();

    Admin a1(4, "Mohamed", "Mohamed012", 10000);
    a1.Display();
    return 0;
}


