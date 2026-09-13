#include <iostream>
#include <fstream>
#include "FileHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "Screens.h"
using namespace std;

void createFileIfNotExists(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        ofstream newFile(fileName);
        newFile << "0";
        newFile.close();
    }
}

void createTextFileIfNotExists(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        ofstream newFile(fileName);
        newFile.close();
    }
}

int main() {
    createFileIfNotExists("ClientLastID.txt");
    createFileIfNotExists("EmployeeLastID.txt");
    createFileIfNotExists("AdminLastID.txt");
    createTextFileIfNotExists("Clients1.txt");
    createTextFileIfNotExists("Employee1.txt");
    createTextFileIfNotExists("Admin1.txt");

    Screens::runApp();

    return 0;
}
