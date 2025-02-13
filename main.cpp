#include <iostream>
#include <fstream>
#include "FileHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

void createFileIfNotExists(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        ofstream newFile(fileName);
        newFile << "0";
        newFile.close();
        cout << "File created: " << fileName << " with initial value 0.\n";
    }
}

int main() {

    createFileIfNotExists("ClientLastID.txt");
    createFileIfNotExists("EmployeeLastID.txt");
    createFileIfNotExists("AdminLastID.txt");


    FileHelper::saveLast("ClientLastID.txt", 5);
    cout << "Last Client ID: " << FileHelper::getLast("ClientLastID.txt") << endl;

    FileHelper::saveLast("EmployeeLastID.txt", 10);
    cout << "Last Employee ID: " << FileHelper::getLast("EmployeeLastID.txt") << endl;

    FileHelper::saveLast("AdminLastID.txt", 15);
    cout << "Last Admin ID: " << FileHelper::getLast("AdminLastID.txt") << endl;


    Client c1(1, "Alimohamed", "pass123456", 2000);
    Employee e1(2, "Omarahmed", "empPass123", 6000);
    Admin a1(3, "Saramohamed", "adminPass123", 10000);

    FileHelper::saveClient(c1);
    FileHelper::saveEmployee(e1);
    FileHelper::saveAdmin(a1);


    FileHelper::getClients();
    FileHelper::getEmployees();
    FileHelper::getAdmins();


    cout << "\nStored Clients:\n";
    for (const auto& client : FileHelper::clients) {
        client.Display();
    }

    cout << "\nStored Employees:\n";
    for (const auto& employee : FileHelper::employees) {
        employee.Display();
    }

    cout << "\nStored Admins:\n";
    for (const auto& admin : FileHelper::admins) {
        admin.Display();
    }


    FileHelper::clearFile("Clients1.txt", "ClientLastID.txt");
    FileHelper::clearFile("Employee1.txt", "EmployeeLastID.txt");
    FileHelper::clearFile("Admin1.txt", "AdminLastID.txt");

    cout << "\nAll files cleared.\n";

    return 0;
}
