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


