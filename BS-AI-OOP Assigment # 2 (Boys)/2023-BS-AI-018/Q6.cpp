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
    SalariedEmployee emp1;
    CommissionedEmployee emp2;

    emp1.getEmpdata();
    emp1.getSEmpdata();
    emp2.getEmpdata();
    emp2.getCEmpdata();

    emp1.putEmpdata();
    emp1.putSEmpdata();
    emp2.putEmpdata();
    emp2.putCEmpdata();

    return 0;
}