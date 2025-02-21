#ifndef PERSON_H
#define PERSON_H

#include "Validator.h"
#include <iostream>
using namespace std;
class Person {
protected:
    int id;
    string name;
    string password;
public:
    Person() : id(0), name(""), password("") {}
    Person(const string& name, const string& password) {
        setName(name);
        setPassword(password);
    }
    void setId(int id) { this->id = id; }
    void setName(const string& name) {
        if (Validator::isAlphaString(name) && Validator::isValidLength(name)) {
            this->name = name;
        }
        else {
            cout << "Invalid Name\n";
        }
    }
    void setPassword(const string& password) {
        if (Validator::isValidPassword(password)) {
            this->password = password;
        }
        else {
            cout << "Invalid Password\n";
        }
    }
    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }
    virtual void Display() const = 0;
};

#endif // PERSON_H
