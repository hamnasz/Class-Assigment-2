#include<iostream>
#include<string>
using namespace std;

class employee{
	private:
		int num;
	protected:
		string name;
		long id;
		char type;
		
		public:
			void employeedata(){
				cout<<"enter name :"<<endl;
				cin>>name;
				cout<<"enter id: "<<endl;
				cin>>id;
				cout<<"enter type (M , S , L)"<<endl;
				cin>>type;
			}
			void displayemployee(){
				cout<<"name:"<<name<<endl;
				cout<<"id:"<<id<<endl;
				cout<<"type:"<<type<<endl;
			}
};

class employee2 : public employee {
	protected :
		double compensation;
		enum class period {hourly,weekly,monthly} period;
		char periodtype;
		public:
			void getemployee2(){
				employee::employeedata();
				cout<<"emplyees compesation:"<<endl;
				cin>>compensation;
				
				switch(periodtype){
					case 'H':
					case 'h':
					   period = period::hourly;
					   break;
					case 'W':
					case 'w':
					   period = period::weekly;
					   break;
					case 'M':
					case 'm':
					   period = period::monthly;
					   break;
					   
					   
				    default:
					cout <<"invalid!"<<endl;
					period = period::hourly;
					break;	         	
				}
			}
			void putemployee2(){
				employee::displayemployee();
				cout<<"compensation: $"<<compensation<<endl;
				
				switch(period){
					case period::hourly:
                cout << "Pay Period: Hourly" << endl;
                break;
            case period::weekly:
                cout << "Pay Period: Weekly" << endl;
                break;
            case period::monthly:
                cout << "Pay Period: Monthly" << endl;
                break;
            }
		}
};

class manager: public employee2{};
class scientist : public employee2{};
class labour : public employee2{};


int main(){
	manager m;
	scientist s;
	labour l;
	
	cout << "enter manager data: "<<endl;
	m.getemployee2();
	
	
	cout<<"enter scientist data:"<<endl;
	s.getemployee2();

	
	cout<<"enter labour data:"<<endl;
	l.getemployee2();
	
	cout<<"____________________________________________"<<endl;
	cout<<"manager's details:  ";
	m.putemployee2();
	
	cout<<"____________________________________________"<<endl;
	cout<<"scientist details:";
	s.putemployee2();
	
	cout<<"____________________________________________"<<endl;
	cout<<"labour details:";
	l.putemployee2();
	
}