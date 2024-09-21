// File: Problem 4 (Data of Employee).cpp
// Date: 20-05-2024
// Name: Waleed Amjad
// Registration No: 2023-BS-AI-054

/*Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new 
class should add a type double data item called compensation, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the 
manager, scientist, and laborer classes so they are derived from employee2 instead of employee. However, 
note that in many circumstances it might be more in the spirit of OOP to create a separate base class called 
compensation and three new classes manager2, scientist2, and laborer2, and use multiple inheritance to 
derive these three classes from the original manager, scien st, and laborer classes and from 
compensation. This way none of the original classes needs to be modified   */
#include <iostream>
#include <string>
using namespace std;

// Base class for compensation
class Compensation {
protected:
    double compensation;
public:
    enum Period { HOURLY, WEEKLY, MONTHLY };
    Period period;
};

// Base class for employee
class Employee {
protected:
    string name;
    long id;
public:
    void getData() {
        cout << "Enter name: ";
        cin.ignore(); // To ignore any leftover newline characters in the input buffer
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
    }

    void putData() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

// Derived class from Employee with compensation details
class Employee2 : public Employee, public Compensation {
public:    
    void getData() {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char periodInput;
        cout << "Enter pay period (h for Hourly, w for Weekly, m for Monthly): ";
        cin >> periodInput;
        switch(periodInput) {
            case 'h':
            case 'H':
                period = HOURLY;
                break;
            case 'w':
            case 'W':
                period = WEEKLY;
                break;
            case 'm':
            case 'M':
                period = MONTHLY;
                break;
            default:
                cout << "Invalid pay period input!" << endl;
        }
    }

    void putData() const {
        Employee::putData();
        cout << "Compensation: $" << compensation << " per ";
        switch(period) {
            case HOURLY:
                cout << "hour" << endl;
                break;
            case WEEKLY:
                cout << "week" << endl;
                break;
            case MONTHLY:
                cout << "month" << endl;
                break;
        }
    }
};

// Derived classes from Employee2 for specific job roles
class Manager2 : public Employee2 {};
class Scientist2 : public Employee2 {};
class Laborer2 : public Employee2 {};

int main() {
    Manager2 manager;
    Scientist2 scientist;
    Laborer2 laborer;

    cout << "Enter details for manager:" << endl;
    manager.getData();
    
    cout << "\nEnter details for scientist:" << endl;
    scientist.getData();
    
    cout << "\nEnter details for laborer:" << endl;
    laborer.getData();
    
    cout << "\nManager details:" << endl;
    manager.putData();
    
    cout << "\nScientist details:" << endl;
    scientist.putData();
    
    cout << "\nLaborer details:" << endl;
    laborer.putData();
    
    return 0;
}
