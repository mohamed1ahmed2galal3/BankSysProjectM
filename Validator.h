#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Validator {
public:
    static bool isAlphaString(const string& str) {
        for (char c : str) {
            if (!isalpha(static_cast<unsigned char>(c))) {
                return false;
            }
        }
        return true;
    }

    static bool isValidLength(const string& str) {
        return str.length() >= 5 && str.length() <= 20;
    }
    static bool isValidPassword(const string& str) {
        return str.length() >= 8 && str.length() <= 20;
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000;
    }
};
#endif // VALIDATOR_H
