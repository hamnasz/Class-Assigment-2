// File: 6_ems.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Design a class hierarchy for an Employee management system. The base class should be Employee with derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data members and member funcƟons to handle the specific aƩributes and behaviors of each type of employee.Employee: Should have data members for name, employee ID, and department. It should also have
member funcƟons to get and set these values.Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have member funcƟons to get and set the salary, and to calculate the monthly pay.Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It should have member funcƟons to get and set these values, and to calculate the total pay based on salesand commission rate*/
#include <iostream>
using namespace std;
class employee
{
public:
    string name, department;
    int empID;
    virtual void setdata()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter ID:";
        cin >> empID;
        cout << "Enter department:";
        cin >> department;
    }
    virtual void getdata()
    {
        cout << "Name:" << name << endl;
        cout << "Department:" << department << endl;
        cout << "ID:" << empID << endl;
    }
};
class salariedEmployee : public employee
{
public:
    double annualSalary;
    double monthlyPay;
    void setdata() override
    {
        employee::setdata();
        cout << "Enter Annual salary";
        cin >> annualSalary;
    }
    void getdata() override
    {
        employee::getdata();
        monthlyPay = annualSalary / 12;
        cout << "Monthly Salary:" << monthlyPay << endl;
    }
};
class commissionEmployee : public employee
{
public:
    double commissionRate, monthlySalary;
    double totalPay;
    void setdata() override
    {
        employee::setdata();
        cout << "Enter Commission Rate";
        cin >> commissionRate;
        cout << "Enter Monthly Salary";
        cin >> monthlySalary;
    }
    void getdata() override
    {
        employee::getdata();
        totalPay = commissionRate * monthlySalary;
        cout << "Monthly Salary:" << totalPay << endl;
    }
};
int main()
{
    salariedEmployee s;
    cout << "Enter details of salaried Employees:\n";
    s.setdata();
    cout << "\nDetails:\n";
    s.getdata();

    commissionEmployee c;
    cout << "\nEnter details of commission Employees:\n";
    c.setdata();
    cout << "\nDetails:\n";
    c.getdata();
    return 0;
}