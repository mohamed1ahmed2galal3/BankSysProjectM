#include <iostream>
#include <fstream>
#include "FileHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
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

    FileManager fileManager;
    Admin admin1("Omar", "admin789", 12000.0);
    Employee emp1("Ahmed", "emp456", 7000.0);

    Client client1("Ali", "pass123", 5000.0);
    fileManager.addClient(client1);
    cout << " Client Added!\n";


    fileManager.addEmployee(emp1);
    cout << " Employee Added!\n";

    fileManager.addAdmin(admin1);
    cout << " Admin Added!\n";

    fileManager.getAllData();
    cout << "\n Data Loaded from Files!\n";

    cout << "\n Clients List:\n";
    emp1.listClient();

    cout << "\n Employees List:\n";
    admin1.listEmployee();

    /*fileManager.removeAllClients();
    fileManager.removeAllEmployees();
    fileManager.removeAllAdmins();

    cout << "\nAll files cleared.\n";*/
}
