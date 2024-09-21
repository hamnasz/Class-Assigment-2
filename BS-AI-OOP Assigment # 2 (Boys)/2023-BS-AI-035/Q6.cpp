#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;

public:
    // Constructor
    Employee(const string& n, int id, const string& dept) 
        : name(n), employeeID(id), department(dept) {}

    // Member functions to get and set the values
    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setEmployeeID(int id) {
        employeeID = id;
    }

    int getEmployeeID() const {
        return employeeID;
    }

    void setDepartment(const string& dept) {
        department = dept;
    }

    string getDepartment() const {
        return department;
    }

    // Virtual function to be overridden by derived classes
    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};
class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    // Constructor
    SalariedEmployee(const string& n, int id, const string& dept, double salary) 
        : Employee(n, id, dept), annualSalary(salary) {}

    // Member functions to get and set the salary
    void setAnnualSalary(double salary) {
        annualSalary = salary;
    }

    double getAnnualSalary() const {
        return annualSalary;
    }

    // Function to calculate the monthly pay
    double calculateMonthlyPay() const {
        return annualSalary / 12;
    }

    // Override displayDetails to include salary information
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Monthly Pay: $" << calculateMonthlyPay() << endl;
    }
};
class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    // Constructor
    CommissionEmployee(const string& n, int id, const string& dept, double s, double rate) 
        : Employee(n, id, dept), sales(s), commissionRate(rate) {}

    // Member functions to get and set sales and commission rate
    void setSales(double s) {
        sales = s;
    }

    double getSales() const {
        return sales;
    }

    void setCommissionRate(double rate) {
        commissionRate = rate;
    }

    double getCommissionRate() const {
        return commissionRate;
    }

    // Function to calculate the total pay
    double calculateTotalPay() const {
        return sales * commissionRate;
    }

    // Override displayDetails to include sales and commission information
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Sales: $" << sales << endl;
        cout << "Commission Rate: " << commissionRate * 100 << "%" << endl;
        cout << "Total Pay: $" << calculateTotalPay() << endl;
    }
};
int main() {
    // Creating a SalariedEmployee object
    SalariedEmployee salariedEmp("John Doe", 101, "Finance", 60000);
    cout << "Salaried Employee Details:" << endl;
    salariedEmp.displayDetails();

    // Creating a CommissionEmployee object
    CommissionEmployee commissionEmp("Jane Smith", 102, "Sales", 150000, 0.10);
    cout << "\nCommission Employee Details:" << endl;
    commissionEmp.displayDetails();

    return 0;
}

 
