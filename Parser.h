#ifndef PARSER_H
#define PARSER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Parser {
public:
    static vector<string> split(const string& line) {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, '#')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(const string& line) {
        vector<string> tokens = split(line);
        if (tokens.size() == 4) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            string password = tokens[2];
            double balance = stod(tokens[3]);

            Client client(name, password, balance);
            client.setId(id);
            return client;
        }
        cout << "Warning: Invalid client data format: " << line << endl;
        return Client();
    }

    static Employee parseToEmployee(const string& line) {
        vector<string> tokens = split(line);
        if (tokens.size() == 4) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            string password = tokens[2];
            double salary = stod(tokens[3]);

            Employee employee(name, password, salary);
            employee.setId(id);
            return employee;
        }
        cout << "Warning: Invalid employee data format: " << line << endl;
        return Employee();
    }

    static Admin parseToAdmin(const string& line) {
        vector<string> tokens = split(line);
        if (tokens.size() == 4) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            string password = tokens[2];
            double salary = stod(tokens[3]);

            Admin admin(name, password, salary);
            admin.setId(id);
            return admin;
        }
        cout << "Warning: Invalid admin data format: " << line << endl;
        return Admin();
    }
};

#endif // PARSER_H
