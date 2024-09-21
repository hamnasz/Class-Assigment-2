// File: 6.cpp  
// Date: 21-05-2024  
// Name: M.Hanzla  
// Registration no:2023-BS-AI-046)  
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
    string name;
    int empID;
    string dept;

public:
    Employee(const string& name, int empID, const string& dept):name(name), empID(empID), dept(dept) {}

    string getName() const { return name; }
    int getEmpID() const { return empID; }
    string getDept() const { return dept; }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(const string& name, int empID, const string& dept,
                     double annualSalary)
        : Employee(name, empID, dept), annualSalary(annualSalary) {}

    double calcMonthlyPay() const {
        return annualSalary / 12.0;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commRate;

public:
    CommissionEmployee(const string& name, int empID, const string& dept,double sales, double commRate):Employee(name, empID, dept), sales(sales), commRate(commRate) {}
double calcTotalPay() const {
        return sales*commRate;
    }
};
int main() {
    SalariedEmployee salaried("hanzla", 1233, "Sales", 60000.0);
    cout << "Monthly Salary for " << salaried.getName() << " " << salaried.calcMonthlyPay() << endl;

    CommissionEmployee commission("hammad", 2234, "Marketing", 100000.0, 0.05);
    cout << "Total Pay is  " << commission.getName() << " " << commission.calcTotalPay() << endl;

    return 0;
}
