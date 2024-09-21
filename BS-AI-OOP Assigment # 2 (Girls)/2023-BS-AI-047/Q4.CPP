// File: PROGRAM4.cpp
// Date: 22-05-2024
// Name: LAIBA FATIMA
// Registration No: 2023-BS-AI-047
// Question Statement:
/* Derive a class called employee2 from the employee class in the EMPLOY program in this chapter. This new 
class should add a type double data item called compensaƟon, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity you can change the 
manager, scienƟst, and laborer classes so they are derived from employee2 instead of employee. However, 
note that in many circumstances it might be more in the spirit of OOP to create a separate base class called 
compensaƟon and three new classes manager2, scienƟst2, and laborer2, and use mulƟple inheritance to 
derive these three classes from the original manager, scienƟst, and laborer classes and from 
compensaƟon. This way none of the original classes needs to be modified
 */
#include <iostream>
using namespace std;
enum class Period { HOURLY, WEEKLY, MONTHLY, YEARLY };

class Employee {
protected:
  string name;
  int hireDate; // Can be a more complex date struct if needed

public:
  Employee(const string& name, int hireDate) : name(name), hireDate(hireDate) {}
  virtual void display() const {
    cout << "Name: " << name << endl;
    cout << "Hire Date: " << hireDate << endl;
  }
};

class Compensation {
protected:
  double compensation;
  Period period;

public:
  Compensation(double compensation, Period period) : compensation(compensation), period(period) {}
  void displayCompensation() const {
    cout << "Compensation: $" << compensation << " ";
    switch (period) {
      case Period::HOURLY:
        cout << "(hourly)" << endl;
        break;
      case Period::WEEKLY:
        cout << "(weekly)" << endl;
        break;
      case Period::MONTHLY:
        cout << "(monthly)" << endl;
        break;
      case Period::YEARLY:
        cout << "(yearly)" << endl;
        break;
    }
  }
};

class Manager2 : public Employee, public Compensation {
public:
  Manager2(const string& name, int hireDate, double compensation, Period period) :
      Employee(name, hireDate), Compensation(compensation, period) {}
  void display() const override {
    Employee::display();
    cout << "**Manager**" << endl;
    displayCompensation();
  }
};

class Scientist2 : public Employee, public Compensation {
public:
  Scientist2(const string& name, int hireDate, double compensation, Period period) :
      Employee(name, hireDate), Compensation(compensation, period) {}
  void display() const override {
    Employee::display();
    cout << "**Scientist**" << endl;
    displayCompensation();
  }
};

class Laborer2 : public Employee, public Compensation {
public:
  Laborer2(const string& name, int hireDate, double compensation, Period period) :
      Employee(name, hireDate), Compensation(compensation, period) {}
  void display() const override {
    Employee::display();
    cout << "**Laborer**" << endl;
    displayCompensation();
  }
};

int main() {
  Manager2 manager("LAIBA FATIMA", 20200101, 80000.0, Period::MONTHLY);
  Scientist2 scientist("MARIA SIDDIQUE", 20180715, 120000.0, Period::YEARLY);
  Laborer2 laborer("AMINA AZIZ", 20230510, 18.0, Period::HOURLY);

  manager.display();
  scientist.display();
  laborer.display();

  return 0;
}
