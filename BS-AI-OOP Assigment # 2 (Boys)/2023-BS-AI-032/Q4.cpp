#include <iostream>
#include <string>

using namespace std;

// Base Employee class
class Employee {
protected:
    string name;
    long id;
    char type;

public:
    void getData() {
        cout << "Enter employee's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee's id: ";
        cin >> id;
        cout << "Enter employee's type (M, S, L): ";
        cin >> type;
    }

    void putData() const {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Employee Type: " << type << endl;
    }
};

// Derived Employee2 class
class Employee2 : public Employee {
protected:
    double compensation;
    enum class Period { Hourly, Weekly, Monthly } period;

public:
    void getData() {
        Employee::getData();
        cout << "Enter employee's compensation: ";
        cin >> compensation;
        char periodType;
        cout << "Enter employee's pay period (H for Hourly, W for Weekly, M for Monthly): ";
        cin >> periodType;
        switch (periodType) {
            case 'H':
            case 'h':
                period = Period::Hourly;
                break;
            case 'W':
            case 'w':
                period = Period::Weekly;
                break;
            case 'M':
            case 'm':
                period = Period::Monthly;
                break;
            default:
                cout << "Invalid pay period entered. Defaulting to Hourly." << endl;
                period = Period::Hourly;
                break;
        }
    }

    void putData() const {
        Employee::putData();
        cout << "Compensation: $" << compensation << endl;
        switch (period) {
            case Period::Hourly:
                cout << "Pay Period: Hourly" << endl;
                break;
            case Period::Weekly:
                cout << "Pay Period: Weekly" << endl;
                break;
            case Period::Monthly:
                cout << "Pay Period: Monthly" << endl;
                break;
        }
    }
};

// Derived classes from Employee2
class Manager : public Employee2 {};
class Scientist : public Employee2 {};
class Laborer : public Employee2 {};

int main() {
    Manager m;
    Scientist s;
    Laborer l;

    cout << "Enter data for Manager:" << endl;
    m.getData();

    cout << "Enter data for Scientist:" << endl;
    s.getData();

    cout << "Enter data for Laborer:" << endl;
    l.getData();

    cout << "----------------------------------------------------" << endl;
    cout << "Manager's Details:" << endl;
    m.putData();
    cout << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "Scientist's Details:" << endl;
    s.putData();
    cout << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "Laborer's Details:" << endl;
    l.putData();
    cout << endl;

    return 0;
}
