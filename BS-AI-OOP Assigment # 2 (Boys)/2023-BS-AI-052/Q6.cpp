// muhmmd zain 052
#include <iostream>
#include <string>
 using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;

public:
    Employee(string n, int id, string dept) : name(n), employeeID(id), department(dept) {}

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
    SalariedEmployee(string n, int id, string dept, double salary) : Employee(n, id, dept), annualSalary(salary) {}

    double getAnnualSalary() const { return annualSalary; }
    double calculateMonthlyPay() const { return annualSalary / 12; }

    void setAnnualSalary(double salary) { annualSalary = salary; }
};

class CommissionEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    CommissionEmployee(string n, int id, string dept, double sales, double rate) : Employee(n, id, dept), sales(sales), commissionRate(rate) {}

    double getSales() const { return sales; }
    double getCommissionRate() const { return commissionRate; }
    double calculateTotalPay() const { return sales * commissionRate; }

    void setSales(double s) { sales = s; }
    void setCommissionRate(double rate) { commissionRate = rate; }
};

int main() {
    SalariedEmployee salariedEmp("John Doe", 101, "Sales", 50000.0);
    CommissionEmployee commissionEmp("Jane Smith", 102, "Marketing", 10000.0, 0.1);

    cout << "Salaried Employee: " << salariedEmp.getName() << endl;
    cout << "Monthly Pay: " << salariedEmp.calculateMonthlyPay() << endl;

    cout << "Commission Employee: " << commissionEmp.getName() << endl;
    cout << "Total Pay: " << commissionEmp.calculateTotalPay() << endl;

    return 0;
}
