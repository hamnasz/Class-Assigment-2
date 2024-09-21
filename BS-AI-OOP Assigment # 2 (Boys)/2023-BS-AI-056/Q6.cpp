//Masood Bakhtiar 
//Roll no 56

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;

public:
    Employee(const string& empName, int empID, const string& dept) : name(empName), employeeID(empID), department(dept) {}

    void setName(const string& empName) {
        name = empName;
    }

    void setEmployeeID(int empID) {
        employeeID = empID;
    }

    void setDepartment(const string& dept) {
        department = dept;
    }

    string getName() const {
        return name;
    }

    int getEmployeeID() const {
        return employeeID;
    }

    string getDepartment() const {
        return department;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(const string& empName, int empID, const string& dept, double salary) : Employee(empName, empID, dept), annualSalary(salary) {}

    void setAnnualSalary(double salary) {
        annualSalary = salary;
    }

    double getAnnualSalary() const {
        return annualSalary;
    }

    double calculateMonthlyPay() const {
        return annualSalary / 12;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    CommissionEmployee(const string& empName, int empID, const string& dept, double salesAmt, double commission) : Employee(empName, empID, dept), sales(salesAmt), commissionRate(commission) {}

    void setSales(double salesAmt) {
        sales = salesAmt;
    }

    void setCommissionRate(double commission) {
        commissionRate = commission;
    }

    double getSales() const {
        return sales;
    }

    double getCommissionRate() const {
        return commissionRate;
    }

    double calculateTotalPay() const {
        return sales * commissionRate;
    }
};

int main() {
    SalariedEmployee salariedEmployee("John Doe", 1001, "Finance", 60000.0);
    CommissionEmployee commissionEmployee("Jane Smith", 1002, "Sales", 100000.0, 0.05);

    cout << "Salaried Employee Details:" << endl;
    cout << "Name: " << salariedEmployee.getName() << endl;
    cout << "Employee ID: " << salariedEmployee.getEmployeeID() << endl;
    cout << "Department: " << salariedEmployee.getDepartment() << endl;
    cout << "Annual Salary: $" << salariedEmployee.getAnnualSalary() << endl;
    cout << "Monthly Pay: $" << salariedEmployee.calculateMonthlyPay() << endl;

    cout << "\nCommission Employee Details:" << endl;
    cout << "Name: " << commissionEmployee.getName() << endl;
    cout << "Employee ID: " << commissionEmployee.getEmployeeID() << endl;
    cout << "Department: " << commissionEmployee.getDepartment() << endl;
    cout << "Total Sales: $" << commissionEmployee.getSales() << endl;
    cout << "Commission Rate: " << commissionEmployee.getCommissionRate() << endl;
    cout << "Total Pay: $" << commissionEmployee.calculateTotalPay() << endl;

    return 0;
}
