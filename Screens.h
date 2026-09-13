#ifndef SCREENS_H
#define SCREENS_H

#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
using namespace std;

class Screens {
public:
    static void bankName() {
        cout << R"(
   ____ ____  ____   _   _ ____    ____   _    _   _ _  __
  / ___|  _ \|  _ \ | | | / ___|  | __ ) / \  | \ | | |/ /
 | |   | |_) | |_) || | | \___ \  |  _ \/ _ \ |  \| | ' /
 | |___|  __/|  __/ | |_| |___) | | |_) / ___ \| |\  | . \
  \____|_|   |_|     \___/|____/  |____/_/   \_\_| \_|_|\_\
)" << endl;
    }

    static void welcome() {
        cout << "=======================================================\n";
        cout << "          Welcome to CPP Bank Management System        \n";
        cout << "     Your trust, our priority - Banking made simple    \n";
        cout << "=======================================================\n\n";
    }

    static void loginOptions() {
        cout << "\n--------------- Main Menu ---------------\n";
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter your choice: ";
    }

    static int loginAs() {
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
        return choice;
    }

    static void invalid(int c) {
        cout << "\nInvalid option: " << c << ". Please choose a valid option.\n";
    }

    static void logout() {
        cout << "\nYou have been logged out. See you soon!\n";
    }

    static void loginScreen(int c) {
        int id;
        string password;

        switch (c) {
            case 1: {
                cout << "\n----- Client Login -----\n";
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Password: ";
                cin >> password;
                Client* client = ClientManager::login(id, password);
                if (client) {
                    cout << "\nLogin successful! Welcome, " << client->getName() << "!\n";
                    while (ClientManager::clientOptions(client)) {}
                    logout();
                } else {
                    cout << "Invalid ID or password!\n";
                }
                break;
            }
            case 2: {
                cout << "\n----- Employee Login -----\n";
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Password: ";
                cin >> password;
                Employee* employee = EmployeeManager::login(id, password);
                if (employee) {
                    cout << "\nLogin successful! Welcome, " << employee->getName() << "!\n";
                    while (EmployeeManager::employeeOptions(employee)) {}
                    logout();
                } else {
                    cout << "Invalid ID or password!\n";
                }
                break;
            }
            case 3: {
                cout << "\n----- Admin Login -----\n";
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Password: ";
                cin >> password;
                Admin* admin = AdminManager::login(id, password);
                if (admin) {
                    cout << "\nLogin successful! Welcome, " << admin->getName() << "!\n";
                    while (AdminManager::adminOptions(admin)) {}
                    logout();
                } else {
                    cout << "Invalid ID or password!\n";
                }
                break;
            }
            default:
                invalid(c);
        }
    }

    // Ensures the app is usable on a completely empty first run by
    // creating a default admin account (id printed for the user).
    static void bootstrapDefaultAdminIfNeeded() {
        if (Admins.empty()) {
            Admin defaultAdmin("SuperAdmin", "admin1234", 20000);
            FileManager::getInstance().addAdmin(defaultAdmin);
            FileManager::getInstance().getAllAdmins();
            cout << "No admin accounts found. A default admin was created:\n";
            cout << "  ID: " << Admins.back().getId() << "   Password: admin1234\n";
            cout << "Please log in and create real employees/admins as needed.\n\n";
        }
    }

    static void runApp() {
        bankName();
        welcome();

        FileManager::getInstance().getAllClients();
        FileManager::getInstance().getAllEmployees();
        FileManager::getInstance().getAllAdmins();

        bootstrapDefaultAdminIfNeeded();

        bool running = true;
        while (running) {
            loginOptions();
            int choice = loginAs();
            if (choice == 4) {
                cout << "\nThank you for using CPP Bank. Goodbye!\n";
                running = false;
            } else if (choice >= 1 && choice <= 3) {
                loginScreen(choice);
            } else {
                invalid(choice);
            }
        }
    }
};

#endif // SCREENS_H
