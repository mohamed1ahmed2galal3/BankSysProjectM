#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client client) override {
        FileHelper::saveClient(client);
    }

    void addEmployee(Employee employee) override {
        FileHelper::saveEmployee(employee);
    }

    void addAdmin(Admin admin) override {
        FileHelper::saveAdmin(admin);
    }

    void getAllClients() override {
        FileHelper::getClients();
    }

    void getAllEmployees() override {
        FileHelper::getEmployees();
    }

    void getAllAdmins() override {
        FileHelper::getAdmins();
    }

    void removeAllClients() override {
        FileHelper::clearFile("Clients1.txt", "ClientLastID.txt");
    }

    void removeAllEmployees() override {
        FileHelper::clearFile("Employee1.txt", "EmployeeLastID.txt");
    }

    void removeAllAdmins() override {
        FileHelper::clearFile("Admin1.txt", "AdminLastID.txt");
    }
};

#endif // FILEMANAGER_H
