#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    string department;

public:
    Employee(const string& name, int employeeID, const string& department)
        : name(name), employeeID(employeeID), department(department) {}

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getEmployeeID() const { return employeeID; }
    void setEmployeeID(int employeeID) { this->employeeID = employeeID; }

    string getDepartment() const { return department; }
    void setDepartment(const string& department) { this->department = department; }

    void printDetails() const {
        cout << "Name: " << name << ", Employee ID: " << employeeID
                  << ", Department: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(const string& name, int employeeID, const string& department, double annualSalary)
        : Employee(name, employeeID, department), annualSalary(annualSalary) {}

    double getAnnualSalary() const { return annualSalary; }
    void setAnnualSalary(double annualSalary) { this->annualSalary = annualSalary; }

    double calculateMonthlyPay() const { return annualSalary / 12; }

    void printDetails() const {
        Employee::printDetails();
        cout << "Annual Salary: " << annualSalary << ", Monthly Pay: " << calculateMonthlyPay() << endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    CommissionEmployee(const string& name, int employeeID, const string& department, double sales, double commissionRate)
        : Employee(name, employeeID, department), sales(sales), commissionRate(commissionRate) {}

    double getSales() const { return sales; }
    void setSales(double sales) { this->sales = sales; }

    double getCommissionRate() const { return commissionRate; }
    void setCommissionRate(double commissionRate) { this->commissionRate = commissionRate; }

    double calculateTotalPay() const { return sales * commissionRate; }

    void printDetails() const {
        Employee::printDetails();
        std::cout << "Sales: " << sales << ", Commission Rate: " << commissionRate
                  << ", Total Pay: " << calculateTotalPay() << std::endl;
    }
};

int main() {
    SalariedEmployee salariedEmployee("Alice", 1001, "HR", 60000);
    salariedEmployee.printDetails();

    CommissionEmployee commissionEmployee("Bob", 1002, "Sales", 50000, 0.10);
    commissionEmployee.printDetails();

    return 0;
}
