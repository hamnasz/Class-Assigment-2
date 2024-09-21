//file: file eman.cpp
//date: 21-05-2024
//name: eman tahir
//reg no. 2023-bs-ai-015
//question statement: Design a class hierarchy for an Employee management system. The base class should be Employee with derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data members and member functions to handle the specific atributes and behaviors of each type of employee. 
//Employee: Should have data members for name, employee ID, and department. It should also have member functions to get and set these values.
//Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have member functions to get and set the salary, and to calculate the monthly pay. 
//Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It should have member functions to get and set these values, and to calculate the total pay based on sales and commission rate.


#include <iostream>
using namespace std;
class Employee {
private:
    int employeeID;
    string name;
    string department;

public:
    Employee(int id, string n, string dept) : employeeID(id), name(n), department(dept) {}

    int display() 
	const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }
};

class SEmployee : public Employee {
private:
    double annualSalary;

public:
    SEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), annualSalary(salary) {}

    double calMonthlyPay() const {
        return annualSalary / 15.0;
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

    double calTotalPay() const {
        return sales * commissionRate;
    }

    void displayCommissionInfo() const {
        cout << "Total Sales: $" << sales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }
};

int main() {
    SEmployee sEmp(1, "emp1", "Marketing", 30000.0);
    sEmp.display();
    sEmp.displaySalary();
    cout << "Monthly Pay: $" << sEmp.calMonthlyPay() << endl;

    CommissionEmployee commissionEmp(2, "emp2", "Sales", 80000.0, 0.07);
    commissionEmp.display();
    commissionEmp.displayCommissionInfo();
    cout << "Total Pay: $" << commissionEmp.calTotalPay() << endl;

    return 0;
}

