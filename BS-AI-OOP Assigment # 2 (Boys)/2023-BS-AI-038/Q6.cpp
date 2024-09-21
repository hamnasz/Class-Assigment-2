// Ali Hassan
// File: Problem5.cpp  
// Registration No:2023-BS-AI-038
/* Design a class hierarchy for an Employee management system. The base class should be Employee with 
derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
members and member func ons to handle the specific a ributes and behaviors of each type of employee. 
Employee: Should have data members for name, employee ID, and department. It should also have 
member func ons to get and set these values. 
Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
member func ons to get and set the salary, and to calculate the monthly pay. 
Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
should have member func ons to get and set these values, and to calculate the total pay based on sales 
and commission rate. */
#include <iostream>
using namespace std;

class Employee {
protected:
    string employeeName;
    int employeeID;
    string departmentName;

public:
    Employee(const string& name, int id, const string& dept)
        : employeeName(name), employeeID(id), departmentName(dept) {}

    string getName() const { return employeeName; }
    int getID() const { return employeeID; }
    string getDepartment() const { return departmentName; }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(const string& name, int id, const string& dept, double salary)
        : Employee(name, id, dept), annualSalary(salary) {}

    double calculateMonthlyPay() const 
	{
        return annualSalary / 12.0;
    }
};

class CommissionedEmployee : public Employee {
private:
    double salesTotal;
    double rateOfCommission;

public:
    CommissionedEmployee(const string& name, int id, const string& dept, double sales, double rate)
        : Employee(name, id, dept), salesTotal(sales), rateOfCommission(rate) {}

    double calculateTotalPay() const 
	{
        return salesTotal * rateOfCommission;
    }
};

int main() 
{
    SalariedEmployee salariedEmployee("Ali", 2024038, "AI Development", 1400000.0);
    cout << "Monthly Pay of " << salariedEmployee.getName() << ": $" << salariedEmployee.calculateMonthlyPay() << endl;

    CommissionedEmployee commissionedEmployee("Hassan", 2023038, "E-commerce Sales", 50000.0, 0.10);
    cout << "Total Pay of " << commissionedEmployee.getName() << ": $" << commissionedEmployee.calculateTotalPay() << endl;

    return 0;
}
