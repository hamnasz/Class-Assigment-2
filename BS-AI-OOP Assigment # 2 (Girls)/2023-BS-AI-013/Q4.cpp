// File: seemal.cpp
// Date: 02-05-2024
// Name: seemal mustafa
// Registration No: 2023-BSAI-013
// Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new
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

enum Period { HOURLY, WEEKLY, MONTHLY };

class Employee {
protected:
    string name;
    unsigned long number;
public:
    Employee() : name(""), number(0) {}

    void getData() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number: ";
        cin >> number;
    }

    void putData() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class Employee2 : public Employee {
protected:
    double compensation;
    Period period;
public:
    Employee2() : compensation(0.0), period(HOURLY) {}

    void getData() {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char periodChar;
        cout << "Enter period (h for hourly, w for weekly, m for monthly): ";
        cin >> periodChar;
        switch (periodChar) {
            case 'h': case 'H':
                period = HOURLY;
                break;
            case 'w': case 'W':
                period = WEEKLY;
                break;
            case 'm': case 'M':
                period = MONTHLY;
                break;
            default:
                period = HOURLY;
                break;
        }
    }

    void putData() const {
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

class Manager : public Employee2 {
private:
    string title;
    double dues;
public:
    Manager() : title(""), dues(0.0) {}

    void getData() {
        Employee2::getData();
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter dues: ";
        cin >> dues;
    }

    void putData() const {
        Employee2::putData();
        cout << "Title: " << title << endl;
        cout << "Dues: " << dues << endl;
    }
};

class Scientist : public Employee2 {
private:
    int pubs;
public:
    Scientist() : pubs(0) {}

    void getData() {
        Employee2::getData();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }

    void putData() const {
        Employee2::putData();
        cout << "Publications: " << pubs << endl;
    }
};

class Laborer : public Employee2 {
public:
    void getData() {
        Employee2::getData();
    }

    void putData() const {
        Employee2::putData();
    }
};

int main() {
    Manager mgr;
    Scientist sci;
    Laborer lab;

    cout << "Enter data for manager:" << endl;
    mgr.getData();
    cout << "\nEnter data for scientist:" << endl;
    sci.getData();
    cout << "\nEnter data for laborer:" << endl;
    lab.getData();

    cout << "\nDisplaying manager data:" << endl;
    mgr.putData();
    cout << "\nDisplaying scientist data:" << endl;
    sci.putData();
    cout << "\nDisplaying laborer data:" << endl;
    lab.putData();

    return 0;
}
