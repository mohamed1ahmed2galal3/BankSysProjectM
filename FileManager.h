#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DatasourceInterface.h"
#include "FileHelper.h"

class FileManager : public DatasourceInterface {
public:
    void addClient(Client client) override {
        int newId = FileHelper::getLast("ClientLastID.txt") + 1;
        client.setId(newId);
        FileHelper::saveClient(client);
        FileHelper::saveLast("ClientLastID.txt", newId);
    }

    void addEmployee(Employee employee) override {
        int newId = FileHelper::getLast("EmployeeLastID.txt") + 1;
        employee.setId(newId);
        FileHelper::saveEmployee(employee);
        FileHelper::saveLast("EmployeeLastID.txt", newId);
    }

    void addAdmin(Admin admin) override {
        int newId = FileHelper::getLast("AdminLastID.txt") + 1;
        admin.setId(newId);
        FileHelper::saveAdmin(admin);
        FileHelper::saveLast("AdminLastID.txt", newId);
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

    static void getAllData()
    {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }
    static void updateClients() {
        removeAllClients();
        for (auto& client : Clients) {
            addClient(client);
        }
    }

    static void updateEmployees() {
        removeAllEmployees();
        for (auto& employee : Employees) {
            addEmployee(employee);
        }
    }

    static void updateAdmins() {
        removeAllAdmins();
        for (auto& admin : Admins) {
            addAdmin(admin);
        }
    }
};

#endif // FILEMANAGER_H
