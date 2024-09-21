#include <iostream>
#include <string>

using namespace std;

class Employee {
  private:
    string name;
    int employeeID;
    string department;
  
  public:
    Employee(string name, int employeeID, string department) {
        this->name = name;
        this->employeeID = employeeID;
        this->department = department;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getEmployeeID() {
        return employeeID;
    }

    void setEmployeeID(int employeeID) {
        this->employeeID = employeeID;
    }

    string getDepartment() {
        return department;
    }

    void setDepartment(string department) {
        this->department = department;
    }
};

class SalariedEmployee : public Employee {
  private:
    double annualSalary;
  
  public:
    SalariedEmployee(string name, int employeeID, string department, double annualSalary)
    : Employee(name, employeeID, department) {
        this->annualSalary = annualSalary;
    }

    double getAnnualSalary() {
        return annualSalary;
    }

    void setAnnualSalary(double annualSalary) {
        this->annualSalary = annualSalary;
    }

    double calculateMonthlyPay() {
        return annualSalary / 12;
    }
};

class CommissionEmployee : public Employee {
  private:
    double sales;
    double commissionRate;
  
  public:
    CommissionEmployee(string name, int employeeID, string department, double sales, double commissionRate)
    : Employee(name, employeeID, department) {
        this->sales = sales;
        this->commissionRate = commissionRate;
    }

    double getSales() {
        return sales;
    }

    void setSales(double sales) {
        this->sales = sales;
    }

    double getCommissionRate() {
        return commissionRate;
    }

    void setCommissionRate(double commissionRate) {
        this->commissionRate = commissionRate;
    }

    double calculateTotalPay() {
        return sales * commissionRate;
    }
};

int main() {
    SalariedEmployee salariedEmp("Rizwan Saleem", 12345, "Sales", 50000.0);
    CommissionEmployee commissionEmp("Hasaan Rizwan", 67890, "Marketing", 30000.0, 0.05);
    
    cout << "Salaried Employee:" << endl;
    cout << "Name: " << salariedEmp.getName() << endl;
    cout << "Employee ID: " << salariedEmp.getEmployeeID() << endl;
    cout << "Department: " << salariedEmp.getDepartment() << endl;
    cout << "Annual Salary: $" << salariedEmp.getAnnualSalary() << endl;
    cout << "Monthly Pay: $" << salariedEmp.calculateMonthlyPay() << endl;

    cout << endl;

    cout << "Commission Employee:" << endl;
    cout << "Name: " << commissionEmp.getName() << endl;
    cout << "Employee ID: " << commissionEmp.getEmployeeID() << endl;
    cout << "Department: " << commissionEmp.getDepartment() << endl;
    cout << "Sales: $" << commissionEmp.getSales() << endl;
    cout << "Commission Rate: " << commissionEmp.getCommissionRate() << endl;
    cout << "Total Pay: $" << commissionEmp.calculateTotalPay() << endl;
    
    return 0;
}