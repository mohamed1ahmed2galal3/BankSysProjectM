# 🏦 CPP Bank Management System

A console-based Bank Management System built in C++ using file-based storage (no database required). The system supports three types of users — **Clients**, **Employees**, and **Admins** — each with their own login and set of permissions.

## Features

### Client
- Login with ID and password
- Deposit money
- Withdraw money
- Check balance
- Transfer money to another client
- Update password

### Employee
- Login with ID and password
- Add a new client
- Search for a client by ID
- List all clients
- Edit client information
- Display their own info
- Update password

### Admin
- Everything an Employee can do, plus:
- Add a new employee
- Search for an employee by ID
- List all employees
- Edit employee information

### General
- Data is stored and persisted in plain text files (no database needed)
- Simple console animations (typewriter welcome text, loading dots during login/transactions)
- Auto-creates a default Admin account on first run so you always have a way in

## Project Structure

| File | Description |
|---|---|
| `Person.h` | Base class for Client/Employee/Admin (id, name, password) |
| `Validator.h` | Static validation rules (name, password, balance, salary) |
| `Client.h` | Client class (balance, deposit, withdraw, transfer) |
| `Employee.h` | Employee class (salary, client management) |
| `Admin.h` | Admin class (inherits Employee, adds employee management) |
| `DatasourceInterface.h` | Abstract interface for data storage operations |
| `Parser.h` | Parses text file lines into Client/Employee/Admin objects |
| `FileHelper.h` | Low-level read/write helpers for the `.txt` data files |
| `FileManager.h` | Implements `DatasourceInterface` using `FileHelper` (singleton) |
| `ClientManager.h` | Client menu, login, and actions |
| `EmployeeManager.h` | Employee menu, login, and actions |
| `AdminManager.h` | Admin menu, login, and actions |
| `Screens.h` | Welcome screen, main menu, login routing, app loop |
| `Animations.h` | Small console animation helpers (typewriter, loading dots, spinner) |
| `main.cpp` | Entry point — initializes files and starts the app |

## Data Files (auto-created on first run)

- `Clients1.txt`, `Employee1.txt`, `Admin1.txt` — stored records
- `ClientLastID.txt`, `EmployeeLastID.txt`, `AdminLastID.txt` — ID counters

Each record line format: `id#name#password#balance_or_salary`

## How to Build & Run

Requires a C++17-compatible compiler (e.g., g++).

```bash
g++ -std=c++17 -Wall main.cpp -o bankapp
./bankapp
```

On Windows (MinGW):
```bash
g++ -std=c++17 -Wall main.cpp -o bankapp.exe
bankapp.exe
```

## First Run

If no admin account exists yet, the system automatically creates a default one and prints its credentials:

Use these to log in as Admin and start adding real employees and clients.

## Validation Rules

- **Name:** alphabetic characters only, 5–20 characters
- **Password:** 8–20 characters
- **Client balance:** minimum 1500
- **Employee/Admin salary:** minimum 5000

## Notes

- This project is for educational purposes and uses plain text files instead of a real database.
- Passwords are stored in plain text in this version — not intended for production use.
