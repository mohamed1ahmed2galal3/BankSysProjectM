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
    Employee() : Person(), salary(0.0) {}
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
        cout << "Client with ID " << id << " not found.\n";
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
        cout<<"-------------------------\n";
    }
}

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client " << id << " updated successfully.\n";
            cout << "Client " << id << " updated successfully.\n";
        } else {
            cout << "Client not found!" << endl;
        }
    }
    /*void saveClientsToFile() {
        ofstream file("Clients1.txt", ios::app);
        if (file.is_open()) {
            for (const auto& client : Clients) {
                file << client.getId() << "#" << client.getName() << "#" << client.getPassword() << "#" << client.getBalance() << "\n";
            }
            file.close();
        } else {
            cout << "Error opening Clients1.txt file!" << endl;
        }
    }*/
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
