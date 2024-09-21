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
        cin.ignore();
        getline(cin, name);
        cout << "Enter number: ";
        cin >> number;
    }
    
    void putdata() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};
class Employee2 : public Employee {
protected:
    double compensation;
    enum Period { hourly, weekly, monthly } period;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        char p;
        cout << "Enter pay period (h for hourly, w for weekly, m for monthly): ";
        cin >> p;
        switch(p) {
            case 'h': period = hourly; break;
            case 'w': period = weekly; break;
            case 'm': period = monthly; break;
            default: 
                cout << "Invalid input. Defaulting to hourly." << endl;
                period = hourly;
        }
    }
    
    void putdata() const {
        Employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay Period: ";
        switch(period) {
            case hourly: cout << "Hourly"; break;
            case weekly: cout << "Weekly"; break;
            case monthly: cout << "Monthly"; break;
        }
        cout << endl;
    }
};
class Manager : public Employee2 {
public:
    void getdata() {
        Employee2::getdata();
    }
    
    void putdata() const {
        Employee2::putdata();
    }
};
class Scientist : public Employee2 {
public:
    void getdata() {
        Employee2::getdata();
    }
    
    void putdata() const {
        Employee2::putdata();
    }
};
class Laborer : public Employee2 {
public:
    void getdata() {
        Employee2::getdata();
    }
    
    void putdata() const {
        Employee2::putdata();
    }
};

int main() {
    Manager manager;
    Scientist scientist;
    Laborer laborer;
    
    cout << "Enter details for manager:" << endl;
    manager.getdata();
    
    cout << "\nEnter details for scientist:" << endl;
    scientist.getdata();
    
    cout << "\nEnter details for laborer:" << endl;
    laborer.getdata();
    
    cout << "\nDetails of the manager entered:" << endl;
    manager.putdata();
    
    cout << "\nDetails of the scientist entered:" << endl;
    scientist.putdata();
    
    cout << "\nDetails of the laborer entered:" << endl;
    laborer.putdata();
}