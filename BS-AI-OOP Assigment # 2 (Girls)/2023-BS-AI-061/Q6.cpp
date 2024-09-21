//DATE:21-5-24
//NAME:AYESHA IMRAN
// REGISTRATION NO:2023-BS-AI-061
//QUESTION STATEMENT
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
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;
public:
    // Constructor
    Employee(const string& n = "", int id = 0, const string& dept = "") 
        : name(n), employeeID(id), department(dept) {}

    // Getters
    string getName() const { return name; }
    int getEmployeeID() const { return employeeID; }
    string getDepartment() const { return department; }

    // Setters
    void setName(const string& n) { name = n; }
    void setEmployeeID(int id) { employeeID = id; }
    void setDepartment(const string& dept) { department = dept; }

    // Function to display basic employee information
    void display() const {
        cout << "Name: " << name << "\nEmployee ID: " << employeeID << "\nDepartment: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    float annualSalary;
public:
    // Constructor
    SalariedEmployee(const string& n = "", int id = 0, const string& dept = "", float salary = 0.0f) 
        : Employee(n, id, dept), annualSalary(salary) {}

    // Getter and Setter for salary
    float getAnnualSalary() const { return annualSalary; }
    void setAnnualSalary(float salary) { annualSalary = salary; }

    // Function to calculate monthly pay
    float calculateMonthlyPay() const { return annualSalary / 12; }

    // Function to display salaried employee information
    void display() const {
        Employee::display();
        cout << "Annual Salary: $" << annualSalary << "\nMonthly Pay: $" << calculateMonthlyPay() << endl;
    }
};

class CommissionEmployee : public Employee {
private:
    float sales;
    float commissionRate; // in percentage
public:
    // Constructor
    CommissionEmployee(const string& n = "", int id = 0, const string& dept = "", float salesAmt = 0.0f, float rate = 0.0f) 
        : Employee(n, id, dept), sales(salesAmt), commissionRate(rate) {}

    float getSales() const { return sales; }
    void setSales(float salesAmt) { sales = salesAmt; }

    float getCommissionRate() const { return commissionRate; }
    void setCommissionRate(float rate) { commissionRate = rate; }

    float calculateTotalPay() const { return sales * (commissionRate / 100); }

    void display() const {
        Employee::display();
        cout << "Sales: $" << sales << "\nCommission Rate: " << commissionRate << "%\nTotal Pay: $" << calculateTotalPay() << endl;
    }
};

int main() {
    SalariedEmployee salariedEmp("ayesha", 12345, "Engineering", 60000);
    cout << "Salaried Employee Details:\n";
    salariedEmp.display();
    CommissionEmployee commissionEmp("amna", 54321, "Sales", 150000, 10);
    cout << "\nCommission Employee Details:\n";
    commissionEmp.display();

    return 0;
}
