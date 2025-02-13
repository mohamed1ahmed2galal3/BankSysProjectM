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


vector<Client> clients;
vector<Employee> employees;
vector<Admin> admins;

class FileHelper {
public:

    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        } else {
            cout << "Error opening file: " << fileName << endl;
        }
    }


    static int getLast(string fileName) {
        ifstream file(fileName);
        int lastId = 0;
        if (file.is_open()) {
            file >> lastId;
            file.close();
        } else {
            cout << "Error opening file: " << fileName << endl;
        }
        return lastId;
    }


    static void saveClient(Client c) {
        ofstream file("Clients1.txt", ios::app);
        if (file.is_open()) {
            file << c.getId() << "#" << c.getName() << "#" << c.getPassword() << "#" << c.getBalance() << "\n";
            file.close();
        } else {
            cout << "Error opening Clients1.txt" << endl;
        }
    }


    static void saveEmployee(Employee e) {
        ofstream file("Employee1.txt", ios::app);
        if (file.is_open()) {
            file << e.getId() << "#" << e.getName() << "#" << e.getPassword() << "#" << e.getSalary() << "\n";
            file.close();
        } else {
            cout << "Error opening Employee1.txt" << endl;
        }
    }


    static void saveAdmin(Admin a) {
        ofstream file("Admin1.txt", ios::app);
        if (file.is_open()) {
            file << a.getId() << "#" << a.getName() << "#" << a.getPassword() << "#" << a.getSalary() << "\n";
            file.close();
        } else {
            cout << "Error opening Admin1.txt" << endl;
        }
    }


    static void getClients() {
        clients.clear();
        ifstream file("Clients1.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                clients.push_back(Parser::parseToClient(line));
            }
            file.close();
        } else {
            cout << "Error opening Clients1.txt" << endl;
        }
    }


    static void getEmployees() {
        employees.clear();
        ifstream file("Employee1.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                employees.push_back(Parser::parseToEmployee(line));
            }
            file.close();
        } else {
            cout << "Error opening Employee1.txt" << endl;
        }
    }


    static void getAdmins() {
        admins.clear();
        ifstream file("Admin1.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                admins.push_back(Parser::parseToAdmin(line));
            }
            file.close();
        } else {
            cout << "Error opening Admin1.txt" << endl;
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
