#ifndef ADMIN_H
#define ADMIN_H
#include"Employee.h"

class Admin : public Employee {
private:
    vector<Employee> employees;
public:
    Admin() {}
    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary) {}

    void addEmployee(Employee& employee) {
        employees.push_back(employee);
    }
    Employee* searchEmployee(int id) {
        for (auto& employee : employees) {
            if (employee.getId() == id) {
                return &employee;
            }
        }
        return nullptr;
    }
    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
        } else {
            cout << "Employee not found!" << endl;
        }
    }
    void listEmployee() {
    if (employees.empty()) {
        cout << "No employees available.\n";
        return;
    }
    for (const auto& employee : employees) {
        employee.Display();
    }
}

    void saveEmployeesToFile() {
        ofstream file("Employee1.txt", ios::app);
        if (file.is_open()) {
            for (const auto& employee : employees) {
                file << employee.getId() << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << "\n";
            }
            file.close();
        } else {
            cout << "Error opening Employee1.txt file!" << endl;
        }
    }
    void Display() const override {
        cout << "===== Admin =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Password   = " << password << "\n";
        cout << "Salary     = " << salary << "\n";
        cout << "================\n";
    }
};

#endif // ADMIN_H
