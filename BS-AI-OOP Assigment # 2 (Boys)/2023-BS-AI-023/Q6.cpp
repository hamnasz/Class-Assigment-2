// File: code6.cpp
// Date: 20-05-2024
// Name: HARIS AWAN 
// Registration No: 2023-BS-AI-023
//Design a class hierarchy for an Employee management system. The base class should be Employee with 
//derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
//members and member funcOons to handle the specific a?ributes and behaviors of each type of employee.
//Employee: Should have data members for name, employee ID, and department. It should also have 
//member funcOons to get and set these values.
//Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
//member funcOons to get and set the salary, and to calculate the monthly pay.
//Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
//should have member funcOons to get and set these values, and to calculate the total pay based on sales 
//and commission rate

#include<iostream>
using namespace std;

class Employee {
private:
    string name, department;
    int ID;

public:
    void getEmp() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Department: ";
        cin >> department;
        cout << "Enter Employee ID: ";
        cin >> ID;
    }

    void putEmp() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Department: " << department << endl;
        cout << "Employee ID: " << ID << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    int salary;

public:
    void getSalariedEmp() {
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void putSalariedEmp() {
        cout << "Employee Salary: " << salary << endl;
    }
};

class CommissionedEmployee : public Employee {
private:
    int salary;
    float comirate;

public:
    void getCommissionedEmp() {

        cout << "Enter Employee Commission Rate (%): ";
        cin >> comirate;
    }

    void putCommissionedEmp() {
        float commission = (salary * comirate) / 100;
        float totalSalary = salary + commission;
        cout << "Employee Salary after commission: " << totalSalary << endl;
    }
};

int main() {
    SalariedEmployee obj;
    CommissionedEmployee obj1 ;

    obj.getEmp();
    obj.getSalariedEmp();
    obj1.getCommissionedEmp();

    obj.putEmp();
    obj.putSalariedEmp();
    obj1.putCommissionedEmp();

    return 0;
}
