// File: Program6.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Design a class hierarchy for an Employee management system. The base class should be Employee with derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data members and member func􀆟ons to handle the specific a􀆩ributes and behaviors of each type of employee.
// Employee: Should have data members for name, employee ID, and department. It should also have member func􀆟ons to get and set these values.
// Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have member func􀆟ons to get and set the salary, and to calculate the monthly pay.
// Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It should have member func􀆟ons to get and set these values, and to calculate the total pay based on sales and commission rate.
#include<iostream>
using namespace std;

// Base class for Employee
class Employee
{
protected:
    string name; // Name of the employee
    int id; // Employee ID
    string department; // Department of the employee

public:
    // Function to input employee information
    void getInfo()
    {
        cout<<"Enter Employee Name: ";
        cin>>name;
        cout<<"Enter Employee Id: ";
        cin>>id;
        cout<<"Enter Employee Department: ";
        cin>>department;
    }

    // Function to display employee information
    void setInfo()
    {
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Id: "<<id<<endl;
        cout<<"Employee Department: "<<department<<endl;
    }
};

// Derived class for Salaried Employee inheriting from Employee
class SalariedEmployee : public Employee
{
private:
    double annualSalary; // Annual salary of the employee
    double monthlySalary; // Monthly salary of the employee

public:
    // Function to input salaried employee information
    void getInfo()
    {
        Employee::getInfo(); // Input base class information
        cout<<"Enter Annual Salary: ";
        cin>>annualSalary;
    }

    // Function to calculate monthly salary
    void calculate()
    {
        monthlySalary = annualSalary / 12;
    }

    // Function to display salaried employee information
    void setInfo()
    {
        Employee::setInfo(); // Display base class information
        cout<<"Annual Salary: "<<annualSalary<<endl;
        cout<<"Monthly Salary: "<<monthlySalary<<endl;
    }
};

// Derived class for Commission Employee inheriting from Employee
class CommissionEmployee : public Employee
{
private:
    double sales; // Sales made by the employee
    double commissionRate; // Commission rate of the employee
    double totalSalary; // Total salary of the employee

public:
    // Function to input commission employee information
    void getInfo()
    {
        Employee::getInfo(); // Input base class information
        cout<<"Enter Sales: ";
        cin>>sales;
        cout<<"Enter Commission Rate: ";
        cin>>commissionRate;
    }

    // Function to calculate total salary
    void calculate()
    {
        totalSalary = sales * commissionRate;
    }

    // Function to display commission employee information
    void setInfo()
    {
        Employee::setInfo(); // Display base class information
        cout<<"Total Salary: "<<totalSalary<<endl;
    }
};

// Main function
int main()
{
	cout<<"Enter Salaried Employee Info"<<endl;
    SalariedEmployee obj1; // Object for SalariedEmployee class
    obj1.getInfo(); // Inputting salaried employee details
    obj1.calculate(); // Calculating monthly salary
    cout<<"\nSalaried Employee Info"<<endl;
    obj1.setInfo(); // Displaying salaried employee details
	
	cout<<"\nEnter Commission Employee Info"<<endl;
    CommissionEmployee obj2; // Object for CommissionEmployee class
    obj2.getInfo(); // Inputting commission employee details
    obj2.calculate(); // Calculating total salary
    cout<<"\nCommission Employee Info"<<endl;
    obj2.setInfo(); // Displaying commission employee details

    return 0;
}