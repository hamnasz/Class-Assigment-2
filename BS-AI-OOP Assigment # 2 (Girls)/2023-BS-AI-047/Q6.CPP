// File: PROGRAM6.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/*
Design a class hierarchy for an Employee management system. The base class should be Employee with 
derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
members and member funcƟons to handle the specific aƩributes and behaviors of each type of employee.
Employee: Should have data members for name, employee ID, and department. It should also have 
member funcƟons to get and set these values.
Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
member funcƟons to get and set the salary, and to calculate the monthly pay.
Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
should have member funcƟons to get and set these values, and to calculate the total pay based on sales 
and commission rate.
*/

#include <iostream>
using namespace std;
class Employee {
protected:
  string name;
  int employeeID;
  string department;

public:
  Employee(const string& name, int employeeID, const string& department) :
      name(name), employeeID(employeeID), department(department) {}

  // Getters
  const string& getName() const { return name; }
  int getEmployeeID() const { return employeeID; }
  const string& getDepartment() const { return department; }

  // Setters
  void setName(const string& name) { this->name = name; }
  void setEmployeeID(int employeeID) { this->employeeID = employeeID; }
  void setDepartment(const string& department) { this->department = department; }
};

class SalariedEmployee : public Employee {
private:
  double annualSalary;

public:
  SalariedEmployee(const string& name, int employeeID, const string& department, double annualSalary) :
      Employee(name, employeeID, department), annualSalary(annualSalary) {}

  // Getters
  double getAnnualSalary() const { return annualSalary; }

  // Setters
  void setAnnualSalary(double annualSalary) { this->annualSalary = annualSalary; }

  // Calculate monthly pay
  double calculateMonthlyPay() const {
    return annualSalary / 12.0;
  }
};

class CommissionEmployee : public Employee {
private:
  double sales;
  double commissionRate;

public:
  CommissionEmployee(const string& name, int employeeID, const string& department, double sales, double commissionRate) :
      Employee(name, employeeID, department), sales(sales), commissionRate(commissionRate) {}

  // Getters
  double getSales() const { return sales; }
  double getCommissionRate() const { return commissionRate; }

  // Setters
  void setSales(double sales) { this->sales = sales; }
  void setCommissionRate(double commissionRate) { this->commissionRate = commissionRate; }

  // Calculate total pay
  double calculateTotalPay() const {
    return sales * commissionRate;
  }
};

int main() {
  SalariedEmployee salariedEmployee("John Doe", 12345, "Engineering", 100000.0);
  CommissionEmployee commissionEmployee("Jane Smith", 54321, "Sales", 10000.0, 0.1);

  cout << "Salaried Employee Details:" << endl;
  cout << "  Name: " << salariedEmployee.getName() << endl;
  cout << "  Employee ID: " << salariedEmployee.getEmployeeID() << endl;
  cout << "  Department: " << salariedEmployee.getDepartment() << endl;
  cout << "  Monthly Pay: $" << salariedEmployee.calculateMonthlyPay() << endl;

  cout << "\nCommission Employee Details:" << endl;
  cout << "  Name: " << commissionEmployee.getName() << endl;
  cout << "  Employee ID: " << commissionEmployee.getEmployeeID() << endl;
  cout << "  Department: " << commissionEmployee.getDepartment() << endl;
  cout << "  Total Pay: $" << commissionEmployee.calculateTotalPay() << endl;

  return 0;
}


