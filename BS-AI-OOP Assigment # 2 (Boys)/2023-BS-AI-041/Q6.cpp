#include <iostream>
using namespace std;

class Employee {
	public:
		string name;
		int empID;
		string department;
		
		void getVal(){
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Employee ID: ";
			cin>>empID;
			cout<<"Enter Department: ";
			cin>>department;
		}
};

class SalariedEmployee : public Employee{
	public:
		double annualSal;
		double monthSal;
		void getVal(){
			Employee::getVal();
			cout<<"Enter Annual Salary: ";
			cin>>annualSal;
		}
		double monPay(){
			monthSal = annualSal/12;
			cout<<"\nYour monthly Salary: "<<monthSal<<endl;
		}
};

class CommissionEmployee : public Employee{
	public:
		double sales;
		double commRate;
		double comSal;
		
		void getVal(){
			Employee::getVal();
			cout<<"Enter Sales: ";
			cin>>sales;
			cout<<"Enter Commision Rate: ";
			cin>>commRate;
		}
		
		double commPay(){
			comSal = sales * (commRate/100);
			cout<<"\nYour Total Pay: "<<comSal<<endl;
		}
};

int main() {
	SalariedEmployee s1;
	cout<<"Salaried Employee Data: "<<endl;
	s1.getVal();
	s1.monPay();
	
	cout<<"\nCommisioned Employee Data: "<<endl;
	CommissionEmployee c1;
	c1.getVal();
	c1.commPay();
}
	