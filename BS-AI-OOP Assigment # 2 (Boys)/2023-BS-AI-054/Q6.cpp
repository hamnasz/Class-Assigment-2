// File: Problem 6 (Hierarchy of Employee Management system).cpp
// Date: 20-05-2024
// Name: Waleed Amjad
// Registration No: 2023-BS-AI-054

/*Design a class hierarchy for an Employee management system. The base class should be Employee with 
derived classes SalariedEmployee and CommissionEmployee. Each class should have appropriate data 
members and member functions to handle the specific attributes and behaviors of each type of employee. 
Employee: Should have data members for name, employee ID, and department. It should also have 
member functions to get and set these values. 
Salaried Employee: Inherits from Employee and adds a data member for annual Salary. It should have 
member functions to get and set the salary, and to calculate the monthly pay. 
Commission Employee: Inherits from Employee and adds data members for sales and commission Rate. It 
should have member functions to get and set these values, and to calculate the total pay based on sales 
and commission rate.   */

#include <iostream>
#include <string>
using namespace std;

class Employee{
	private:
		string Name;
		double ID;
		string Department;
		
		public:
			//initialize
			Employee(const string Name, double ID,const string Department): Name(Name) , ID(ID) , Department(Department){}
			
			//method
			string getName() const{
				return Name;
				}
				
				double getID() const{
					return ID;
				}
			    
			    string getDepartment() const{
			    	return Department;
				}
		};
					
		  class SalariedEmployee: public Employee{
		  	private:
		  		double AnnualSalary;
		  		
		  		public:
		  			//constructor to initialize 
		  			
		  			SalariedEmployee(const string Name, double ID , const string Department, double AnnualSalary):
		  				Employee(Name,ID,Department) , AnnualSalary(AnnualSalary){}
		  				
		  				//Method to calculate the monthly salary
		  				
		  				double MonthlySalary() const {
		  					return AnnualSalary/12;
						  }
		  			
		  };
		  
		  class	CommissionedEmployee: public Employee{
		  	private:
		  		double sales,Commissionrate;
		  		
		  		public:
		  			//Constructor to initialize
		  			CommissionedEmployee(const string Name, double ID , const string Department, double sales, double Commissionrate ):
		  				Employee(Name,ID,Department) , sales(sales) , Commissionrate(Commissionrate){}
		  				
		  				//Method to calculate total pay based on salaries and commmission
		  				double TotalPay() const{
		  					return sales*Commissionrate;
						  }
		  				
		  };		
		  
		  int main(){
		  	
		  	SalariedEmployee salariedemployee("Waleed",01,"AI",50000);
		  	cout<<"Name of the Employee is: "<<salariedemployee.getName()<<endl;
		  	cout<<"ID of the Employee is: "<<salariedemployee.getID()<<endl;
		  	cout<<"The Department of the employee is: "<<salariedemployee.getDepartment()<<endl;
		  	cout<<"The monthly pay of the employee is: "<<salariedemployee.MonthlySalary()<<endl;
		  	
		  	cout<<endl;
		  	
		  	CommissionedEmployee commissionedemployee("Talal",02,"CyberSecurity",2000,1.5);
		  	cout<<"The name of the employee is: "<<commissionedemployee.getName()<<endl;
		  	cout<<"The Id of the employee is: "<<commissionedemployee.getID()<<endl;
		  	cout<<"The Department of the employee is: "<<commissionedemployee.getDepartment()<<endl;
		  	cout<<"The total pay of the employee is: "<<commissionedemployee.TotalPay()<<endl;
		  	
		  	return 0;
		  }