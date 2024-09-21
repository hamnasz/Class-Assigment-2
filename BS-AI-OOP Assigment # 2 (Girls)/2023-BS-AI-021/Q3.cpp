// cd dvd code 
//20-05-2024
//Yumna Irfan
//2023-bs-ai-021

#include<iostream>
using namespace std;

class publication //parent class
{
	private:
		float price;
		string title;
		
		public:
		void getData()
		{
			cout<<"Enter the price: "<<endl;
			cin>>price;
			cout<<"Enter the title: "<<endl;
			cin>>title;
		}
		void putData()
		{
			cout<<"\nprice: "<<title;
			cout<<"\ntitle: "<<price;
		}
};
class book : private publication //child class 1
{
	private:
		int pages;
		
		public:
			void getData()
			{
				publication :: getData();
				cout<<"Enter number of pages: "<<endl;
				cin>>pages;
			}
			void putData() 
			{
				publication :: getData();
				cout<<"\npages: "<<pages;
			}
};
class tape : private publication //child class 2
{
	private:
		float time;
		
		public:
		void getData()
		{
			publication :: getData();
			cout<<"Enter playing time in mins: "<<endl;
			cin>>time;
		}
		void putData() 
		{
			publication :: putData();
			cout<<"\nplaying time in mins: "<<time;
		}
};
class disk : private publication  // child class 3
{
	private:
		enum diskType {DVD , CD} diskType;
		public:
			void getData()
			{
				publication :: getData();
				char type;
				cout<<"Enter disk type (d for DVD , c for CD): ";
				cin>>type;
				if(type == 'd' || type == 'D')
				diskType = DVD;
				else if(type == 'c' || type == 'C')
				diskType = CD;
			}
			void putData() 
			{
				publication :: putData();
				cout<<"\ndisk type: "<<(diskType == DVD ? "DVD" : "CD");
			}
};
int main()
{
    book b;
    tape t;
    disk d;
    
    cout << "Enter book details:" << endl;
    b.getData();
    
    cout << "Enter tape details:" << endl;
    t.getData();
    
    cout<<"enter disk details: "<<endl;
    d.getData();
    
    cout << "\nBook details:" << endl;
    b.putData();
    
    cout << "\nTape details:" << endl;
    t.putData();
    
    cout<<"\nDisk details:"<<endl;
    d.putData();
    
    cout << "\n";
    return 0;
}