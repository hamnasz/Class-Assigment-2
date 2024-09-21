/* File: Q6.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
      Design a class hierarchy for an Employee 
      management system. The base class should 
      be Employee with derived classes 
      SalariedEmployee and CommissionEmployee.
      Each class should have appropriate data
      members and member func􀆟ons to handle
      the specific a􀆩ributes and behaviors
      of each type of employee. Employee: 
      Should have data members for name,
      employee ID, and department. It should
      also have member func􀆟ons to get and
      set these values. Salaried Employee:
      Inherits from Employee and adds a data
      member for annual Salary. It should
      have member func􀆟ons to get and set
      the salary, and to calculate the
      monthly pay. Commission Employee:
      Inherits from Employee and adds data
      members for sales and commission Rate.
      It should have member func􀆟ons to get
      and set these values, and to calculate
      the total pay based on sales and
      commission rate.
*/
#include<iostream>
using namespace std;

// Base class for Employee
class Employee
{
protected:
    string name;
    int id;
    string department;

public:

    void getInfo()
    {
        cout<<"Enter Employee Name: ";
        cin>>name;
        cout<<"Enter Employee Id: ";
        cin>>id;
        cout<<"Enter Employee Department: ";
        cin>>department;
    }

    void setInfo()
    {
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Id: "<<id<<endl;
        cout<<"Employee Department: "<<department<<endl;
    }
};

// Derived class
class SalariedEmployee : public Employee
{
private:
    double annualSalary;
    double monthlySalary;

public:

    void getInfo()
    {
        Employee::getInfo();
        cout<<"Enter Annual Salary: ";
        cin>>annualSalary;
    }

    void calculate()
    {
        monthlySalary = annualSalary / 12;
    }

    void setInfo()
    {
        Employee::setInfo();
        cout<<"Annual Salary: "<<annualSalary<<endl;
        cout<<"Monthly Salary: "<<monthlySalary<<endl;
    }
};

// Derived class
class CommissionEmployee : public Employee
{
private:
    double sales;
    double commissionRate;
    double totalSalary;

public:

    void getInfo()
    {
        Employee::getInfo();
        cout<<"Enter Sales: ";
        cin>>sales;
        cout<<"Enter Commission Rate: ";
        cin>>commissionRate;
    }

    void calculate()
    {
        totalSalary = sales * commissionRate;
    }

    void setInfo()
    {
        Employee::setInfo();
        cout<<"Total Salary: "<<totalSalary<<endl;
    }
};

int main()
{
	cout<<"Enter Salaried Employee Info"<<endl;
    SalariedEmployee obj1;
    obj1.getInfo();
    obj1.calculate();

    cout<<"\nSalaried Employee Info"<<endl;
    obj1.setInfo();
	
	cout<<"\nEnter Commission Employee Info"<<endl;
    CommissionEmployee obj2;
    obj2.getInfo();
    obj2.calculate();

    cout<<"\nCommission Employee Info"<<endl;
    obj2.setInfo();

    return 0;
}