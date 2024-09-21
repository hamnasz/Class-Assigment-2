// File: code2.cpp
// Date: 20-05-2024
// Name: HARIS AWAN 
// Registration No: 2023-BS-AI-023
//Start with the publicaOon, book, and tape classes of QuesOon 1. Add a base class sales that holds an 
//array of three floats so that it can record the dollar sales of a parOcular publicaOon for the last three 
//months. Include a getdata() funcOon to get three sales amounts from the user, and a putdata() funcOon 
//to display the sales figures. Alter the book and tape classes so they are derived from both publicaOon 
//and sales. An object of class book or tape should input and output sales data along with its other data. 
//Write a main() funcOon to create a book object and a tape object and exercise their input/output 
//capabiliOes. 

#include<iostream>
using namespace std;
class publication
{
	private:
	string title;
	float price;
	public:
		void getpublication(){
			cout<<"Enter Title of book: ";
			cin>>title;
			cout<<"Enter price of book: ";
			cin>>price;
		}
		void putpublication(){
			cout<<"Title of book is: "<<title<<endl;
			cout<<"Price of book is: "<<price<<endl;
		}
};
class sales{
	private:
	float arr[3];
	public:
	void getsales(){
		
		for(int i=0;i<3;i++){
		cout<<"Enter sales of month "<<i+1<<": ";
			cin>>arr[i];
		}
	}
	void putsales(){
		for(int i=0;i<3;i++){
			cout<<"Sales of month "<<i+1<<" is ";
			cout<<arr[i]<<endl;
		}
	}
};
class book:public publication, public sales
{
	private:
	int page_count;
	public:
		void getbook(){
			cout<<"Enter Page count of book: ";
			cin>>page_count;
		}
		void putbook(){
			cout<<"Page count of book is: "<<page_count<<endl;
		}	
};
class tape:public publication,public sales
{
	private:
	float minutes;
	public:
		void gettape(){
			cout<<"Enter minutes of book: ";
			cin>>minutes;
		}
		void puttape(){
			cout<<"Minutes of book is: "<<minutes<<endl;
		}	
};
int main(){
	book oop;
	tape haris;
	
	oop.getpublication();
	oop.getbook();
	haris.gettape();
	haris.getsales();
	
	oop.putpublication();
	oop.putbook();
	haris.puttape();
	haris.putsales();
}