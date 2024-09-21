// File: Program6.cpp
// Date: 22-05-2024
// Name: Muhammad Faisal Kamran
// Registration No: 2023-BS-AI-025
/*Design a class hierarchy for an Employee management system. The base class should be Employee with 
derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
members and member funcƟons to handle the specific aƩributes and behaviors of each type of employee.
Employee: Should have data members for name, employee ID, and department. It should also have 
member funcƟons to get and set these values.
Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
member funcƟons to get and set the salary, and to calculate the monthly pay.
Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
should have member funcƟons to get and set these values, and to calculate the total pay based on sales 
and commission rate
*/
#include<iostream>
using namespace std;

class Employee {
private:
    string name, department;
    int EmpID;

public:
    void getEmpdata() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Department: ";
        cin >> department;
        cout << "Enter Employee ID: ";
        cin >> EmpID;
    }

    void putEmpdata() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Department: " << department << endl;
        cout << "Employee ID: " << EmpID << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    int salary;

public:
    void getSEmpdata() {
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void putSEmpdata() {
        cout << "Employee Salary: " << salary << endl;
    }
};

class CommissionedEmployee : public Employee {
private:
    int salary;
    float commissionrate;

public:
    void getCEmpdata() {
        cout << "Enter Employee Salary: ";
        cin >> salary;
        cout << "Enter Employee Commission Rate (%): ";
        cin >> commissionrate;
    }

    void putCEmpdata() {
        float commission = (salary * commissionrate) / 100;
        float totalSalary = salary + commission;
        cout << "Employee Salary after commission: " << totalSalary << endl;
    }
};

int main() {
    SalariedEmployee faisal;
    CommissionedEmployee danish;

    faisal.getEmpdata();
    faisal.getSEmpdata();
    danish.getCEmpdata();

    faisal.putEmpdata();
    faisal.putSEmpdata();
    danish.putCEmpdata();

    return 0;
}
