#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    unsigned long number;

public:
    void getdata() {
        cout << "Enter name: ";
        cin.ignore(); // Ignore any leftover newline character
        getline(cin, name);
        cout << "Enter number: ";
        cin >> number;
    }

    void putdata() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};
enum Period { HOURLY, WEEKLY, MONTHLY };

class Employee2 : public Employee {
protected:
    double compensation;
    Period period;

public:
    void getdata() {
        Employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        char periodChoice;
        cout << "Enter period (h for hourly, w for weekly, m for monthly): ";
        cin >> periodChoice;
        switch (periodChoice) {
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
                cout << "Invalid choice! Defaulting to hourly." << endl;
                period = HOURLY;
                break;
        }
    }

    void putdata() const {
        Employee::putdata();
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
public:
    void getdata() {
        cout << "Enter details for Manager:" << endl;
        Employee2::getdata();
    }

    void putdata() const {
        cout << "Manager details:" << endl;
        Employee2::putdata();
    }
};

class Scientist : public Employee2 {
public:
    void getdata() {
        cout << "Enter details for Scientist:" << endl;
        Employee2::getdata();
    }

    void putdata() const {
        cout << "Scientist details:" << endl;
        Employee2::putdata();
    }
};

class Laborer : public Employee2 {
public:
    void getdata() {
        cout << "Enter details for Laborer:" << endl;
        Employee2::getdata();
    }

    void putdata() const {
        cout << "Laborer details:" << endl;
        Employee2::putdata();
    }
};
int main() {
    Manager mgr;
    Scientist sci;
    Laborer lab;

    cout << "Writing the  details for Manager:" << endl;
    mgr.getdata();

    cout << "Enter details for Scientist:" << endl;
    sci.getdata();

    cout << "Enter details for Laborer:" << endl;
    lab.getdata();

    cout << "Displaying Manager details:" << endl;
    mgr.putdata();

    cout << "Displaying Scientist details:" << endl;
    sci.putdata();

    cout << "Displaying Laborer details:" << endl;
    lab.putdata();

    return 0;
}
 
