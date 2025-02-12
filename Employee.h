#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"
#include <vector>
#include <fstream>

class Employee : public Person {
protected:
    double salary;
    vector<Client> clients;
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

    void addClient(Client& client) {
        clients.push_back(client);
    }
    Client* searchClient(int id) {
        for (auto& client : clients) {
            if (client.getId() == id) {
                return &client;
            }
        }
        return nullptr;
    }
    void listClient() {
        for (const auto& client : clients) {
            client.Display();
        }
    }
    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
        } else {
            cout << "Client not found!" << endl;
        }
    }
    void saveClientsToFile() {
        ofstream file("Clients1.txt", ios::app);
        if (file.is_open()) {
            for (const auto& client : clients) {
                file << client.getId() << "#" << client.getName() << "#" << client.getPassword() << "#" << client.getBalance() << "\n";
            }
            file.close();
        } else {
            cout << "Error opening Clients1.txt file!" << endl;
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
#endif // EMPLOYEE_H
