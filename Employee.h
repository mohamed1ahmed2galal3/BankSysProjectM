#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"
#include <vector>
#include <fstream>

class Employee : public Person {
protected:
    double salary;

public:
    Employee() : Person(), salary(5000.0) { id = -1; }
    Employee(const string& name, const string& password, double salary)
        : Person(name, password) {
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

    void addClient(Client& client) {
        Clients.push_back(client);
        cout << "Client " << client.getName() << " added successfully.\n";
    }

    Client* searchClient(int id) {
        for (auto& client : Clients) {
            if (client.getId() == id) {
                return &client;
            }
        }
        return nullptr;
    }

    void listClient() {
        if (Clients.empty()) {
            cout << "No clients available.\n";
            return;
        }
        cout << "========= Client List =========\n";
        for (const auto& client : Clients) {
            client.Display();
            cout << "-------------------------\n";
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client " << id << " updated successfully.\n";
        } else {
            cout << "Client not found!" << endl;
        }
    }

    void Display() const override {
        cout << "===== Employee =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Password   = " << password << "\n";
        cout << "Salary     = " << salary << "\n";
        cout << "===================\n";
    }
};

static vector<Employee> Employees;
static vector<Employee> ::iterator emit;
#endif // EMPLOYEE_H
