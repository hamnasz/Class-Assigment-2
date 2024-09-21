// File: Program4.cpp
// Date: 05-22-2024
// Name: Muhammad Tayyab Imran
// Registration No: 2023-BS-AI-2023
// Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new class should add a type double data item called compensa..on, and also an enum type called period to indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the manager, scien..st, and laborer classes so they are derived from employee2 instead of employee. However, note that in many circumstances it might be more in the spirit of OOP to create a separate base class called compensa..on and three new classes manager2, scien..st2, and laborer2, and use mul..ple inheritance to derive these three classes from the original manager, scientist, and laborer classes and from compensayion. This way none of the original classes needs to be modified
#include <iostream>
using namespace std;

// Base class for Compensation
class Compensation 
{
protected:
    double compensation; // Compensation amount
    char period; // Period for compensation (h for hourly, w for weekly, m for monthly)

public:
    // Constructor to input compensation and period
    Compensation() 
    {
        cout<<"Enter Compensation: ";
        cin>>compensation;
        cout<<"Enter Period(h for Hourly, w for Weekly, m for Monthly): ";
        cin>>period;
    }

    // Function to display compensation details
    void display() const
    {
        cout << "Compensation: " << compensation << " per ";
        switch (period)
        {
            case 'h':
                cout<<"Hour";
                break;
            case 'w':
                cout<<"Week";
                break;
            case 'm':
                cout<<"Month";
                break;
        }
        cout << endl;
    }
};

// Base class for Employee
class Employee 
{
protected:
    string name; // Name of the employee
    int id; // ID of the employee
    
public:
    // Constructor to input name and ID of the employee
    Employee() 
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter ID: ";
        cin>>id;
    }

    // Function to display employee details
    void display() const 
    {
        cout << "\nName: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

// Derived class for Manager inheriting from Employee
class Manager : public Employee 
{
public:
    Manager() {}
    void display() const
    {
        Employee::display();
    }
};

// Derived class for Scientist inheriting from Employee
class Scientist : public Employee 
{
public:
    Scientist() {}
    void display() const
    {
        Employee::display();
    }
};

// Derived class for Laborer inheriting from Employee
class Laborer : public Employee 
{
public:
    Laborer() {}
    void display() const
    {
        Employee::display();
    }
};

// Derived class for Manager2 inheriting from Manager and Compensation
class Manager2 : public Manager, public Compensation
{
public:
    Manager2() {}
    void display()
    {
        Manager::display();
        Compensation::display();
    }
};

// Derived class for Scientist2 inheriting from Scientist and Compensation
class Scientist2 : public Scientist, public Compensation
{
public:
    Scientist2() {}
    void display()
    {
        Scientist::display();
        Compensation::display();
    }
};

// Derived class for Laborer2 inheriting from Laborer and Compensation
class Laborer2 : public Laborer, public Compensation
{
public:
    Laborer2() {}
    void display()
    {
        Laborer::display();
        Compensation::display();
    }
};

// Main function
int main() 
{
    cout<<"Enter Manager Info"<<endl;
    Manager2 manager; // Object for Manager2 class
    cout<<"\nEnter Scientist Info"<<endl;
    Scientist2 scientist; // Object for Scientist2 class
    cout<<"\nEnter Laborer Info"<<endl;
    Laborer2 laborer; // Object for Laborer2 class

    manager.display(); // Display manager info
    scientist.display(); // Display scientist info
    laborer.display(); // Display laborer info

    return 0;
}