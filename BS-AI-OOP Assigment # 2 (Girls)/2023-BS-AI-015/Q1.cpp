//file: file eman.cpp
//date: 21-05-2024
//name: eman tahir
//reg no. 2023-bs-ai-015
//question statement:Imagine a publishing company that markets both book and audiocassetes versions of its works. Create a class publicaion that stores the ?tle (a string) and price (type float) of a publicaon. From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Each of these three classes should have a getdata() function to get its data from the user at the keyboard, and a putdata() function to display its data. Write a main() program to test the book and tape classes by creatng instances of them, asking the user to fill in data with getdata(), and then displaying the data with putdata().

#include<iostream>
using namespace std;
class publication
{
	private:
	int pageC;
	float pageT;
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
	}
	int putdata()
	{
		cout<<"publications detail:"<<endl;
		cout<<"title: "<<title<<endl;
		cout<<"price: "<<price<<" Rs"<<endl;
		cout<<"number of pages: "<<pageC<<endl;
		cout<<"playing time: "<<pageT<<" minutes"<<endl;
	}
};
int main ()
{
	publication p;
	p.getdata();
	p.putdata();
}
