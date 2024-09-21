// File: P6
// Date: 22-MAY-2023
// Name: M.HASHIR AFZAAL
// Registration No: 062
/*Design a class hierarchy for an Employee management system. The base class should be Employee with 
derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
members and member func ons to handle the specific a ributes and behaviors of each type of employee. 
Employee: Should have data members for name, employee ID, and department. It should also have 
member func ons to get and set these values. 
Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
member func ons to get and set the salary, and to calculate the monthly pay. 
Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
should have member func ons to get and set these values, and to calculate the total pay based on sales 
and commission rate.*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Employee {
protected:
    string name;
    int employeeId;
    string department;
};

class SalariedEmployee : virtual protected Employee {
private:
    double salary;

public:
    void get() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> employeeId;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Annual Salary: ";
        cin >> salary;
    }

    void set() {
    	cout << "----INFORMATION----";
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        double monthlySalary = salary / 12;
        cout << "Monthly Salary is: " << monthlySalary << endl;
    }
};

class CommissionEmp : virtual protected Employee {
private:
    double commissionRate;
    int sales;

public:
    void getdata() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> employeeId;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Commission Rate on Each Sale: ";
        cin >> commissionRate;
        cout << "Enter Number of Sales: ";
        cin >> sales;
    }

    void setdata() {
    	cout << "----INFORMATION----";
        cout << "Name is: " << name << endl;
        cout << "ID is: " << employeeId << endl;
        cout << "Department is: " << department << endl;
        cout << "Commission Rate is: " << commissionRate << endl;
        cout << "Number of Sales are: " << sales << endl;
        double commission = commissionRate * sales;
        cout << "Commission of an Employee is: " << commission << endl;
    }
};

int main() {
    char choice;

    cout << "Press 's' to calculate Salary of an Employee" << endl;
    cout << "Press 'c' to calculate Commission of an Employee" << endl;
    cin >> choice;

    switch (choice) {
        case 's': {
            SalariedEmployee ss;
            ss.get();
            ss.set();
            break;
        }
        case 'c': {
            CommissionEmp cc;
            cc.getdata();
            cc.setdata();
            break;
        }
        default:
            cout << "Invalid Choice!" << endl;
    }

    return 0;
}

