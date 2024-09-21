//file: file eman.cpp
//date: 21-05-2024
//name: eman tahir
//reg no. 2023-bs-ai-015
//question statement: Assume that the publisher in Question 1 and 3 decides to add a third way to distribute books: on computer disk, for those who like to do their reading on their laptop. Add a disk class that, like book and tape, is derived from publication. The disk class should incorporate the same member functions as the other classes. The data item unique to this class is the disk type: either CD or DVD. You can use an enum type to store this item. The user could select the appropriate type by typing c or d.


#include<iostream>
using namespace std;
class publication
{
	private:
	int pageC;
	float pageT;
	float s1, s2, s3;
	string type;
	public:
	string title;
	float price;
	int book()
	{
		int pageC;
	}
	int tape()
	{
		float pageT;
	}
	int sales()
	{
		float s1;
		float s2;
		float s3;
	}
	int disk()
	{
		string type;
	}
	int getdata()
	{
		cout<<"enter title of book: ";
		cin>>title;
		cout<<"enter price of book: ";
		cin>>price;
		cout<<"enter number of pages: ";
		cin>>pageC;
		cout<<"enter time in minutes: ";
		cin>>pageT;
		cout<<"sales amount in first month: ";
		cin>>s1;
		cout<<"sales amount in second month: ";
		cin>>s2;
		cout<<"sales amount in third month: ";
		cin>>s3;
		cout<<"enter c for CD type and d for DVD type: ";
		cin>>type;
	}
	int putdata()
	{
		cout<<"publications detail:"<<endl;
		cout<<"title: "<<title<<endl;
		cout<<"price: "<<price<<" Rs"<<endl;
		cout<<"number of pages: "<<pageC<<endl;
		cout<<"playing time: "<<pageT<<" minutes"<<endl;
		cout<<"sales amount in first three month:"<<endl;	
		cout<<"sales amount in first month: "<<s1<<"%"<<endl;
		cout<<"sales amount in second month: "<<s2<<"%"<<endl;
		cout<<"sales amount in third month: "<<s3<<"%"<<endl;
		cout<<"the disk type u wanted is: "<<type<<"type"<<endl;
	}
};
int main ()
{
	publication p;
	p.getdata();
	p.putdata();
}
