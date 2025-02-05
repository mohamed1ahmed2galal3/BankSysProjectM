#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee {
public:
    Admin() {}
    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary) {}

    void Display() const override {
        cout << "===== Admin =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Salary     = " << salary << "\n";
        cout << "================\n";
    }
};

#endif // ADMIN_H
