// Ali Hassan
// File: Problem4.cpp  
// Registration No:2023-BS-AI-038
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

class Employee 
{
protected:
    string name;
    int salary;

public:
    Employee(string empName, int empSalary) : name(empName), salary(empSalary) {} //constructor

    virtual void display() const 
	{
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

enum class PayPeriod { HOURLY, WEEKLY, MONTHLY };

class Employee2 : public Employee 
{
private:
    double compensation;
    PayPeriod payPeriod;

public:
    Employee2(string empName, int empSalary, double comp, PayPeriod period)
        : Employee(empName, empSalary), compensation(comp), payPeriod(period) {}

    void display() const override
	 {
        Employee::display();
        cout << "Compensation: $" << compensation << endl;
        cout << "Pay Period: ";
        if (payPeriod == PayPeriod::HOURLY) 
		{
            cout << "Hourly" << endl;
        } else if (payPeriod == PayPeriod::WEEKLY) 
		{
            cout << "Weekly" << endl;
        } else if (payPeriod == PayPeriod::MONTHLY) 
		{
            cout << "Monthly" << endl;
        }
    }
};

int main() 
{
    Employee2 emp1("Ali", 32000, 5.0, PayPeriod::HOURLY);
    Employee2 emp2("Hassan", 44000, 210.0, PayPeriod::WEEKLY);

    cout << "Employee 1 Details:" << endl;
    emp1.display();
    cout << "\nEmployee 2 Details:" << endl;
    emp2.display();

    return 0;
}
