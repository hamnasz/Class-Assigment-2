//employee code (6)
//20-05-2024
//Yumna Irfan
//2023-bs-ai-021

#include<iostream>
using namespace std;

class employee 
{
private:
    string name, department;
    int empID;
public:
    void getdata() 
	{
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee department: ";
        cin >> department;
        cout << "Enter employee ID: ";
        cin >> empID;
    }
    void putdata() 
	{
        cout << "employee name: " << name << endl;
        cout << "employee department: " << department << endl;
        cout << "employee ID: " << empID << endl;
    }
};

class salariedemployee : public employee 
{
private:
    int salary;
public:
    void getdata() 
	{
        cout << "Enter employee salary: ";
        cin >> salary;
    }
    void putdata() 
	{
        cout << "employee salary: " << salary << endl;
    }
};

class commissionedemployee : public employee 
{
private:
    int salary;
    float commissionrate;
public:
    void getdata() 
	{
        cout << "Enter employee salary: ";
        cin >> salary;
        cout << "Enter employee commission rate: ";
        cin >> commissionrate;
    }
    void putdata() 
	{
        float commission = (salary * commissionrate) / 100;
        float totalSalary = salary + commission;
        cout << "employee salary after commission: " << totalSalary << endl;
    }
};

int main() 
{
    salariedemployee s;
    commissionedemployee c;
    s.getdata();
    s.getdata();
    c.getdata();
    s.putdata();
    s.putdata();
    c.putdata();
    return 0;
}