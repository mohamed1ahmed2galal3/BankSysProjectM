#ifndef FILESHELPER_H
#define FILESHELPER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        } else {
            cout << "Error: Unable to open " << fileName << endl;
        }
    }

    static int getLast(string fileName) {
        ifstream file(fileName);
        int lastId = 0;
        if (file.is_open()) {
            file >> lastId;
            file.close();
        } else {
            cout << "Error: Unable to open " << fileName << endl;
        }
        return lastId;
    }

    static void saveClient(const Client& c) {
        int lastId = getLast("ClientLastID.txt");
        Client newClient = c;
        newClient.setId(lastId + 1);

        ofstream file("Clients1.txt", ios::app);
        if (file.is_open()) {
            file << newClient.getId() << "#" << newClient.getName() << "#"
                 << newClient.getPassword() << "#" << newClient.getBalance() << "\n";
            file.close();
            saveLast("ClientLastID.txt", newClient.getId());
        } else {
            cout << "Error: Unable to open Clients1.txt" << endl;
        }
    }

    static void saveEmployee(const Employee& e) {
        int lastId = getLast("EmployeeLastID.txt");
        Employee newEmployee = e;
        newEmployee.setId(lastId + 1);

        ofstream file("Employee1.txt", ios::app);
        if (file.is_open()) {
            file << newEmployee.getId() << "#" << newEmployee.getName() << "#"
                 << newEmployee.getPassword() << "#" << newEmployee.getSalary() << "\n";
            file.close();
            saveLast("EmployeeLastID.txt", newEmployee.getId());
        } else {
            cout << "Error: Unable to open Employee1.txt" << endl;
        }
    }

    static void saveAdmin(const Admin& a) {
        int lastId = getLast("AdminLastID.txt");
        Admin newAdmin = a;
        newAdmin.setId(lastId + 1);

        ofstream file("Admin1.txt", ios::app);
        if (file.is_open()) {
            file << newAdmin.getId() << "#" << newAdmin.getName() << "#"
                 << newAdmin.getPassword() << "#" << newAdmin.getSalary() << "\n";
            file.close();
            saveLast("AdminLastID.txt", newAdmin.getId());
        } else {
            cout << "Error: Unable to open Admin1.txt" << endl;
        }
    }

    // Save a record that already has its final ID (used when rewriting
    // the file from the in-memory vector, e.g. after an edit/deposit).
    static void saveClientKeepId(const Client& c) {
        ofstream file("Clients1.txt", ios::app);
        if (file.is_open()) {
            file << c.getId() << "#" << c.getName() << "#"
                 << c.getPassword() << "#" << c.getBalance() << "\n";
            file.close();
            saveLast("ClientLastID.txt", c.getId());
        } else {
            cout << "Error: Unable to open Clients1.txt" << endl;
        }
    }

    static void saveEmployeeKeepId(const Employee& e) {
        ofstream file("Employee1.txt", ios::app);
        if (file.is_open()) {
            file << e.getId() << "#" << e.getName() << "#"
                 << e.getPassword() << "#" << e.getSalary() << "\n";
            file.close();
            saveLast("EmployeeLastID.txt", e.getId());
        } else {
            cout << "Error: Unable to open Employee1.txt" << endl;
        }
    }

    static void saveAdminKeepId(const Admin& a) {
        ofstream file("Admin1.txt", ios::app);
        if (file.is_open()) {
            file << a.getId() << "#" << a.getName() << "#"
                 << a.getPassword() << "#" << a.getSalary() << "\n";
            file.close();
            saveLast("AdminLastID.txt", a.getId());
        } else {
            cout << "Error: Unable to open Admin1.txt" << endl;
        }
    }

    static void getClients() {
        Clients.clear();
        ifstream file("Clients1.txt");
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                if (!line.empty()) {
                    Clients.push_back(Parser::parseToClient(line));
                }
            }
            file.close();
        } else {
            cout << "Error: Unable to open Clients1.txt" << endl;
        }
    }

    static void getEmployees() {
        Employees.clear();
        ifstream file("Employee1.txt");
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                if (!line.empty()) {
                    Employees.push_back(Parser::parseToEmployee(line));
                }
            }
            file.close();
        } else {
            cout << "Error: Unable to open Employee1.txt" << endl;
        }
    }

    static void getAdmins() {
        Admins.clear();
        ifstream file("Admin1.txt");
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                if (!line.empty()) {
                    Admins.push_back(Parser::parseToAdmin(line));
                }
            }
            file.close();
        } else {
            cout << "Error: Unable to open Admin1.txt" << endl;
        }
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            cout << "Error clearing file: " << fileName << endl;
        }
        saveLast(lastIdFile, 0);
    }
};

#endif // FILESHELPER_H
