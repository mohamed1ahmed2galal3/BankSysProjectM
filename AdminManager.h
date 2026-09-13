#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include "Admin.h"
#include "Employee.h"
#include "FileManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include <iostream>
#include <limits>
using namespace std;

class AdminManager {
public:
    static void printAdminMenu() {
        cout << "\n========= Admin Menu =========\n";
        cout << "1. Add New Employee\n";
        cout << "2. List All Employees\n";
        cout << "3. Search For Employee\n";
        cout << "4. Edit Employee Info\n";
        cout << "5. Add New Client\n";
        cout << "6. List All Clients\n";
        cout << "7. Search For Client\n";
        cout << "8. Edit Client Info\n";
        cout << "9. Display My Info\n";
        cout << "10. Update Password\n";
        cout << "11. Logout\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
    }

    static void newEmployee(Admin* admin) {
        string name, password;
        double salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter employee name (alphabetic, 5-20 chars): ";
        getline(cin, name);
        cout << "Enter employee password (8-20 chars): ";
        getline(cin, password);
        cout << "Enter salary (min 5000): ";
        cin >> salary;

        Employee newEmployee(name, password, salary);
        if (newEmployee.getName().empty() || newEmployee.getPassword().empty()) {
            cout << "Employee not created due to invalid data.\n";
            return;
        }
        int newId = FileHelper::getLast("EmployeeLastID.txt") + 1;
        newEmployee.setId(newId);
        admin->addEmployee(newEmployee);
        FileHelper::saveLast("EmployeeLastID.txt", newId);
        FileManager::getInstance().updateEmployees();
    }

    static Admin* login(int id, string password) {
        for (auto& admin : Admins) {
            if (admin.getId() == id && admin.getPassword() == password) {
                return &admin;
            }
        }
        return nullptr;
    }

    static bool adminOptions(Admin* admin) {
        int choice;
        printAdminMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            return true;
        }

        switch (choice) {
            case 1:
                newEmployee(admin);
                break;
            case 2:
                admin->listEmployee();
                break;
            case 3: {
                int id;
                cout << "Enter employee ID to search: ";
                cin >> id;
                Employee* emp = admin->searchEmployee(id);
                if (emp) emp->Display();
                else cout << "Employee not found!\n";
                break;
            }
            case 4: {
                int id;
                string name, password;
                double salary;
                cout << "Enter employee ID to edit: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new password: ";
                getline(cin, password);
                cout << "Enter new salary: ";
                cin >> salary;
                admin->editEmployee(id, name, password, salary);
                FileManager::getInstance().updateEmployees();
                break;
            }
            case 5:
                EmployeeManager::newClient(admin);
                break;
            case 6:
                admin->listClient();
                break;
            case 7:
                EmployeeManager::searchForClient(admin);
                break;
            case 8:
                EmployeeManager::editClientInfo(admin);
                break;
            case 9:
                admin->Display();
                break;
            case 10:
                ClientManager::updatePassword(admin);
                FileManager::getInstance().updateAdmins();
                break;
            case 11:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        return true;
    }
};

#endif // ADMINMANAGER_H
