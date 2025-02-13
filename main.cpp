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


    FilesHelper::saveLast("ClientLastID.txt", 5);
    cout << "Last Client ID: " << FilesHelper::getLast("ClientLastID.txt") << endl;

    FilesHelper::saveLast("EmployeeLastID.txt", 10);
    cout << "Last Employee ID: " << FilesHelper::getLast("EmployeeLastID.txt") << endl;

    FilesHelper::saveLast("AdminLastID.txt", 15);
    cout << "Last Admin ID: " << FilesHelper::getLast("AdminLastID.txt") << endl;


    Client c1(1, "Ali", "pass1234", 2000);
    Employee e1(2, "Omar", "empPass", 6000);
    Admin a1(3, "Sara", "adminPass", 10000);

    FilesHelper::saveClient(c1);
    FilesHelper::saveEmployee(e1);
    FilesHelper::saveAdmin(a1);


    FilesHelper::getClients();
    FilesHelper::getEmployees();
    FilesHelper::getAdmins();


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


    FilesHelper::clearFile("Clients1.txt", "ClientLastID.txt");
    FilesHelper::clearFile("Employee1.txt", "EmployeeLastID.txt");
    FilesHelper::clearFile("Admin1.txt", "AdminLastID.txt");

    cout << "\nAll files cleared.\n";

    return 0;
}
