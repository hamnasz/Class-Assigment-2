#include <iostream>
#include <string>
using namespace std;

enum Period { HOURLY, WEEKLY, MONTHLY };

class Employee {
protected:
    string name;
    int number;
public:
    virtual void getData() {
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee number: ";
        cin >> number;
    }
    virtual void putData() const {
        cout << "Name: " << name << "\nNumber: " << number << endl;
    }
};

class Employee2 : public Employee {
protected:
    double compensation;
    Period period;
public:
    void getData() override {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char per;
        cout << "Enter period (h for hourly, w for weekly, m for monthly): ";
        cin >> per;
        switch (per) {
            case 'h': period = HOURLY; break;
            case 'w': period = WEEKLY; break;
            case 'm': period = MONTHLY; break;
            default: period = HOURLY; // Default case to handle invalid input
        }
    }
    void putData() const override {
        Employee::putData();
        cout << "Compensation: " << compensation << "\nPeriod: "
             << (period == HOURLY ? "Hourly" : period == WEEKLY ? "Weekly" : "Monthly") << endl;
    }
};

class Manager : public Employee2 {
    // No need to override getData and putData since they don't add new functionality
};

class Scientist : public Employee2 {
    // No need to override getData and putData since they don't add new functionality
};

class Laborer : public Employee2 {
    // The previous code was incomplete, adding the full method
public:
    void getData() override {
        Employee2::getData();
    }
    void putData() const override {
        Employee2::putData();
    }
};

int main() {
    Manager manager;
    Scientist scientist;
    Laborer laborer;

    cout << "Enter details for manager:\n";
    manager.getData();
    cout << "Enter details for scientist:\n";
    scientist.getData();
    cout << "Enter details for laborer:\n";
    laborer.getData();

    cout << "\nManager details:\n";
    manager.putData();
    cout << "\nScientist details:\n";
    scientist.putData();
    cout << "\nLaborer details:\n";
    laborer.putData();

    return 0;
}