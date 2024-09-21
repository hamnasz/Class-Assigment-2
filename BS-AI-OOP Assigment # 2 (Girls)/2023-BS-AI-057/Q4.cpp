// File: assignment no 5 task 4 .cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/* This program derives a new class Employee2 from the base class Employee and introduces additional
   data members and functionalities. Employee2 includes a double type data member for compensation
   and an enumeration type to represent the pay period (hourly, weekly, or monthly). This program also
   showcases how to modify derived classes Manager, Scientist, and Laborer to inherit from Employee2. */

#include <iostream>
#include <string>

using namespace std;

class Compensation {
protected:
    double compensation;
public:
    enum class Period { HOURLY, WEEKLY, MONTHLY };
    Period payPeriod;
};

class Employee {
protected:
    string name;
    long id;
public:
    virtual void getData() {
        cout << "Enter name: ";
        cin>>name;
        cout << "Enter ID: ";
        cin >> id;
    }

    virtual void putData() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee2 : public Employee, public Compensation {
public:
    void getData() override {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char periodInput;
        cout << "Enter pay period (h for Hourly, w for Weekly, m for Monthly): ";
        cin >> periodInput;

        switch (tolower(periodInput)) {
            case 'h':
                payPeriod = Period::HOURLY;
                break;
            case 'w':
                payPeriod = Period::WEEKLY;
                break;
            case 'm':
                payPeriod = Period::MONTHLY;
                break;
            default:
                cout << "Invalid pay period input! Defaulting to Hourly." << endl;
                payPeriod = Period::HOURLY;
        }
    }

    void putData() const override {
        Employee::putData();
        cout << "Compensation: $" << compensation << " per ";
        switch (payPeriod) {
            case Period::HOURLY:
                cout << "hour" << endl;
                break;
            case Period::WEEKLY:
                cout << "week" << endl;
                break;
            case Period::MONTHLY:
                cout << "month" << endl;
                break;
        }
    }
};


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
