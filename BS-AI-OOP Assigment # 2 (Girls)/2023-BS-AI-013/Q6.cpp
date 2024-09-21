// File: seemal.cpp
// Date: 02-05-2024
// Name: seemal mustafa
// Registration No: 2023-BSAI-013
// Design a class hierarchy for an Employee management system. The base class should be Employee with
//derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data
//members and member funcOons to handle the specific a?ributes and behaviors of each type of employee.
//Employee: Should have data members for name, employee ID, and department. It should also have
//member funcOons to get and set these values.
//Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have
//member funcOons to get and set the salary, and to calculate the monthly pay.
//Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It
//should have member funcOons to get and set these values, and to calculate the total pay based on sales
//and commission rate.

#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;
public:
    Employee(const string& name, int employeeID, const string& department)
        : name(name), employeeID(employeeID), department(department) {}

    void setName(const string& name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setEmployeeID(int employeeID) {
        this->employeeID = employeeID;
    }

    int getEmployeeID() const {
        return employeeID;
    }

    void setDepartment(const string& department) {
        this->department = department;
    }

    string getDepartment() const {
        return department;
    }

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;
public:
    SalariedEmployee(const string& name, int employeeID, const string& department, double annualSalary)
        : Employee(name, employeeID, department), annualSalary(annualSalary) {}

    void setAnnualSalary(double annualSalary) {
        this->annualSalary = annualSalary;
    }

    double getAnnualSalary() const {
        return annualSalary;
    }

    double calculateMonthlyPay() const {
        return annualSalary / 12;
    }

    void display() const override {
        Employee::display();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Monthly Pay: $" << calculateMonthlyPay() << endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;
public:
    CommissionEmployee(const string& name, int employeeID, const string& department, double sales, double commissionRate)
        : Employee(name, employeeID, department), sales(sales), commissionRate(commissionRate) {}

    void setSales(double sales) {
        this->sales = sales;
    }

    double getSales() const {
        return sales;
    }

    void setCommissionRate(double commissionRate) {
        this->commissionRate = commissionRate;
    }

    double getCommissionRate() const {
        return commissionRate;
    }

    double calculateTotalPay() const {
        return sales * commissionRate;
    }

    void display() const override {
        Employee::display();
        cout << "Sales: $" << sales << endl;
        cout << "Commission Rate: " << commissionRate * 100 << "%" << endl;
        cout << "Total Pay: $" << calculateTotalPay() << endl;
    }
};

int main() {
    SalariedEmployee salariedEmp("John Doe", 123, "HR", 60000);
    CommissionEmployee commissionEmp("Jane Smith", 456, "Sales", 50000, 0.10);

    cout << "Salaried Employee Details:" << endl;
    salariedEmp.display();
    cout << endl;

    cout << "Commission Employee Details:" << endl;
    commissionEmp.display();

    return 0;
}
