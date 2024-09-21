// File: assignment no 5 task 6.cpp
// Date: 18-05-2024
// Name: Ayesha Imran
// Registration No: 2023-BS-AI-057

/* This program designs a class hierarchy for an Employee Management System. The base class is Employee, 
   with derived classes SalariedEmployee and CommissionEmployee. Each class contains appropriate data 
   members and functions to handle the specific attributes and behaviors of each type of employee. */

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;
    string department;

public:
    // Constructor to initialize Employee
    Employee(const string& name, int id, const string& department)
        : name(name), id(id), department(department) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter for ID
    int getID() const {
        return id;
    }

    // Getter for department
    string getDepartment() const {
        return department;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    // Constructor to initialize SalariedEmployee
    SalariedEmployee(const string& name, int id, const string& department, double annualSalary)
        : Employee(name, id, department), annualSalary(annualSalary) {}

    // Method to calculate the monthly salary
    double calculateMonthlySalary() const {
        return annualSalary / 12;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    // Constructor to initialize CommissionEmployee
    CommissionEmployee(const string& name, int id, const string& department, double sales, double commissionRate)
        : Employee(name, id, department), sales(sales), commissionRate(commissionRate) {}

    // Method to calculate total pay based on sales and commission rate
    double calculateTotalPay() const {
        return sales * commissionRate;
    }
};

int main() {
    
    SalariedEmployee salariedEmployee("AYESHA", 1, "AI", 1000000);
    cout << "Employee Name: " << salariedEmployee.getName() << endl;
    cout << "Employee ID: " << salariedEmployee.getID() << endl;
    cout << "Department: " << salariedEmployee.getDepartment() << endl;
    cout << "Monthly Salary: $" << salariedEmployee.calculateMonthlySalary() << endl;

    cout << endl;

    
    CommissionEmployee commissionEmployee("Maham", 2, "SE", 20000, 1.5);
    cout << "Employee Name: " << commissionEmployee.getName() << endl;
    cout << "Employee ID: " << commissionEmployee.getID() << endl;
    cout << "Department: " << commissionEmployee.getDepartment() << endl;
    cout << "Total Pay: $" << commissionEmployee.calculateTotalPay() << endl;

    return 0;
}
