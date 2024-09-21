//date:19-5-2024
//name:ayesha imran
//regno: bsai-2023-011
//Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new
//class should add a type double data item called compensaOon, and also an enum type called period to
//indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the
//manager, scienOst, and laborer classes so they are derived from employee2 instead of employee. However,
//note that in many circumstances it might be more in the spirit of OOP to create a separate base class called
//compensaOon and three new classes manager2, scienOst2, and laborer2, and use mulOple inheritance to
//derive these three classes from the original manager, scienOst, and laborer classes and from
//compensaOon. This way none of the original classes needs to be modified

#include <iostream>
using namespace std;

// Base class Employee
class Employee {
protected:
    int empID;
public:
    Employee() {
	 empID=0; }
    void setEmpID(int id) 
	{ 
	empID = id; 
	}
    int getEmpID() const 
	{
	 return empID;
	  }
    virtual void display() const
	 {
        cout << "Employee ID: " << empID << endl;
    }
};

// Derived class Employee2
class Employee2 : public Employee {
public:
    enum Period { HOURLY, WEEKLY, MONTHLY };
private:
    double compensation;
    Period payPeriod;
public:
    Employee2() 
	{
	 compensation=0.0;
	  payPeriod=HOURLY;
	  }
    void setCompensation(double comp) 
	{ 
	compensation = comp; 
	}
    double getCompensation() const 
	{ 
	return compensation;
	 }
    void setPayPeriod(Period period) 
	{ 
	payPeriod = period;
	 }
    Period getPayPeriod() const
	 { 
	 return payPeriod; 
	 }
    void display() const override {
        Employee::display();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay Period: " << (payPeriod == HOURLY ? "Hourly" : payPeriod == WEEKLY ? "Weekly" : "Monthly") << endl;
    }
};

// Derived classes from Employee2
class Manager : public Employee2 {
public:
    void display() const override {
        cout << "Manager" << endl;
        Employee2::display();
    }
};

class Scientist : public Employee2 {
public:
    void display() const override {
        cout << "Scientist" << endl;
        Employee2::display();
    }
};

class Laborer : public Employee2 {
public:
    void display() const override {
        cout << "Laborer" << endl;
        Employee2::display();
    }
};

// Main function to demonstrate the functionality
int main() {
    Manager mgr;
    mgr.setEmpID(1);
    mgr.setCompensation(5000.0);
    mgr.setPayPeriod(Employee2::MONTHLY);

    Scientist sci;
    sci.setEmpID(2);
    sci.setCompensation(4000.0);
    sci.setPayPeriod(Employee2::WEEKLY);

    Laborer lab;
    lab.setEmpID(3);
    lab.setCompensation(1000.0);
    lab.setPayPeriod(Employee2::HOURLY);

    mgr.display();
    cout << endl;
    sci.display();
    cout << endl;
    lab.display();

    return 0;
}

