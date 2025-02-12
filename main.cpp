#include <iostream>
#include <string>
#include"FileHandler.h"
using namespace std;

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

int main() {
 Client c1  (1, "Alimohamed" , "pass12345", 2000);
 Employee e1(2, "OmarAhmed"  , "empPass1234", 6000);
 Admin a1   (3, "SaraMohamed", "admin123", 8000);

 if (FileHandler::saveClientToFile(c1)) {
     cout << "Client saved successfully.\n";
 }
 else {
     cout << "Failed to save client.\n";
 }

 if (FileHandler::saveEmployeeToFile(e1)) {
     cout << "Employee saved successfully.\n";
 }
 else {
     cout << "Failed to save employee.\n";
 }

 if (FileHandler::saveAdminToFile(a1)) {
     cout << "Admin saved successfully.\n";
 }
 else {
     cout << "Failed to save admin.\n";
 }

 return 0;
}


