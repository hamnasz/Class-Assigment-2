//DATE:21-5-24
//NAME:AYESHA IMRAN
// REGISTRATION NO:2023-BS-AI-061
//QUESTION STATEMENT
//Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new
//class should add a type double data item called compensaOon, and also an enum type called period to
//indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the
//manager, scienOst, and laborer classes so they are derived from employee2 instead of employee. However,
//note that in many circumstances it might be more in the spirit of OOP to create a separate base class called
//compensaOon and three new classes manager2, scienOst2, and laborer2, and use mulOple inheritance to
//derive these three classes from the original manager, scienOst, and laborer classes and from
//compensaOon. This way none of the original classes needs to be modified

#include <iostream>
#include <string>

using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    string address;
    int age;

public:
    // Constructor
    Employee() {}

    // Destructor
    virtual ~Employee() {}

    // Get data from user
    virtual void getData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter age: ";
        cin >> age;
    }

    // Display data
    virtual void putData() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
    }
};

// Enum for period
enum Period { HOURLY, WEEKLY, MONTHLY };

// Derived class Employee2
class Employee2 : public Employee {
protected:
    double compensation;
    Period period;

public:
    // Constructor
    Employee2() {}

    // Destructor
    ~Employee2() {}

    // Get data from user
    void getData() {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        int p;
        cout << "Enter period (1 for hourly, 2 for weekly, 3 for monthly): ";
        cin >> p;
        switch (p) {
            case 1:
                period = HOURLY;
                break;
            case 2:
                period = WEEKLY;
                break;
            case 3:
                period = MONTHLY;
                break;
            default:
                cout << "Invalid period!" << endl;
        }
    }

    // Display data
    void putData() {
        Employee::putData();
        cout << "Compensation: " << compensation << endl;
        cout << "Period: ";
        switch (period) {
            case HOURLY:
                cout << "Hourly" << endl;
                break;
            case WEEKLY:
                cout << "Weekly" << endl;
                break;
            case MONTHLY:
                cout << "Monthly" << endl;
                break;
        }
    }
};

// Derived classes Manager, Scientist, and Laborer
class Manager : public Employee2 {
    // ...
};

class Scientist : public Employee2 {
    // ...
};

class Laborer : public Employee2 {
    // ...
};

int main() {
    Manager manager;
    Scientist scientist;
    Laborer laborer;

    // ...

    return 0;
}