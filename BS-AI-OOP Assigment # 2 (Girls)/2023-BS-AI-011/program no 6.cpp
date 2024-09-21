//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
//Design a class hierarchy for an Employee management system. The base class should be Employee with
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
private:
    int employeeID;
    string name;
    string department;

public:
    Employee(int id, string n, string dept) : employeeID(id), name(n), department(dept) {}

    void display() const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), annualSalary(salary) {}

    double calculateMonthlyPay() const {
        return annualSalary / 12.0;
    }

    void displaySalary() const {
        cout << "Annual Salary: $" << annualSalary << endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    CommissionEmployee(int id, string n, string dept, double salesAmt, double rate)
        : Employee(id, n, dept), sales(salesAmt), commissionRate(rate) {}

    double calculateTotalPay() const {
        return sales * commissionRate;
    }

    void displayCommissionInfo() const {
        cout << "Total Sales: $" << sales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }
};

int main() {
    // Example usage
    SalariedEmployee salariedEmp(101, "Ayesha Imran", "Marketing", 20000.0);
    salariedEmp.display();
    salariedEmp.displaySalary();
    cout << "Monthly Pay: $" << salariedEmp.calculateMonthlyPay() << endl;

    CommissionEmployee commissionEmp(102, "Amna Imran", "Sales", 700000.0, 0.05);
    commissionEmp.display();
    commissionEmp.displayCommissionInfo();
    cout << "Total Pay: $" << commissionEmp.calculateTotalPay() << endl;

    return 0;
}

