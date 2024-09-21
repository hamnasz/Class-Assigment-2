/*  File: Q4.cpp
    Date: 19-05-2024
    Name: Humna Imran
    Registration No: 2023-BS-AI-017

    Question Statement
      Derive a class called employee2 from the 
      employee class in the EMPLOY program in 
      this chapter. This new class should add 
      a type double data item called 
      compensation, and also an enum type 
      called period to indicate whether the 
      employee is paid hourly, weekly, or 
      monthly. For simplicity you can change 
      the manager, scienOst, and laborer 
      classes so they are derived from 
      employee2 instead of employee. However,
      note that in many circumstances it 
      might be more in the spirit of OOP to 
      create a separate base class called
      compensation and three new classes
      manager2, scientist2, and laborer2,
      and use mulOple inheritance to derive
      these three classes from the original
      manager, scientist, and laborer classes
      and from compensation. This way none of
      the original classes needs to be modified
*/

#include <iostream>
#include <string>

using namespace std;

// Base class
class compensation
{
protected:
    double compensation;

    enum class Period
    {
        hourly,
        weekly,
        monthly
    }

    period;

public:
    void getCompensationData()
    {

        cout << "Enter compensation: ";
        cin >> compensation;

        cout << "Select period:" << endl
             << "0. Hourly" << endl
             << "1. Weekly" << endl
             << "2. Monthly" << endl;

        int periodChoice;
        cin >> periodChoice;

        switch (periodChoice)
        {
        case 0:
            period = Period::hourly;
            break;
        case 1:
            period = Period::weekly;
            break;
        case 2:
            period = Period::monthly;
            break;
        default:
            cout << "Invalid choice. Setting period to hourly by default." << endl;
            period = Period::hourly;
        }
    }

    void putCompensationData() const
    {

        cout << "Compensation: " << compensation << endl;

        cout << "Period: ";
        switch (period)
        {
        case Period::hourly:
            cout << "Hourly";
            break;
        case Period::weekly:
            cout << "Weekly";
            break;
        case Period::monthly:
            cout << "Monthly";
            break;
        default:
            cout << "Unknown";
        }
        cout << endl;
    }
};

// Original employee class
class employee
{
protected:
    string name;
    long number;

public:
    void getdata()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class manager2 : public employee, public compensation
{
private:
    string title;
    int dues;

public:
    void getdata()
    {
        employee::getdata();

        cout << "Enter title: ";
        cin >> title;
        cout << "Enter dues: ";
        cin >> dues;
    }

    void putdata() const
    {
        employee::putdata();

        cout << "Title: " << title << "\n";
        cout << "Dues: " << dues << "\n";
    }
};

class scientist2 : public employee, public compensation
{
private:
    int publications;

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of publications: ";
        cin >> publications;
    }

    void putdata() const
    {
        employee::putdata();
        cout << "Publications: " << publications << "\n";
    }
};

class laborer2 : public employee, public compensation {};

int main()
{
    manager2 m;
    scientist2 s;
    laborer2 l;

    cout << "Enter manager data:" << endl;
    m.getdata();
    m.getCompensationData();

    cout << "\nManager data:" << endl;
    m.putdata();
    m.putCompensationData();

    cout << "\nEnter scientist data:" << endl;
    s.getdata();
    s.getCompensationData();

    cout << "\nScientist data:" << endl;
    s.putdata();
    s.putCompensationData();

    cout << "\nEnter laborer data:" << endl;
    l.getdata();
    l.getCompensationData();

    cout << "\nLaborer data:" << endl;
    l.putdata();
    l.putCompensationData();

    return 0;
}
