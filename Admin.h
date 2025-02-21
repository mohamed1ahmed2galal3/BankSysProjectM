#ifndef ADMIN_H
#define ADMIN_H
#include"Employee.h"

class Admin : public Employee {
public:
    Admin() {}
    Admin(const string& name, const string& password, double salary)
        : Employee(name, password, salary) {}

    void addEmployee(Employee& employee) {
        employees.push_back(employee);
        cout << "Employee " << employee.getName() << " added successfully.\n";
    }
    Employee* searchEmployee(int id) {
        for (auto& employee : employees) {
            if (employee.getId() == id) {
                return &employee;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
        return nullptr;
    }
    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
            cout << "Employee " << id << " updated successfully.\n";
        } else {
            cout << "Employee not found!" << endl;
        }
    }
    void listEmployee() {
    if (employees.empty()) {
        cout << "No employees available.\n";
        return;
    }
    cout << "========= Employee List =========\n";
    for (const auto& employee : Employees) {
        employee.Display();
        cout<<"-------------------------\n";
    }
}

    /*void saveEmployeesToFile() {
        ofstream file("Employee1.txt", ios::app);
        if (file.is_open()) {
            for (const auto& employee : Employees) {
                file << employee.getId() << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << "\n";
            }
            file.close();
        } else {
            cout << "Error opening Employee1.txt file!" << endl;
        }
    }*/
    void Display() const override {
        cout << "===== Admin =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Password   = " << password << "\n";
        cout << "Salary     = " << salary << "\n";
        cout << "================\n";
    }
};
static vector<Admin> Admins;
static vector<Admin> ::iterator adit;

#endif // ADMIN_H
