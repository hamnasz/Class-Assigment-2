#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    string department;

public:
    void getData() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee department: ";
        cin >> department;
    }

    void showData() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Employee Department: " << department << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlyPay;

public:
    void getData() {
        Employee::getData();
        cout << "Enter the monthly salary for the employee: ";
        cin >> monthlyPay;
    }

    void showData() const {
        Employee::showData();
        cout << "Monthly Salary: " << monthlyPay << endl;
        cout << "Annual Salary: " << monthlyPay * 12 << endl;
    }
};

class CommissionedEmployee : public Employee {
private:
    double sales;
    double commissionRate;

public:
    void getData() {
        Employee::getData();
        cout << "Enter the sales amount for the employee: ";
        cin >> sales;
        cout << "Enter the commission rate (as a decimal, e.g., 0.10 for 10%): ";
        cin >> commissionRate;
    }

    void showData() const {
        Employee::showData();
        double totalPay = sales * commissionRate;
        cout << "Sales: " << sales << endl;
        cout << "Commission Rate: " << commissionRate * 100 << "%" << endl;
        cout << "Total Pay: " << totalPay << endl;
    }
};

int main() {
    cout << "-------------The details for salaried employee are as follows:-------------" << endl;
    SalariedEmployee salariedEmp;
    salariedEmp.getData();
    cout << "------------------------------------" << endl;
    salariedEmp.showData();

    cout << "------------------------------------" << endl;

    cout << "-------------The details for commissioned employee are as follows:-------------" << endl;
    CommissionedEmployee commissionedEmp;
    commissionedEmp.getData();
    cout << "------------------------------------" << endl;
    commissionedEmp.showData();

    return 0;
}
