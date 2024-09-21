//file: file eman.cpp
//date: 21-05-2024
//name: eman tahir
//reg no. 2023-bs-ai-015
//question statement:Start with the publication, book, and tape classes of Question 1. Add a base class sales that holds an array of three floats so that it can record the dollar sales of a particular publication for the last three months. Include a getdata() function to get three sales amounts from the user, and a putdata() function to display the sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data. Write a main() function to create a book object and a tape object and exercise their input/output capabilities.

#include<iostream>
using namespace std;
class publication
{
	private:
	int pageC;
	float pageT;
	float s1, s2, s3;
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
	}
};
int main ()
{
	publication p;
	p.getdata();
	p.putdata();
}
