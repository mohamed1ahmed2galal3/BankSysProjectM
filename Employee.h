#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    double salary;

public:
    Employee() : Person(), salary(0.0) {}

    Employee(int id, const string& name, const string& password, double salary)
        : Person(id, name, password) {
        setSalary(salary);
    }

    void setSalary(double salary) {
        if (Validator::isValidSalary(salary)) {
            this->salary = salary;
        } else {
            cout << "Invalid Salary! Minimum is 5000.\n";
        }
    }

    double getSalary() const { return salary; }

    void Display() const override {
        cout << "===== Employee =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Salary     = " << salary << "\n";
        cout << "===================\n";
    }
};

#endif // EMPLOYEE_H
