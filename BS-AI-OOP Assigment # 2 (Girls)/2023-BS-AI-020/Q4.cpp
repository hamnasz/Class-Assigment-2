// File: 4_employee.cpp
// Date: 19-05-2024
// Name: Mishal Nadeem
// Registration No: 2023-BS-AI-020

/*Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new class should add a type double data item called compensaƟon, and also an enum type called period to
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the manager, scienƟst, and laborer classes so they are derived from employee2 instead of employee. However,
note that in many circumstances it might be more in the spirit of OOP to create a separate base class called compensaƟon and three new classes manager2, scienƟst2, and laborer2, and use mulƟple inheritance to
derive these three classes from the original manager, scienƟst, and laborer classes and from compensaƟon. This way none of the original classes needs to be modifie*/
#include <iostream>
using namespace std;

class employee
{
public:
    string name;
    double compensation;
    enum period
    {
        hourly,
        weekly,
        monthly
    };
    period p;
    virtual void getdata()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter compensation:";
        cin >> compensation;
        int periodInput;
        cout << "Enter period [hourly=0, weekly=1, monthly=2]: ";
        cin >> periodInput;

        // Validate input and set the period enum
        if (periodInput >= 0 && periodInput <= 2)
        {
            p = static_cast<period>(periodInput);
        }
        else
        {
            cout << "Invalid input! Defaulting to hourly." << endl;
            p = hourly;
        }
    }
    virtual void putdata()
    {
        cout << "Name:" << name << endl;
        cout << "Compensation:" << compensation << endl;
        cout << "Time period:" << p << endl;
    }
};
class labourer : public employee
{
public:
    string site;
    void getdata() override
    {
        employee::getdata();
        cout << "Enter site name:";
        cin >> site;
    }

    void putdata() override
    {
        employee::putdata();
        cout << "Site:" << site;
    }
};
class scientist : public employee
{
public:
    string lab;
    void getdata() override
    {
        employee::getdata();
        cout << "Enter lab name:";
        cin >> lab;
    }

    void putdata() override
    {
        employee::putdata();
        cout << "Lab:" << lab;
    }
};
class manager : public employee
{
public:
    string company;
    void getdata() override
    {
        employee::getdata();
        cout << "Enter company name:";
        cin >> company;
    }

    void putdata() override
    {
        employee::putdata();
        cout << "Company:" << company;
    }
};
int main()
{
    labourer l;
    scientist s;
    manager m;

    cout << "Enter data for labourer:" << endl;
    l.getdata();
    cout << "\nDetails for labourer:" << endl;
    l.putdata();

    cout << "\nEnter data for scientist:" << endl;
    s.getdata();
    cout << "\nDetails for scientist:" << endl;
    s.putdata();

    cout << "\nEnter data for manager:" << endl;
    m.getdata();
    cout << "\nDetails for manager:" << endl;
    m.putdata();
    return 0;
}