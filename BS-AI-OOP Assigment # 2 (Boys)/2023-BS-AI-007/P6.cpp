#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    string department;
public:
    void getData() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cin.ignore();
        cout << "Enter department: ";
        getline(cin, department);
    }
    void putData() const {
        cout << "Name: " << name << "\nEmployee ID: " << employeeID << "\nDepartment: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;
public:
    void getData() {
        Employee::getData();
        cout << "Enter annual salary: ";
        cin >> annualSalary;
    }
    void putData() const {
        Employee::putData();
        cout << "Annual Salary: " << annualSalary << "\nMonthly Pay: " << calculateMonthlyPay() << endl;
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
    void getData() {
        Employee::getData();
        cout << "Enter sales: ";
        cin >> sales;
        cout << "Enter commission rate: ";
        cin >> commissionRate;
    }
    void putData() const {
        Employee::putData();
        cout << "Sales: " << sales << "\nCommission Rate: " << commissionRate << "\nTotal Pay: " << calculateTotalPay() << endl;
    }
    double calculateTotalPay() const {
        return sales * commissionRate;
    }
};

int main() {
    SalariedEmployee mySalariedEmployee;
    CommissionEmployee myCommissionEmployee;

    cout << "Enter data for salaried employee:\n";
    mySalariedEmployee.getData();
    cout << "\nEnter data for commission employee:\n";
    myCommissionEmployee.getData();

    cout << "\nSalaried Employee data:\n";
    mySalariedEmployee.putData();
    cout << "\nCommission Employee data:\n";
    myCommissionEmployee.putData();

    return 0;
}
