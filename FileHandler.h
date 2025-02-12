#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <fstream>
#include<iostream>
using namespace std;
class FileHandler {
public:
static bool saveClientToFile(const Client& client) {
    ofstream file("Clients1.txt", ios::app);
    if (file.is_open()) {
        file << client.getId() << "#" << client.getName() << "#" << client.getPassword() << "#" << client.getBalance() << "\n";
        file.close();
        return true;
    }
    return false;
}

static bool saveEmployeeToFile(const Employee& employee) {
    ofstream file("Employee1.txt", ios::app);
    if (file.is_open()) {
        file << employee.getId() << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << "\n";
        file.close();
        return true;
    }
    return false;
}

static bool saveAdminToFile(const Admin& admin) {
    ofstream file("Admin1.txt", ios::app);
    if (file.is_open()) {
        file << admin.getId() << "#" << admin.getName() << "#" << admin.getPassword() << "#" << admin.getSalary() << "\n";
        file.close();
        return true;
    }
    return false;
}
};

#endif // FILEHANDLER_H
