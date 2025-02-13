#ifndef PARSER_H
#define PARSER_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <sstream>

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
            return Client(id, name, password, balance);
        }
        return Client();
    }

    static Employee parseToEmployee(const string& line) {
        vector<string> tokens = split(line);
        if (tokens.size() == 4) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            string password = tokens[2];
            double salary = stod(tokens[3]);
            return Employee(id, name, password, salary);
        }
        return Employee();
    }

    static Admin parseToAdmin(const string& line) {
        vector<string> tokens = split(line);
        if (tokens.size() == 4) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            string password = tokens[2];
            double salary = stod(tokens[3]);
            return Admin(id, name, password, salary);
        }
        return Admin();
    }
};

#endif // PARSER_H
