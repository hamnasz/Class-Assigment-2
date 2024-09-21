// File: 4.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla 
// Registration No:2023-BS-AI-046
/*Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new 
class should add a type double data item called compensa on, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the 
manager, scien st, and laborer classes so they are derived from employee2 instead of employee. However, 
note that in many circumstances it might be more in the spirit of OOP to create a separate base class called 
compensa on and three new classes manager2, scien st2, and laborer2, and use mul ple inheritance to 
derive these three classes from the original manager, scien st, and laborer classes and from 
compensa on. This way none of the original classes needs to be modified*/

#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int salary;

public:
    Employee(string empName, int empSalary) : name(empName), salary(empSalary) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

enum class Period { HOURLY, WEEKLY, MONTHLY };

class Employee2 : public Employee {
private:
    double compensation;
    Period paymentPeriod;

public:
    Employee2(string empName, int empSalary, double comp, Period period)
        : Employee(empName, empSalary), compensation(comp), paymentPeriod(period) {}

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Compensation: $" << compensation << endl;
        cout << "Payment Period: ";
        switch (paymentPeriod) {
            case Period::HOURLY:
                cout << "Hourly" << endl;
                break;
            case Period::WEEKLY:
                cout << "Weekly" << endl;
                break;
            case Period::MONTHLY:
                cout << "Monthly" << endl;
                break;
        }
    }
};

int main() {
    Employee2 emp1("John Doe", 50000, 25.0, Period::HOURLY);
    Employee2 emp2("Jane Smith", 60000, 800.0, Period::WEEKLY);

    emp1.displayInfo();
    emp2.displayInfo();

    return 0;
}
