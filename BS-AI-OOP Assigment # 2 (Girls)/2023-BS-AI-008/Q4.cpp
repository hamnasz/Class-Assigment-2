//Assignment 2
//Mohammad Mukedas
//2023-BSAI-008
//PROGRAM 4
#include <iostream>
using namespace std;
 
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
       cout << "Pay Period: " << (payPeriod == HOURLY  ?"Hourly" : payPeriod == WEEKLY ? "Weekly" : "Monthly") << endl;
   }
};
 
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
 
int main() {
   Manager m;
   m.setEmpID(1);
   m.setCompensation(2000.0);
   m.setPayPeriod(Employee2::MONTHLY);
 
   Scientist s;
   s.setEmpID(2);
   s.setCompensation(8000.0);
   s.setPayPeriod(Employee2::WEEKLY);
 
   Laborer l;
   l.setEmpID(3);
   l.setCompensation(5000.0);
   l.setPayPeriod(Employee2::HOURLY);
 
   m.display();
   cout << endl;
   s.display();
   cout << endl;
   l.display();
 
   return 0;
}
