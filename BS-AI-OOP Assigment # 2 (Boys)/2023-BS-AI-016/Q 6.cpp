#include<iostream>
using namespace std;
class Employee
{
    protected:
    string name;
    int id;
    string department;

    public:
    void getInfo()
    {
        cout<<"Enter the  Name of Employee : ";
        cin>>name;
        cout<<"Enter the Id of Employee : ";
        cin>>id;
        cout<<"Enter the of Department Employee : ";
        cin>>department;
    }
    void setInfo()
    {
        cout<<"The name of Employee is: "<<name<<endl;
        cout<<"The Id of Employee is: "<<id<<endl;
        cout<<"The Department of Employee is: "<<department<<endl;
    }
};
class SalariedEmployee : public Employee
{
    private:
    double annualSalary;
    double monthlySalary;

    public:
    void getInfo()
    {
        Employee::getInfo();
        cout<<"Enter Employee Annual Salary: ";
        cin>>annualSalary;
    }
    void calculate()
    {
        monthlySalary = annualSalary / 12;
    }
    void setInfo()
    {
        Employee::setInfo();
        cout<<"Annual Salary of employee is: "<<annualSalary<<endl;
        cout<<"Monthly Salary of employee is: "<<monthlySalary<<endl;
    }
};
class CommisionEmployee : public Employee
{
    private:
    double sales;
    double commissionRate;
    double totalSalary;

    public:
    void getInfo()
    {
        Employee::getInfo();
        cout<<"Enter Sales: ";
        cin>>sales;
        cout<<"Enter Commission Rate: ";
        cin>>commissionRate;
    }
    void calculate()
    {
        Employee::setInfo();
        totalSalary = sales * commissionRate;
    }
    void setInfo()
    {
        cout<<"Total Salary: "<<totalSalary<<endl;
    }
};
int main()
{
    SalariedEmployee obj1;
    obj1.getInfo();
    obj1.calculate();
    cout<<"\nSalaried Employee Info"<<endl;
    obj1.setInfo();

    CommisionEmployee obj2;
    obj2.getInfo();
    obj2.calculate();
    cout<<"Commission Employee Info"<<endl;
    obj2.setInfo();
    return 0;
}