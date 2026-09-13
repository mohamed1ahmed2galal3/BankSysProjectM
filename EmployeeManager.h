#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include "Client.h"
#include "FileManager.h"
#include "ClientManager.h"
#include <iostream>
#include <limits>
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout << "\n========= Employee Menu =========\n";
        cout << "1. Add New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search For Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Display My Info\n";
        cout << "6. Update Password\n";
        cout << "7. Logout\n";
        cout << "==================================\n";
        cout << "Enter your choice: ";
    }

    static void newClient(Employee* employee) {
        string name, password;
        double balance;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter client name (alphabetic, 5-20 chars): ";
        getline(cin, name);
        cout << "Enter client password (8-20 chars): ";
        getline(cin, password);
        cout << "Enter initial balance (min 1500): ";
        cin >> balance;

        Client newClient(name, password, balance);
        if (newClient.getName().empty() || newClient.getPassword().empty()) {
            cout << "Client not created due to invalid data.\n";
            return;
        }
        int newId = FileHelper::getLast("ClientLastID.txt") + 1;
        newClient.setId(newId);
        employee->addClient(newClient);
        FileHelper::saveLast("ClientLastID.txt", newId);
        FileManager::getInstance().updateClients();
    }

    static void listAllClients(Employee* employee) {
        employee->listClient();
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client) {
            client->Display();
        } else {
            cout << "Client not found!\n";
        }
    }

    static void editClientInfo(Employee* employee) {
        int id;
        string name, password;
        double balance;
        cout << "Enter client ID to edit: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new name: ";
        getline(cin, name);
        cout << "Enter new password: ";
        getline(cin, password);
        cout << "Enter new balance: ";
        cin >> balance;

        employee->editClient(id, name, password, balance);
        FileManager::getInstance().updateClients();
    }

    static Employee* login(int id, string password) {
        for (auto& employee : Employees) {
            if (employee.getId() == id && employee.getPassword() == password) {
                return &employee;
            }
        }
        return nullptr;
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        printEmployeeMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            return true;
        }

        switch (choice) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                employee->Display();
                break;
            case 6:
                ClientManager::updatePassword(employee);
                FileManager::getInstance().updateEmployees();
                break;
            case 7:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        return true;
    }
};

#endif // EMPLOYEEMANAGER_H
