#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "Client.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
using namespace std;

class ClientManager {
public:
    static void printClientMenu() {
        cout << "\n========= Client Menu =========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Transfer To Another Client\n";
        cout << "5. Update Password\n";
        cout << "6. Logout\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
    }

    // Generic password update shared by Client/Employee/Admin menus.
    // Persisting to disk is the caller's job, since it depends on which
    // vector (Clients/Employees/Admins) the person belongs to.
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password (8-20 characters): ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated (if valid).\n";
    }

    static Client* login(int id, string password) {
        for (auto& client : Clients) {
            if (client.getId() == id && client.getPassword() == password) {
                return &client;
            }
        }
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        int choice;
        printClientMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            return true;
        }

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposit(amount);
                FileManager::getInstance().updateClients();
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdraw(amount);
                FileManager::getInstance().updateClients();
                break;
            }
            case 3:
                client->checkBalance();
                break;
            case 4: {
                int recipientId;
                double amount;
                cout << "Enter recipient client ID: ";
                cin >> recipientId;
                Client* recipient = nullptr;
                for (auto& c : Clients) {
                    if (c.getId() == recipientId) {
                        recipient = &c;
                        break;
                    }
                }
                if (!recipient) {
                    cout << "Recipient not found!\n";
                    break;
                }
                cout << "Enter amount to transfer: ";
                cin >> amount;
                client->transferTo(amount, *recipient);
                FileManager::getInstance().updateClients();
                break;
            }
            case 5:
                updatePassword(client);
                FileManager::getInstance().updateClients();
                break;
            case 6:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        return true;
    }
};

#endif // CLIENTMANAGER_H
