// book code (1)
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
			void putData() const
			{
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
int main()
{
	book b;
	tape t;
	b.getData();
	t.getData();
	b.putData();
	t.putData();
	cout<<"\n";
	return 0;
}