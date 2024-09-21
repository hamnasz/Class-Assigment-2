//date:19-5-2024
//name:hassan tariq
//regno: bsai-2023-004
//program 6

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

class SEmployee : public Employee {
private:
    double annualSalary;

public:
    SEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), annualSalary(salary) {}

    double calMonthlyPay() const {
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

    double calTotalPay() const {
        return sales * commissionRate;
    }

    void displayCommissionInfo() const {
        cout << "Total Sales: $" << sales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }
};

int main() {
    // Example usage
    SEmployee sEmp(1, "hassan tariq", "Marketing", 60000.0);
    sEmp.display();
    sEmp.displaySalary();
    cout << "Monthly Pay: $" << sEmp.calMonthlyPay() << endl;

    CommissionEmployee commissionEmp(2, "masood bakhtiar", "Sales", 90000.0, 0.05);
    commissionEmp.display();
    commissionEmp.displayCommissionInfo();
    cout << "Total Pay: $" << commissionEmp.calTotalPay() << endl;

    return 0;
}

