#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    int employeeID;
    string department;
public:
    Employee(const string& n, int id, const string& dept) : name(n), employeeID(id), department(dept) {}
    string getName() const { return name; }
    int getEmployeeID() const { return employeeID; }
    string getDepartment() const { return department; }
    void setName(const string& n) { name = n; }
    void setEmployeeID(int id) { employeeID = id; }
    void setDepartment(const string& dept) { department = dept; }
};
class SalariedEmployee : public Employee {
private:
    double annualSalary;
public:
    SalariedEmployee(const string& n, int id, const string& dept, double salary) : Employee(n, id, dept), annualSalary(salary) {}
    double getAnnualSalary() const { return annualSalary; }
    void setAnnualSalary(double salary) { annualSalary = salary; }
    double calculateMonthlyPay() const { return annualSalary / 12.0; }
};
class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;
public:
    CommissionEmployee(const string& n, int id, const string& dept, double s, double rate) : Employee(n, id, dept), sales(s), commissionRate(rate) {}
    double getSales() const { return sales; }
    void setSales(double s) { sales = s; }
    double getCommissionRate() const { return commissionRate; }
    void setCommissionRate(double rate) { commissionRate = rate; }
    double calculateTotalPay() const { return sales * commissionRate; }
};
int main() {
    SalariedEmployee salariedEmp("John Doe", 1001, "Marketing", 60000.0);
    cout << "Salaried Employee Details:" << endl;
    cout << "Name: " << salariedEmp.getName() << endl;
    cout << "Employee ID: " << salariedEmp.getEmployeeID() << endl;
    cout << "Department: " << salariedEmp.getDepartment() << endl;
    cout << "Annual Salary: $" << salariedEmp.getAnnualSalary() << endl;
    cout << "Monthly Pay: $" << salariedEmp.calculateMonthlyPay() << endl;
    cout << endl;
    CommissionEmployee commissionEmp("Jane Smith", 1002, "Sales", 100000.0, 0.05);
    cout << "Commission Employee Details:" << endl;
    cout << "Name: " << commissionEmp.getName() << endl;
    cout << "Employee ID: " << commissionEmp.getEmployeeID() << endl;
    cout << "Department: " << commissionEmp.getDepartment() << endl;
    cout << "Sales: $" << commissionEmp.getSales() << endl;
    cout << "Commission Rate: " << commissionEmp.getCommissionRate() * 100 << "%" << endl;
    cout << "Total Pay: $" << commissionEmp.calculateTotalPay() << endl;
}