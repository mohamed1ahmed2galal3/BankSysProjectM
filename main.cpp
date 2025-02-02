#include<iostream>
#include <cctype>
#include<string>

using namespace std ;

class Validator
{
public :
    static bool isAlphaString(string & str)
    {
        for(auto c : str)
        {
            if(!isalpha(static_cast<unsigned char>(c)))
            {
                return false;
            }
        }
        return true;
    }
   static bool isValidLength(string& str) {
    return str.length() >= 5 && str.length() <= 20;
   }
   static bool isValidbalance(double& balance)
   {
       if(balance >=1500)
        {
            return true ;
        }
        else{
            return false;
        }
   }
   static bool isValidSalay(double& salary)
   {
       if(salary >= 5000)
       {
           return true;
       }
       else{
           return false;
       }
   }
};
class Person{
protected:
    int id;
    string name;
    string password;
public:
    //Def Con
    Person()
    {
        this->id = 0;
    }
    //Para Con
    Person(int id,string name , string password)
    {
        this->id = 0;
        if(Validator::isAlphaString(name) &&Validator::isValidLength(name))
        {
            this->name = name;
        }
        else{
            cout<<"Invalid Name\n";
        }
        if(Validator::isValidLength(password))
        {
            this->password=password;
        }
        else{
            cout<<"Invalid Password\n";
        }
    }
    //Setter
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        if(Validator::isAlphaString(name) &&Validator::isValidLength(name))
        {
            this->name = name;
        }
        else{
            cout<<"Invalid Name\n";
        }
    }
    void setPassword(string password)
    {
        if(Validator::isValidLength(password))
        {
            this->password=password;
        }
        else{
            cout<<"Invalid Password\n";
        }
    }
    //Getter
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getPassword()
    {
        return this->password;
    }
    //Methods
    virtual void Display() = 0; //Pure Virtual Method To Force Child Class To Override On Display Method
};

class Client : public Person {
private:
    double balance;

public:
    //Def Con
    Client():Person()
    {
        this->balance = 0.0;
    }
    //Para Con
    Client(int id, string name, string password, double balance) : Person(id, name, password) {
        this->balance=balance;
    }
    //Setters
    void setBalance(double balance) {
        if (Validator::isValidbalance(balance))
            this->balance = balance;
        else
            cout << "Invalid balance! Minimum is 1500.\n";
    }
    //Getters
    double getBalance() {
         return balance;
    }
    //Methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << this->balance << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }

    void transferTo(double amount, Client &recipient) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Transferred: " << amount << " to " << recipient.getName() << ". Your New Balance: " << balance << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance!\n";
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << this->balance << endl;
    }

    void Display() {
        cout << "Client - ";
        cout<<"ID         ="<<this->id<<endl;
        cout<<"Name       ="<<this->id<<endl;
        cout<<"Password   ="<<this->id<<endl;
        cout <<"Balance   ="<<this->balance << endl;
    }
};

int main(){
    Client c1(1,"Mohamed","Mohamed123",20000);
    c1.Display();
    c1.deposit(500);
    c1.Display();
    c1.withdraw(1000);
    c1.Display();
    Client c2(2,"ahmed","Ahmed246",1500);
    c1.transferTo(9500,c2);
    c1.Display();
    c2.Display();
}
