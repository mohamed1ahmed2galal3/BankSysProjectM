#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DatasourceInterface.h"
#include "FileHelper.h"

class FileManager : public DatasourceInterface {
private:
    FileManager() {}

public:
    // Singleton accessor: the interface methods are virtual overrides,
    // so they must be called through an instance (not as static methods).
    static FileManager& getInstance() {
        static FileManager instance;
        return instance;
    }

    void addClient(Client client) override {
        int newId = FileHelper::getLast("ClientLastID.txt") + 1;
        client.setId(newId);
        FileHelper::saveClient(client);
    }

    void addEmployee(Employee employee) override {
        int newId = FileHelper::getLast("EmployeeLastID.txt") + 1;
        employee.setId(newId);
        FileHelper::saveEmployee(employee);
    }

    void addAdmin(Admin admin) override {
        int newId = FileHelper::getLast("AdminLastID.txt") + 1;
        admin.setId(newId);
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

    // Loads clients/employees/admins from files and prints them all.
    void getAllData() {
        getAllClients();
        getAllEmployees();
        getAllAdmins();

        cout << "\n--- Clients ---\n";
        if (Clients.empty()) cout << "No clients available.\n";
        for (const auto& c : Clients) { c.Display(); }

        cout << "\n--- Employees ---\n";
        if (Employees.empty()) cout << "No employees available.\n";
        for (const auto& e : Employees) { e.Display(); }

        cout << "\n--- Admins ---\n";
        if (Admins.empty()) cout << "No admins available.\n";
        for (const auto& a : Admins) { a.Display(); }
    }

    // Rewrites the on-disk file so it matches the current in-memory vector.
    // Use after editing/depositing/withdrawing so changes persist.
    void updateClients() {
        removeAllClients();
        for (auto& client : Clients) {
            FileHelper::saveClientKeepId(client);
        }
    }

    void updateEmployees() {
        removeAllEmployees();
        for (auto& employee : Employees) {
            FileHelper::saveEmployeeKeepId(employee);
        }
    }

    void updateAdmins() {
        removeAllAdmins();
        for (auto& admin : Admins) {
            FileHelper::saveAdminKeepId(admin);
        }
    }
};

#endif // FILEMANAGER_H
