// File: Program4.cpp
// Date: 22-05-2024
// Name: Muhammad Faisal Kamran
// Registration No: 2023-BS-AI-025
/*Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new 
class should add a type double data item called compensaOon, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the 
manager, scienOst, and laborer classes so they are derived from employee2 instead of employee. However, 
note that in many circumstances it might be more in the spirit of OOP to create a separate base class called 
compensaOon and three new classes manager2, scientist2, and laborer2, and use mulOple inheritance to 
derive these three classes from the original manager, scienOst, and laborer classes and from 
compensation. This way none of the original classes needs to be modified

*/
#include <iostream>
#include <string>

using namespace std;

enum Period { HOURLY, WEEKLY, MONTHLY };

class Employee {
protected:
    string name;
    unsigned long number;
public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Name: " << name << "\n";
        cout << "Number: " << number << "\n";
    }
};

class Employee2 : public Employee {
private:
    double compensation;
    Period period;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        int periodInput;
        cout << "Enter pay period (0 for Hourly, 1 for Weekly, 2 for Monthly): ";
        cin >> periodInput;
        period = static_cast<Period>(periodInput);
    }
    void putdata() const {
        Employee::putdata();
        cout << "Compensation: " << compensation << "\n";
        cout << "Pay period: ";
        switch (period) {
            case HOURLY: cout << "Hourly\n"; break;
            case WEEKLY: cout << "Weekly\n"; break;
            case MONTHLY: cout << "Monthly\n"; break;
        }
    }
};

class Manager2 : public Employee2 {
private:
    string title;
    double dues;
public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter dues: ";
        cin >> dues;
    }
    void putdata() const {
        Employee2::putdata();
        cout << "Title: " << title << "\n";
        cout << "Dues: " << dues << "\n";
    }
};

class Scientist2 : public Employee2 {
private:
    int publications;
public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> publications;
    }
    void putdata() const {
        Employee2::putdata();
        cout << "Publications: " << publications << "\n";
    }
};

class Laborer2 : public Employee2 {
    // No additional data members
};

int main() {
    Manager2 mgr;
    Scientist2 sci;
    Laborer2 lab;

    cout << "Enter manager data:\n";
    mgr.getdata();
    cout << "\nEnter scientist data:\n";
    sci.getdata();
    cout << "\nEnter laborer data:\n";
    lab.getdata();

    cout << "\nManager data:\n";
    mgr.putdata();
    cout << "\nScientist data:\n";
    sci.putdata();
    cout << "\nLaborer data:\n";
    lab.putdata();

    return 0;
}
