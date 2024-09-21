// muammad zain 052

#include <iostream>
using namespace std;

enum Period { HOURLY, WEEKLY, MONTHLY };

class Employee {
protected:
    string name;
    int id;
    static int nextId;
public:
    Employee() : name(""), id(nextId++) {}
    Employee(string n) : name(n), id(nextId++) {}
    string getName() { return name; }
    int getId() { return id; }
};

int Employee::nextId = 1;

class Employee2 : public Employee {
protected:
    double compensation;
    Period period;
public:
    void getData() {
        cout << "Enter compensation: ";
        cin >> compensation;
        cout << "Enter period (0 for HOURLY, 1 for WEEKLY, 2 for MONTHLY): ";
        int p;
        cin >> p;
        switch (p) {
            case 0:
                period = HOURLY;
                break;
            case 1:
                period = WEEKLY;
                break;
            case 2:
                period = MONTHLY;
                break;
            default:
                cout << "Invalid period!" << endl;
        }
    }
    void putData() {
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Compensation: " << compensation << endl;
        cout << "Period: " << (period == HOURLY ? "HOURLY" : period == WEEKLY ? "WEEKLY" : "MONTHLY") << endl;
    }
};

class Manager : public Employee2 {
public:
    void getData() {
        Employee2::getData();
        // Add manager-specific data
    }
    void putData() {
        Employee2::putData();
        // Add manager-specific data
    }
};

class Scientist : public Employee2 {
public:
    void getData() {
        Employee2::getData();
        // Add scientist-specific data
    }
    void putData() {
        Employee2::putData();
        // Add scientist-specific data
    }
};

class Laborer : public Employee2 {
public:
    void getData() {
        Employee2::getData();
        // Add laborer-specific data
    }
    void putData() {
        Employee2::putData();
        // Add laborer-specific data
    }
};

int main() {
    Manager manager;
    Scientist scientist;
    Laborer laborer;
    
    manager.getData();
    scientist.getData();
    laborer.getData();
    
    manager.putData();
    scientist.putData();
    laborer.putData();
    
    return 0;
}

