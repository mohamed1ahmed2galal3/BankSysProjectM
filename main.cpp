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
