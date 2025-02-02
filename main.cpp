#include <iostream>
#include <cctype>
#include <string>

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

    static bool isValidbalance(double balance) {
        return balance >= 1500;
    }

    static bool isValidSalay(double salary) {
        return salary >= 5000;
    }
};

class Person {
protected:
    int id;
    string name;
    string password;

public:
    // Default Constructor
    Person(){
    this->id = 0;
    }

    // Parameterized Constructor
    Person(int id, string name, string password) {
        this->id = id; // Correctly assign ID
        if (Validator::isAlphaString(name) && Validator::isValidLength(name)) {
            this->name = name;
        } else {
            cout << "Invalid Name\n";
        }
        if (Validator::isValidLength(password)) {
            this->password = password;
        } else {
            cout << "Invalid Password\n";
        }
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(const string& name) {
        if (Validator::isAlphaString(name) && Validator::isValidLength(name)) {
            this->name = name;
        } else {
            cout << "Invalid Name\n";
        }
    }

    void setPassword(const string& password) {
        if (Validator::isValidLength(password)) {
            this->password = password;
        } else {
            cout << "Invalid Password\n";
        }
    }

    // Getters
    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    string getPassword(){
        return password;
    }

    // Abstract Method
    virtual void Display() = 0;
};

class Client : public Person {
private:
    double balance;

public:
    // Default Constructor
    Client() : Person(){
       this->balance = 0.0;
    }

    // Parameterized Constructor
    Client(int id, string name, string password, double balance) : Person(id, name, password) {
        if (Validator::isValidbalance(balance))
            this->balance = balance;
        else
            cout << "Invalid balance! Minimum is 1500.\n";
    }

    // Setter
    void setBalance(double balance) {
        if (Validator::isValidbalance(balance))
            this->balance = balance;
        else
            cout << "Invalid balance! Minimum is 1500.\n";
    }

    // Getter
    double getBalance()  {
        return balance;
    }

    // Methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
            cout<<"================================\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
            cout<<"================================\n";
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }

    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Transferred: " << amount << " to " << recipient.getName() << ". Your New Balance: " << balance << endl;
            cout<<"================================\n";
        } else {
            cout << "Invalid transfer amount or insufficient balance!\n";
        }
    }

    void checkBalance()  {
        cout << "Current Balance: " << balance << endl;
    }

    void Display()  {
        cout << "=====Client=====  " << endl;
        cout << "ID         = " << id << endl;
        cout << "Name       = " << name << endl;
        cout << "Password   = " << password << endl;
        cout << "Balance    = " << balance << endl;
        cout<<"\n================================\n";
    }
};
class Employee : public Person{
protected:
    double salary;
public:
    //Def Con
    Employee() : Person()
    {
        this->salary =0.0;
    }
    //Para Con
    Employee(int id, string name, string password, double salary) : Person(id, name, password)
    {
        if(Validator::isValidSalay(salary))
        {
            this->salary = salary;
        }
        else{
            cout<<"Invalid Salary! Minimum is 5000.\n";
        }
    }
    //Setters
    void setSalary(double salary)
    {
        if(Validator::isValidSalay(salary))
        {
            this->salary = salary;
        }
        else{
            cout<<"Invalid Salary! Minimum is 5000.\n";
        }
    }
    //Getters
    double getSalary()
    {
        return this->salary;
    }
    //Methods
    void Display()
    {
        cout << "=====Employee=====  " << endl;
        cout << "ID         = " << id << endl;
        cout << "Name       = " << name << endl;
        cout << "Password   = " << password << endl;
        cout << "Salary     = " << salary << endl;
        cout<<"\n================================\n";
    }
};
class Admin : public Employee{

public:
    //Def Con
    Admin(){}
    //Para Con
    Admin(int id, string name, string password, double salary) : Employee(id,name,password,salary){}
    void Display()
    {
        cout << "=====Admin=====  " << endl;
        cout << "ID         = " << id << endl;
        cout << "Name       = " << name << endl;
        cout << "Password   = " << password << endl;
        cout << "Salary     = " << salary << endl;
        cout<<"\n================================\n";
    }

};


int main() {
    Client c1(1, "Mohamed", "Mohamed123", 20000);
    c1.Display();
    c1.deposit(500);
    c1.Display();
    c1.withdraw(1000);
    c1.Display();

    Client c2(2, "Ahmed", "Ahmed246", 1500);
    c1.transferTo(9500, c2);

    c1.Display();
    c2.Display();

    Employee e1(1,"Mahmoud","Mahmoud135",6000);
    e1.Display();

    Admin a1(1,"Mohamed","Mohamed012",10000);
    a1.Display();
    return 0;
}

